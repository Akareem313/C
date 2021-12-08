#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void random_variables(void);

void print_variables(void);
void user_input(void);
void timer_start(void);
void answers(int correct);
void results(void);
void mode(void);
void save_results(void);

void leaderboards(void);

int first;
int second;
int attempts = 0;
int mistakes = 0;
int game_mode = 0;
int answer;
int lives;
int max_attempts;
int mistake_saved;

char operator;

double game_time;
double best_time = 300;


time_t initial;
time_t final;


void leaderboards(void)
{
	printf("\n Top results: ");
	printf("\n\n\nBest time: %.3f minutes\t number of attempts: %d\t mistakes : %d\n",		best_time / 60,	max_attempts,	mistake_saved);
}


void save_results(void)
{
	
	
	if(best_time > game_time )
	{
		printf("New high score\n");
		best_time = game_time;
		max_attempts = lives;
		mistake_saved= mistakes;
	}
	else
	{
		printf("Same high");
	}
}


void mode(void)
{
	printf("Select what game mode do you want?\n");
	printf("Enter 1 for addition\n");
	printf("Enter 2 for substraction\n");
	
	scanf("%d",	&game_mode);
}


void results(void)
{
	double total_time = final - initial;
	if(mistakes == 1)	//mistake for 1 the rest is mistakes
	{
		printf("%d Attempts and %d Mistake in %f Seconds\n",		attempts,	mistakes, total_time);
	}
	else
	{
		printf("%d Attempts and %d Mistakes in %f Seconds\n",		attempts,	mistakes, total_time);
	}
}


void answers(int correct)
{
	switch(game_mode)
	{			
		case 1: //addition
		correct = first + second;			
		break;
			
		case 2: //substraction	
			if(second < first)
			{
				correct = first - second;
			}				
			else
			{
				correct = second - first;
			}				
			break;
	}
	
	if(answer == correct)
	{
		printf("Correct\n");
	}
	else
	{
		printf("\nWrong, correct answer is %d\n",	correct);
		mistakes++;
	}
}


void random_variables(void)
{
	bool generated = false;
	srand((unsigned)time(NULL));
	
	while(generated != true)
	{
		first = rand() % 10;
		second = rand() % 10;
		generated = true;
	}
}


void print_variables(void)
{
	switch(game_mode)
	{			
		case 1: //addition		
			operator = '+';
			break;
			
		case 2: //substraction
			operator = '-';
			break;
	}
	
	if(first > second)
	{
		printf("\n%d %c %d\n",	first, operator, second);
	}
	else
	{
		printf("\n%d %c %d\n",	second, operator, first);
	}
}


void timer_end(void)
{
	final = time(NULL);
}


void timer_start(void)
{
	initial = time(NULL);
}


void user_input(void)
{
	scanf("%d",	&answer);
	attempts++;
}


int main(void)
{	
	char again;
	time_t time_started;

	do
	{
		mode();
		random_variables();


		printf("\nHow many equations do you want to solve?\n");
		scanf("%d",	&lives);

		time_started = time(NULL);
		
		attempts = 0;
		for(int i = 0; i < lives; i++)
		{
			print_variables();
			timer_start();
			user_input();
			timer_end();
			answers(1);
			results();
			random_variables();
		}

		game_time = time(NULL) - time_started;
		printf("Took %f minutes to solve %d equations",		game_time / 60.0, lives);

		save_results();
		leaderboards();

		printf("\n\nDo you want to play again?\n");
		printf("press n to stop or y to repeat\n");

		scanf("%s",	&again);

	}while(again != 'n' && again == 'y' );
}
