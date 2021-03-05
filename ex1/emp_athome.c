/*
Name: SINA MONAJEMI
Student number: 021-324-124
Email: smonajemi@myseneca.ca
Workshop: W5-Home
Section: BTP100-SAA
Date: Feb 22, 2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 4

// Declare Struct Employee 
struct Employee {

	int id, age;
	float salary;
};

/* main program */
int main(void) {

	//variables = 0
	int n = 0;
	int i = 0;
	int u = 0;
	int r = 0;
	int option = 0;
	int input = 0;
	int rem = 0;
	
	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	struct Employee emp[SIZE] = { { 0 } };

	// Print the option list
	do {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n\n");

			break;

		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (n = 0; n<SIZE; n++)
			{
				printf("%6d%9d%11.2lf\n", emp[n].id, emp[n].age, emp[n].salary); // displaying loop for id,age&salary				
			}
			
			printf("\n");// spacing
			break;

		
		case 2:	// Adding Employee
				

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			input++;
			if (input > 4) {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");//spacing
				break;
			}

			printf("Enter Employee ID: ");
			scanf("%d", &emp[i].id);
			int duplicate = 0;
			for (int j = 0; j < 4; j++)
			{

				if (emp[i].id == emp[j].id && emp[j].id != 0 && j != i)
				{
					printf("ERROR!!! Duplicate ID\n\n\n");
					duplicate = 1;
					emp[i].id = 0;
				}
			}
			if (duplicate == 1)
				break;

			printf("Enter Employee Age: ");
			scanf("%d", &emp[i].age);

			printf("Enter Employee Salary: ");
			scanf("%f", &emp[i].salary);

			printf("\n"); // spacing
			i++; // incrementing number of inputs
			i = i;
			break;
			
		case 3: // updating employee

			printf("Update Employee Salary\n");
			printf("======================\n");

				int upd = 0;

				printf("Enter Employee ID: ");
				scanf("%d", &upd);
				for (u = 0; u<SIZE; u++)
				{
					if (upd == emp[u].id)
					{
						printf("The current salary is %f\n", emp[u].salary);

						printf("Enter Employee New Salary: ");
						scanf("%f", &emp[u].salary);
						printf("\n");
					}
				}

				break;

		case 4: // Removing Employee
				
				
																
					printf("Remove Employee\n");
					printf("===============\n");

					printf("Enter Employee ID: ");
					scanf("%d", &rem);
					for (r = 0; r < SIZE; r++)
					{
						if (rem == emp[r].id && emp[r].id != 0)
						{
							printf("Employee %d will be removed\n", emp[r].id);
							emp[r].id = 0;
							emp[r].age = 0;
							emp[r].salary = 0;

							printf("\n");
						}
					}

					break;

			default:
				printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	




	return 0;
}



