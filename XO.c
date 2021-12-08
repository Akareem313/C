/*
 *Date created: Mon, Dec. 6 
 *Time created: 02 : 47 AM
 */
#include "X | O.h"

void game(void);

void game(void)
{
	initialize_board();
	do
	{
		print_array();
		get_input();
		implement_changes();

		check_if(won);
		if(check_if(won) == false)
		{
			pc_move();
			implement_changes();
			check_if(won);
		}
	}while(check_if(won) == false);
	printf("Player %c won!",	player);
}

int main()
{
	bool again = true;
	do
	{
		game();
		play_again(again);
		if(play_again(again))
		{
			again = true;
		}
		else
		{
			again = false;
		}
	}while(play_again(again));
	return 0;
}
