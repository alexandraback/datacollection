// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		cout << "Case #"  << t+1 << ": ";
		int N, ans1 =0, ans2 =0, pOld;
		cin >> N >> pOld;
		vector<int> V(N,pOld);
		int rateM =0;
		for(int i =1; i < N; i++) {
			int p;
			cin >> p;
			V[i] =p;
			if(p < pOld) ans1 +=pOld-p;
			rateM =max(rateM,pOld-p);
			pOld =p;}
		for(int i =0; i < N-1; i++) {
			int pNew =max(0,V[i]-rateM);
			ans2 +=V[i]-pNew;}
		cout << ans1 << " " << ans2 << "\n";}
	return 0;}

// look at my code
// my code is amazing
