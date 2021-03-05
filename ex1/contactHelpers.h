/* ------------------------------------------------------------------
Name: Sina Monajemi
Student number: 021-324-124
Email: smonajemi@myseneca.ca
Section: SAA
Date: April 6
---------------------------------------------------------------------
Assignment: 2
Milestone:  4
*/



#include"contacts.h"

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------


// Clear the standard input buffer
// clearKeyboard:
void clearKeyboard(void);

// pause:
void pause(void);

// getInt:
int getInt(void);

// getIntInRange:
int getIntInRange(int low, int up);

// yes:
int yes(void);

// menu:
int menu(void);

// ContactManagerSystem:
void ContactManagerSystem(void);

// Generic function to get a ten-digit phone number:
// getTenDigitPhone:
void getTenDigitPhone(char[11]);

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cell[]);

// displayContactHeader:
void displayContactHeader(void);

// displayContactFooter:
void displayContactFooter(int);

// displayContact:
void displayContact(const struct Contact*contacts);

// displayContacts:
void displayContacts(const struct Contact[], int);

// searchContacts:
void searchContacts(const struct Contact[], int);

// addContact:
void addContact(struct Contact[], int);

// updateContact:
void updateContact(struct Contact[], int);

// deleteContact:
void deleteContact(struct Contact[], int);

//sortContacts:
//void sortContacts(struct Contact[],int);