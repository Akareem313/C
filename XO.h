#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define board_size 9


//variables
int input;
int full = 0;

char player = 'X';

bool won;
bool again;
bool input_valid;

//board initialization
char board[board_size] = {'1','2','3','4','5','6','7','8','9'};
char initial_board[board_size] = {'1','2','3','4','5','6','7','8','9'};

//function declaration
void print_array(void);
void get_input(void);
void implement_changes(void);
void pc_move(void);
void initialize_board(void);
void if_full(void);

bool validating(bool input_valid);
bool check_if(bool won);
bool play_again(bool again);


//functions
void if_full(void)
{
	if(input_valid == true)
	{
		full++;
	}
	if(full == board_size)
	{
		won = true;
	}
}


void initialize_board(void)
{
	for(int i = 0; i < board_size; i++)
	{
		board[i] = initial_board[i];
	}
}


bool validating(bool input_valid)
{
	input_valid = false;
	
	switch(input)
	{
		case 1:
			if(board[0]== '1')
			{
				input_valid = true;
			}
			else
			{
				input_valid = false;
			}
		break;

		case 2:
			if(board[1] == '2')
			{
				input_valid = true;
			}
			else
			{
				input_valid = false;
			}
		break;

		case 3:
			if(board[2] == '3')
			{
				input_valid = true;
			}
			else
			{
				input_valid = false;
			}
		break;

		case 4:
			if(board[3] == '4')
			{
				input_valid = true;
			}
			else
			{
				input_valid = false;
			}
		break;

		case 5:
			if(board[4] == '5')
			{
				input_valid = true;
			}
			else
			{
				input_valid = false;
				}
		break;

		case 6:
			if(board[5] == '6')
			{
				input_valid = true;
			}
			else
			{
				input_valid = false;
			}
		break;

		case 7:
			if(board[6] == '7')
			{
				input_valid = true;
			}
			else
			{
				input_valid = false;
			}
		break;

		case 8:
			if(board[7] == '8')
			{
				input_valid = true;
			}
			else
			{
				input_valid = false;
			}
		break;

		case 9:
			if(board[8] == '9')
			{
				input_valid = true;
		}
		else
		{
			input_valid = false;
		}
		break;

		default:
			input_valid = false;
		break;
	}
	if(input_valid == false && player == 'X')
	{
		printf("\n Invalid input\n");
	}
	return input_valid;
}


bool play_again(bool again)
{
	char input;
	
	printf("\nPress anything to play again, n to stop: ");

	scanf("%c",	&input);
	
	switch(input)
	{
		case 'n':
			again = false;
		break;
		
		case 'N':
			again = false;
		break;
		
		default:
			again = true;
		break;
	}
	return again;
}


void pc_move(void)
{
	
	srand((unsigned)time(NULL));
	
	player = 'O';
	do
	{
		input = rand() % 10;
		validating(input_valid);
	}while(validating(input_valid) == false);
}


bool check_if(bool won)
{
	if(board[0] == player && board[1] == player && board[2] == player)
	{
		won = true;
	}
	else if(board[3] == player && board[4] == player && board[5] == player)
	{
		won = true;
	}
	else if(board[6] == player && board[7] == player && board[8] == player)
	{
		won = true;
	}
	else if(board[0] == player && board[3] == player && board[6] == player)
	{
		won = true;
	}
	else if(board[1] == player && board[4] == player && board[7] == player)
	{
		won = true;
	}
	else if(board[2] == player && board[5] == player && board[8] == player)
	{
		won = true;
	}
	else if(board[0] == player && board[4] == player && board[8] == player)
	{
		won = true;
	}
	else if(board[2] == player && board[4] == player && board[6] == player)
	{
		won = true;
	}
	else
	{
		won = false;
	}
	return won;
}


void print_array(void)
{
	printf("\n\n\n");
	for(int i = 0; i < board_size; i++)
	{
		printf("%c\t",	board[i]);
		if((i + 1) % 3 == 0)
		{
			printf("\n\n\n");
		}
		
	}
} 


void get_input(void)
{
	player = 'X';
	
	do
	{
		printf("\n\tEnter where you want to place X:");
		scanf("%d",	&input);
		validating(input_valid);
	}while(validating(input_valid) == false);
}


void implement_changes(void)
{
	switch(input)
	{
		case 1:
				board[0] = player;
			break;

		case 2:
				board[1] = player;
			break;

		case 3:
				board[2] = player;
			break;

		case 4:
				board[3] = player;
			break;

		case 5:
				board[4] = player;
			break;

		case 6:
				board[5] = player;
			break;

		case 7:
				board[6] = player;
			break;

		case 8:
				board[7] = player;
			break;

		case 9:
				board[8] = player;
			break;
		}
}
