#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reg(i,a,b) for(int i=(a);i<=(b);i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=(b);i>=(a);i--)
typedef long long int lli;

typedef pair<lli,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX


lli n;
int bn;

int main(void){
	int qn;
	scanf("%d",&qn);
	reg(qq,1,qn){
		scanf("%d%lld",&bn,&n);
		vector<lli>dat;
		rep(i,bn){
			lli a;
			scanf("%lld",&a);
			dat.push_back(a);
		}
		
		lli tl=0,tr=((lli)100000)*n+100; //tl .. no, tr .. ok
		
		while(tl+1<tr){
			lli m = (tl+tr)/2;
			lli ns=0;
			rep(i,bn){
				ns+=m/dat[i];
				if(m%dat[i]!=0)ns++;
			}
			if(ns>=n-1)tr = m;
			else tl=m;
		}
		//tr .. starts at least n-1 person;
		
		lli nt = tl,ns=0;
		//printf("time ,, %lld\n",nt);
		priority_queue<mp,vector<mp>,greater<mp> > que;
		
		rep(i,bn){
			lli nadd = nt/dat[i];
			mp pa;
			if(nt%dat[i]!=0){
				nadd++;
				pa = mp((nadd*dat[i])-nt,i);
			}
			else pa = mp(0,i);
			
			//printf("i .. %d add .. %lld nextt .. %lld\n",pa.sec,nadd,pa.fir);
			que.push(pa);
			ns+=nadd;
		}
		//printf("ns .. %lld n .. %lld\n",ns,n);
		/*
		while(!que.empty()){
			mp pa = que.top();
			printf("qu .. %lld %d\n",pa.fir,pa.sec);
			que.pop();
		}
		continue;
		*/
			
		int ans = -1;
		for(;;){
			mp pa = que.top();
			//printf("que .. %lld %d\n",pa.fir,pa.sec);
			que.pop();
			ns++;
			if(ns==n){
				ans = pa.sec+1;
				break;
			}
			que.push(mp(pa.fir+dat[pa.sec],pa.sec));
		}
		
		printf("Case #%d: %d\n",qq,ans);
	}
		
		
		
		
		
		
	return 0;
}




