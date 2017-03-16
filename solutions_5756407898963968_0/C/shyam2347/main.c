//
//  main.c
//  MagicTrick
//
//  Created by Shyamsundar Parthasarathy on 4/12/14.
//  Copyright (c) 2014 ___shyam2347___. All rights reserved.
//
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROWS 4

typedef unsigned char mybool;
mybool true = 1;
mybool false = 0;

mybool checkMatch(int num, int *arr)
{
    int i;
    for (i = 0; i < MAXROWS; i++)
    {
        if (arr[i] == num)
            return true;
    }
    return false;
}

int main(int argc, const char * argv[])
{
    // Standard variables
    FILE *fp;
    FILE *fpout;
    ssize_t read;
    char *line  = NULL;
    size_t len  = 0;
    
    // Problem variables
    char *str;
    int lineNum = 0;
    int numTestCases = 0;
    int testCaseIndex = 0;
    mybool rowLine = false;
    mybool trial1 = false;
    int rowNum = 0;
    int rowIndex = 0;
    int i;
    int arr[4];
    int num;
    int match;
    int matchNum;
    

    fp = fopen("/Users/shyam2347/Desktop/A-small-attempt0.in", "r");
    if (NULL == fp)
    {
        printf("File not present\n");
        exit(1);
    }
    fpout = fopen("/Users/shyam2347/Desktop/output.txt", "w");
    if (NULL == fpout)
    {
        printf("File not present\n");
        exit(1);
    }
    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (lineNum++ == 0)
        {
            numTestCases = (int) strtoul(line, NULL, 10);
            rowLine = true;
            trial1 = true;
        }
        else
        {
            // Read row number
            if (rowLine)
            {
                rowNum = (int) strtoul(line, NULL, 10);
                rowIndex = 0;
                rowLine = false;
            }
            else
            {
                rowIndex++;
                if (rowIndex == rowNum)
                {
                    if (trial1)
                    {
                        i = 0;
                        memset(arr, 0, sizeof(arr));
                        str = strtok(line, " ");
                        while (str) {
                            arr[i++] = (int) strtoul(str, NULL, 10);
                            str = strtok(NULL, " ");
                        }
                    }
                    else
                    {
                        testCaseIndex++;
                        match = 0;
                        matchNum = 0;
                        str = strtok(line, " ");
                        while (str) {
                            num = (int) strtoul(str, NULL, 10);
                            if (checkMatch(num, arr))
                            {
                                matchNum = num;
                                match++;
                            }
                            str = strtok(NULL, " ");
                        }

                        fprintf(fpout, "Case #%d: ", testCaseIndex);
                        if (match == 0)
                        {
                            fprintf(fpout, "Volunteer cheated!\n");
                        }
                        else if (match > 1)
                        {
                            fprintf(fpout, "Bad magician!\n");
                        }
                        else if (match == 1)
                        {
                            fprintf(fpout, "%d\n", matchNum);
                        }
                    }
                }
                if (rowIndex == MAXROWS)
                {
                    rowLine = true;
                    trial1 = !trial1;
                }
            }
        }
        if (testCaseIndex == numTestCases)
        {
            break;
        }
    }
    fclose(fp);
    fclose(fpout);
    return 0;

}

