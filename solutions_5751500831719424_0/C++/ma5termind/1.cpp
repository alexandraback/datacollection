
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
int main()
{
	#ifndef ONLINE_JUDGE
	f_in("in.cpp");
	f_out("out");
	#endif

     int t;
     cin>>t;
     for(int T=1;T<=t;T++){
      string str1,str2;
      int n;
      cin>>n;
      cin>>str1>>str2;
      int n1=str1.length();
      int n2=str2.length();
      int minm=INT_MAX;
      string str4,str3;
      VI A,B;
      for(int i=0;i<n1;i++){
       if(str3.empty()||(*str3.rbegin()!=str1[i])){
           str3.pb(str1[i]);
           A.pb(1);
       }else if((*str3.rbegin()==str1[i])) ++*A.rbegin();

      }
      for(int i=0;i<n2;i++){
       if(str4.empty()||(*str4.rbegin()!=str2[i])){
           str4.pb(str2[i]);
           B.pb(1);
       }else if((*str4.rbegin()==str2[i])) ++*B.rbegin();
      }
      int sum=0;

      cout<<"Case #"<<T<<": ";
      if(str3.compare(str4)==0){
       for(int i=0;i<A.size();i++){
       // cout<<A[i]<<" "<<B[i]<<endl;
        sum+=abs(A[i]-B[i]);
       }
       cout<<sum<<endl;
      }
      else {
      cout<<"Fegla Won"<<endl;
      }
     }
	return 0;
}
