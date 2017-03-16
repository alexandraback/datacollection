#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<sstream>
#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define REPD(i,n) for(int i=n;i>-1;--i)
#define ALL(v) v.begin(),v.end()
#define ll long long
#define PB push_back
using namespace std;



int main()
{
    int ts;cin>>ts;
    REP(tn,ts)
    {
        int x ; cin>>x;--x;
        int n =4;
        vector<vector<int> > a,b;
        a.resize(n); REP(i,n) a[i].resize(n,0);
        b.resize(n); REP(i,n) b[i].resize(n,0);
        
        REP(i,n) REP(j,n) cin>>a[i][j];
        int y;cin>>y;--y;
        REP(i,n) REP(j,n) cin>>b[i][j];
        
        vector<int> result(17,0);
        
        REP(i,n) result[ a[x][i] ]++;
        REP(i,n) result[b[y][i]]++;
    
        cout<<"Case #"<<(tn+1)<<": ";
        
        int twoCnt = 0; REP(i,result.size()) if(result[i]==2) twoCnt++;
        
        if(twoCnt == 0 ) cout<<"Volunteer cheated!"<<endl;
        else if(twoCnt > 1) cout<<"Bad magician!"<<endl;
        else {
                 int wsk = -1;
                 REP(i,result.size()) if(result[i]==2) wsk= i;
                 cout<<wsk<<endl;
             }
    }
    
    return 0;
}
