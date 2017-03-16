#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define infin 2147483647
#define pb push_back
#define rs resize
#define mp make_pair
#define sz(x) int((x).size())
#define vv(x) vector<vector<x> >
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
	int tests;
	cin>>tests;
	for(int t=1; t<=tests; t++){
		int r, c, n, svar = infin;
		cin>>r>>c>>n;
		for(int b=0; b<(1<<(r*c)); b++){
			int nusvar = 0;
			bitset<16> bs (b);
			if(bs.count() != n) continue;
			// cout<<bs<<endl<<endl;
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){
					if(bs[j+c*i] == 0) continue;
					if(j != c-1 && bs[j+1+c*i]) nusvar++;
					if(i != r-1 && bs[j+c*(i+1)]) nusvar++;
				}
			}
			svar = min(svar, nusvar);
		}
		printf("Case #%d: %d\n", t, svar);
	}
}