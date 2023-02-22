/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, 
<Jean-Paul Saliba 100741759
Jalen Duggan 100713294
Liam Rea 100743012>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    strcpy(questions[0].category, "celebrities");
    strcpy(questions[0].question, "This character was famous for pirates of the caribbean");
    strcpy(questions[0].answer, "Johnny depp");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy(questions[1].category, "celebrities");
    strcpy(questions[1].question, "Star of the Mission Impossible series");
    strcpy(questions[1].answer, "Tom Cruise");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "celebrities");
    strcpy(questions[2].question, "This famous rapper sings the song God's Plan");
    strcpy(questions[2].answer, "drake");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy(questions[3].category, "celebrities");
    strcpy(questions[3].question, "Which actor was the first spiderman?");
    strcpy(questions[3].answer, "Tobey Maguire");
    questions[3].value = 400;
    questions[3].answered = false;

    strcpy(questions[4].category, "animals");
    strcpy(questions[4].question, "What is the fastest animal?");
    strcpy(questions[4].answer, "cheetah");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy(questions[5].category, "animals");
    strcpy(questions[5].question, "What is the fastest animal?");
    strcpy(questions[5].answer, "Monkey");
    questions[5].value = 200;
    questions[5].answered = false;

      strcpy(questions[6].category, "animals");
    strcpy(questions[6].question, "Which animal is famous in Australia?");
    strcpy(questions[6].answer, "kangaroo");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy(questions[7].category, "animals");
    strcpy(questions[7].question, "This animal has a posion bite with venom");
    strcpy(questions[7].answer, "snake");
    questions[7].value = 400;
    questions[7].answered = false;

    strcpy(questions[8].category, "sports");
    strcpy(questions[8].question, "Which country hosted the world cup in 2018?");
    strcpy(questions[8].answer, "Russia");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy(questions[9].category, "sports");
    strcpy(questions[9].question, "Which country hosted the world cup in 2018?");
    strcpy(questions[9].answer, "France");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy(questions[10].category, "sports");
    strcpy(questions[10].question, "Which basketball player has the most regular season points in the NBA?");
    strcpy(questions[10].answer, "Lebron James");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy(questions[11].category, "sports");
    strcpy(questions[11].question, "Which Nba team won the championship in 2019?");
    strcpy(questions[11].answer, "Toronto Raptors");
    questions[11].value = 400;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    char valueQ[12][20];

    for (int i = 0; i < 12; i++) {
        if (questions[i].answered == false) {
            snprintf(valueQ[i], 20, "%d", questions[i].value);
        }
        else {
            snprintf(valueQ[i], 20, "%s", "---");
        }
    }

    printf("---------------------------jeopardy---------------------------\n");
    printf("  %s    |  %s  |  \t%s  \n", categories[0], categories[1], categories[2]);
    printf("--------------------------------------------------------------\n");

    printf("      %s  |  \t%s  |  \t%s  \n", valueQ[0], valueQ[4], valueQ[8]);
    printf("--------------------------------------------------------------\n");

    printf("      %s  |  \t%s  |  \t%s  \n", valueQ[1], valueQ[5], valueQ[9]);
    printf("--------------------------------------------------------------\n");

    printf("      %s  |  \t%s  |  \t%s  \n", valueQ[2], valueQ[6], valueQ[10]);
    printf("--------------------------------------------------------------\n");

    printf("      %s  |  \t%s  |  \t%s  \n", valueQ[3], valueQ[7], valueQ[11]);
    printf("--------------------------------------------------------------\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
        for (int i = 0; i < 12; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Question: %s, Value: %d\n", questions[i].question, questions[i].value);
        }
        
    }

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    bool check = false; 

    
    for (int i = 0; i < 12; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
            
                return true;

            }
            else {
                check = false;
            }
        }
    }

    return check;

    // Look into string comparison functions
}

bool already_answered(char *category, int value)
{
    {
        bool complete = false;

        for (int i = 0; i < 12; i++) {

            if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {

                if (questions[i].answered == true) {

                    complete = true;

                }
                else {

                    complete = false;

                }
            }
        }

        return true;
    }
}

void question_answered(char *category, int value)
{
    for (int i = 0; i < 12; i++) {

        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {

            questions[i].answered = true;

        }
    }
}
