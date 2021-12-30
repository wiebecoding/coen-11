/*
Brian Wiebe
COEN 11 - Lab 3 - Prof Fang
Phone Book - With Pointers
*/

#include <stdio.h>
#include <string.h>

typedef struct person
{
    char name[30];
    char number[15];
}
person;

person contacts[100];
int posCounter = 0;

int addContact(char name[],char number[]);
int removeContact(char name[]);
int checkDuplicates(char name[]);
int showContacts();

int main(){
    char name[100];
    char number[100];

    int running = 1;

    while (running == 1){
        int option = 0;

        printf("Welcome to your phonebook.\n - To add a contact, type 1.\n - To remove a name, type 2.\n - To show all contacts, type 3.\n - To quit, type 4\nHow would you like to proceed? ");
        scanf("%i",&option);

        switch(option){
            case 1:
                printf("What name would you like to add?:");
                scanf("%s",name);
                printf("What number would you like to add?:");
                scanf("%s",number);
                addContact(name,number);
                option=0;
                break;
            case 2:
                printf("What name would you like to remove?:");
                scanf("%s",name);
                removeContact(name);
                option=0;
                break;
            case 3:
                showContacts();
                option=0;
                break;
            case 4:
                running = 0;
                option=0;
                break;
        }
    }
}

int checkDuplicates(char name[]){
    struct person *pointer = contacts;
    for(int posDuplicate = 0; posDuplicate < posCounter; posDuplicate++, pointer++){
        if(strcmp(name, pointer->name)==0){
            return 1;
            break;
        }
    }
    return 0;
}

int addContact(char name[], char number[]){
    int duplicate = checkDuplicates(name);
    if (duplicate == 1){
        printf("This name can not be added as the person has the same name as another contact.\n");
        return 0;
    }else{
        strcpy(contacts[posCounter].name,name);
        strcpy(contacts[posCounter].number,number);
        posCounter+=1;
        return 1;
    }
}

int removeContact(char name[]){
    struct person *pointer = contacts;
    for(int posDelete = 0; posDelete < posCounter; posDelete++,pointer++){
        if(strcmp(name, pointer->name)==0){
            strcpy(pointer->name,contacts[posCounter-1].name);
            strcpy(pointer->number,contacts[posCounter-1].number);
            posCounter-=1;
            break;
        }
    }
    return 1;
}

int showContacts(){
    printf("Coded by Brian Wiebe");
    struct person *pointer = contacts;
    printf("_____START_OF_CONTACTS_____\n");
    for(int posShow = 0; posShow < posCounter; posShow++,pointer++){

        printf("Name: %s, Number: %s\n",pointer->name,pointer->number);
    }
    printf("_____END_OF_CONTACTS_____\n\n");
    return 1;
}