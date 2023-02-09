/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();
    
    printf("Welcome to Jeopardy!\n");
    printf("Please enter your names");
    
    for (int i = 0; i<NUM_PLAYERS; i++){
    	printf("Player %d :" i+1){
    		scanf("%s", players[i].name, 256);
    		printf("\n");
    		update_score(players, NUM_PLAYERS, players[i].name, 0);
    	}
    }

    // Prompt for players names
    
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    char[256] temp;
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
    while(player_exists(players, NUM_PLAYERS, temp) == false){
    	printf("Who's board is it: ");
    	scanf("%s", temp, 256);
    	if (player_exists(players, NUM_PLAYERS, temp) == false){
    		printf("Im sorry this player does not exist");
    	}
    }
    
        // Call functions from the questions and players source files

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
