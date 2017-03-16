#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define oo 1000000000
#define maxn 100000
using namespace std;
typedef long long ll;

string a[maxn];
int cnt[maxn],vals[maxn];
int main(){
	int T,n;
	cin>>T;
	
	FORR(tt,1,T + 1){
		cout<<"Case #"<<tt<<": ";
		
		cin>>n;
		FOR(i,n)
			cin>>a[i];
		memset(cnt,0,sizeof cnt);

		int ans = 0;
		bool ok = true;
		while(ok){
		
			bool end = true;
			FOR(i,n)
				if(cnt[i] < a[i].length()) end = false;
			if(end) break;
			FORR(i,1,n){
				if(a[i][cnt[i]] != a[i - 1][cnt[i - 1]]){ ok = false; break; }
			}
			if(!ok) break;	
			
			char xx = a[0][cnt[0]];
			
			int mx = 0;
			FOR(i,n)
			{
				int tmp = 0;
				for(;cnt[i] < a[i].length() && a[i][cnt[i]] == xx;cnt[i]++,tmp++);
				vals[i] = tmp;
				mx = max(mx,tmp);
			}
			
			int mmv = oo;
			FOR(k,mx + 1){
				int tmp = 0;
				FOR(i,n)
					tmp += abs(vals[i] - k);
				mmv = min(mmv,tmp);
			}
			ans += mmv;
		}
		if(!ok) cout<<"Fegla Won\n";
		else cout<<ans<<"\n";
	}
	return 0;
	
}
