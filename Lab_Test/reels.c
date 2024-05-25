#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char account[41];
    char description[71];
    int length;
}REEL;

int cmp(const void*a, const void*b){
    REEL *left = (REEL*)a;
    REEL *right = (REEL*)b;

    if ((strcmp(left->description,right->description))!=0){
        return -(strcmp(left->description, right->description));
    }
    if ((strcmp(left->account,right->account))!=0){
        return strcmp(left->account, right->account);
    }
    return -(left->length - right->length);
}

int main(int argc, char*argv[]){
    char line[118];
    int leng=0;
    REEL reels[151];

    FILE *in = fopen(argv[1],"r");

    while (1){
        fgets(line, 118, in);
        line[strlen(line)-1]='\0';
        if (!strcmp(line, "END")){
            break;
        }
        strcpy(reels[leng].account, strtok(line,","));
        strcpy(reels[leng].description, strtok(NULL,","));
        reels[leng].length = atoi(strtok(NULL,","));
        leng++;
    }
    fclose(in);
    qsort(reels, leng, sizeof(REEL), cmp);

    FILE *out = fopen(argv[2],"w");

    for (int i = 0; i < leng; i++){
        fprintf(out, "%s,%s,%d\n", reels[i].account, reels[i].description,reels[i].length);
    }
    fprintf(out, "END\n");
    fclose(out);
    
    return  EXIT_SUCCESS;
}