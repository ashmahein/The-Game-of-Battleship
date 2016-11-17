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
#include"Mahein_Ash_PA6.h"  
int main(void)
{
	//Varible declaration.
	FILE *stats = NULL;
	stats = fopen("battleship_stats.txt", "w");
	srand((unsigned int)time(NULL));
	char board_p1[10][10] = { { '\0' },{ '\0' } }, board_p2[10][10] = { { '\0' },{ '\0' } }, ship_placement = '\0', board[10][10] = { { '\0' },{ '\0' } };
	Direction dir = 0;
	int row_size = 0, col_size = 0, choose_again = 1, starter = 0, starting_player = 0, hit = 0, misses = 0, hits_made = 0, hits_made_p1 = 0, hits_made_p2 = 0, shot_coordinate1 = 0, shot_coordinate2 = 0, total_hits_p1 = 0, total_hits_p2 = 0, ship_hit_p1 = 0, ship_hit_p2 = 0;
	int carrier_sunk_p1 = 0, crusier_sunk_p1 = 0, battleship_sunk_p1 = 0, submarine_sunk_p1 = 0, destroyer_sunk_p1 = 0, carrier_sunk_p2 = 0, crusier_sunk_p2 = 0, battleship_sunk_p2 = 0, submarine_sunk_p2 = 0, destroyer_sunk_p2 = 0, misses_p1 = 0, misses_p2 = 0;
	struct stats p1_stats = { 0, 0, 0.0 };
	Stats p2_stats = { 0, 0, 0.0};

	//Prints out rules.
	welcome_screen();
	system("pause");
	system("cls");
	//Displays boards to player.
	printf("Player 1's board.\n");
	init_board(board_p1, 10, 10);
	print_board(board_p1, 10, 10);
	printf("Player 2's board.\n");
	init_board(board_p2, 10, 10);
	print_board(board_p2, 10, 10);
	init_board(board, 10, 10);
	system("pause");
	system("cls");
	//Ask player to pick whether they want to place ships randomly or manually.
	printf("Would you like to manually place your ships?<Y/N>\n");
	scanf(" %c", &ship_placement);
	system("pause");
	system("cls");
	//If they want to place them randomly then this loop is entered. GO SLOW WHEN ENTERING SHIPS.
	if (ship_placement == 'y')
	{
		//MANUALLY PLACES SHIPS.
		manually_place_ships_on_board(board_p1, dir, row_size, col_size);
		//Prints boards with ships placed on them.
		printf("Player 1's board.\n");
		print_board(board_p1, 10, 10);
		printf("Player 2's board.\n");
		print_board(board_p2, 10, 10);
		system("pause");
		system("cls");
	}
	//If player wants to randomly place ships then this loop is enterd.
	else if (ship_placement == 'n')
	{
		printf("We'll place your ships randomly then.\n");
		//Randomly places ships.
		randomly_place_ships_on_board(board_p1, dir, row_size, col_size);
		//Prints out boards.
		printf("Player 1's board.\n");
		print_board(board_p1, 10, 10);
		printf("Player 2's board.\n");
		print_board(board_p2, 10, 10);
		system("pause");
		system("cls");
	}
	//Randomly places Player 2's ships to board.
	randomly_place_ships_on_board(board_p2, dir, row_size, col_size);
	//Hides player 2's ships.
	board_p2[10][10] = board[10][10];
	system("pause");
	system("cls");

	//Selects a player to go first.
	starting_player = select_who_starts_first(starter);

	//While all ships are still remaining the game will continue to execute prompting player for coordinates.
	while ((total_hits_p1 < 17) && (total_hits_p2 < 17))
	{
		//If player 1 is choosen to go first this loop will execute.
		if (starting_player == 1)
		{
			do
			{
				//If player puts in a coordinate that already been used they get prompted to choose another coordinate.
				choose_again = 1;
				printf("Take a shot.\n");
				printf("Please enter a [ROW] and [COLUMN] number to shoot at it.\n");
				scanf("%d%d", &shot_coordinate1, &shot_coordinate2);
				//Total hits made on a player 2's board.
				total_hits_p1 = check_shot(stats, board, board_p1, board_p2, &choose_again, row_size, col_size, &misses_p1, &misses_p2, starting_player, &hits_made_p1, &hits_made_p2, &shot_coordinate1, &shot_coordinate2, total_hits_p1, total_hits_p2, &ship_hit_p1, &ship_hit_p2);
				starting_player = 2;
				//Checks if a ship has been sunk after each shot.
				check_if_sunk_ship(stats, board_p1, board_p2, row_size, col_size, &hits_made_p1, &hits_made_p2, shot_coordinate1, shot_coordinate2, ship_hit_p1, ship_hit_p2, &carrier_sunk_p1, &crusier_sunk_p1, &battleship_sunk_p1, &submarine_sunk_p1, &destroyer_sunk_p1, &carrier_sunk_p2, &crusier_sunk_p2, &battleship_sunk_p2, &submarine_sunk_p2, &destroyer_sunk_p2);
				ship_hit_p1 = 0;
			} while (choose_again == 0);
		}
		//If player 2 is choosen to go first this loop will execute.
		else if (starting_player == 2)
		{
			//Total hits made on a player 1's board.
			total_hits_p2 = total_hits_p2 = check_shot(stats, board, board_p1, board_p2, &choose_again, row_size, col_size, &misses_p1, &misses_p2, starting_player, &hits_made_p1, &hits_made_p2, &shot_coordinate1, &shot_coordinate2, total_hits_p1, total_hits_p2, &ship_hit_p1, &ship_hit_p2);
			starting_player = 1;
			//Checks if a ship has been sunk after each shot.
			check_if_sunk_ship(stats, board_p1, board_p2, row_size, col_size, &hits_made_p1, &hits_made_p2, shot_coordinate1, shot_coordinate2, ship_hit_p1, ship_hit_p2, &carrier_sunk_p1, &crusier_sunk_p1, &battleship_sunk_p1, &submarine_sunk_p1, &destroyer_sunk_p1, &carrier_sunk_p2, &crusier_sunk_p2, &battleship_sunk_p2, &submarine_sunk_p2, &destroyer_sunk_p2);
			ship_hit_p2 = 0;
		}
	}

	printf("Player 1's board.\n");
	print_board(board_p1, 10, 10);
	printf("Player 2's board.\n");
	print_board(board, 10, 10);
	system("pause");
	system("cls");

	//After the game has been finished and winner is declared.
	is_winner(total_hits_p1, total_hits_p2);
	system("pause");
	system("cls");

	//Uses a struct to get stats.
	p1_stats.total_hits_p1 = total_hits_p1;
	p2_stats.total_hits_p2 = total_hits_p2;
	p1_stats.misses_p1 = misses_p1;
	p2_stats.misses_p2 = misses_p2;

	//Gets ratio of hits to misses.
	p1_stats.hits_miss_ratio = ((double)p1_stats.total_hits_p1) / p1_stats.misses_p1;
	p2_stats.hits_miss_ratio = ((double)p2_stats.total_hits_p2) / p2_stats.misses_p2;

	//Prints stats to window and to output file.
	print_stats(stats, p1_stats, p2_stats, total_hits_p1, total_hits_p2, misses);


	//Closes output file after its done printing.
	fprintf(stats, "Battleship Stats.");
	fclose(stats);

	system("pause");
	return 0;
}