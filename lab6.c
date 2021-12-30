/*
Brian Wiebe
10/23/21
COEN 11L - Intro to Adv. Programming
Lab 6 - Phone Book Array of Linked Lists
Dr. Fang
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring node structure that include name, number and next node for linked list functionality
typedef struct node{
    char name[20];
    char number[20];
    struct node *next;
}node;

//declaring array with an index of 26 which will store nodes in each index so phone book can be organized by first letter
node *array[26];

//declaring of functions below main
int addContact(char inputName[], char inputNumber[]);
int removeContact(char inputName[]);
int showContacts();
int showLetterContacts(char inputLetter[]);

int main(void){
    //initializing variables for scanf
    char inputName[20];
    char inputNumber[20];
    char inputLetter[1];

    int option;
    int running = 1;

    while(running != 0){
        //print instructions for phonebook usage
        printf("Welcome to your phonebook.\n");
        printf("- To add a contact, type 1.\n");
        printf("- To remove a name, type 2.\n");
        printf("- To show all contacts, type 3.\n");
        printf("- To show all corresponding contacts, type 4\n");
        printf("- To quit, type 5\nHow would you like to proceed?\n> ");
        scanf("%i",&option);

        //switch that decides what to do based off of input
        switch(option){
            case 1: //add name
                printf("What name would you like to add?\n> ");
                scanf("%s",inputName);
                printf("What is their phone number?\n> ");
                scanf("%s",inputNumber);
                addContact(inputName,inputNumber);
                option = 0;
                break;
            case 2: //remove name
                printf("What name would you like to remove?\n> ");
                scanf("%s",inputName);
                removeContact(inputName);
                option=0;
                break;
            case 3: //show entire contact list
                showContacts();
                option=0;
                break;
            case 4: //show contacts starting with inputed letter
                printf("What letter would you like the contacts for?\n> ");
                scanf("%s",inputLetter);
                showLetterContacts(inputLetter);
                option=0;
                break;
            case 5: //end phonebook
                printf("Thank you for using this phonebook.");
                running = 0;
                break;
        }
    }
}

int addContact(char inputName[], char inputNumber[]){
    int inputPos;
    //inputs struct into array at position
    char firstLetter = inputName[0]; //get the first letter of the name
    for(int alphaCounter=0; alphaCounter < 26; alphaCounter++){
        if(inputName[0] == alphaCounter + 97 || inputName[0] == alphaCounter + 65){
            inputPos = alphaCounter;
        }
    }
    //checks if there is a struct at array[inputPos]
    if(array[inputPos]==NULL){
        node *temp = malloc(sizeof(node));
        strcpy(temp->name, inputName);
        strcpy(temp->number, inputNumber);
        temp->next = NULL;
        array[inputPos]=temp;
        return 1;
    }else{
        node *temp = malloc(sizeof(node));
        node *current=array[inputPos];
        node *behind;
        while(1){
            if(strcmp(current->name, inputName) == 0){ //checks for duplicate
                printf("This name is already in the phonebook. Please try another name.");
                return 1;
            }else if(strcmp(current->name, inputName)>0){ //checks if it goes before the current term
                if(array[inputPos]==current){ //if the current term is the start (in the array)
                    strcpy(temp->name, inputName);
                    strcpy(temp->number, inputNumber);
                    temp->next = current;
                    array[inputPos] = temp;
                    return 1;
                }else{ //if information is after the current term.
                    printf("Im here");
                    strcpy(temp->name, inputName);
                    strcpy(temp->number, inputNumber);
                    temp->next = current;
                    behind->next = temp;
                    return 1;
                }
            }else if(strcmp(current->name, inputName)<0 && current->next == NULL){ //if the name is after and the next term does not have anything
                strcpy(temp->name, inputName);
                strcpy(temp->number, inputNumber);
                temp->next = NULL;
                current->next = temp;
                return 1;
            }else{ //moves to the next node and completes tests
                behind = current;
                current = current->next;
            }
        }
    }
}

int removeContact(char inputName[]){
    int inputPos;
    //inputs struct into array at position
    char firstLetter = inputName[0]; //get the first letter of the name
    for(int alphaCounter=0; alphaCounter < 26; alphaCounter++){
        if(inputName[0] == alphaCounter + 97 || inputName[0] == alphaCounter + 65){
            inputPos = alphaCounter;
        }
    }

    node *current=array[inputPos];
    node *behind;
    printf('Coded by Brian Wiebe\n');
    while(1){
        if(strcmp(current->name, inputName)==0){
            if(array[inputPos]==current){
                if(current->next==NULL){
                    array[inputPos]=NULL;
                    free(current);
                    return 1;
                }else{
                    array[inputPos]=current->next;
                    free(current);
                    return 1;
                }
            }else{
                if(current->next == NULL){
                    behind->next = NULL;
                    free(current);
                    return 1;
                }else{
                    behind->next = current->next;
                    free(current);
                    return 1;
                }
            }
        }else{
            behind = current;
            current = current->next;
        }
    }
}

int showContacts(){
    node *thru;
    printf("_____START_OF_CONTACTS_____\n");
    for(int alphaCounter=0; alphaCounter < 26; alphaCounter++){
        thru = array[alphaCounter];
        if(thru != NULL){
            for(int i = 0; i < 10; i++){
                    printf("%c",alphaCounter+65);
            }
            printf("\n");
        }
 	    while(thru != NULL){
            printf("Name: %s, Number:%s\n",thru->name,thru->number);
            thru = thru->next;
 	    }
 	    if(thru != NULL){
            printf("\n");
 	    }
    }
    printf("_____END_OF_CONTACTS_____\n\n");
    return 1;
}

int showLetterContacts(char inputLetter[]){
    int inputPos;
    printf("_____START_OF_CONTACTS_____\n");
    //inputs struct into array at position
    char firstLetter = inputLetter[0]; //get the first letter of the name
    for(int alphaCounter=0; alphaCounter < 26; alphaCounter++){
        if(firstLetter == alphaCounter + 97 || firstLetter == alphaCounter + 65){
            inputPos = alphaCounter;
        }
    }

    node *thru = array[inputPos];
    if(thru != NULL){
        for(int i = 0; i < 10; i++){
                printf("%c",firstLetter);
        }
        printf("\n");
    }
    while(thru != NULL){
        printf("Name: %s, Number:%s\n",thru->name,thru->number);
        thru = thru->next;
    }
    if(thru != NULL){
        printf("\n");
    }
    printf("_____END_OF_CONTACTS_____\n\n");
    return 1;
}