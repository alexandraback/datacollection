#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back
const int MAXN = 128;
string word[MAXN];

string unique(string s){
	string res = "";
	forn(i,s.length()){
		if(i==0)res+=s[i];
		else if(s[i]!=s[i-1])res+=s[i];
	}
	return res;
}

int main(){
	int t; cin>>t;
	forn(tc,t){
		printf("Case #%d: ", tc+1);
		int n; cin>>n;
		forn(i,n)cin>>word[i];
		string patron = unique(word[0]);
		bool fegla = false;
		forn(i,n){
			if(patron != unique(word[i]))fegla = true;
		}
		if (fegla)printf("Fegla Won\n");
		else{
			//cout<<patron<<endl;
			vector<int>v[MAXN];
			forn(i,n){
				int count = 0;
				int pos = 0;
				forn(j,word[i].length()){
					if(j==0)count++;
					else{
						if(word[i][j]==word[i][j-1])count++;
						else{
							v[pos].pb(count);
							pos++;
							count=1;
						}
					}
				}
				v[pos].pb(count);
			}
			/*forn(i,patron.length()){
				forn(j,v[i].size())cout<<v[i][j]<<' ';
				cout<<endl;
			}*/
			int res = 0;
			forn(i,patron.length()){
				int best = 1000000;
				forn(j,v[i].size()){
					int dist=0;
					forn(k,v[i].size()){
						dist+=abs(v[i][j]-v[i][k]);
					}
					best = min(best, dist);
				}
				res+=best;
			}
			printf("%d\n", res);
		}
		
	}
}
