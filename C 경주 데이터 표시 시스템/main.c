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

#define _CRT_SECURE_NO_WARNINGS

#define RIDERS_SIZE 5000

#include "file_helper.h"
#include "menu.h"
#include "rider_array.h"

int main(void)
{
	// TODO: Code the necessary logic for your solution below
	//
	// NOTE: Use modularity whenever possible in your design
	//
	// HINTS:
	// 1) You will need to load the file data and store
	//    it to a data structure array 
	//    (MUST USE: provided "readFileRecord" function)
	//
	// 2) Create a menu system to provide the user with
	//    the reporting options
	//
	// 3) Generate the user-selected report
  printf("******************** Seneca Cycling Race Results ********************\n");
	FILE* fp = NULL;
  fp = fopen("data.txt", "r");
	struct RiderInfo riders[RIDERS_SIZE] = { 0 };
	struct RiderInfo winners[3];
	int indexes[RIDERS_SIZE];
	int i = 0;
	int size;
	char category;
	
	while (readFileRecord(fp, &riders[i]) == 0 && i < RIDERS_SIZE) {
		i++;
	}

	riders_sorted(riders, RIDERS_SIZE);

	while (1)
	{
		switch (menu()) {
		case 1:
			category = categorySelection();
			size = selection_find(riders, RIDERS_SIZE, indexes, category, 1);
			if (size > 3) {
				size = 3;
			}
			printRiders(riders, indexes, size);
			break;
		case 2:
			category = categorySelection();
			size = selection_find(riders, RIDERS_SIZE, indexes, category, 0);
			printRiders(riders, indexes, size);
			break;
		case 3:
			category = categorySelection();
			size = selection_find(riders, RIDERS_SIZE, indexes, category, 1);
			int begin = size > 3 ? size - 3 : 0;
			printRiders(riders, &indexes[begin], size-begin);
			break;
		case 4:
			i = 0;
			size = selection_find(riders, RIDERS_SIZE, indexes, 's', 1);
			if (size > 0) {
				winners[i] = riders[indexes[0]];
				i++;
			}
			size = selection_find(riders, RIDERS_SIZE, indexes, 'm', 1);
			if (size > 0) {
				winners[i] = riders[indexes[0]];
				i++;
			}
			size = selection_find(riders, RIDERS_SIZE, indexes, 'l', 1);
			if (size > 0) {
				winners[i] = riders[indexes[0]];
				i++;
			}
			int temp_array[] = { 0, 1, 2 };
			printRiders(winners, temp_array, i);
			break;
		case 0:
			printf("\nKeep on Riding!\n");
			return 0;
		}
	}

}