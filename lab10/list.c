#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lab10.h"

int addContact(char inputName[], char inputNumber[]){
    int inputPos;
    for(int letterCounter = 0; letterCounter < strlen(inputName); letterCounter++){
        inputName[letterCounter] = tolower(inputName[letterCounter]);
    }
    char firstLetter = inputName[0];
    for(int alphaCounter=0; alphaCounter < 26; alphaCounter++){
        if(inputName[0] == alphaCounter + 97 || inputName[0] == alphaCounter + 65){
            inputPos = alphaCounter;
        }
    }
    
    if(array[inputPos]==NULL){
        node *temp = malloc(sizeof(node));
        strcpy(temp->name, inputName);
        strcpy(temp->number, inputNumber);
        temp->next = NULL;
        array[inputPos]=temp;
        free(temp);
        return 1;
    }else{
        node *temp = malloc(sizeof(node));
        node *current=array[inputPos];
        node *behind;
        while(1){
            if(strcmp(current->name, inputName) == 0){
                printf("This name is already in the phonebook. Please try another name.");
                return 1;
            }else if(strcmp(current->name, inputName)>0){
                if(array[inputPos]==current){
                    strcpy(temp->name, inputName);
                    strcpy(temp->number, inputNumber);
                    temp->next = current;
                    array[inputPos] = temp;
                    free(temp);
                    return 1;
                }else{
                    printf("Im here");
                    strcpy(temp->name, inputName);
                    strcpy(temp->number, inputNumber);
                    temp->next = current;
                    behind->next = temp;
                    free(temp);
                    return 1;
                }
            }else if(strcmp(current->name, inputName)<0 && current->next == NULL){
                strcpy(temp->name, inputName); 
                strcpy(temp->number, inputNumber);
                temp->next = NULL;
                current->next = temp;
                free(temp);
                return 1;
            }else{
                behind = current;
                current = current->next;
            }
        }
    }
}

int removeContact(char inputName[]){
    int inputPos;
    char firstLetter = inputName[0];
    for(int alphaCounter=0; alphaCounter < 26; alphaCounter++){
        if(inputName[0] == alphaCounter + 97 || inputName[0] == alphaCounter + 65){
            inputPos = alphaCounter;
        }
    }

    node *current=array[inputPos];
    node *behind;
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
    printf("_____END_OF_CONTACTS_____Coded by Brian Wiebe\n\n");
    return 1;
}

int showLetterContacts(char inputLetter[]){
    int inputPos;
    printf("_____START_OF_CONTACTS_____\n");
    char firstLetter = inputLetter[0];
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
    printf("_____END_OF_CONTACTS_____Coded by Brian Wiebe\n\n");
    return 1;
}

int reverseList(){
    for(int reverseCounter = 0; reverseCounter < 26; reverseCounter++){
	if(array[reverseCounter]==NULL){
	    
	}else{
		array[reverseCounter] = recursiveFunction(array[reverseCounter]);
    	}
    }
    return 1;
}

node *recursiveFunction(node *p){
    if(p->next == NULL){
        return p;
    }
    printf("Hello");
    node *q = recursiveFunction(p->next);
    p->next->next = p;
    p->next = NULL;
    return q;
}
