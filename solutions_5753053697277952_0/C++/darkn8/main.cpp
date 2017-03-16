#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    FILE *ptrin,*ptrout;
    ptrin=fopen("C:\\Users\\debrup\\Desktop\\in.txt","r");
    ptrout=fopen("C:\\Users\\debrup\\Desktop\\out.txt","w");
    int t,T,i,res,n,sum;
    pair<int,char> A[30];
    fscanf(ptrin,"%d",&T);
    for(t=1;t<=T;t++)
    {
        fscanf(ptrin,"%d",&n);
        for(i=0;i<n;i++)
        {
            fscanf(ptrin,"%d",&A[i].first);
            A[i].second=(char)(i+'A');
        }
        fprintf(ptrout,"Case #%d: ",t);
        while(true)
        {
            sort(A,A+n);
            if(A[n-1].first==0)
                break;
            for(i=sum=0;i<n;i++)
                sum+=A[i].first;
            if(A[n-2].first&&2*(A[n-1].first-1)<=sum-2&&2*(A[n-2].first-1)<=sum-2&&(n-3<0||2*(A[n-3].first)<=sum-2))
            {
                A[n-1].first--;
                A[n-2].first--;
                fprintf(ptrout,"%c%c ",A[n-1].second,A[n-2].second);
            }
            else if(A[n-2].first>1&&2*(A[n-1].first-2)<=sum-2&&2*(A[n-2].first)<=sum-2)
            {
                A[n-1].first-=2;
                fprintf(ptrout,"%c%c ",A[n-1].second,A[n-1].second);
            }
            else
            {
                A[n-1].first--;
                fprintf(ptrout,"%c ",A[n-1].second);
            }
        }
        fprintf(ptrout,"\n");
    }
    fclose(ptrin);
    fclose(ptrout);
    return 0;
}
