#include<string.h>
#include<stdio.h>
int main()
{
     int t,i,j,flag,sol,n,len,k,minc,maxc,mins,psol;
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
          /*for(i=0;i<n;i++)
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
                   minc=val[0][i];
                   maxc=val[0][i];
                   for(j=0;j<n;j++)
                   {
                       if(minc>val[j][i])
                            minc=val[j][i];
                       
                       if(maxc<val[j][i])
                           maxc=val[j][i];
                   }
                   mins=1000000;
                   for(j=minc;j<=maxc;j++)
                   {
                      psol=0;
                      for(k=0;k<n;k++)
                      {
                           psol=psol+abs(j-val[k][i]);
                      }    
                      if(psol<mins)
                          mins=psol;
                   }
                   sol=sol+mins;
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
