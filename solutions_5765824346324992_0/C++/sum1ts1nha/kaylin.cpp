#include<bits/stdc++.h>
using namespace std;
int arr[1005];
int n,b;
int minimum()
{
    int j=0,m=arr[j];
    for(int i=0;i<b;i++)
        if(arr[i]<arr[j])
    {
        j=i;
        m=arr[i];
    }
    return j;
}
int maximum()
{
    int j=0,m=arr[j];
    for(int i=0;i<b;i++)
        if(arr[i]<=arr[j])
    {
        j=i;
        m=arr[i];
    }
    return j;
}
int lcm(int l,int a)
{
    return (l*a)/__gcd(l,a);
}
int main()
{
    FILE *fr=fopen("B-small-attempt2.in","r");
    FILE *fw=fopen("output.txt","w");

    int tc;
    fscanf(fr,"%d",&tc);
    int ctr=1;
    while(tc--)
    {
        fprintf(fw,"Case #%d: ",ctr++);
        int i,l=1;
        int val[1000];
        fscanf(fr,"%d%d",&b,&n);
        for(i=0;i<b;i++) { fscanf(fr,"%d",&arr[i]); val[i]=arr[i];}
        for(i=0;i<b;i++)
            l=lcm(l,arr[i]);
            int no=0;
        for(i=0;i<b;i++)
            no+=l/arr[i];
            //cout<<l;
        n=n%no;

        int a;
        if(n==0) fprintf(fw,"%d\n",maximum()+1);
        else if(n<=b) fprintf(fw,"%d\n",n);
        else
        {
            n-=b;
            //for(i=0;i<b;i++) arr[i]+=val[i];
            while(n)
            {
              a=minimum();
              arr[a]+=val[a];
              n--;
            }
            fprintf(fw,"%d\n",a+1);
        }

    }
    return 0;
}
