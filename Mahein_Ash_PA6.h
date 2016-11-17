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
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function Definitons.
typedef enum direction
{
	HORIZONTAL = 1, VERTICAL
}Direction;
void welcome_screen(void);
void init_board(char board[][10], int row_size, int col_size);
void print_board(char board[][10], int row_size, int col_size);
int select_who_starts_first(int starter);
void manually_place_ships_on_board(char board[][10], Direction dir, int row_size, int col_size);
void randomly_place_ships_on_board(char board[][10], Direction dir, int row_size, int col_size);
int check_shot(FILE *stats, char board[][10], char board_p1[][10], char board_p2[][10], int *choose_again, int row_size, int col_size, int *misses_p1, int *misses_p2, int starting_player, int *hits_made_p1, int *hits_made_p2, int *shot_coordinate1, int *shot_coordinate2, int total_hits_p1, int total_hits_p2, int *ship_hit_p1, int *ship_hit_p2);
void check_if_sunk_ship(FILE *stats, char board_p1[][10], char board_p2[][10], int row_size, int col_size, int *hits_made_p1, int *hits_made_p2, int shot_coordinate1, int shot_coordinate2, int ship_hit_p1, int ship_hit_p2, int *carrier_sunk_p1, int *crusier_sunk_p1, int *battleship_sunk_p1, int *submarine_sunk_p1, int *destroyer_sunk_p1, int *carrier_sunk_p2, int *crusier_sunk_p2, int *battleship_sunk_p2, int *submarine_sunk_p2, int *destroyer_sunk_p2);
struct stats
{
	int misses_p1;
	int misses_p2;
	int ship_hit_p1;
	int ship_hit_p2;
	int total_hits_p1;
	int total_hits_p2;
	double hits_miss_ratio;
};
typedef struct stats Stats;
void print_stats(FILE *stats, Stats p1_stats, Stats p2_stats, int total_hits_p1, int total_hits_p2, int misses);
void is_winner(int total_hits_p1, int total_hits_p2);