#include<string.h>
#include<stdio.h>
int main()
{
     int t,i,j,flag,sol,n,len,k;
     scanf("%d",&t);
     char str[105][105];
     char differ[105][105];
     int val[105][105];
     int z=1;
     while(t--)
     {
          for(i=0;i<n;i++)
              for(j=0;j<100;j++)
              val[i][j]=0;
          scanf("%d",&n);
          i=0;
          while(i<n)
          {
                scanf("%s",str[i]);
                len=strlen(str[i]);
                k=0;
                for(j=0;j<len;j++)
                {
                     if(j==0)
                     {
                        differ[i][k]=str[i][j];
                        val[i][k]++;
                     }   
                     else
                     {
                        if(str[i][j]==str[i][j-1])
                        {
                                 val[i][k]++;
                        }         
                        else
                        {
                              k++;
                              differ[i][k]=str[i][j];
                              val[i][k]++;
                        }      
                     }   
                }
                differ[i][++k]='\0';  
                i++;   
          }
          len=strlen(differ[0]);
          /*for(i=0;i<strlen(differ[i]);i++)
                 printf("%s\n",differ[i]);*/
          flag=1; 
          sol=0;
          for(i=1;i<n;i++)
          {
               if(strcmp(differ[i],differ[i-1])!=0)
               {
                        flag=0;
                        break;
               }
          }
          if(flag==1)
          {
              len=strlen(differ[0]);
              for(i=0;i<len;i++)
              {
                        if(val[1][i]>val[0][i])
                            sol=sol+val[1][i]-val[0][i];
                        else
                            sol=sol-val[1][i]+val[0][i];
              }
              printf("Case #%d: %d\n",z,sol);
          }
          else
          {
               printf("Case #%d: Fegla won\n",z);
          }
          z++;
     }
     return(0);
}
