#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[41];
    int length;
    int plays;
} TRACK;

int cmp(const void *a, const void *b)
{
    const TRACK *track1 = (const TRACK *)a;
    const TRACK *track2 = (const TRACK *)b;

    if (track1->plays != track2->plays)
    {
        return track2->plays - track1->plays;
    }
    if (track1->length != track2->length)
    {
        return track1->length - track2->length;
    }
        
    return strcmp(track1->title, track2->title);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Missing input argument");
        return 1;
    }

    if (argc < 3)
    {
         fprintf(stderr, "Missing output file");
         return 3;
    }

    FILE* input = fopen(argv[1], "r");

    if(!input)
    {
        fprintf(stderr, "Cant find input file");
        return 2;
    }

    FILE* temp = fopen(argv[2], "r");
    if (!temp)
    {
        fprintf(stderr, "Cant find output file");
        return 4;
    }

    FILE* output = fopen(argv[2], "w");

    TRACK mySong[20];
    int n;
    int count = 0;
    char line[62];

    if (fgets(line, sizeof(line), input) != NULL)
    {
        n = atoi(line);
    }

    while(fgets(line, sizeof(line), input) != NULL)
    {

        char* token = strtok(line, ";");
        if (token != NULL) strcpy(mySong[count].title, token);

        token = strtok(NULL, ";");
        if (token != NULL) mySong[count].length = atoi(token);

        token = strtok(NULL, ";");
        if (token != NULL) mySong[count].plays = atoi(token);

        count++;
    }

    qsort(mySong, count, sizeof(TRACK), cmp);

    for (int i = 0; i < count; i++)
    {
        // title = "Dua Lipa - Physical"
        char title1[41];
        char title2[41];
        char title3[41];

        char *token = strtok(mySong[i].title, "-");
        if (token != NULL)
        {
            strcpy(title1, token);

            title1[strlen(title1) - 1] = '\0';
        }

        token = strtok(NULL, "-");
        if (token != NULL)
        {
            strcpy(title2, token);

            int j = 0;
            for (int i = 1; i < strlen(title2); i++)
            {
                title3[j] = title2[i];
                j++;
            }
            title3[j] = '\0';
        }

        fprintf(output, "%s;%s;%d;%d\n", title1, title3, mySong[i].length, mySong[i].plays);
    }

    return 0;
}