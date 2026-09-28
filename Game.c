
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

	int num, guess, tries = 0;
	char play;
	srand(time(0)); //Random generator
	

	printf("You will guess my favorite number\n");
	
	do
	{
		num = rand() % 100 + 1; //Random number between 1 and 100
		tries = 0;
		do
		{

			tries++;

			printf("Enter a number between 1 and 100\n");
			int read = scanf("%d", &guess);
			if (read == EOF)
			{
				return 0;
			}
			if (read != 1)
			{
				int c;
				while ((c = getchar()) != '\n' && c != EOF); //Discard non-numeric input
				printf("That is not a number\n");
				guess = -1;
				tries--;
				continue;
			}

			if (guess > num)
			{
				printf("Too high!, try again\n");
			}
			else if (guess < num)
			{
				printf("Too low!, try again\n");
			}
			else
			{
				printf("You did it! Congrats. It just took you %d tries haha! \n\n\n", tries);
			}
		} while (guess != num);

		while (getchar() != '\n'); //Clean input buffer

		printf("Do you want to play again? (Y/N)\n\n");
		scanf("%c", & play);

	} while (play == 'y' || play == 'Y');


	
	printf("Game is over\n");

	return 0;
}