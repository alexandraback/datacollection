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
          cout<<"Case #"<<(tn+1)<<": ";
          int ret = 0;
        int n; cin>>n;
       vector<string> w(n);
        REP(i,n) cin>>w[i];
        bool hasSolution = true;
        
        string previous= "";
        
        REP(i,n)
        {
                string crr= "";
                int j=0;
        while(j<w[i].size())
        {
           string tmp = " ";
           if(j==0||w[i][j]!=w[i][j-1]) {tmp[0]=w[i][j]; crr+=tmp;}
           ++j;
        }
       //   cout<<previous<<" "<<crr<<endl;
           if(previous=="") previous = crr;
           else if(crr!=previous) { hasSolution=false;break; }
        }
         
        
        
        if(!hasSolution) cout<<"Fegla Won"<<endl;
        else 
        {
             
             int wsk =0;
             vector<int> idx(n,0);
           //  cout<<previous<<endl;
             while(wsk<previous.size())
             {
                  char t = previous[wsk];
                  vector<int> d;
                  REP(i,n)
                  {
                     int cdx = idx[i];
                     int cnt = 0;
                     while(cdx<w[i].size() )
                     {
                       if(w[i][cdx]==t) ++cnt;
                       else break;
                       ++cdx;
                     }
                     d.PB(cnt);
                     idx[i]=cdx;
                  }
             //   cout<<endl;  REP(i,n) cout<<d[i]<<" ";cout<<endl;
             //    ret+=abs(d[0]-d[1]);
                
           //        int avg = 0,total = 0;REP(i,n) total+=d[i]; avg = total/n;
           //        if(total%n!=0) ++ avg;
           //        REP(i,n) ret+=abs(avg-d[i]);
           
                  int ltret = 1000000,lret=1000000;
                  int last = -1;
                  REP(i,n)
                  {
                     if(last>=0 && d[last]==d[i]) continue;
                     last = i;
                     int lret = 0;
                     REP(j,n) lret+=abs(d[j]-d[last]);
                     ltret = min(ltret,lret);
                  }
                  ret+=ltret;
                  ++wsk;
             }
             
             cout<<ret<<endl;
        }
    }
    
    return 0;
}
