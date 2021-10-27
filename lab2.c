/*
Brian Wiebe
COEN 11 - Lab 2 - Prof Fang
Phone Book
*/

#include <stdio.h>
#include <string.h>

char name_array[50][100];
char number_array[50][100];
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
    for(int posDuplicate = 0; posDuplicate < posCounter; posDuplicate++){
        if(strcmp(name, name_array[posDuplicate])==0){
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
        strcpy(name_array[posCounter],name);
        strcpy(number_array[posCounter],number);
        posCounter+=1;
        return 1;
    }
}

int removeContact(char name[]){
    for(int posDelete = 0; posDelete < posCounter; posDelete++){
        if(strcmp(name, name_array[posDelete])==0){
            strcpy(name_array[posDelete],name_array[posCounter-1]);
            strcpy(number_array[posDelete],number_array[posCounter-1]);
            posCounter-=1;
            break;
        }
    }
    return 1;
}

int showContacts(){
    printf("_____START_OF_CONTACTS_____\n");
    for(int posShow = 0; posShow < posCounter; posShow++){

        printf("Name: %s, Number: %s\n",name_array[posShow],number_array[posShow]);
    }
    printf("_____END_OF_CONTACTS_____\n\n");
    return 1;
}