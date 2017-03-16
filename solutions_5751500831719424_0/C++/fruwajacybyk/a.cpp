#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;


int main(){
	int z; scanf("%d",&z);
	int casenr=0;
	while(z--){
		casenr++;
		printf("Case #%d: ",casenr);
		int n;
		char s[105][105];
		scanf("%d",&n);
		FOR(i,0,n) scanf("%s",s[i]);
		
		vector<pair<int, char> > kod[105];

		FOR(i,0,n){
			int dl = strlen(s[i]);
			char akt = 'A';
			FOR(j,0,dl){
				if(s[i][j]==akt)
					kod[i][kod[i].size()-1] = mp(kod[i][kod[i].size()-1].st+1,kod[i][kod[i].size()-1].nd);
				else 
					kod[i].pb(mp(1,s[i][j]));

				akt = s[i][j];
			}
		}

		bool flaga = true;
		int m = kod[0].size();
		FOR(i,0,n){
			if(kod[i].size()!=m || !flaga){ flaga = false; break;}
			FOR(j,0,m){
				if(kod[i][j].nd!=kod[0][j].nd){
					flaga = false;
					break;
				}
			}
		}
		if(!flaga){
			printf("Fegla Won\n");
		}
		else{
			int res = 0;
			FOR(j,0,m){
				VI v;
				FOR(i,0,n) v.pb(kod[i][j].st);
				sort(v.begin(),v.end());
				int pos1 = (n-1)/2;
				int pos2 = (n+1)/2;
				int w1 = 0;
				int w2 = 0;
				FOR(i,0,n){
					w1+=abs(v[i]-v[pos1]);
					w2+=abs(v[i]-v[pos2]);
				}
				res+=min(w1,w2);
			}

		printf("%d\n",res);
		}
	}
	return 0;
}
  

