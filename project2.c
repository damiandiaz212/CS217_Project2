// Damian Diaz (N00821283@students.ncc.edu)
// CSC 217
// Project 2: "Missing Data"
// Due 12/04/17 11:59 pm
// project2.c

#include "record.h"
#include <stdio.h>
#include <string.h>

// PROTOTYPES
int checkRecord(char line[]);

int main() {

  FILE *file;

  char *line;
  size_t len = 0;
  char read;

  // Open record.txt
  file = fopen("record.txt", "r");

  // If file is empty
  if (file == NULL)
    return 1;

  // While a line exists, make a record of it
  while ((read = getline(&line, &len, file)) != -1) {
    makeRecordFromLine(line);
  }

  // Close file
  fclose(file);

  // Open and compare lines from data.txt
  file = fopen("data.txt", "r");

  // If file is empty
  if (file == NULL)
    return 1;

  // While line exists, compare it to the records
  while ((read = getline(&line, &len, file)) != -1) {

    // If data does not exist in records
    if (checkRecord(line) == 0) {
      printf("%s", line);
    }
  }

  fclose(file);

  return 0;
}

// int checkRecord
// takes a char[]
// checks if that char[] matches any of the records
//
int checkRecord(char line[]) {

  // Set count to amount of records
  int count = getCount();
  int i;

  for (i = 0; i < count; i++) {

    // Compare line passed to each record, if found return 1
    if (strcmp(line, getRecordLine(i)) == 0) {
      return 1;
    }
  }

  // Record wasnt found, return 0
  return 0;
}
