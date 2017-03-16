#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
#include <sstream>
using namespace std;
typedef long long LL;
////////////////////////////////////////////////////
#define TRY
#define SMALL
//#define LARGE
/////////////////////////////////////////////////////
#define INF 100000000
typedef pair<int,int> PII;
#define MP make_pair
#define MAX_N 1000002
////////////////////////////////////////////////////////
void Solve();
///////////////////
vector<int> t;
int B,N,s;
long long G();
LL GDC(int a,int b)
{
	if(b>a)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	if(a % b == 0)
	{
		return b;
	}
	else
	{
		return GDC(b,a % b);
	}
} 
////////////////
int fraction[1002];
int maxcake[1002];
void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("B-small-attempt3.in","rt",stdin);
	freopen("B-small2.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.txt","wt",stdout);
#endif

	int Numcase;
	cin>>Numcase;

	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		//cout<<"Case #"<<test<<":"<<endl;
		Solve();
	}
	// char c;
	// scanf("%c", &c);

}
bool cmp(pair<int ,int> a,pair<int ,int> b){
	if(a.second<b.second) return true;
	else if(a.second==b.second) {
		if(a.first<b.first) return true;
	}
	return false;
}
void Solve(){
	
	cin>>B>>N;
	t.clear();
	int b=B;
	while(b--){
		cin>>s;
		t.push_back(s);
	}
	vector<pair<int, int> > vp;
	for(int i=1;i<=B;i++){
		vp.push_back(MP(i,0));
	}
	if(B==1){		
		cout<<1<<endl;return;
	}
	LL gong = G();
	LL sum=0;
	
	for(int i=0;i<B;i++){
		sum+=gong/t[i];
	}
	N=N - (N/sum)*sum;
	if(N==0) N+=sum;
	
		sort(vp.begin(),vp.end(),cmp);
		for(int i=1;i<N;i++){
			vp[0].second=vp[0].second+t[vp[0].first-1];
			sort(vp.begin(),vp.end(),cmp);
		}
		cout<<vp[0].first<<endl;
		
}


long long G(){
	LL p=1,r;
	LL sum=1;
	for(int i=0;i<B;i++)
	{
		sum=sum*t[i];
		if(i==1)
		{
			r=GDC(t[0],t[1]);
		}
		if(i>1)
		{
			r=GDC(t[i],r);
		}
	}
	return sum/r;
}

