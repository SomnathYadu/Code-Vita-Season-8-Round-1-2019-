#include <iostream>

struct runner {
	int distance; // Distance covered in each steps
	int* steps;	// Steps pers second

	int total_dist; //Total distance covered by participant
};

int main() {
	// Number of prtocopants | Number of seconds
	int num_participants, num_seconds;
	struct runner* runners; // Structre for participants
	int* leading; //Array to store number of times any 
				  //participants is leading

	//Reading number of participants and number of seconds
	std::cin >> num_participants;
	std::cin >> num_seconds;

	//Dynamically creating array
	runners = new struct runner[num_participants];
	leading = new int[num_participants];

	//Reading value of steps and distance on each steps
	//for all paticipants
	for (int i = 0; i < num_participants; i++) {
		struct runner* r = &runners[i]; //r pointer to structure runners at ith position
										// We could also have used struct 
		r->steps = new int[num_seconds];//Dynamically creating array
		for (int j = 0; j < num_seconds; j++) {
			std::cin >> r->steps[j];
		}

		std::cin >> r->distance;

		r->total_dist = 0;
		leading[i] = 0;
	}

	for (int s = 0; s < num_seconds; s++) {
		int leading_val = 0; //Leading value for each second

		for (int i = 0; i < num_participants; i++) {
			struct runner* r = &runners[i];

			//Total distance by participant =( step on that time * distance on each steps
			//											+ previous distance covered )
			r->total_dist += r->steps[s] * r->distance;

			//To store the greatest value of participant leading in 
			//current second s
			if (leading_val < r->total_dist) {
				leading_val = r->total_dist;
			}
		}

		//Check for leading participant on each 2nd second
		//since 0 is 1 and 1 is 2 so we will check for 
		//every odd value of "s" in upper for loop :line 41
		if ((s % 2) == 1) {
			for (int i = 0; i < num_participants; i++) {
				struct runner* r = &runners[i];

				//Increase the value of leading participant
				//which has leading_val on current second s
				if (r->total_dist == leading_val) {
					leading[i] += 1;
				}
			}
		}
	}

	int winner_idx = 0; //Index of winner
	int winner_leading = 0; //Max number of any participant will be leading
	//This loop will decide winner
	for (int i = 0; i < num_participants; i++) {
		//If participant at ith index leading more then previous participant
		//then change winnde_idx to current ith and update 
		//winner_leading to leading score of current participant
		if (leading[i] > winner_leading) {
			winner_idx = i;
			winner_leading = leading[i];
		}
	}

	//Addint 1 to winner_idx because in question starting index is 1 but in program
	//it is 0
	std::cout << (winner_idx + 1) << std::endl;

	return 0;
}
