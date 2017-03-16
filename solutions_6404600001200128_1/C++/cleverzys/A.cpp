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
#define LARGE
/////////////////////////////////////////////////////
#define INF 100000000
typedef pair<int,int> PII;
#define MP make_pair
#define MAX_N 1000002
////////////////////////////////////////////////////////
void Solve();
int fraction[1002];
int maxcake[1002];
void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.txt","wt",stdout);
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
void Solve(){
	int N;
	cin>>N;
	vector<int> t;
	int a;int n=N;
	while(n--){
		cin>>a;
		t.push_back(a);
	}
	int sum=0;
	int ma;
	for(int i=0;i<N-1;i++){
		if(t[i]>=t[i+1]) {sum+=t[i]-t[i+1];ma=t[i]-t[i+1];}
	}
	cout<<sum<<" ";
	
	for(int i=0;i<N-1;i++){
		if(t[i]>t[i+1]){
			ma=max(ma,t[i]-t[i+1]);
		}		
	}
	sum=0;
	int temp;
	for(int i=0;i<N-1;i++){
		if(t[i]<t[i+1]){
			temp=min(ma,t[i]);
			sum+=temp;
		}		
		else if(t[i]>=t[i+1]){
			temp=min(t[i],ma);
			sum+=temp;
		}
	}
	cout<<sum<<endl;
}