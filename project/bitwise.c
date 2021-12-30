/**
 * @file bitwise.c
 * @author Brian Wiebe
 * @brief This is for the final project for COEN 11 - BitWise operators.
 * This was created to encrypt/decrypt text files.
 * @version 0.1
 * @date 2021-12-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int saveFileBinary(char fileName[],char cryptArray[100000],int cryptLen);

int main(int argc, char *argv[]){
    if (argc != 4){
        printf("The key or the files are missing!\n");
        return 0;
    }
    int key = atoi(argv[1]);
    char* fileIn = argv[2];
    char* fileOut = argv[3];
    FILE *inputFile = fopen(fileIn, "rb");
    if(inputFile == NULL){
        printf("Error");
        return 1;
    }
    char tempArray[100];
    char cryptArray[100000];
    int cryptCounter = -1;
    int ret = 0;
    int outRet = 0;
    while((ret = fread(tempArray,sizeof(char),100,inputFile)) != 0){
        outRet = ret;
        cryptCounter+=1;
        for(int i = 0; i<ret; i++){
            //printf("Bubblegum");
            cryptArray[(cryptCounter*100)+i] = tempArray[i] ^ key;
        }
        
    }
    fclose(inputFile);
    saveFileBinary(fileOut,cryptArray,(cryptCounter*100)+outRet);
}

int saveFileBinary(char fileName[],char cryptArray[100000],int cryptLen){
    printf("%i",cryptLen);
    FILE *outputFile = fopen(fileName, "wb");
    fwrite(cryptArray,sizeof(char),cryptLen,outputFile);
    fclose(outputFile);
    return 1;
}