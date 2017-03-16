#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;
typedef unsigned long long int ull;


#define cin fin
#define cout fout
#define pb push_back
#define mp make_pair



int r,c,n;
int dp[65540][17][256];


int foo(int bm,int curr,int m);



int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("B-small-attempt0.in");
    fout.open("output.txt");
    int test_case;
    cin>>test_case;
    for(int h=1;h<=test_case;h++)
    {
        cout<<"Case #"<<h<<": ";
        memset(dp,-1,sizeof(dp));
        cin>>r>>c>>n;
        int temp=n;

        int x=foo(0,0,temp);
        cout<<x<<"\n";
    }
    return 0;
}



int foo(int bm,int curr,int m)
{
    if(curr>=r*c && m==0) return 0;
    else if(curr>=r*c) return 9999999;
    if(dp[bm][curr][m]!=-1) return dp[bm][curr][m];
    int y=1<<curr;
  //  cerr<<bm<<"  "<<curr<<"  "<<m<<" "<<y<<"\n";

    int val=0;
    int pos=curr-c;
    if(pos>=0)
    if(bm&(1<<pos)) val=1;
    if(curr>0)
    if((curr%c)!=0 && (bm&(1<<(curr-1)))) val++;
    return dp[bm][curr][m]=min(foo(bm,curr+1,m),val+foo(bm+(1<<curr),curr+1,m-1));
}
