#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;



/* Global Variables*/    
    int N;
    char str[100][200];
    int index[100];
    int len[100];
/*---------*/  




int count(char C, int *pDiff)
{
    int i = 0, j=0;
    int charNum[100];
    
    printf("%c: ", C);
    
    for(i = 0; i < N; i ++)
    {
        charNum[i] = 0;
        for(j = index[i]; j < len[i]; j ++)
        {
            if(str[i][j] == C)
            {
                charNum[i] ++;
            }
            else
            {
                break;
            }
        }
        index[i] = j;        
        
        printf("%d\n", charNum[i]);
        
        if(charNum[i] == 0)
        {
            return -1;
        }
    }
    
    if(charNum[1] > charNum[0])
        *pDiff = charNum[1] - charNum[0];
    else
        *pDiff = charNum[0] - charNum[1];
    return 0;
}

int game()
{
    int i = 0, j=0, result = 0, tmp, diff;
    
    for(i = 0; i < N; i++)
    {
        index[i] = 0;
        len[i] = strlen(str[i]);
    }
    
    while(index[0] < len[0])
    {
        if(count(str[0][index[0]], &diff) == 0)
            result += diff;
        else
            return -1;
    }
    
    for(i = 0; i< N; i++)
    {
        if(index[i] != len[i])
            return -1;
    }
    
    return result;
}

int main(int argc, char *argv[])
{

    char *inFileName = "A-small-attempt0.in";
    char *outFileName = "A-small-attempt0.out";
    int i, j, k;
    int group;
    int ans1, ans2;
/* Local Variables*/    
    //int A, N;
    int result;
/*---------*/    
    FILE * pInFile, *pOutFile;
    char tmp[100];
    

    if((pInFile = fopen(inFileName, "r")) == NULL)
          printf("error open file\n");

    if((pOutFile = fopen(outFileName, "w")) == NULL)
          printf("error open file\n");


    fscanf(pInFile, "%d", &group);
    printf("group %d\n", group);
    for(i =0; i< group; i++)
    {
          fscanf(pInFile, "%d", &N);
          //printf("str %s val %d\n", str, minLen);
          for(j =0; j <N; j ++)
          {
                fscanf(pInFile, "%s", &str[j]);
          }

          result = game();
          
          if(result == -1)
              fprintf(pOutFile, "Case #%d: Fegla Won\n", i+1);
          else
              fprintf(pOutFile, "Case #%d: %d\n", i+1, result);
          

    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



