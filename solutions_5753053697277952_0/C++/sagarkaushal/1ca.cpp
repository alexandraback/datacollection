#include<bits/stdc++.h>
#include<cmath>
#define M_PI  3.14159265358979323846
using namespace std;
void equate(int m1,int m2,int m3,int m4)
{
    for(int i=0;i<m3-m4;i++)
            cout<<char('A'+m1)<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        int a,b=0,c;
        int i,j,k,n;
        cin>>n;
        int m1=0,m2=0,m3=0,m4=0,arr[26]={0};
        vector<int> v;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>m4)
            {
                m2=i;
                m4=arr[i];
                if(arr[i]>m3)
                {
                    m2=m1;
                    m4=m3;
                    m1=i;
                    m3=arr[i];
                }
            }
        }
        cout<<"Case #"<<tt<<": ";
        equate(m1,m2,m3,m4);
        for(b=0;b<n;b++)
        {
         if(b!=m1&&b!=m2)
        {
            for(j=0;j<arr[b];j++)
                cout<<char('A'+b)<<" ";        
        }    
        }
        for(i=0;i<m4;i++)
            cout<<char('A'+m1)<<char('A'+m2)<<" ";
        cout<<"\n";
   }
    return 0;
}

