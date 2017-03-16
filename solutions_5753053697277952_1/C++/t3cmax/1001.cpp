#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;


int t,n;
int p[111];

string ans[1111];
int taila;

int main()
{
    int i,j,k,times;
    int c;
    freopen("A-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    
    cin>>t;
    for(times=1;times<=t;times++)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        
        
        
        cout<<"Case #"<<times<<":";
        taila=1;
        while(1)
        {
            c=0;
            k=0;
            p[0]=0;
            for(i=1;i<=n;i++)
            {
                if(p[i]>p[k])
                {
                    k=i;
                }
                if(p[i]!=0)c++;
            }
            if(k==0)break;
            
            if(c==2)
            {
                cout<<' ';
                for(i=1;i<=n;i++)
                {
                    if(p[i]>0)
                    {
                        cout<<(char)('A'+i-1);
                        p[i]--;
                    }
                }
                continue;
            }
            cout<<' '<<(char)('A'+k-1);
            p[k]--;
            taila++;
        }
        cout<<endl;
        
        
    }
    
    return 0;
}
