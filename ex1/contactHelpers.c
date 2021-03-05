/* -------------------------------------------
Name: Sina Monajemi
Student number: 021-324-124
Email: smonajemi@myseneca.ca
Section: SAA
Date: April 6
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include<string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include"contacts.h"



// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5



//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	int value; // assigning value as int
	char fvalue = 0; // false value assigned

	while (fvalue != '\n') // false value is not equal to \n
	{
		scanf("%d%c", &value, &fvalue); // scanning value to int only - calling false value to read the extra character
		if (fvalue != '\n')
		{

			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	}

	return value; // definite return to int value
}

// getIntInRange:
int getIntInRange(int low, int up)
{
	int value = getInt(); // the input has to be an integer 
	while (value < low || value > up)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", low, up);
		value = getInt();
	}
	return value;
}

// yes function definition goes here:
int yes(void)
{
	int r = 0; // result value 
	char input = 0, fvalue;

	do
	{
		scanf("%c%c", &input, &fvalue);
		if (fvalue != '\n') // only Y(es) or N(O) 
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
		else {
			switch (input)
			{
			case 'Y':
			case 'y':
				r = 1;
				break;

			case 'N':
			case 'n':
				r = 0;
				break;
			}
		}
	} while (fvalue != '\n');

	return r; // returning to only 1 or 0
}

// menu:
int menu(void)
{
	int option;

	printf("Contact Management System\n");
	printf("-------------------------\n");

	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");

	printf("\n");

	printf("Select an option:> ");

	option = getIntInRange(0, 6); // numbers only between 0-6n allowed - range option


	return option;
}

// ContactManagerSystem:
void ContactManagerSystem(void)
{
	int choice;
	int exit = 0;
			
	struct Contact contacts[MAXCONTACTS] = 
		{ { { "Rick", { '\0' }, "Grimes" },
		{11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },
	{
		{ "Morgan", "A.", "Jones" },
		{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
		{ "7051112222", "7052223333", "7053334444" } },
	{
		{ "Sasha",{ '\0' }, "Williams" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9052223333", "9052223333", "9054445555" } },
	};

	

	do {
		choice = menu(); // back to menu after choice selected

		switch (choice)
		{

		case 0:
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1)
				exit = 1; // if choice is Y , exit also equals to 1
			printf("\n");
			break;

		case 1:
			printf("\n");
			displayContacts(contacts,MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 2:
			printf("\n");
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 3:
			printf("\n");
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 4:
			printf("\n");
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 5:
			printf("\n");
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 6:
			printf("\n");
			printf("<<< Feature 6 is unavailable >>> \n\n");
			pause();
			printf("\n");
			break;

		}

	} while (exit == 0); // if choice is N, back to menu
	printf("Contact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[11])
{
	int digit = 1;
	
	while (digit == 1)
	{
		scanf("%10s", telNum);
		clearKeyboard();

		if (strlen(telNum) == 10)
			digit = 0;
	
		else
			printf("Enter a 10-digit phone number: ");
	}
	
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int input =0;
	int result = -1;

	for (input = 0; input <= size; input++)
	{
		if ( strcmp(contacts[input].numbers.cell,cellNum) == 0)
		{
			result = input;
		}
	}
	return result;
}

// displayContactHeader
void displayContactHeader(void)
{
printf("+-----------------------------------------------------------------------------+\n");
printf("|                              Contacts Listing                               |\n");
printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int total)
{
printf("+-----------------------------------------------------------------------------+\n");
printf("Total contacts: %d\n\n",total);
}

// displayContact:
void displayContact(const struct Contact*contacts)
{
	//getchar(); // for testing purposes

	// Name:
	if (strlen(contacts->name.middleInitial) > 0)
		printf(" %s %s %s\n", contacts->name.firstName, contacts->name.middleInitial, contacts->name.lastName);
	else 
		printf(" %s %s\n",contacts->name.firstName, contacts->name.lastName);

	//Numbers:
		printf("    C: %-10s   H: %-10s   B: %-10s\n", contacts->numbers.cell, contacts->numbers.home, contacts->numbers.business);

	//Address:
	if (contacts->address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", contacts->address.streetNumber, contacts->address.street, contacts->address.apartmentNumber, contacts->address.city, contacts->address.postalCode);
	else
		printf("       %d %s, %s, %s\n", contacts->address.streetNumber, contacts->address.street, contacts->address.city, contacts->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int input = 0, total = 0;
	displayContactHeader();

	for (input = 0; input < size; input++)
	{
		if (strlen(contacts[input].numbers.cell) > 0)
		{
			total +=1;
			displayContact(&contacts[input]);
		}
	}
	displayContactFooter(total);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char num[11];
	int input = 0;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);

	input = findContactIndex(contacts, size, num);

	if (input != -1)
	{
		printf("\n");
		displayContact(&contacts[input]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int input, slotavailable = -1;
	for (input = 0; input < size; input++)
	{

		if (strlen(contacts[input].numbers.cell) == 0)
		{
			slotavailable = input;
		}
	}
	if (slotavailable > -1)
	{

		getContact(&contacts[slotavailable]);
		printf("--- New contact added! ---\n");
	}
	else
	{
		printf("*** ERROR: The contact list is full! ***\n");
	}
}




// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	
	char num[11];
	int input =0 ,find;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);
	find = findContactIndex(contacts, size, num);
	
	if (find == -1)
	{
		printf("*** Contact NOT FOUND ***");
		printf("\n");
	}
	else
	{

		printf("\n");
		printf("Contact found:\n");
		displayContact(&contacts[find]);

			printf("\nDo you want to update the name? (y or n): ");
			
			input = yes();
			if (input == 1)
			{
				getName(&contacts[find].name);
				getchar();
			}		
			
			printf("Do you want to update the address? (y or n): ");	
			input = yes();
			if (input == 1)
			{
				getAddress(&contacts[find].address);		
				getchar();				
			}

			printf("Do you want to update the numbers? (y or n): ");	
			input = yes();
			if (input == 1)
			
			{
				getNumbers(&contacts[find].numbers);
			}
			printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
void deleteContact (struct Contact contacts[], int size)
{
	char num[11] = { '\0' };
	int input=0,find;
	

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);

	find = findContactIndex(contacts, size, num);

	if (find == -1)
			printf("*** Contact NOT FOUND ***\n");
	else
	{
		printf("\n");
		printf("Contact found:\n");

		displayContact(&contacts[find]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");		
		input = yes();

		if (input == 1) {
			contacts[find].numbers.cell[0] = '\0';
			
			printf("--- Contact deleted! ---\n");
		}

	}

}

// sortContacts:
/*
void sortContacts(const struct Contact contacts[],int order)
{
	int i, j, m;
	int temp;

	for (i = 0; i < order; i++) {
		m = i;
		for (j = i + 1; j < order; j++)
			if (contacts->numbers.cell[j] <contacts->numbers.cell[m]) {
				m = j;
			}
		if (m != i) {
			temp = contacts->numbers.cell[i];
		}
	}
}*/