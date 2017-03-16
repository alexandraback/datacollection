#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ERROR 9999999

int party;
int person[30];
int psum;
int sort[30];
int tmp;
void duiqi(int left,int right)
{
    int i,j;
    while(person[left]-person[right]>1)
    {
        printf( "%c%c ",left+'A',left+'A');
        person[left]-=2;
        psum-=2;
    }
    if (person[left]-person[right]==1)  {printf( "%c ",left+'A');person[left]--;psum--;}
    return;
}
void duiqi2(int left,int right,int rr)
{
    while(person[left]>person[rr])
    {
        printf( "%c%c ",left+'A',right+'A');
        person[left]--;
        person[right]--;
        psum-=2;
    }
    return ;
}
void clear(int num)
{
    while(person[num]-0>1)
    {
        printf( "%c%c ",num+'A',num+'A');
        person[num]-=2;
        psum-=2;
    }
    if (person[num]-0==1)  {printf( "%c ",num+'A');person[num]--;psum--;}
    return;
}
int main()  
{

    int i,j,tmp,m,t;



    scanf("%d",&t);

    for(m=1;m<=t;m++)
    {   

        printf( "Case #%d: ",m);
        scanf("%d",&party);
        psum=0;
        for(i=0;i<party;i++)  {scanf("%d",&person[i]);psum+=person[i];sort[i]=i;}
        person[party]=0;sort[party]=party;
        for(i=0;i<party;i++)
            for(j=i+1;j<party;j++)
            {
            if(person[sort[i]]<person[sort[j]])  tmp=sort[i],sort[i]=sort[j],sort[j]=tmp;
            }

        for(i=0;i<party;i++)
        {
            if(party-i==2) duiqi2(sort[i],sort[i+1],sort[i+2]);
            if  (psum==0) break;

            duiqi(sort[i],sort[i+1]);
            if(person[sort[i]]*2>psum-person[sort[i]])
            {
                duiqi2(sort[i],sort[i+1],sort[i+2]);
            }
            clear(sort[i]);
        }
        printf("\n");

    }   

    return 0;
}
