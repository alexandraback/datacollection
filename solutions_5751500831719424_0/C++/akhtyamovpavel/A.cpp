#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "A.in"
#define FILEOUT "A.out"
int main(){
    freopen(FILEIN,"r",stdin);
    freopen(FILEOUT,"w",stdout);
    int tests;
    cin>>tests;
    for(int _ = 1; _ <= tests; ++_){
    	int N;
    	cin>>N;
    	string s[N];
    	for(int i = 0; i < N; ++i){
    		cin>>s[i];
    	}
    	vector<char> blocks[N];
    	vector<int> cnt[N];
    	for(int i = 0; i < N; ++i){
    		blocks[i].pb(s[i][0]);
    		cnt[i].pb(1);
    		for(int j = 1; j < s[i].length(); ++j){
    			if(blocks[i].back() != s[i][j]){
    				blocks[i].pb(s[i][j]);
    				cnt[i].pb(1);
    			}
    			else{
    				cnt[i].back()++;
    			}
    		}
    	}
    	
        cout<<"Case #"<<_<<": ";
        bool f = false;
        for(int i = 1; i < N; ++i){
        	if(blocks[i] != blocks[i-1]){
        		cout<<"Fegla Won"<<endl;
        		f = true;
        		break;
        	}
        }
        if(!f){
	        int mindiv = 0;

	        for(int i = 0; i < blocks[0].size(); ++i){
	        	int curdif = INF;
	        	for(int cursign = 1; cursign <= 250; ++cursign){
	        		int dd = 0;
	        		for(int j = 0; j < N; ++j){
	        			dd += labs(cursign - cnt[j][i]);
	        		}
	        		curdif = min(dd, curdif);
	        	}
	        	mindiv += curdif;
	        }
	        cout<<mindiv<<endl;
   		}
        endi:;

    }
    return 0;
}