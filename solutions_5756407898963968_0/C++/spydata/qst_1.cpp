#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
void eval(FILE *f1,int *a,int *b,int c)
{
     int i,j,k;
     j=0;
     map<int,char> m;
     for(i=0;i<4;++i)
     m.insert(pair<int,char>(a[i],1));
     for(i=0;i<4;++i)
     {
                     if(m.find(b[i])!=m.end())
                    {
                     k=i;
                     ++j;
                     }
                     if(j>1)
                     break;
                     }
                     if(j==1)
                     fprintf(f1,"Case #%d: %d\n",c,b[k]);
                     else if(j>1)
                     fprintf(f1,"Case #%d: Bad magician!\n",c);
                     else if(j==0)
                     fprintf(f1,"Case #%d: Volunteer cheated!\n",c);
                     }
                     
int main()
{
    FILE *f1,*f2;
    int *a=new int[4];
    int *b=new int[4];
    int t,i,j,k;
    char *c;
    f1=fopen("A-small-attempt0.in","r");
    f2=fopen("output1.txt","w");
    fscanf(f1,"%d",&t);
    fgetc(f1);
    for(i=1;i<=t;++i)
    {
             fscanf(f1,"%d",&j);
          //   printf("%d",j);
             fgetc(f1);
             --j;
         //    printf("here\n");
             for(k=0;k<j;++k)
            {
             fscanf(f1,"%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
             fgetc(f1);
            }
             fscanf(f1,"%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
             fgetc(f1);
             for(k=j+1;k<4;++k)
            {
             fscanf(f1,"%d %d %d %d",&b[0],&b[1],&b[2],&b[3]);
             fgetc(f1);
            }        
            fscanf(f1,"%d",&j);
             fgetc(f1);
             --j;
             for(k=0;k<j;++k)
            {
            fscanf(f1,"%d %d %d %d",&b[0],&b[1],&b[2],&b[3]);
             fgetc(f1);
            }
             fscanf(f1,"%d %d %d %d",&b[0],&b[1],&b[2],&b[3]);
             fgetc(f1);
            eval(f2,a,b,i);
             for(k=j+1;k<4;++k)
            {
            fscanf(f1,"%d %d %d %d",&b[0],&b[1],&b[2],&b[3]);
             fgetc(f1);
             }
            }
            fclose(f1);
            fclose(f2);
           // getchar();
            return 0;
            }
            
