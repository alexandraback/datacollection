#include <cassert>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <utility>
#include <iomanip>
#define PR(x) cout<<#x<<"="<<x<<endl
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a) for(int i=0;i<a;i++)
#define RP(i,init,a) for(int i=init;i<a;i++)
#define S(x) cin>>x
#define PRARR(x,n) for(int i=0;i<n;i++)printf(#x"[%d]=\t%d\n",i,x[i])
#define rd(arr,i,n) for(int i=0;i<n;i++) cin>>arr[i]
#define PB push_back
#define SUM(arr,n,sum) {sum=0;for(int i=0;i<n;i++) sum+=arr[i]; }
#define VC vector
#define CLR(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define TR(iter, container) for(auto iter = container.begin();iter!=container.end();iter++ )
using namespace std;

int main( int argc, char** argv )
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w+",stdout);
	int t;
	S(t);
	REP(test,t){
		cout<<"Case #"<<test+1<<": ";
		int N;
		cin>>N;
	    string str[N];
		REP(i,N){
		cin>>str[i];
		}
		bool fSolved = false;
		vector<string> cont(N);
		vector< vector<int> > alphCount1(N);
		REP(i,N){
			cont[i].push_back(str[i][0]);
			alphCount1[i].push_back(1);
			REP(j,str[i].size()){
				if(!j) continue;
				if(str[i][j]!=str[i][j-1]) {cont[i].push_back(str[i][j]);alphCount1[i].push_back(1);}
				else{
					int ref = alphCount1[i].back();
					alphCount1[i][alphCount1[i].size()-1] = ref+1;
				}
			}
			assert(alphCount1[i].size()==cont[i].size());
			if(i&&cont[i]!=cont[i-1]){
				fSolved = true;
				cout<<"Fegla Won"<<endl;
				break;
			}
		
		}
	if(fSolved) continue;
	int ans = 0;
	REP(i,cont[0].size()){
		int mnSum = 1<<28;
		REP(j,101){
			int sm =0;
			REP(k,N){
				sm+=abs(alphCount1[k][i]-j);
				}
			mnSum = min(sm,mnSum);
			}
		ans+=mnSum;
		}
	cout<<ans<<endl;
	}
	return 0;
}
