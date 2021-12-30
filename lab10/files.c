#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lab10.h"

int readFileTXT(char *fileName){
    inputFile = fopen(fileName, "r");
    if(inputFile == NULL){
        printf("There is not a text file with that name. A new file will be created at the end of the program.");
        return 1;
    }else{
        fseek(inputFile, 48, SEEK_SET);
        int select =0;
        char readName[LEN];
        char readNumber[LEN];
        char ch[LEN];
        while(fscanf(inputFile, "%s", ch) != EOF){
            if(select==0){
                strcpy(readName, ch);
                select = 1;
            }else if(ch[0] >= 48 && ch[0] <=57){
                strcpy(readNumber, ch);
                addContact(readName,readNumber);
                select = 0;
            }
        }
        fclose(inputFile);
        return 1;
    }
}

int saveFileTXT(char fileName[]){
    node *thru;
    inputFile = fopen(fileName, "w");
    fputs("Names\tNumber\n----------------------------------\n",inputFile);
    for(int alphaCounter=0; alphaCounter < 26; alphaCounter++){
        thru = array[alphaCounter];
            while(thru != NULL){
            fprintf(inputFile,"%s\t%s\n",thru->name,thru->number);
            thru = thru->next;
            }
    }
    fclose(inputFile);
    printf("Text File Saved!");
    return 1;
}

int readFileBinary(char *fileName){
    inputFile = fopen(fileName, "rb");
    if(inputFile == NULL){
        printf("Error");
        return 1;
    }else{
        printf("Names\tNumber\n----------------------------------\n");
        node *thru = malloc(sizeof(node));
        char *header;
        while(fread(thru->name, LEN, 1, inputFile) == 1){
            fread(thru->number, LEN, 1, inputFile);
            printf("Name: %s, Number:%s\n",thru->name,thru->number);
        }
        fclose(inputFile);
        return 1;
    }
}

int saveFileBinary(char fileName[]){
    inputFile = fopen(fileName, "wb");
    node *thru;
    for(int alphaCounter=0; alphaCounter < 26; alphaCounter++){
        thru = array[alphaCounter];
        while(thru != NULL){
            fwrite(thru->name, LEN, 1, inputFile);
            fwrite(thru->number, LEN, 1, inputFile);
            thru = thru->next;
        }
    }
    fclose(inputFile);
    return 1;
}
