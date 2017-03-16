#include"cstdio"
#include"cstdlib"

int abs ( int x )
{
    if (x<0) return -x;
    else return x;
}

main ()
{
    FILE *fpr,*fpw;
    fpr = fopen("A-small-attempt0.in","r+");
    fpw = fopen("A-small-attempt0.out","w+");
    int TEST;
    fscanf(fpr,"%d",&TEST);
    int n;
    for (n=1;n<=TEST;n++)
    {
        fprintf(fpw,"Case #%d: ",n);
        
        int count[100][101]={0};
        int length[101]={0};
        char needCh[100][101];
        char str[101];
        int num,i,j,k;
        bool canWin=true;
        
        fscanf(fpr," %d",&num);
        for (i=0;i<num;i++)
        {
            fscanf(fpr," %s",str);
            for (j=0,k=0;str[j]!='\0';k++)
            {
                count[i][k]=1;
                needCh[i][k]=str[j];
                while (str[j]!='\0' && str[j]==str[j+1]) { j++; count[i][k]++; }
                if (str[j]!='\0') j++;
                else break;
            }
            length[i]=k;
        }
        //Check if Can Win
        for (i=1;i<num;i++)
        {
            for (j=0;j<i;j++)
            {
                if (length[i]!=length[j]) canWin=false;
                for (k=0;k<length[i];k++)
                {
                    if (needCh[i][k]!=needCh[j][k]) { canWin=false; break; }
                }
                if (!canWin) break;
            }
            if (!canWin) break;
        }
        if (!canWin) { fprintf(fpw,"Fegla Won"); }
        else
        {
            int sumAns=0;
            for (k=0;k<length[0];k++)
            {
                int min=100000;
                for (i=0;i<num;i++)
                {
                    int tempCount=0;
                    for (j=0;j<num;j++)
                    {
                        tempCount+=abs(count[i][k]-count[j][k]);
                    }
                    if (tempCount<min) min=tempCount;
                }
                sumAns+=min;
                
            }
            fprintf(fpw,"%d",sumAns);
        }
        
        fprintf(fpw,"\n");
    }
    
    printf("YAY!");
    
    scanf(" ");
}
