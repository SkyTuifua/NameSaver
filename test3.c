#include <stdio.h>
#include <stdlib.h>


struct People {
	char firstName[30];
	char lastName[20];
	int age;
};

void PrintOptions()
{
	printf("_____________________________________________________________________\n\n");
	printf("a: Add new Person.\nr: Remove person.\nf: edit someones first name.\nl: edit someone's last name.\nn: edit someone's age.\ni: list people\no: options\nq: quit\n");
	printf("_____________________________________________________________________\n");
}
struct People AddPerson()
{
	struct People newPerson;
	printf("Enter a first name: ");
	scanf("%s", &newPerson.firstName);
	printf("Enter a Last Name: ");
	scanf("%s", &newPerson.lastName);
	printf("Enter their age: ");
	scanf("%d", &newPerson.age);
	return newPerson;
}
struct People EditPerson(struct People editedPerson, char editType)
{
	if (editType == 'f')
	{
		printf("New First Name: \n");
		scanf("%s", &editedPerson.firstName);
		
	}
	if (editType == 'l')
	{
		printf("New Last Name: \n");
		scanf("%s", &editedPerson.lastName);

	}
	if (editType == 'n')
	{
		printf("New Age: \n");
		scanf("%d", &editedPerson.age);

	}
	return editedPerson;
}
void ListPeople(struct People* peopleArray, int currentPeople)
{
	printf("_____________________________________________________________________\n\n");
	for (int i = 0; i < currentPeople; i++)
	{
		printf("%d: %s %s %d \n", i, peopleArray[i].firstName, peopleArray[i].lastName, peopleArray[i].age);
	}
	printf("_____________________________________________________________________\n");
}

int main()
{
	FILE *fp;
	fp = fopen("Output.txt", "r");
	struct People peopleArray[100];

	char UserText[20];
	int currentPeople = 0;
	int MAX = 100;
	int currentPosition = 0;
	char userOption;
	int editIndex;

	if (fp == NULL) {
		printf("Not able to open the file.");
	}
	
	
	while (fgets(UserText, MAX, fp))
	{
		sscanf(UserText, "%s %s %d", &peopleArray[currentPeople].firstName, &peopleArray[currentPeople].lastName, &peopleArray[currentPeople].age);
		currentPeople++;
	}
		
	ListPeople(peopleArray, currentPeople);

	
	PrintOptions();

	while (userOption != 'q')
	{
		
		printf("Please type a command:");
		scanf(" %c", &userOption);
		if (userOption == 'a')
		{
			peopleArray[currentPeople] = AddPerson();
			currentPeople++;
		}
		if (userOption == 'i')
		{
			ListPeople(peopleArray, currentPeople);
		}
		if (userOption == 'o')
		{
			PrintOptions();
		}
		if (userOption == 'f' || userOption == 'l' || userOption == 'n')
		{
			
			ListPeople(peopleArray, currentPeople);
			printf("Enter the number of the person you would like to edit: ");
			scanf("%d", &editIndex);
			peopleArray[editIndex] = EditPerson(peopleArray[editIndex], userOption);
		}
		if (userOption == 'r')
		{
			ListPeople(peopleArray, currentPeople);
			printf("Enter the number of the person you would like to remove: ");
			scanf("%d", &editIndex);
			for (int i = editIndex; i < currentPeople; i++)
			{
				peopleArray[i] = peopleArray[i + 1];
			}
			currentPeople--;
			

		}
		
	}

	fp = fopen("Output.txt", "w");
	
	for (int i = 0; i < currentPeople; i++)
	{
		fprintf(fp, "%s %s %d\n", peopleArray[i].firstName, peopleArray[i].lastName, peopleArray[i].age);
	}

	fclose(fp);
	
	
	return 0;

}