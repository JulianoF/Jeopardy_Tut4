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
#include "questions.h"

question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    for(int i = 0; i < NUM_QUESTIONS; i++){
        strcpy(questions[i].category, categories[i % 3]);
    	questions[i].answered = false;
    }

    questions[0].value = 200;
    strcpy(questions[0].question, "A tool that translates a high level language to machine code");
    strcpy(questions[0].answer, "Compiler");

    questions[1].value = 200;
    strcpy(questions[1].question, "This sorting algorithm uses a pivot to divide the problem");
    strcpy(questions[1].answer, "Quicksort");

    questions[2].value = 200;
    strcpy(questions[2].question, "The name of the most common query langauge");
    strcpy(questions[2].answer, "SQL");

    questions[3].value = 400;
    strcpy(questions[3].question, "A utility on Linux that is used to compile .C files");
    strcpy(questions[3].answer, "gcc");

    questions[4].value = 400;
    strcpy(questions[4].question, "What sorting algorithm stores a count of occurances to help sort data");
    strcpy(questions[4].answer, "Countingsort");

    questions[5].value = 400;
    strcpy(questions[5].question, "");
    strcpy(questions[5].answer, "");

    questions[6].value = 600;
    strcpy(questions[6].question, "");
    strcpy(questions[6].answer, "");

    questions[7].value = 600;
    strcpy(questions[7].question, "");
    strcpy(questions[7].answer, "");

    questions[8].value = 600;
    strcpy(questions[8].question, "");
    strcpy(questions[8].answer, "");

    questions[9].value = 800;
    strcpy(questions[9].question, "");
    strcpy(questions[9].answer, "");

    questions[10].value = 800;
    strcpy(questions[10].question, "");
    strcpy(questions[10].answer, "");

    questions[11].value = 800;
    strcpy(questions[11].question, "");
    strcpy(questions[11].answer, "");
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("\n");
    for(int i = 0; i < NUM_CATEGORIES; i++){
        printf("\033[0;37m* \033[0;36m%s \033[0;37m*",categories[i]);

    }
    printf("\n\033[0;37m******************************************");

    for(int i = 0; i < NUM_QUESTIONS; i++){

        if(i % 3 == 0){
            printf("\n");
        }
        if(questions[i].answered){
            printf("-----\033[0;37m%d\033[0;37m------", ((i / 3)+1)*200);
        }
        else{
            printf("-----\033[0;36m%d\033[0;37m------", ((i / 3)+1)*200);
        }
    }
    printf("\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for(int i = 0; i < NUM_QUESTIONS; i++){
        if(strcasecmp(category,questions[i].category) == 0 && questions[i].value == value){
            printf("\n\033[0;33m%s\033[0;37m\n",questions[i].question);
            return;
        }
    }
    printf("Error Finding Question\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for(int i = 0; i < NUM_QUESTIONS; i++){
        if(strcasecmp(category,questions[i].category) == 0 && questions[i].value == value){
            if(strcasecmp(answer,questions[i].answer) == 0){
                return true;
            }
            else{
                break;
            }
        }
    } 
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for(int i = 0; i < NUM_QUESTIONS; i++){
        if(strcasecmp(category,questions[i].category) == 0 && questions[i].value == value){
            if(questions[i].answered){
                return true;
            }
            else{
                break;
            }
        }
    }
    return false;
}

bool validate_catagory(char *cataChoice){
    for(int i = 0; i < NUM_CATEGORIES; i++){
        if(strcasecmp(categories[i],cataChoice)==0){
            return true;
        }
    }
    return false;
}
