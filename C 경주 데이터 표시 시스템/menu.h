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
#include "file_helper.h"

int menu();

char categorySelection();

void printRiders(struct RiderInfo riders[], int indexes[], int indexes_len);