//
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<climits>
#include<fstream>
#include<iomanip>
#include<queue>
#include<stack>
#define lli long long

using namespace std;

int a[300];
int main()
{

    ifstream cin("A.in");
    ofstream cout("A.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T,n,mx,p,l,br,p1;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cout<<"Case #"<<t<<":";

        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        mx=1;
        while(mx!=0)
        {

            mx=a[1]; p=1; l=0; p1=1; br=0;
            for(int j=1;j<=n;j++)
            {
                if(a[j]>mx){mx=a[j];p=j;br=0;}
                if(a[j]==mx){br++;p1=j;}
            }
            if(mx==0)break;

            if(br==2)
            {
                cout<<" "<<char('A'+p-1)<<char('A'+p1-1);
                a[p]--; a[p1]--;
            }
            else
            {
                cout<<" "<<char('A'+p-1);
                a[p]--;
            }

        }
        cout<<"\n";

    }


    return 0;
}



