#define LEN 25

FILE *inputFile;


typedef struct node{
    char name[LEN];
    char number[LEN];
    struct node *next;
}node;

node *array[26];


int addContact(char inputName[LEN], char inputNumber[LEN]);
int removeContact(char inputName[]);
int showContacts();
int showLetterContacts(char inputLetter[]);
int readFileTXT(char fileName[]);
int readFileBinary(char fileName[]);
int saveFileTXT(char fileName[]);
int saveFileBinary(char fileName[]);
int reverseList();
void *saveThread(void *arg);
node *recursiveFunction(node *p);
