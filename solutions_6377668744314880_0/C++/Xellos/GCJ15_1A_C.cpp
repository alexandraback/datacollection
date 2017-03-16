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

struct pt {
	long long x,y;

	bool operator<(const pt &A) const {
		int q =0, qA =0;
		if(x <= 0 && y > 0) q =1;
		if(x < 0 && y <= 0) q =2;
		if(x >= 0 && y < 0) q =3;
		if(A.x <= 0 && A.y > 0) qA =1;
		if(A.x < 0 && A.y <= 0) qA =2;
		if(A.x >= 0 && A.y < 0) qA =3;
		if(q != qA) return q < qA;
		if(q == 0) return y*A.x < A.y*x;
		if(q == 1) return (-x)*A.y < (-A.x)*y;
		if(q == 2) return (-y)*(-A.x) < (-A.y)*(-x);
		return x*(-A.y) < A.x*(-y);}
	};

long long vs(pt A, pt B) {
	return A.x*B.y-B.x*A.y;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		cout << "Case #"  << t+1 << ":\n";
		int N;
		cin >> N;
		vector<pt> P(N);
		for(int i =0; i < N; i++) cin >> P[i].x >> P[i].y;
		for(int k =0; k < N; k++) {
			vector<pt> Po =P;
			for(int i =0; i < N; i++) Po[i].x -=P[k].x, Po[i].y -=P[k].y;
			Po.erase(begin(Po)+k);
			sort(begin(Po),end(Po));
//			for(int i =0; i < N-1; i++) cout << Po[i].x << " " << Po[i].y << "\n";

			int akt =0, a =0;
			while(a < N-1 && ((Po[a].x > 0 && Po[a].y >= 0) || (Po[a].x <= 0 && Po[a].y > 0))) a++, akt++;
			int ans =min(akt,N-1-akt);
			if(a == N-1) a =0;

			int ps =0;
			for(int i =0; i < N-1; i++) {
				// prekrocim bod i
				akt--;
				if(vs(Po[i],Po[(i+1)%(N-1)]) == 0 && (Po[i].x*Po[(i+1)%(N-1)].x > 0 || Po[i].y*Po[(i+1)%(N-1)].y > 0)) {
					ps++;
					continue;}
				else ps =1;
				while(a != i && vs(Po[i],Po[a]) > 0) a =(a+1)%(N-1), akt++;
				int b =a, p2 =0;
				while(b != i && vs(Po[i],Po[b]) == 0 && (Po[i].x*Po[b].x < 0 || Po[i].y*Po[b].y < 0)) b =(b+1)%(N-1), p2++;
				ans =min(ans,min(akt,N-1-ps-p2-akt));}

			cout << max(0,ans) << "\n";}
		}
	return 0;}

// look at my code
// my code is amazing
