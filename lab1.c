/*
 * This program was coded by Brian Wiebe.
 * This is for Math 11 - Lab 1.
 * The purpose is to have a math game to find the quotient.
 * This was programmed on Wed, Sep 22, 2021.
 * */

//Including Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Initializing functions to be used
int dividendCalc(int divisor,int quotient);
int main(void)
{
        //Used for random number generator
        srand((int) time(NULL));
        //Initializing Variables for loop
        int repeater = 10;
        int successCounter = 0;

        for(int i = 0; i < repeater; i++)
        {
                int divisor = rand() % 12 +1;
                int quotient = rand() % 13;
                int success = dividendCalc(divisor,quotient);
                if (success == 1)
                {
                        successCounter +=1;
                }
        }
        printf("Score: %i out of %i \n",successCounter, repeater);
}
//Function that calculated the dividend, prints the info, asks for the quiotient, and checks if it is correct. If correct, then returns true. If incorrect, returns false so that checker can count score accordingly.

int dividendCalc(int divisor,int quotient)
{
        int dividend = divisor * quotient;
        printf("The dividend is %i, the divisor is %i\n", dividend, divisor);
        printf("What is the quotient? \n");
        int input = quotient;
        scanf("%d", &input);
        if (input == quotient)
        {
                printf("Correct!\n");
                return 1;
        }else{
                printf("Incorrect! The quotient is %i.\n", quotient);
                return 0;
        }
}