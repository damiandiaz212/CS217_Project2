// Damian Diaz (N00821283@students.ncc.edu)
// CSC 217
// Project 2: "Missing Data"
// Due 12/04/17 11:59 pm
// record.c

#include "record.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXRECORDS 100

// VARIABLES

// Record struct array
struct Record records[MAXRECORDS];

// Amount of records stored in array
int count = 0;

int quantity;

char *pnPointer;
char *quanPointer;

// void makeRecordFromLine
// Takes one char array
// converts char[] into a record struct
//
void makeRecordFromLine(char recordLine[]) {

  makeId(recordLine);
  makePartNumber(recordLine);
  makeQuanity(recordLine);
  makePrice(recordLine);
  makeString();

  count += 1; // increment count
}

// void makeId
// Takes one char array
// Take id out of line and store it in record struct
//
void makeId(char str[]) {

  char temp[10]; // temp char array
  char *c;       // char pointer

  const char beginChar = '('; // char to begin at
  const char endChar = ')';   // char to end at

  c = strchr(str, beginChar); // assigns c to the index of ch
  c++;                        // assigns c to the next char in the array

  int i = 0;
  temp[i] = *c; // stores value at c to the first index

  while (*c != endChar) { // while the value of c isn't the endChar
    i += 1;
    c++;
    temp[i] = *c;
  }

  temp[i] = '\0'; // assign the null terminator to the end of the array

  strcpy(records[count].customerId, temp); // assign new char[] to the struct

  pnPointer = (c += 2); // assign part number pointer
}

// void makePartNumber
// Takes one char array
// Take part number out of line and store it in record struct
//
void makePartNumber(char str[]) {

  char temp[10];
  char *c;
  c = pnPointer; // assign c to part number pointer

  const char endChar = ' ';

  int i = 0;
  temp[i] = *c;

  while (*c != endChar) {
    i += 1;
    c++;
    temp[i] = *c;
  }

  temp[i] = '\0';

  strcpy(records[count].partNumber, temp);

  quanPointer = (c += 3); // assign quantity pointer
}

// void makeQuanity
// Takes one char array
// Take quantity out of line and store it in record struct
//
void makeQuanity(char str[]) {

  char temp[5];
  char *c;
  c = quanPointer;

  const char endChar = ' ';

  int i = 0;

  while (*c != endChar) {
    temp[i] = *c;
    i += 1;
    c++;
  }

  temp[i] = '\0';

  quantity = atoi(temp); // assign quantity to temp converted to int
  strcpy(records[count].quantity, temp);
}

// void makePrice
// Takes one char array
// Take price out of line and store it in record struct
//
void makePrice(char str[]) {

  char temp[10];
  char *c;

  const char beginChar = '$';
  const char endChar = '\n';

  c = strchr(str, beginChar);
  c++;

  int i = 0;

  while (*c != endChar) {
    temp[i] = *c;
    c++;
    i++;
  }

  double total = atof(temp);       // convert temp to double and assign to total
  double price = total / quantity; // assign price to total / quantity

  char totTemp[10];

  sprintf(totTemp, "%.2f", price); // convert double to char[]
  strcpy(records[count].total, totTemp);
}

// void makeString
// Create a char[] with all data and store in struct
//
void makeString() {

  strcat(records[count].string, records[count].customerId);
  strcat(records[count].string, " ");
  strcat(records[count].string, records[count].partNumber);
  strcat(records[count].string, " ");
  strcat(records[count].string, records[count].quantity);
  strcat(records[count].string, " ");
  strcat(records[count].string, records[count].total);
  strcat(records[count].string, "\n");
}

// int getCount
// returns amount of records
//
int getCount() { return count; }

// char *getRecordLine
// takes an integer as index
// returns a char[] of the record at the index
//
char *getRecordLine(int i) { return records[i].string; }
