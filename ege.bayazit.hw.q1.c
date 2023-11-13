#include <stdio.h>

int getInput(); // to get the chosen number

void clearGrades(float *,float *, float *,int); // to clear the chosen grade


int main(){
	
	float grade1 = 0;
	float *grade2 = &grade1; //we use first grade's adress to access grade2 & grade3
	float *grade3 = &grade1;
	float tempGrade2, tempGrade3, gpa;
	int choice1, choice2;
	
	
	do{
	printf("--------------GRADES--------------\n");
	printf("1- CMPE114: %.0f, (%p)\n",grade1,&grade1);
	printf("2- PHYS102: %.0f, (%p)\n",*grade2,&grade2);
	printf("3- HIST201: %.0f, (%p)\n",*grade3,&grade3);
	printf("---------------------------------- \n");
	
		gpa = (grade1 + *grade2 + *grade3) / 3.0 / 25.0; //calculating the current GPA 
	
	printf("Your GPA is: %.1f/4.0\n",gpa);
	printf("1- Edit class grade \n");
	printf("2- Clear grade \n");
	printf("3- Quit \n");
	
	choice1 = getInput();  // function call to get the number
	
	switch (choice1){
				case 1:
					printf("Enter a class number to edit (1-3): ");
					scanf("%d",&choice2);
				while (choice2>3 || choice2<0)
				{	printf("Not a valid number!\n");
					printf("Enter a class number to edit (1-3): ");
					scanf("%d",&choice2);}
				
					printf("Enter grade for class %d: ",choice2);
					
					float newGrade;
					grade2 = &tempGrade2;
					grade3 = &tempGrade3;
			
			switch (choice2){
				case 1:
					scanf ("%f",&newGrade);
					grade1 = newGrade;
					break;
				case 2:
					scanf ("%f",&newGrade);
					tempGrade2 = newGrade;          // using temp grades to change indiviual grades without effecting others
					break;
				case 3:
					scanf ("%f",&newGrade);
					tempGrade3 = newGrade;
					break;
					}
					printf("Updated the grade for class %d!\n",choice2);
			break;
		
		case 2:
			printf("Enter a class number to clear (1-3): ");
			scanf("%d",&choice2);
				while (choice2>3 || choice2<0)
				{	printf("Not a valid number!\n");
					printf("Enter a class number to clear (1-3): ");
					scanf("%d",&choice2);}
					
					printf("Cleared grade for class %d!\n",choice2);
					*grade2 = tempGrade2;
					*grade3 = tempGrade3;
					clearGrades(&grade1,grade2,grade3,choice2);  // function call to clear the spesified grade
			break;		
		
	}
	
		
		}while (choice1 != 3);  // checking if user want to quit the program or not
		
		printf("Goodbye : )");
		
		return 0;
}


int getInput()
{	
	int num=0;
	
	do
	{
		printf("Enter selection: ");
		scanf ("%d",&num);
			if(num>3 || num<0)
				printf("Not a vaild number!\n");
			
	} while (num>3 || num<0);
	
	return num;	
		
}
	
	
void clearGrades(float *g1,float *g2, float *g3, int choice)
{
	switch(choice){
		case 1:
			*g1=0;
			break;
		case 2:
			*g2=0;
			break;
		case 3:
			*g3=0;
			break;
	}
	
}	


	

