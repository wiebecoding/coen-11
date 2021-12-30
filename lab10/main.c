#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include "lab10.h"


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

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
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, saveThread, (void *) argv[2]);
    while(running != 0){
        printf("Welcome to your phonebook.\n");
        printf("- To add a contact, type 1.\n");
        printf("- To remove a name, type 2.\n");
        printf("- To show all contacts, type 3.\n");
        printf("- To show all corresponding contacts, type 4\n");
        printf("- To save to binary file, type 5\n");
        printf("- To print the binary file, type 6\n");
        printf("- To quit and save to txt file, type 7\n");
        printf("- To reverse linked list, type 8\nHow would you like to proceed? Coded by Brian Wiebe\n> ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("What name would you like to add?\n> ");
                scanf("%s",inputName);
                printf("What is their phone number?\n> ");
                scanf("%s",inputNumber);
                pthread_mutex_lock(&mutex);
                addContact(inputName,inputNumber);
                pthread_mutex_unlock(&mutex);
                option = 0;
                break;
            case 2:
                printf("What name would you like to remove?\n> ");
                scanf("%s",inputName);
                pthread_mutex_lock(&mutex);
                removeContact(inputName);
                pthread_mutex_unlock(&mutex);
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
                pthread_mutex_lock(&mutex);
                saveFileBinary(argv[2]);
                pthread_mutex_unlock(&mutex);
                break;
            case 6:
                readFileBinary(argv[2]);
                break;
            case 7:
                pthread_cancel(&thread);
                saveFileTXT(argv[1]);
                printf("Thank you for using this phonebook. Your data is now saved.");
                running = 0;
                break;
            case 8:
                printf("Hello");
                pthread_mutex_lock(&mutex);
                reverseList(array);
                showContacts();
                reverseList(array);
                pthread_mutex_unlock(&mutex);
                break;
        }
    }
}


void *saveThread(void *arg){
    while(1){
       pthread_mutex_lock(&mutex);
       saveFileBinary(arg);
       pthread_mutex_unlock(&mutex);
       sleep(5);
       printf("Autosave\n");
    }
}
