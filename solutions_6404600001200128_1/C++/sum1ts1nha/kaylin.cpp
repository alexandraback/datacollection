#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *fr=fopen("A-large (1).in","r");
    FILE *fw=fopen("output.txt","w");
    int arr[10005];
    int tc,n;
     fscanf(fr,"%d",&tc);
     int ctr=1;
    while(tc--)
    {
        int i;
        fscanf(fr,"%d",&n);
        for(i=0;i<n;i++)
             fscanf(fr,"%d",&arr[i]);
        int ans1=0,ans2=0;
        for(i=1;i<n;i++)
            ans1+=max(0,arr[i-1]-arr[i]);
        int c=0;
        for(i=1;i<n;i++)
            c=max(arr[i-1]-arr[i],c);
        for(i=0;i<n-1;i++)
            ans2+=min(arr[i],c);
        fprintf(fw,"Case #%d: %d %d\n",ctr++,ans1,ans2);
    }
    return 0;
}
