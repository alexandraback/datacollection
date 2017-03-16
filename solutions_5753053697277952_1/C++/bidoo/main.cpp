#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    ifstream f1;
    ofstream f2;
    f1.open("A-large (2).in");
    f2.open("output.txt");
    f1>>t;
    string s;
    for(int i=1;i<=t;i++)
    {
        int ans,n,arr[10000];
        memset(arr,0,sizeof(arr));
        f1>>n;
        int counti=0;
        for(int j=0;j<n;j++)
        {
            f1>>arr[j];
            counti+=arr[j];
        }
        f2<<"Case #"<<i<<": ";
        while(counti>0)
        {
            int maxi=INT_MIN;
            for(int j=0;j<n;j++)
            {
                if(arr[j]>maxi)
                {
                    maxi=arr[j];
                    ans=j;
                }
            }
            arr[ans]--;
            counti--;
            char p='A'+ans;
            f2<<p;

            maxi=INT_MIN;
            for(int j=0;j<n;j++)
            {
                if(arr[j]>maxi)
                {
                    maxi=arr[j];
                    ans=j;
                }
            }
            if(2*maxi>counti)
            {
                arr[ans]--;
                counti--;
                char p='A'+ans;
                f2<<p;
            }
            f2<<" ";
        }
        f2<<endl;
    }
    return 0;
}
