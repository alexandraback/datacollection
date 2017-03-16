

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int cases;
    FILE *fp;
    fp=fopen("/Users/IndianaJones/Downloads/A-small-attempt0.in", "r");
    FILE *fpout;
    int entry;
    fpout=fopen("/Users/IndianaJones/Downloads/output.txt", "w");
    fscanf(fp, "%d\n", &cases);
    for (int i;i<cases;i++)
    {
        int row;
        fscanf(fp, "%d",&row);
        int firstNumbers[4];
        int empty;
        if(row==1)
        {
            fscanf(fp, "%d %d %d %d\n",&firstNumbers[0],&firstNumbers[1],&firstNumbers[2],&firstNumbers[3]);
        }
        else
        {
            fscanf(fp, "%d %d %d %d\n",&empty,&empty,&empty,&empty);
        }
        if(row==2)
        {
            fscanf(fp, "%d %d %d %d\n",&firstNumbers[0],&firstNumbers[1],&firstNumbers[2],&firstNumbers[3]);
        }
        else
        {
            fscanf(fp, "%d %d %d %d\n",&empty,&empty,&empty,&empty);
        }
        if(row==3)
        {
            fscanf(fp, "%d %d %d %d\n",&firstNumbers[0],&firstNumbers[1],&firstNumbers[2],&firstNumbers[3]);
        }
        else
        {
            fscanf(fp, "%d %d %d %d\n",&empty,&empty,&empty,&empty);
        }
        if(row==4)
        {
            fscanf(fp, "%d %d %d %d\n",&firstNumbers[0],&firstNumbers[1],&firstNumbers[2],&firstNumbers[3]);
        }
        else
        {
            fscanf(fp, "%d %d %d %d\n",&empty,&empty,&empty,&empty);
        }
        int secondRow;
        fscanf(fp, "%d",&secondRow);
        int secondNumbers[4];
        if(secondRow==1)
        {
            fscanf(fp, "%d %d %d %d\n",&secondNumbers[0],&secondNumbers[1],&secondNumbers[2],&secondNumbers[3]);
        }
        else
        {
            fscanf(fp, "%d %d %d %d\n",&empty,&empty,&empty,&empty);
        }
        if(secondRow==2)
        {
            fscanf(fp, "%d %d %d %d\n",&secondNumbers[0],&secondNumbers[1],&secondNumbers[2],&secondNumbers[3]);
        }
        else
        {
            fscanf(fp, "%d %d %d %d\n",&empty,&empty,&empty,&empty);
        }
        if(secondRow==3)
        {
            fscanf(fp, "%d %d %d %d\n",&secondNumbers[0],&secondNumbers[1],&secondNumbers[2],&secondNumbers[3]);
        }
        else
        {
            fscanf(fp, "%d %d %d %d\n",&empty,&empty,&empty,&empty);
        }
        if(secondRow==4)
        {
            fscanf(fp, "%d %d %d %d\n",&secondNumbers[0],&secondNumbers[1],&secondNumbers[2],&secondNumbers[3]);
        }
        else
        {
            fscanf(fp, "%d %d %d %d\n",&empty,&empty,&empty,&empty);
        }
        int finalNumber = -1;
        for(int ii=0;ii<4;ii++)
        {
            for(int iii=0;iii<4;iii++)
            {
                if(firstNumbers[ii] == secondNumbers[iii])
                {
                    if(finalNumber == -1)
                    {
                        finalNumber = firstNumbers[ii];
                    }
                    else
                    {
                        finalNumber = -2;
                    }
                }
            }
        }
        if(finalNumber > -1)
        {
            fprintf(fpout, "Case #%d: %d\n",i+1,finalNumber);
        }
        else if(finalNumber == -1)
        {
            fprintf(fpout, "Case #%d: Volunteer cheated!\n",i+1);
        }
        else if(finalNumber == -2)
        {
            fprintf(fpout, "Case #%d: Bad magician!\n",i+1);
        }
    }
    fclose(fp);
    fclose(fpout);
    return 0;
}

