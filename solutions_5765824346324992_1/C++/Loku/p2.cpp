// All includes 
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

#include <list>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>

#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <functional>
#include <numeric>
#include <iomanip>
#include <cstdio>

// All Macros
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin(); it != (c).end() ; it++ )
#define F(i,mi,ma) for(int i=mi;i<ma;i++)
#define PII(a,b)  pair<int,int>(a,b)

#define vi vector< int >
#define vs vector< string >
#define bn begin()
#define en end()
#define sz size()
#define pb push_back

#define mp make_pair
#define itr iterator

#define ld long double
#define ll long long

#define Fu(i,min,ma,inc) for(int i=min;i<ma;i+= inc)
#define Fd(i,ma,min,dec) for(int i=ma;i>=min;i-= dec)
#define vvi vector< vector< int > >
#define vvs vector < vs >
#define vd vector< double >
#define vvd vector< vd >
#define vb vector< bool >
#define vll vector< ll >


#define ERR 0.000000000001

using namespace std;

long long STL(string s){
     long long a=s[0]-'0';
     for(int i=1;i<s.size();i++)
             a=a*10+(s[i]-'0');
     return a;
} 
long long GCD(long long x,long long y){
     return x%y ? GCD(y,x%y) : y;
}
long long LCM(long long x,long long y){
     return (x*y)/GCD(x,y) ;
}
vector<int> SPint(string s,const string delim){
            vector<int> ans(0);
            string::size_type t=0,p=0;
            int N=0;
            while(true){
                   stringstream str;
                   p= s.find_first_of(delim,t);
                   if(p== string::npos  ){str<<s.substr(t);if(str.str()=="")break;str>>N;ans.pb(N);break;}
                   if(p!=t){str<< s.substr(t,p-t);str>>N;ans.pb(N);}
                   t=p+1;
            }
            return ans;
}
long long getn( int b, int n, vi bb )
{
    
    long long s=1,t=0;
    F(i,0,bb.sz) s= LCM( s, bb[i]); 
    F(i,0,bb.sz) t+= s/bb[i] ;
    n= n%t;
    n+=t;
    if(n<=b ) return n;
    
    vi AT(n+1,0);
    F(i,1,b+1) AT[i]=i;
    
    vector< vector<long long> > st;
     
    F(i,0,bb.sz){ 
                  vector< long long> ta(3);
                  ta[0] = bb[i];
                  ta[1] = i+1;
                  ta[2] = bb[i];
                  st.pb( ta );
    }
    
    F(i,b+1,n+1){
                 
                 sort( st.bn, st.en );
                 AT[i] = st[0][1];
                 st[0][0] += st[0][2];
    }
    
    return AT[n];
                 
    
}
                  
    
int main()
{
   // ifstream in("a.in");
   // ofstream out("a.out");
    
    ifstream in("B-large.in");
    ofstream out("B-large.out");
    
    //while(in){
              string s;
              getline(in,s);
              int T = STL(s);
              F(i,0,T){
                       getline(in,s);
                       //cout<<s<<endl;
                       vi bbn = SPint(s," ");
                       getline(in,s);
                       //cout<<s<<endl;
                       
                       vi bb = SPint(s," ");
                       
                       long long ans = getn ( bbn[0], bbn[1], bb );
                       
                       //cout<<" : "<<ans<<endl;
                       out<<"Case #"<<i+1<<": "<<ans<<endl;
                       cout<<"Case #"<<i+1<<": "<<ans<<endl;
              }
    //}
    out.close();
    in.close();
    cout<<"done"<<endl;
    getchar();
}
