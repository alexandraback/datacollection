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
		int B;
		long long N;
		cin >> B >> N;
		vector<long long> M(B);
		for(int i =0; i < B; i++) cin >> M[i];
		long long tA =-1, tB =123456789123456789LL;
		while(tB-tA > 1) {
			long long tC =(tB+tA)/2, n =0;
			for(int i =0; i < B; i++) n +=tC/M[i]+1;
			if(n >= N) tB =tC;
			else tA =tC;}
		for(int i =0; i < B; i++) N -=(tB-1)/M[i]+1;
		for(int i =0; i < B; i++) if(tB%M[i] == 0)
			if(--N == 0) {
				cout << i+1 << "\n";
				break;}
		}
	return 0;}

// look at my code
// my code is amazing
