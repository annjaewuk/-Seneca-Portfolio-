/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Luis Miguel Hernandez    ljaime-hernandez@myseneca.ca
   2) Jaewook Ahn              jahn33@myseneca.ca
   3) Mark Ruffolo             maruffolo@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */
#include <string.h>
#include "rider_array.h"

int find_size(struct RiderInfo riders[], int max_size) {
	int i;
	for (i = 0; i < max_size; i++) {
		if (riders[i].raceLength == 0) {
			break;
		}
	}
	return i;
}

int selection_find(struct RiderInfo riders[], int max_size, int indexes[], char category, int no_withdraw) {
	int size = find_size(riders, max_size);
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (riders[i].raceLength == toupper(category) && (!no_withdraw || !riders[i].withdrawn)) {
			indexes[j] = i;
			j++;
		}
	}
	return j;
}

int compare_riders(struct RiderInfo* r1, struct RiderInfo* r2){
	double t1 = (*r1).finishTime - (*r1).startTime;
	double t2 = (*r2).finishTime - (*r2).startTime;
	int swap = 0;
	if ((*r1).withdrawn == 0 && (*r2).withdrawn == 0) {
		if (t1 < t2) {
			swap = 0;
		}
		else if (t1 == t2) {
			if ((*r1).mountainTime < (*r2).mountainTime) {
				swap = 0;
			}
			else {
				swap = 1;
			}
		}
		else {
			swap = 1;
		}
	}
	else if ((*r1).withdrawn == 1) {
		swap = 1;
	}
	return swap;
}

void riders_switch(struct RiderInfo* r1, struct RiderInfo* r2)
{
	struct RiderInfo tmp;
	tmp = *r1;
	*r1 = *r2;
	*r2 = tmp;
}

void riders_sorted(struct RiderInfo riders[], int max_size)
{
	int size = find_size(riders, max_size);
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (compare_riders(&riders[j - 1], &riders[j])) {
				riders_switch(&riders[j - 1], &riders[j]);
			}
		}
	}
}