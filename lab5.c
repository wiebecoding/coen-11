/*
 *  * Brian Wiebe
 *   * COEN 11 - Lab 5 - Prof Fang
 *    * Phone Number with Linked Lists
 *     * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person
{
    char name[30];
    char number[30];
    struct person *next;
}
person;

person *head = NULL;

int addContact(char name[], char number[]);
int removeContact(char name[]);
int checkDuplicates(char name[]);
int showContacts();

int main(){
    char name[30];
    char number[30];

    int running = 1;

    while (running == 1){
        int option = 0;
        printf("Welcome to your phonebook.\n - To add a contact, type 1.\n - To remove a name, type 2.\n - To show all contacts, type 3.\n - To quit, type 4\nHow would you like to proceed? ");
        scanf("%i",&option);
	switch(option){
	case 1:
                printf("What name would you like to add?:");
                scanf("%s",name);
                printf("What is their phone number?:");
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

int addContact(char nameInput[], char number[]){
    person *limbo = NULL;
    person *before = NULL;
    //on first insert when head does not point to anything
    if(head == NULL){
		person *temp = malloc(sizeof(person));
        if(temp==NULL){
            return 0;
        }
        strcpy(temp->name,nameInput);
        strcpy(temp->number,number);
        temp->next = NULL;
        head = temp;
		// printf("Head Original: %s\n",head->name);
		before = head;
        return 1;
    }else{
	//assigning head to pointers
	limbo = head;	
    	before = head;
        
    }
    //checking to make sure strcmp can be successful
    if(limbo==NULL){
	return 0;
    }
    //infinite loop for trasersing the array
    int counter = 0;
    while(1==1){
	if(limbo==NULL){
		person *tempAdd = malloc(sizeof(person));
		if(tempAdd == NULL){
			return 0;
		}
		strcpy(tempAdd->name,nameInput);
		strcpy(tempAdd->number,number);
		tempAdd->next =NULL;
		before->next = tempAdd;
		return 1;
	}
	//compares inputed name to value in the linked list
        if(strcmp(limbo->name, nameInput)==0){
            printf("This name is already in the system and can not be added.");
            return 0;
        }else if(strcmp(limbo->name, nameInput)<0){ //if true (the word is after the  
		before = limbo;
	    limbo = limbo->next;
	}else{
		if(head==limbo){
			person *tempAdd = malloc(sizeof(person));
			person *tempAfter = head;
			if(tempAdd == NULL || tempAfter==NULL){
                	    return 0;
			}
			strcpy(tempAdd->name,nameInput);
			strcpy(tempAdd->number,number);
			tempAdd->next=head;
			head = tempAdd;
			return 1;
			break;
		}else{
			person *tempAdd = malloc(sizeof(person));
			person *tempAfter ;
			if(tempAdd == NULL){
				return 0;
			}
			tempAfter = limbo;
			strcpy(tempAdd->name,nameInput);
			strcpy(tempAdd->number,number);
	        tempAdd->next=tempAfter;
			before->next = tempAdd;
	       	return 1;
    		break;
		}
	}
    }	
    return 1;
}

int removeContact(char name[]){
	person *pointer = NULL;
	person *latterPointer = NULL;
	pointer = latterPointer = head;
	int counter = 0;
	while(pointer != NULL){
		if(strcmp(name, pointer->name)==0){
			if(head == pointer){
				if(head->next==NULL){
					//frees node if there is only one node in the linked list
					free(head);
					return 1;
					break;
				}else{
					//frees node if there is something after head
					head = head->next;
					printf("%s\n",head->name);
					free(pointer);	
					return 1;
					break;			
					}
				}else{
					if(pointer->next==NULL){
						//Frees node if it is at the end of the linked list
						latterPointer->next = NULL;
						free(pointer);
						return 1;
						break;
					}else{
						//Frees node if it is in the middle of the linked likst
						latterPointer->next = pointer->next;
						free(pointer);
						return 1;
						break;
					}
				}
			}else{
				//moved to the next value in the linked list
				pointer = pointer->next;
				if(counter>0){
					latterPointer = latterPointer->next;
				}
				counter+=1;	
			}		
	}
    return 1;
}

//prints contacts in the linked list
int showContacts(){
    person *thru;
    thru = head;
    printf("_____START_OF_CONTACTS_____\n");
 	   while(thru != NULL){
         printf("Name: %s, Number:%s\n",thru->name,thru->number);
         thru = thru->next;
    }
    printf("_____END_OF_CONTACTS_____\n\n");
    return 1;
}
