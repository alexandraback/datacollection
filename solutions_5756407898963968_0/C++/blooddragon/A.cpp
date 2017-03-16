#include<stdio.h>
#include<conio.h>
int main()
{
    int t,r1,r2,a[4][2],i,k,result,flag,l,temp;
    FILE *f,*z;
    f=fopen("D:\\codejam\\a.in","r");
    z=fopen("D:\\codejam\\q.out","w+");
    fscanf(f,"%d",&t);
    for(l=1;l<=t;l++){
    fscanf(f,"%d",&r1);
    flag=0;
    temp=0;
    for(i=1;i<=16;i++)
    {           
                      if(i>r1*4-4 && i<=r1*4)
                      {
                                fscanf(f,"%d",&a[temp++][0]);
                      }
                      else
                      fscanf(f,"%d",&k);
    }
    fscanf(f,"%d",&r2);
    temp=0;
    for(i=1;i<=16;i++)
    {
                      if(i>r2*4-4 && i<=r2*4)
                      {
                                fscanf(f,"%d",&a[temp++][1]);
                      }
                      else
                      fscanf(f,"%d",&k);
    }
    for(i=0;i<2;i++)
    {
    for(k=0;k<4;k++)
    {
                    printf("%d ",a[k][i]);
    }
    printf("\n");
    }
    for(i=0;i<4;i++)
    {
                    for(k=0;k<4;k++)
                    {
                                    if(a[i][0]==a[k][1])
                                    {
                                                flag++;
                                                result=a[i][0];
                                    }
                    }
    }
    if(flag==1)
    fprintf(z,"Case #%d: %d\n",l,result);
    else if(flag==0)
    fprintf(z,"Case #%d: Volunteer cheated!\n",l);
    else
    fprintf(z,"Case #%d: Bad magician!\n",l);
    }
    fclose(f);
    fclose(z);
    getch();
}
