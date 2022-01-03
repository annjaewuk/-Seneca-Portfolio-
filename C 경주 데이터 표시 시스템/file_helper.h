/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Luis Miguel Hernandez    ljaime-hernandez@myseneca.ca
   2) Jaewook Ahn              jahn33@myseneca.ca
   3) Mark Ruffolo             maruffolo@myseneca.ca

   +--------------------------------------------------------+
   |                FILE: file_helper.h                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>

/********************************************************/
/* Define the missing members for the RiderInfo data    */
/* used to store Rider information read from a file     */
/********************************************************/
struct RiderInfo
{
	char name[25];
	int age;
	char raceLength;
	double startTime;
	double mountainTime;
	double finishTime;
	int withdrawn;
};



/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!        DO NOT ALTER THE CONTENTS BELOW       !!!*/
/*!!!             ( function prototype )           !!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/********************************************************/
/* Read all the information on one rider from the       */
/* file and store it in the struct. Return true         */
/* when end of file has been reached.                   */
/********************************************************/
int readFileRecord(FILE* fp, struct RiderInfo* info);

#endif
