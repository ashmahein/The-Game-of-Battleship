/*Name: Ash Mahein
* Date: 03/31/16
* Class: CptS 121, Spring 2016; Lab Section 4
* Programming Assignment: Battleship
* Collobaration: Connor Wytko, Rahul Singal, Jose Cuevas.
* Description: This program plays the game of battlship by explaining the rule and then placing player ships either randomly of manually.
* It then chooses one of the players to start. Player shoot until all ships have been sunk on one of the player boards. Then stats are printed to an outfile and to the board.
*
*Constants: None.
*
*Outputs: Shot coordinates, total hits, total misses, hits to miss ratio, ships sunk.
*
*/
#include "Mahein_Ash_PA6.h"
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Prints out a welcome screen and the game rules.                              *
*********************************************************************************************/
void welcome_screen(void)
{
	printf("Welcom to Battleship\n");
	printf("This is a two player game. Player 1 is you and Player 2 is the computer. You \nwill be asked to position your ships manually or have the program position your \nships for you.\n");
	printf("Once your ships have been positioned, game play will begin. You will be asked to \nenter in a two digit area to attack.\n");
	printf("If you hit an enemy ship you will be asked to enter in new coordinates. If you \nmiss your turn will end, and it will \nbe player 2's turn.\n");
	printf("Once one player ships have all been sunk the game will end and your score will be printed to another file.\n");
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for making the two demensional array that is used in the game.      *
*********************************************************************************************/
void init_board(char board[][10], int row_size, int col_size)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < row_size; row_index++)
	{
		for (col_index = 0; col_index < col_size; col_index++)
		{
			board[row_index][col_index] = '~';
		}
	}
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for printing the two demensioanl game board to the screen.          *
*********************************************************************************************/
void print_board(char board[][10], int row_size, int col_size)
{
	int row_index = 0, col_index = 0;

	printf("%3d %2d %2d %2d %2d %2d %2d %2d %2d %2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

	for (row_index = 0; row_index < row_size; row_index++)
	{
		printf("%-2d", row_index);
		for (col_index = 0; col_index < col_size; col_index++)
		{
			printf(" %c ", board[row_index][col_index]);
		}
		putchar('\n');
	}
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for choosing which player is to start first. Randomly choosen.      *
*********************************************************************************************/
int select_who_starts_first(int starter)
{
	int starting_player = 0;

	starting_player = (rand() % 2 + 1);

	if (starting_player == 1)
	{
		printf("Player 1 you start.\n");
	}
	else
	{
		printf("Player 2 you start.\n");
	}

	return starting_player;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for generting a direction when placing ship randomly. This is an    *
*               enumerated type.                                                             *
*********************************************************************************************/
Direction generate_direction(void)
{
	Direction dir = 0;

	dir = (Direction)((rand() % 2) + 1);

	return dir;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for manually placing ship. Asks player for a ROW number and then a  *
*               COLUMN number with a space inbetween each entry.                             *                                                                             
*********************************************************************************************/
void manually_place_ships_on_board(char board[][10], Direction dir, int row_size, int col_size)
{
	int index = 0, random_carrier_row_selection = 0, random_crusier_row_selection = 0, random_battleship_row_selection = 0, random_submarine_row_selection = 0, random_destroyer_row_selection = 0;
	int random_carrier_placement = 0, random_crusier_placement = 0, random_battleship_placement = 0, random_submarine_placement = 0, random_destroyer_placement = 0;
	int random_carrier_col_selection = 0, random_crusier_col_selection = 0, random_battleship_col_selection = 0, random_submarine_col_selection = 0, random_destroyer_col_selection = 0;
	char player_entry = '\0';

	printf("Would you like to place your carrier horizontal or vertical? <H/V>\n");
	scanf(" %c", &player_entry);
	// HORIZONTAL PLACEMENT CARRIER
	if (player_entry == 'h')
		for (index = 0; index != 5; index++)
		{
			printf("Where would you like to place your carrier? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_carrier_row_selection, &random_carrier_placement);
			if (board[random_carrier_row_selection][random_carrier_placement] != '~')
			{
				printf("Sorry, you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_carrier_row_selection][random_carrier_placement] = 'C';
			}
		}

	// VERTICAL PLACEMENT CARRIER
	if (player_entry == 'v')
	{
		for (index = 0; index != 5; index++)
		{
			printf("Where would you like to place your carrier? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_carrier_col_selection, &random_carrier_placement);
			if (board[random_carrier_placement][random_carrier_col_selection] != '~')
			{
				printf("Sorry you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_carrier_placement][random_carrier_col_selection] = 'C';
			}
		}
	}

	//HORIZONTAL PLACEMENT CRUSIER
	printf("Would you like to place your crusier horizontal or vertical? <H/V>\n");
	scanf(" %c", &player_entry);
	if (player_entry == 'h')
	{
		for (index = 0; index != 3; index++)
		{
			printf("Where would you like to place your crusier? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_crusier_row_selection, &random_crusier_placement);
			if (board[random_crusier_row_selection][random_crusier_placement] != '~')
			{
				printf("Sorry you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_crusier_row_selection][random_crusier_placement] == 'R';
			}
		}
	}

	//VERTICAL CRUISER PLACEMENT
	if (player_entry == 'v')
	{
		for (index = 0; index != 3; index++) //might need to be (index = 1; index != 4; index++)
		{
			printf("Where would you like to place your crusier? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_crusier_col_selection, &random_crusier_placement);
			if (board[random_crusier_placement][random_crusier_col_selection] != '~')
			{
				printf("Sorry you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_crusier_placement][random_crusier_col_selection] = 'R';
			}
		}
	}

	//HORIZONTAL BATTLESHIP PLACEMENT
	printf("Would you like to place your battleship horizontal or vertical? <H/V>\n");
	scanf(" %c", &player_entry);
	if (player_entry == 'h')
	{
		for (index = 0; index != 4; index++)
		{
			printf("Where would you like to place your battleship? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_battleship_row_selection, &random_battleship_placement);
			if (board[random_battleship_row_selection][random_battleship_placement] != '~')
			{
				printf("Sorry you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_battleship_row_selection][random_battleship_placement] = 'B';
			}
		}
	}

	//VERTICAL BATTLESHIP PLACEMENT
	if (player_entry == 'v')
	{
		for (index = 0; index != 4; index++)
		{
			printf("Where would you like to place your battleship? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_battleship_col_selection, &random_battleship_placement);
			if (board[random_battleship_placement][random_battleship_col_selection] != '~')
			{
				printf("Sorry you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_battleship_placement][random_battleship_col_selection] = 'B';
			}
		}
	}

	//HORIZONTAL SUBMARINE PLACEMENT
	printf("Would you like to place your submarine horizontal or vertical? <H/V>\n");
	scanf(" %c", &player_entry);
	if (player_entry == 'h')
	{
		for (index = 0; index != 3; index++)
		{
			printf("Where would you like to place your submarine? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_submarine_row_selection, &random_submarine_placement);
			if (board[random_submarine_row_selection][random_submarine_placement] != '~')
			{
				printf("Sorry you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_submarine_row_selection][random_submarine_placement] = 'S';
			}
		}
	}

	//VERTICAL SUBMARINE PLACEMENT
	if (player_entry == 'v')
	{
		for (index = 0; index != 3; index++)
		{
			printf("Where would you like to place your submarine? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_submarine_col_selection, &random_submarine_placement);
			if (board[random_submarine_placement][random_submarine_col_selection] != '~')
			{
				printf("Sorry you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_submarine_placement][random_submarine_col_selection] = 'S';
			}
		}
	}

	//HORIZONTAL DESTROYER PLACEMENT
	printf("Would you like to place your destroyer horizontal or vertical? <H/V>\n");
	scanf(" %c", &player_entry);
	if (player_entry == 'h')
	{
		for (index = 0; index != 2; index++)
		{
			printf("Where would you like to place your destroyer? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_destroyer_row_selection, &random_destroyer_placement);
			if (board[random_destroyer_row_selection][random_destroyer_placement] != '~')
			{
				printf("Sorry you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_destroyer_row_selection][random_destroyer_placement] = 'S';
			}
		}
	}
	//VERTICAL DESTROYER PLACEMENT
	if (player_entry == 'v')
	{
		for (index = 0; index != 2; index++)
		{
			printf("Where would you like to place your destroyer? Enter a number for the [ROW] and [COLUMN]. Leave space inbetween entries.?\n");
			scanf("%d%d", &random_destroyer_col_selection, &random_destroyer_placement);
			if (board[random_destroyer_placement][random_destroyer_col_selection] != '~')
			{
				printf("Sorry you can't place there. It is either taken or off the board.\n");
				index -= 1;
			}
			else
			{
				board[random_destroyer_placement][random_destroyer_col_selection] = 'D';
			}
		}
	}
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for randomly placing ships. It uses a generated direction and checks*
*               to see before placing each ship if it will overlap or not. If it will overlap*
*               then the ROW and COLUMN are randomly generated again until a fit has been    *
*               found.																		 *
*********************************************************************************************/
void randomly_place_ships_on_board(char board[][10], Direction dir, int row_size, int col_size)
{

	int index = 0, random_carrier_row_selection = 0, random_crusier_row_selection = 0, random_battleship_row_selection = 0, random_submarine_row_selection = 0, random_destroyer_row_selection = 0;
	int random_carrier_placement = 0, random_crusier_placement = 0, random_battleship_placement = 0, random_submarine_placement = 0, random_destroyer_placement = 0;
	int random_carrier_col_selection = 0, random_crusier_col_selection = 0, random_battleship_col_selection = 0, random_submarine_col_selection = 0, random_destroyer_col_selection = 0;
	int carrier_placed = 0, crusier_placed = 0, battleship_placed = 0, submarine_placed = 0, destroyer_placed = 0;

	//CARRIER PLACEMENT HORIZONTAL
	dir = generate_direction();
	if ((dir == 1) && (carrier_placed != 1))
		do
		{
			random_carrier_row_selection = rand() % 10;
			random_carrier_placement = rand() % 5;

			if ((board[random_carrier_row_selection][random_carrier_placement] != '~') || (board[random_carrier_row_selection][random_carrier_placement + 1] != '~') || (board[random_carrier_row_selection][random_carrier_placement + 2] != '~'))
			{
				carrier_placed = 0;
			}
			else
			{
				for (index = 1; index != 6; index += 1)
				{
					board[random_carrier_row_selection][random_carrier_placement + index] = 'C';
				}
				carrier_placed = 1;
			}
		} while (carrier_placed != 1);

		//CARRIER PLACEMENT VERTICAL
		if ((dir == 2) && (carrier_placed != 1))
		{
			do
			{
				random_carrier_col_selection = rand() % 10;
				random_carrier_placement = rand() % 5;

				if ((board[random_carrier_placement][random_carrier_col_selection] != '~') || (board[random_carrier_placement][random_carrier_col_selection + 1] != '~') || (board[random_carrier_placement][random_carrier_col_selection + 2] != '~'))
				{
					carrier_placed = 0;
				}
				else
				{
					for (index = 1; index != 6; index += 1)
					{
						board[random_carrier_placement + index][random_carrier_col_selection] = 'C';
					}
					carrier_placed = 1;
				}
			} while (carrier_placed != 1);
		}

		//CRUSIER PLACEMENT HORIZONTAL
		dir = generate_direction();
		if ((dir == 1) && (crusier_placed != 1))
		{
			do
			{
				random_crusier_row_selection = rand() % 10;
				random_crusier_placement = rand() % 7;

				if ((board[random_crusier_row_selection][random_crusier_placement] != '~') || (board[random_crusier_row_selection][random_crusier_placement + 1] != '~') || (board[random_crusier_row_selection][random_crusier_placement + 2] != '~') ||
					(board[random_crusier_row_selection][random_crusier_placement] == 'C') || (board[random_crusier_row_selection][random_crusier_placement + 1] == 'C') || (board[random_crusier_row_selection][random_crusier_placement + 2] == 'C'))
				{
					crusier_placed = 0;
				}
				else
				{
					for (index = 0; index != 3; index += 1)
					{
						board[random_crusier_row_selection][random_crusier_placement + index] = 'R';
					}
					crusier_placed = 1;
				}
			} while (crusier_placed != 1);
		}

		//CRUSIER PLACEMENT VERTICAL
		if ((dir == 2) && (crusier_placed != 1))
		{
			do
			{
				random_crusier_col_selection = rand() % 10;
				random_crusier_placement = rand() % 7;

				if ((board[random_crusier_placement][random_crusier_col_selection] != '~') || (board[random_crusier_placement + 1][random_crusier_col_selection] != '~') || (board[random_crusier_placement + 2][random_crusier_col_selection] != '~') ||
					(board[random_crusier_placement][random_carrier_col_selection] == 'C') || (board[random_crusier_placement + 1][random_crusier_col_selection] == 'C') || (board[random_crusier_placement + 2][random_crusier_col_selection] == 'C'))
				{
					crusier_placed = 0;
				}
				else
				{
					for (index = 0; index != 3; index += 1)
					{
						board[random_crusier_placement + index][random_crusier_col_selection] = 'R';
					}
					crusier_placed = 1;
				}
			} while (crusier_placed != 1);
		}

		//BATTLESHIP PLACEMENT HORIZONTAL
		dir = generate_direction();
		if ((dir == 1) && (battleship_placed != 1))
		{
			do
			{
				random_battleship_row_selection = rand() % 10;
				random_battleship_placement = rand() % 6;

				if ((board[random_battleship_row_selection][random_battleship_placement] != '~') || (board[random_battleship_row_selection][random_battleship_placement + 1] != '~') || (board[random_battleship_row_selection][random_battleship_placement + 2] != '~') || (board[random_battleship_row_selection][random_battleship_placement + 3] != '~') ||
					(board[random_battleship_row_selection][random_battleship_placement] == 'C') || (board[random_battleship_row_selection][random_battleship_placement + 1] == 'C') || (board[random_battleship_row_selection][random_battleship_placement + 2] == 'C') || (board[random_battleship_row_selection][random_battleship_placement + 3] == 'C') ||
					(board[random_battleship_row_selection][random_battleship_placement] == 'R') || (board[random_battleship_row_selection][random_battleship_placement + 1] == 'R') || (board[random_battleship_row_selection][random_battleship_placement + 2] == 'R') || (board[random_battleship_row_selection][random_battleship_placement + 3] == 'R'))
				{
					battleship_placed = 0;
				}
				else
				{
					for (index = 0; index != 4; index += 1)
					{
						board[random_battleship_row_selection][random_battleship_placement + index] = 'B';
					}
					battleship_placed = 1;
				}
			} while (battleship_placed != 1);
		}

		//BATTLESHIP PLACEMENT VERTICAL
		if ((dir == 2) && (battleship_placed != 1))
		{
			do
			{
				random_battleship_col_selection = rand() % 10;
				random_battleship_placement = rand() % 6;

				if ((board[random_battleship_placement][random_battleship_col_selection] != '~') || (board[random_battleship_placement + 1][random_battleship_col_selection] != '~') || (board[random_battleship_placement + 2][random_battleship_col_selection] != '~') || (board[random_battleship_placement + 3][random_battleship_col_selection] != '~') ||
					(board[random_battleship_placement][random_battleship_col_selection] == 'C') || (board[random_battleship_placement + 1][random_battleship_col_selection] == 'C') || (board[random_battleship_placement + 2][random_battleship_col_selection] == 'C') || (board[random_battleship_placement + 3][random_battleship_col_selection] == 'C') ||
					(board[random_battleship_placement][random_battleship_col_selection] == 'R') || (board[random_battleship_placement + 1][random_battleship_col_selection] == 'R') || (board[random_battleship_placement + 2][random_battleship_col_selection] == 'R') || (board[random_battleship_placement + 3][random_battleship_col_selection] == 'R'))
				{
					battleship_placed = 0;
				}
				else
				{
					for (index = 0; index != 4; index += 1)
					{
						board[random_battleship_placement + index][random_battleship_col_selection] = 'B';
					}
					battleship_placed = 1;
				}
			} while (battleship_placed != 1);
		}

		//SUBMARINE PLACEMENT HORIZONTAL
		dir = generate_direction();
		if ((dir == 1) && (submarine_placed != 1))
		{
			do
			{
				random_submarine_row_selection = rand() % 10;
				random_submarine_placement = rand() % 7;

				if ((board[random_submarine_row_selection][random_submarine_placement] != '~') || (board[random_submarine_row_selection][random_submarine_placement + 1] != '~') || (board[random_submarine_row_selection][random_submarine_placement + 2] != '~') ||
					(board[random_submarine_row_selection][random_submarine_placement] == 'C') || (board[random_submarine_row_selection][random_submarine_placement + 1] == 'C') || (board[random_submarine_row_selection][random_submarine_placement + 2] == 'C') ||
					(board[random_submarine_row_selection][random_submarine_placement] == 'R') || (board[random_submarine_row_selection][random_submarine_placement + 1] == 'R') || (board[random_submarine_row_selection][random_submarine_placement + 2] == 'R') ||
					(board[random_submarine_row_selection][random_submarine_placement] == 'B') || (board[random_submarine_row_selection][random_submarine_placement + 1] == 'B') || (board[random_submarine_row_selection][random_submarine_placement + 2] == 'B'))
				{
					submarine_placed = 0;
				}
				else
				{
					for (index = 1; index != 4; index += 1)
					{
						board[random_submarine_row_selection][random_submarine_placement + index] = 'S';
					}
					submarine_placed = 1;
				}
			} while (submarine_placed != 1);
		}

		//SUBMARINE PLACEMENT VERTICAL
		if ((dir == 2) && (submarine_placed != 1))
		{
			do
			{
				random_submarine_col_selection = rand() % 10;
				random_submarine_placement = rand() % 7;

				if ((board[random_submarine_placement][random_submarine_col_selection] != '~') || (board[random_submarine_placement + 1][random_submarine_col_selection] != '~') || (board[random_submarine_placement + 2][random_submarine_col_selection] != '~') ||
					(board[random_submarine_placement][random_submarine_col_selection] == 'C') || (board[random_submarine_placement + 1][random_submarine_col_selection] == 'C') || (board[random_submarine_placement + 2][random_submarine_col_selection] == 'C') ||
					(board[random_submarine_placement][random_submarine_col_selection] == 'R') || (board[random_submarine_placement + 1][random_submarine_col_selection] == 'R') || (board[random_submarine_placement + 2][random_submarine_col_selection] == 'R') ||
					(board[random_submarine_placement][random_submarine_col_selection] == 'B') || (board[random_submarine_placement + 1][random_submarine_col_selection] == 'B') || (board[random_submarine_placement + 2][random_submarine_col_selection] == 'B'))
				{
					submarine_placed = 0;
				}
				else
				{
					for (index = 1; index != 4; index += 1)
					{
						board[random_submarine_placement + index][random_submarine_col_selection] = 'S';
					}
					submarine_placed = 1;
				}
			} while (submarine_placed != 1);
		}

		//DESTROYER PLACEMENT HORIZONTAL
		dir = generate_direction();
		if ((dir == 1) && (destroyer_placed != 1))
		{
			do
			{
				random_destroyer_row_selection = rand() % 10;
				random_destroyer_placement = rand() % 7;

				if ((board[random_destroyer_row_selection][random_destroyer_placement] != '~') || (board[random_destroyer_row_selection][random_destroyer_placement + 1] != '~') ||
					(board[random_destroyer_row_selection][random_destroyer_placement] == 'C') || (board[random_destroyer_row_selection][random_destroyer_placement + 1] == 'C') ||
					(board[random_destroyer_row_selection][random_destroyer_placement] == 'R') || (board[random_destroyer_row_selection][random_destroyer_placement + 1] == 'R') ||
					(board[random_destroyer_row_selection][random_destroyer_placement] == 'B') || (board[random_destroyer_row_selection][random_destroyer_placement + 1] == 'B') ||
					(board[random_destroyer_row_selection][random_destroyer_placement] == 'S') || (board[random_destroyer_row_selection][random_destroyer_placement + 1] == 'S'))
				{
					destroyer_placed = 0;
				}
				else
				{
					for (index = 1; index != 3; index += 1)
					{
						board[random_destroyer_row_selection][random_destroyer_placement + index] = 'D';
					}
					destroyer_placed = 1;
				}
			} while (destroyer_placed != 1);
		}

		//DESTROYER PLACEMENT VERTICAL
		if ((dir == 2) && (destroyer_placed != 1))
		{
			do
			{
				random_destroyer_col_selection = rand() % 10;
				random_destroyer_placement = rand() % 7;

				if ((board[random_destroyer_placement][random_destroyer_col_selection] != '~') || (board[random_destroyer_placement + 1][random_destroyer_col_selection] != '~') ||
					(board[random_destroyer_placement][random_destroyer_col_selection] == 'C') || (board[random_destroyer_placement + 1][random_destroyer_col_selection] == 'C') ||
					(board[random_destroyer_placement][random_destroyer_col_selection] == 'R') || (board[random_destroyer_placement + 1][random_destroyer_col_selection] == 'R') ||
					(board[random_destroyer_placement][random_destroyer_col_selection] == 'B') || (board[random_destroyer_placement + 1][random_destroyer_col_selection] == 'B') ||
					(board[random_destroyer_placement][random_destroyer_col_selection] == 'S') || (board[random_destroyer_placement + 1][random_destroyer_col_selection] == 'S'))
				{
					destroyer_placed = 0;
				}
				else
				{
					for (index = 1; index != 3; index += 1)
					{
						board[random_destroyer_placement + index][random_destroyer_col_selection] = 'D';
					}
					destroyer_placed = 1;
				}
			} while (destroyer_placed != 1);
		}

}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for taking shots and then checking if the shots were hits or misses.*
*               If shot is a hit, total hits is incremented and total hits is printed to the *
*               output file along with the shot coordinates.                                 *
*********************************************************************************************/
int check_shot(FILE *stats, char board[][10], char board_p1[][10], char board_p2[][10], int *choose_again, int row_size, int col_size, int *misses_p1, int *misses_p2, int starting_player, int *hits_made_p1, int *hits_made_p2, int *shot_coordinate1, int *shot_coordinate2, int total_hits_p1, int total_hits_p2, int *ship_hit_p1, int *ship_hit_p2)
{
	int misses = 0, hit = 0;

	if (starting_player == 1)
	{
		while (hit == 0)
		{
			if ((board[*shot_coordinate1][*shot_coordinate2] != 'M') && (board[*shot_coordinate1][*shot_coordinate2] != '*'))
			{
				if (board_p2[*shot_coordinate1][*shot_coordinate2] == '~')
				{
					printf("Missed your shot.\n");
					board[*shot_coordinate1][*shot_coordinate2] = 'M';
					fprintf(stats, "%d%d Player 1 MISS.\n", *shot_coordinate1, *shot_coordinate2);
					*misses_p1 += 1;
					print_board(board, 10, 10);
					hit = 1;
				}
				else
				{
					printf("HIT!\n");
					board[*shot_coordinate1][*shot_coordinate2] = '*';
					total_hits_p1 += 1;
					*hits_made_p1 += 1;
					*ship_hit_p1 = 1;
					fprintf(stats, "%d%d Player 1 HIT.\n", *shot_coordinate1, *shot_coordinate2);
					print_board(board, 10, 10);
					hit = 1;
				}
			}
			else if ((board[*shot_coordinate1][*shot_coordinate2] == 'M') || (board[*shot_coordinate1][*shot_coordinate2] == '*'))
			{
				printf("You already shot there, choose again.\n");
				*choose_again = 0;
			}
			break;
		}
	}
	else if (starting_player == 2)
	{
		while (hit == 0)
		{
			*shot_coordinate1 = rand() % 10;
			*shot_coordinate2 = rand() % 10;

			if ((board_p1[*shot_coordinate1][*shot_coordinate2] != 'M') && (board_p1[*shot_coordinate1][*shot_coordinate2] != '*'))
			{
				if (board_p1[*shot_coordinate1][*shot_coordinate2] == '~')
				{
					printf("Player 2 missed.\n");
					board_p1[*shot_coordinate1][*shot_coordinate2] = 'M';
					*misses_p2 += 1;
					fprintf(stats, "%d%d Player 2 MISS.\n", *shot_coordinate1, *shot_coordinate2);
					print_board(board_p1, 10, 10);
					hit = 1;
				}
				else
				{
					printf("Player 2 hit your ship.\n");
					board_p1[*shot_coordinate1][*shot_coordinate2] = '*';
					fprintf(stats, "%d%d Player 2 HIT.\n", *shot_coordinate1, *shot_coordinate2);
					total_hits_p2 += 1;
					*hits_made_p2 += 1;
					*ship_hit_p2 = 1;
					misses += 1;
					print_board(board_p1, 10, 10);
					hit = 1;
				}
			}
			else
			{
				printf("You already shot there, choose again.\n");
				hit = 0;
			}
		}
		return total_hits_p2;
	}
	return total_hits_p1;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for checking if the shot that was taken sunk a ship. The ship that  *
*               has been sunk will be printed out letting the player know.                   *
*********************************************************************************************/
void check_if_sunk_ship(FILE *stats, char board_p1[][10], char board_p2[][10], int row_size, int col_size, int *hits_made_p1, int *hits_made_p2, int shot_coordinate1, int shot_coordinate2, int ship_hit_p1, int ship_hit_p2, int *carrier_sunk_p1, int *crusier_sunk_p1, int *battleship_sunk_p1, int *submarine_sunk_p1, int *destroyer_sunk_p1, int *carrier_sunk_p2, int *crusier_sunk_p2, int *battleship_sunk_p2, int *submarine_sunk_p2, int *destroyer_sunk_p2)
{
	if (ship_hit_p1 == 1)
	{
		if ((board_p2[shot_coordinate1][shot_coordinate2] == 'C') && (*hits_made_p1 == 5) && (*carrier_sunk_p2 == 0))
		{
			printf("Opponents CARRIER has been sunk.\n");
			fprintf(stats, "Opponents CARRIER has been sunk.\n");
			*hits_made_p1 = 0;
			ship_hit_p1 = 0;
			*carrier_sunk_p2 = 1;
		}
		else if ((board_p2[shot_coordinate1][shot_coordinate2] == 'B') && (*hits_made_p1 == 4) && (*battleship_sunk_p2 == 0))
		{
			printf("Opponents BATTLESHIP has been sunk.\n");
			fprintf(stats, "Opponents BATTLESHIP has been sunk.\n");
			*hits_made_p1 = 0;
			ship_hit_p1 = 0;
			*battleship_sunk_p2 = 1;
		}
		else if ((board_p2[shot_coordinate1][shot_coordinate2] == 'S') && (*hits_made_p1 == 3) && (*submarine_sunk_p2 == 0))
		{
			printf("Opponents SUBMARINE has been sunk.\n");
			fprintf(stats, "Opponents SUBMARINE has been sunk.\n");
			*hits_made_p1 = 0;
			ship_hit_p1 = 0;
			*submarine_sunk_p2 = 1;
		}
		else if ((board_p2[shot_coordinate1][shot_coordinate2] == 'R') && (*hits_made_p1 == 3) && (*crusier_sunk_p2 == 0))
		{
			printf("Opponents CRUSIER has been sunk.\n");
			fprintf(stats, "Opponents CRUSIER has been sunk.\n");
			*hits_made_p1 = 0;
			ship_hit_p1 = 0;
			*crusier_sunk_p2 = 1;
		}
		else if ((board_p2[shot_coordinate1][shot_coordinate2] == 'D') && (*hits_made_p1 == 2) && (*destroyer_sunk_p2 == 0))
		{
			printf("Opponents DESTROYER has been sunk.\n");
			fprintf(stats, "Opponents DESTROYER has been sunk.\n");
			*hits_made_p1 = 0;
			ship_hit_p1 = 0;
			*destroyer_sunk_p2 = 1;
		}
		ship_hit_p1 = 0;
	}

	//PLAYER 2
	else if (ship_hit_p2 == 1)
	{
		if ((board_p1[shot_coordinate1][shot_coordinate2] == 'C') && (*hits_made_p2 == 5) && (carrier_sunk_p1 == 0))
		{
			printf("Your CARRIER has been sunk.\n");
			fprintf(stats, "Opponents CARRIER has been sunk.\n");
			*hits_made_p2 = 0;
			ship_hit_p2 = 0;
			*carrier_sunk_p1 = 1;
		}
		else if ((board_p1[shot_coordinate1][shot_coordinate2] == 'B') && (*hits_made_p2 == 4) && (battleship_sunk_p1 == 0))
		{
			printf("Your BATTLESHIP has been sunk.\n");
			fprintf(stats, "Opponents BATTLESHIP has been sunk.\n");
			*hits_made_p2 = 0;
			ship_hit_p2 = 0;
			*battleship_sunk_p1 = 1;
		}
		else if ((board_p1[shot_coordinate1][shot_coordinate2] == 'S') && (*hits_made_p2 == 3) && (submarine_sunk_p1 == 0))
		{
			printf("Your SUBMARINE has been sunk.\n");
			fprintf(stats, "Opponents SUBMARINE has been sunk.\n");
			*hits_made_p2 = 0;
			ship_hit_p2 = 0;
			*submarine_sunk_p1 = 1;
		}
		else if ((board_p1[shot_coordinate1][shot_coordinate2] == 'R') && (*hits_made_p2 == 3) && (crusier_sunk_p1 == 0))
		{
			printf("Your CRUSIER has been sunk.\n");
			fprintf(stats, "Opponents CRUSIER has been sunk.\n");
			*hits_made_p2 = 0;
			ship_hit_p2 = 0;
			*crusier_sunk_p1 = 1;
		}
		else if ((board_p1[shot_coordinate1][shot_coordinate2] == 'D') && (*hits_made_p2 == 2) && (destroyer_sunk_p1 == 0))
		{
			printf("Your DESTROYER has been sunk.\n");
			fprintf(stats, "Opponents DESTROYER has been sunk.\n");
			*hits_made_p2 = 0;
			ship_hit_p2 = 0;
			*destroyer_sunk_p1 = 1;
		}
		ship_hit_p2 = 0;
	}
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for checking if there is a winner after all ships have been sunk by *
*               either player 1 or player 2.                                                 *
*********************************************************************************************/
void is_winner(int total_hits_p1, int total_hits_p2)
{
	if (total_hits_p1 == 17)
	{
		printf("Player 1 wins. Game over.\n");
	}
	else if (total_hits_p2 == 17)
	{
		printf("Player 2 wins. Game over.\n");
	}
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Battleship                                                         *
*                                                                                            *
* Date: 03/31/16                                                                             *
*                                                                                            *
* Description://Function for printing out stats to the screen or to the file battlship_stats.*
*               This function untilizes structs in order to do so.                           *
*********************************************************************************************/
void print_stats(FILE *stats, Stats p1_stats, Stats p2_stats, int total_hits_p1, int total_hits_p2, int misses)
{
	fprintf(stats, "Hits Player 1: %d\n", p1_stats.total_hits_p1);
	fprintf(stats, "Misses Player 1: %d\n", p1_stats.misses_p1);
	fprintf(stats, "Ratio Player 1: %.2lf\n", p1_stats.hits_miss_ratio);

	fprintf(stats, "Hits Player 2: %d\n", p2_stats.total_hits_p2);
	fprintf(stats, "Misses Player 2: %d\n", p2_stats.misses_p2);
	fprintf(stats, "Ratio Player 2: %.2lf\n", p2_stats.hits_miss_ratio);

	printf("Hits Player 1: %d\n", p1_stats.total_hits_p1);
	printf("Misses Player 1: %d\n", p1_stats.misses_p1);
	printf("Ratio Player 1: %.2lf\n", p1_stats.hits_miss_ratio);

	printf("Hits Player 2: %d\n", p2_stats.total_hits_p2);
	printf("Misses Player 2: %d\n", p2_stats.misses_p2);
	printf("Ratio Player 2: %.2lf\n", p2_stats.hits_miss_ratio);
}