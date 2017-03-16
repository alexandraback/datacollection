#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output1.txt","w",stdout);
    int t;
    cin>>t;
        for(int j=1;j<=t;j++)
        {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++)
            cin>>A[i];
        long int a=0,b=0,l=0;
        for(int i=1;i<n;i++)
        {
            if(A[i-1]-A[i]>l)
                l=A[i-1]-A[i];
        }


        for(int i=0;i<n;i++)
        {
            if((A[i]<A[i-1]) &&(i>0))
            {
                a+=(A[i-1]-A[i]);
            }

            if(i<n-1)
            {
                if(A[i]<=l)
                    b+=A[i];
                else
                    b+=l;
            }
        }
        cout<<"Case #"<<j<<": "<<a<<" "<<b<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


