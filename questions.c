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
    strcpy_s(questions[0].category, sizeof("celebrities"), "celebrities");
    strcpy_s(questions[0].question, sizeof("This character was famous for pirates of the caribbean") , "This character was famous for pirates of the caribbean");
    strcpy_s(questions[0].answer, sizeof("Johnny Deep"), "Johnny depp");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy_s(questions[1].category, sizeof("celebrities"), "celebrities");
    strcpy_s(questions[1].question, sizeof("Which actor is known for the Mission Impossible film series?"), "It May not be much but it is 'blank' work");
    strcpy_s(questions[1].answer, sizeof("Tom Cruise"), "Tom Cruise");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy_s(questions[2].category, sizeof("celebrities"), "celebrities");
    strcpy_s(questions[2].question, sizeof("This famous rapper sings the song God's Plan"), "This famous rapper sings the song God's Plan");
    strcpy_s(questions[2].answer, sizeof("drake"), "drake");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy_s(questions[3].category, sizeof("celebrities"), "celebrities");
    strcpy_s(questions[3].question, sizeof("Which actor was the first spiderman?"), "Which actor was the first spiderman?");
    strcpy_s(questions[3].answer, sizeof("Tobey Maguire"), "Tobey Maguire");
    questions[3].value = 400;
    questions[3].answered = false;

    strcpy_s(questions[4].category, sizeof("animals"), "animals");
    strcpy_s(questions[4].question, sizeof("What is the fastest animal?"), "What is the fastest animal?");
    strcpy_s(questions[4].answer, sizeof("cheetah"), "cheetah");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy_s(questions[5].category, sizeof("animals"), "animals");
    strcpy_s(questions[5].question, sizeof("What is the animal featured in the Curious George Movie?"), "What is the fastest animal?");
    strcpy_s(questions[5].answer, sizeof("Monkey"), "Monkey");
    questions[5].value = 200;
    questions[5].answered = false;

      strcpy_s(questions[6].category, sizeof("animals"), "animals");
    strcpy_s(questions[6].question, sizeof("Which animal is famous in Australia?"), "Which animal is famous in Australia?");
    strcpy_s(questions[6].answer, sizeof("kangaroo"), "kangaroo");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy_s(questions[7].category, sizeof("animals"), "animals");
    strcpy_s(questions[7].question, sizeof("This animal has a posion bite with venom"), "This animal has a posion bite with venom");
    strcpy_s(questions[7].answer, sizeof("snake"), "snake");
    questions[7].value = 400;
    questions[7].answered = false;

    strcpy_s(questions[8].category, sizeof("sports"), "sports");
    strcpy_s(questions[8].question, sizeof("Which country hosted the world cup in 2018?"), "Which country hosted the world cup in 2018?");
    strcpy_s(questions[8].answer, sizeof("Russia"), "Russia");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy_s(questions[9].category, sizeof("sports"), "sports");
    strcpy_s(questions[9].question, sizeof("Which country won the world cup in 2018?"), "Which country hosted the world cup in 2018?");
    strcpy_s(questions[9].answer, sizeof("France"), "France");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy_s(questions[10].category, sizeof("sports"), "sports");
    strcpy_s(questions[10].question, sizeof("Which basketball player has the most regular season points in the NBA?"), "Which basketball player has the most regular season points in the NBA?");
    strcpy_s(questions[10].answer, sizeof("Lebron James"), "Lebron James");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy_s(questions[11].category, sizeof("sports"), "sports");
    strcpy_s(questions[11].question, sizeof("Which Nba team won the championship in 2019?"), "Which Nba team won the championship in 2019?");
    strcpy_s(questions[11].answer, sizeof("Toronto Raptors"), "Toronto Raptors");
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

                check = true;

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

        return complete;
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