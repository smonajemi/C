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
#include"contacts.h"
#include"contactHelpers.h"

// getName:
void getName(struct Name*name)
{
	int choice;

	printf("Please enter the contact's first name: "); // input first name
	scanf("%30[^\n]s", name->firstName);
	getchar();
	

	// middle name input - y or n option
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	
	choice = yes();

	if (choice == 1)
	{
		printf("Please enter the contact's middle initial(s): "); // input middle name
		scanf("%6s", name->middleInitial);
		getchar();
	}

	
	printf("Please enter the contact's last name: "); // input last name
	scanf("%40[^\n]s", name->lastName);
	};
// getAddress:
void getAddress(struct Address*address)
{
	int choice;

	//clearKeyboard();
	//getchar();
	printf("Please enter the contact's street number: "); // input street number
	address->streetNumber = getInt();

	printf("Please enter the contact's street name: "); { // input street name
		scanf("%40[^\n]s", address->street);
		getchar(); // prevents "enter key" as a string
	}
	printf("Do you want to enter an apartment number? (y or n): ");
	choice = yes();

	if (choice == 1) {
		printf("Please enter the contact's apartment number: "); // input apt number
		scanf("%d", &address->apartmentNumber);
		getchar();
	}
	else address->apartmentNumber= '\0';

	printf("Please enter the contact's postal code: "); { // input postal code
		scanf(" %10[^\n]s", address->postalCode);
		}

	getchar();
	printf("Please enter the contact's city: ");{ // input city
	scanf("%30[^\n]s", address->city);

	}
};

// getNumbers:
void getNumbers(struct Numbers*numbers)
{
	//clearKeyboard();
	int choice;

	printf("Please enter the contact's cell phone number: "); // input cell phone number 
	getTenDigitPhone(numbers->cell);

	// home phone number - y or n optidigiton
	printf("Do you want to enter a home phone number? (y or n): ");
	choice = yes();

	if (choice == 1) {
		printf("Please enter the contact's home phone number: "); // input home phone number
		getTenDigitPhone(numbers->home);
	}
	else
		numbers->home[0] = 0;
	// business phone number - y or n option	
	printf("Do you want to enter a business phone number? (y or n): ");
	choice = yes();
	if (choice == 1) {
		
		printf("Please enter the contact's business phone number: "); // input business phone number 
		getTenDigitPhone(numbers->business);
	}
	else numbers->business[0] = 0;
	
};
// getContact:
void getContact(struct Contact*contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}