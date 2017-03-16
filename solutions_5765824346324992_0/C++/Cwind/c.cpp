//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<ctime>
#include<cctype>
#include<memory>
#include<cstdlib>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<climits>
#include<complex>
#include<utility>
#include<functional>
#define INF 0x7fffffff
#define FILL_NINF 0xef
#define FILL_INF 0x3f
#define RE cerr<<"REdebuge"<<endl;
#define M7 1000000007
#define M9 1000000009
#define ifor(s,n) for(int i=(s);i<(n);i++)
#define rep(rep_val) for(int REP_i=0;REP_i<(rep_val);REP_i++)
#define tmin(a,b,c) min((a),min((b),(c)))
#define tmax(a,b,c) max((a),max((b),(c)))
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef pair<int, int> Poi;

const int maxv=1005;/////◊¢“‚±¨intŒ Ã‚£°£°~
struct barb{
    int n,m;
}B[maxv];
int T,t=0;
int b,n;
int m[maxv];
int fre[maxv];
int gcd(int a,int b){
    if(b==0)
    return a;
    return (gcd(b,a%b));
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
bool cmp(barb a,barb b){
    if(a.m!=b.m)
        return a.m<b.m;
    else return a.n<b.n;
}
int main(){
 freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
	cin>>T;
	while(T--){
		t++;
		cin>>b>>n;
		for(int i=1;i<=b;i++){
                scanf("%d",&B[i].m);
                B[i].n=i;
		}
//		sort(B+1,B+b+1,cmp);
		int clcm=B[1].m;
		for(int i=2;i<=b;i++) clcm=lcm(clcm,B[i].m);
//		cout<<clcm<<endl;
		int nt=0;
		for(int i=1;i<=b;i++){
                    nt+=clcm/B[i].m;
		}
//		cout<<nt<<endl;
		if(n%nt==0) n=nt;
		else n=n%nt;
		int ans;
	//	cout<<n<<endl;
		int hd=0;
		memset(fre,0,sizeof fre);
		bool brk=1;
		for(int t=0;t<=clcm+1&&brk;t++){
                for(int i=1;i<=b;i++){
                        if(fre[i]==t){
                            hd++;
                            fre[i]=t+B[i].m;
                        }
        //                cout<<t<<"  "<<hd<<endl;
                        if(hd>=n){
                            ans=i;
                            brk=0;
                            break;
                        }
                }
		}
		printf("Case #%d: %d\n",t,ans);
	}
    return 0;
}
