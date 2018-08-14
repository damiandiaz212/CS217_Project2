// Damian Diaz (N00821283@students.ncc.edu)
// CSC 217
// Project 2: "Missing Data"
// Due 12/04/17 11:59 pm
// record.h

struct Record {
  char customerId[10];
  char partNumber[10];
  char quantity[10];
  char total[10];
  char string[50];
};

void makeRecordFromLine(char recordLine[]);

void makeId(char str[]);
void makePartNumber(char str[]);
void makeQuanity(char str[]);
void makePrice(char str[]);
void makeString();

int getCount();
char *getRecordLine(int i);
