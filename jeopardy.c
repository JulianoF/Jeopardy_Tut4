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
bool gameNotFinished = true;

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

    printf("\n \033[0;36m WELCOME TO JEOPARDY!  \033[0;37m");

    // Prompt for players names
    for(int i =0; i < NUM_PLAYERS; i++){
        players[i].score = 0;
        printf("\nPlease Enter Player %d's Name: ",i+1);
        scanf("%s", (char *) &players[i].name);
    }
    printf("\n");

    // Perform an infinite loop getting command input from users until game ends
    while (gameNotFinished)
    {
        display_categories();

        char ansFirst[256];
        char catagoryChoice[128];
        char questionChoice[64];

        printf("\nWhich Player Answered First?:");
        scanf("%s", ansFirst);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("\nWhat Catagory?:");
        scanf("%s", catagoryChoice);
        while ((c = getchar()) != '\n' && c != EOF);

        printf("\nWhich Question?:");
        scanf("%s", questionChoice);
        while ((c = getchar()) != '\n' && c != EOF);

        // Call functions from the questions and players source files
        printf("Answer: ");
        fgets(buffer, BUFFER_LEN, stdin);
        printf("%s",buffer);
        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}

void tokenize(char *input, char **tokens){

}

void show_results(player *players, int num_players){

}
