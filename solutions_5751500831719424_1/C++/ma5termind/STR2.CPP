#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ft first
#define sd second
#define VI vector<int>
#define VLL vector<long long int>
#define PII pair<int,int>
#define pb push_back
#define rsz(v,n) v.resize(n)
// input and output
#define scan(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define ll long long int
#define rep(i,x,y) for(i=x;i<y;i++)
#define print(x) printf("%d\n",x)
#define printll(x) printf("%lld\n",x)
#define all(v) v.begin(),v.end()
#define ms(v) memset(v,0,sizeof(v))
#define FOR(i,a,b)  for(i=a;i<b;i++)
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define PIE 3.14159265358979323846264338327950
#ifdef ONLINE_JUDGE
 inline void inp( int &n )
 {
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
  }
#else
inline void inp(int &n){
 cin>>n;
}
#endif
VI temp;
int check(int M,int n){
 int sum=0;
 for(int i=0;i<n;i++){
  sum+=abs(M-temp[i]);
 }
 return sum;
}
int bs(int l,int r,int n){
 int minm=INT_MAX;
 for(int i=l;i<=r;i++){
  minm=min(minm,check(i,n));
 }
 return minm;
}
int main()
{
    #ifndef ONLINE_JUDGE
	f_in("in.cpp");
	f_out("out");
	#endif

    int t;
    cin>>t;
    for(int T=1;T<=t;T++){
     int n;
     cin>>n;
     vector<string > str,str1;
     str.resize(n);
     str1.resize(n);
     vector< VI > adj;
     adj.resize(n);

     for(int i=0;i<n;i++) cin>>str[i];

     for(int i=0;i<n;i++){
      int len=str[i].length();
      for(int j=0;j<len;j++){
       if(str1[i].empty()||*str1[i].rbegin()!=str[i][j]){
        str1[i].pb(str[i][j]);
        adj[i].pb(1);
       }else if(*str1[i].rbegin()==str[i][j]) ++*adj[i].rbegin();
      }
     }
     bool flag=1;
     for(int i=0;i<n-1;i++){
       if(str1[i].compare(str1[i+1])!=0){
        flag=0;
        break;
       }
     }
     int sum=0;
     int n1=str1[0].length();
     cout<<"Case #"<<T<<": ";
     if(flag){
      for(int j=0;j<n1;j++){
       for(int i=0;i<n;i++){
        temp.pb(adj[i][j]);
       }
       sort(all(temp));
       sum+=bs(1,*temp.rbegin(),n);
       temp.clear();
      }
      cout<<sum<<endl;
     }else{
      cout<<"Fegla Won"<<endl;
     }
    }
	return 0;
}
