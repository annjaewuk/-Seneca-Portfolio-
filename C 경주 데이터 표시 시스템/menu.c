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

#include <stdio.h>
#include <string.h>
#include "menu.h"

void displayRider(struct RiderInfo* rider, int display_option, int showNonFinish) {
	char age[10] = "N/A";
	if (16 <= (*rider).age && (*rider).age <= 20) {
		strcpy(age, "Junior");
	}
	else if (21 <= (*rider).age && (*rider).age <= 34) {
		strcpy(age, "Adult");
	}
	else if (35 <= (*rider).age) {
		strcpy(age, "Senior");
	}
	printf("%-30s%-10s", (*rider).name, age);
	if (display_option) {
		char len[10] = "N/A";
    if ((*rider).raceLength == 'S' || (*rider).raceLength == 's')
    {
      strcpy(len, "50km");
    }
    if ((*rider).raceLength == 'M' || (*rider).raceLength == 'm')
    {
      strcpy(len, "75km");
    }
    if ((*rider).raceLength == 'L' || (*rider).raceLength == 'l')
    {
      strcpy(len, "75km");
    }
  }
	double time = (*rider).finishTime - (*rider).startTime;

  int hours = (int)time;
	int minutes = ((((time - (int)time) * 60)*10)+0.001)/10;
	
  if (hours<1) {
		printf("   N/A");
	}
	else {
		printf(" %02d:%02d", hours, minutes);
	}
  
  if (showNonFinish == 1) {
    if ((*rider).withdrawn) {
			printf("%10s", "Yes");
		  }
		else {
			printf("%10s", "No");
		  }
  }
  printf("\n");
}

void printRiders(struct RiderInfo riders[], int indexes[], int indexes_len) {
	int show_category = 0;
	int showNonFinish = 0;
	int check = 0;
	for (int i = 0; i < indexes_len; i++) {
		if (riders[indexes[i]].withdrawn == 1) {
			showNonFinish = 1;
		}
		if (riders[indexes[i]].raceLength == 'S' || riders[indexes[i]].raceLength == 's') {
			check = 1;
		}
		if (riders[indexes[i]].raceLength == 'M' || riders[indexes[i]].raceLength == 'm') {
			check = 1;
		if (riders[indexes[i]].raceLength == 'L' || riders[indexes[i]].raceLength == 'l') {
			check = 1;
		}
		}
	}
	if (check > 1) {
		show_category = 1;
	}

	printf("\n");
	int len = 0;
	printf("%-30s%-10s", "Rider", "Age Group");
	len = len + 40;
	if (show_category == 1) {
		printf("%-10s", "Category");
		len = len + 10;
	}
	printf("%6s", "Time");
	len = len + 6;
	if (showNonFinish == 1) {
		printf("%10s", "Withdrew");
		len = len + 10;
	}
	printf("\n");
	for (int i = 0; i < len; i++) {
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < indexes_len; i++) {
		displayRider(&riders[indexes[i]], show_category, showNonFinish);
	}
	printf("\n");
}

char categorySelection() {
	char inputed=0;
	printf("\nWhich category (S, M, L): ");
	while (1) {
		int result = scanf(" %c", &inputed);
		if (result != 0) {
      if (inputed == 'S' || inputed == 's'){
        return inputed;
      }
      if (inputed == 'M' || inputed == 'm'){
        return inputed;
      }
      if (inputed == 'L' || inputed == 'l'){
        return inputed;
      }
      
		}
		scanf("%*[^\n]");
		printf("Incorrect option, try again: ");
	}
}

int menu()
{
	int inputed=0;
	printf("What would you like to do?\n"
		"0 - Exit\n"\
		"1 - Print top 3 riders in a category\n"
		"2 - Print all riders in a category\n"
		"3 - Print last 3 riders in a category\n"
		"4 - Print winners in all categories\n"
		": ");
	while (1) {
		int result = scanf("%d", &inputed);
		if (inputed >= 0 && inputed <= 4 && result != 0) {
			break;
		}
		scanf("%*[^\n]");
		printf("Incorrect option, try again: ");
	}

	return inputed;
}