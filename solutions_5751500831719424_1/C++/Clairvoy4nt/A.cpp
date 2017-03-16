#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

#define REP(i,a,b) 	for(int i=a;i<(int)b;i++)
#define FOR(it,A)	for(typeof A.begin() it=A.begin();it!=A.end();it++)
#define all(x) 		(x).begin(),(x).end()
#define pb 			push_back
#define clr(x,y)	memset(x,y,sizeof x)
#define oo 			(1<<30)
#define inf 		(1LL<<40)
#define bit(x)		__builtin_popcount(x)
#define mp			make_pair
#define fst			first
#define snd			second
#define maxN		100005
#define mod			1000000007

typedef long long     ll;
typedef pair<int,int> pii;
typedef long double   ld;



int main(){
	int Cases;
	scanf("%d",&Cases);
	
	REP(ii,1,Cases+1){
		printf("Case #%d:",ii);
		int N;
		scanf("%d",&N);
		vector<string> vs;
		set<string> st;
		vector<int> vi[N];
		REP(i,0,N){
			string s;
			cin >> s;
			string news=s.substr(0,1);
			char ultimo = s[0];
			int cont=1;
			REP(j,1,s.size()){
				if(s[j]==ultimo){
					cont++;
				}
				else{
					vi[i].pb(cont);
					ultimo = s[j];
					news.pb(s[j]);
					cont=1;
				}
			}
			vi[i].pb(cont);
			st.insert(news);
			/*cout << news << endl;
			REP(j,0,vi[i].size()){
				cout <<vi[i][j]<<" ";
			}
			cout << endl;*/
		}
		if(st.size()>1){
			cout << " Fegla Won" << endl;
			continue;
		}
		int ans=0;
		vector<int> mins=vi[0];
		vector<int> sorted[vi[0].size()];
		REP(i,0,N){
			REP(j,0,vi[i].size()){
				sorted[j].pb(vi[i][j]);
			}
		}
		REP(j,0,vi[0].size()) sort(all(sorted[j]));
		REP(i,0,vi[0].size()){
			mins[i] = sorted[i][N/2];
		}
//		REP(i,0,mins.size()) cout << mins[i] << " ";
	//	cout << endl; 
		REP(i,0,N){
			REP(j,0,vi[i].size()){
				ans += abs(vi[i][j]-mins[j]);	
			}
		}
		cout << " " <<ans << endl;
	}
    return 0;
}






