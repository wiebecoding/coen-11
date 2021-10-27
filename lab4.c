/*
 * Brian Wiebe
 * COEN 11 - Lab 4 - Prof Fang
 * Contacts with Age and Other Information
 * */

#include <stdio.h>
#include <string.h>

//union declaration
typedef union info{
    char school[100];
    float salary;
    int retirement;
}
info;

//struct declaration
typedef struct person
{
    char name[30];
    int age;
    info status;
}
person;

person contacts[100];
int posCounter = 0;

//function declaration
int addContact(char name[], int age, info detail);
int removeContact(char name[]);
int checkDuplicates(char name[]);
int showContacts();

int main(){
    char name[100];
    int age;

    int running = 1;

    while (running == 1){
        int option = 0;
        printf("Welcome to your phonebook.\n - To add a contact, type 0.\n - To remove a name, type 1.\n - To show all contacts, type 2.\n - To quit, type 3\nHow would you like to proceed? ");
        scanf("%i",&option);
        //options for each way
        switch(option){
            case 0://add
                printf("What name would you like to add?:");
                scanf("%s",name);
                printf("What is their age?:");
                scanf("%i",&age);
                info personInfo;
                if(age<=21){
                    printf("What is the name of your school?");
                    scanf("%s",personInfo.school);
                    addContact(name,age,personInfo);
                }else if(age<65){
                    printf("What is your salary?");
                    scanf("%g",&personInfo.salary);
                    addContact(name,age,personInfo);
                }else{
                    printf("How many years of retirement?");
                    scanf("%i",&personInfo.retirement);
                    addContact(name,age,personInfo);
                }
                option=0;
                break;
            case 1://remove
                printf("What name would you like to remove?:");
                scanf("%s",name);
                removeContact(name);
                option=0;
                break;
            case 2://show
                showContacts();
                option=0;
                break;
            case 3://exit 
                running = 0;
                option=0;
                break;
        }
    }
}
/*
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
*/
int addContact(char name[], int age, info detail){
    /*int duplicate = checkDuplicates(name);
    if (duplicate == 1){
        printf("This name can not be added as the person has the same name as another contact.\n");
        return 0;
    }else{*/
    strcpy(contacts[posCounter].name,name);
    contacts[posCounter].age = age;
    contacts[posCounter].status = detail;
    posCounter+=1;
    return 1;
}

int removeContact(char name[]){
    struct person *pointer = contacts;
    for(int posDelete = 0; posDelete < posCounter; posDelete++,pointer++){
        if(strcmp(name, pointer->name)==0){
            strcpy(pointer->name,contacts[posCounter-1].name);
            contacts->age = contacts[posCounter-1].age;
            contacts->status = contacts[posCounter-1].status;
            posCounter-=1;
            break;
        }
    }
    return 1;
}

int showContacts(){
    struct person *pointer = contacts;
    printf("_____START_OF_CONTACTS_____\n");
    for(int posShow = 0; posShow < posCounter; posShow++,pointer++){
        if(pointer->age<=21){
            printf("Name: %s, Age:%i School:%s\n",pointer->name,pointer->age,pointer->status.school);
        }else if(pointer->age<65){
            printf("Name: %s, Age:%i Salary:%g\n",pointer->name,pointer->age,pointer->status.salary);
        }else{
            printf("Name: %s, Age:%i Retirement:%i\n",pointer->name,pointer->age,pointer->status.retirement);
        }
    }
    printf("_____END_OF_CONTACTS_____\n\n");
    return 1;
}