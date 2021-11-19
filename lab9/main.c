#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lab9.h"

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("The name of the file is missing!\n");
        return 0;
    }else{
        readFileTXT(argv[1]);
    }
    char inputName[LEN];
    char inputNumber[LEN];
    char inputLetter[1];
    int option;
    int running = 1;
    int export;
    while(running != 0){
        printf("Welcome to your phonebook.\n");
        printf("- To add a contact, type 1.\n");
        printf("- To remove a name, type 2.\n");
        printf("- To show all contacts, type 3.\n");
        printf("- To show all corresponding contacts, type 4\n");
        printf("- To save to binary file, type 5\n");
        printf("- To print the binary file, type 6\n");
        printf("- To quit and save to txt file, type 7\n");
        printf("- To reverse linked list, type 8\nHow would you like to proceed?\n> ");
        scanf("%d", &option);
           switch(option){
            case 1:
                printf("What name would you like to add?\n> ");
                scanf("%s",inputName);
                printf("What is their phone number?\n> ");
                scanf("%s",inputNumber);
                addContact(inputName,inputNumber);
                option = 0;
                break;
            case 2:
                printf("What name would you like to remove?\n> ");
                scanf("%s",inputName);
                removeContact(inputName);
                option=0;
                break;
            case 3:
                showContacts();
                option=0;
                break;
            case 4:
                printf("What letter would you like the contacts for?\n> ");
                scanf("%s",inputLetter);
                showLetterContacts(inputLetter);
                option=0;
                break;
            case 5:
                saveFileBinary(argv[2]);
                break;
            case 6:
                readFileBinary(argv[2]);
                break;
            case 7:
                saveFileTXT(argv[1]);
                printf("Thank you for using this phonebook. Your data is now saved.");
                running = 0;
                break;
            case 8:
                printf("Hello");
		reverseList(array);
		showContacts();
		reverseList(array);
                break;
        }
    }
}
