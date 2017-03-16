#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#define pb push_back
#define pf push_front
#define sz size
#define f() first
#define s() second
#define b() begin()
#define e() end()

#define pairii pair< int,int >
#define vint vector< int >
#define vchar vector< char >
#define vbool vector< bool >
#define vstring vector< string >
#define int64 long long
#define Uint64 unsigned long long
#define Uint unsigned int
#define Uchar unsigned char

#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)
#define forir(n) for(int i=n-1;i>=0;i--)
#define forr(i, a, b) for ( int i = (a); i <= (b); ++i )
#define ford(i, a, b) for ( int i = (a); i >= (b); --i )
#define forit(v) for(it = v.begin();it != v.end();it++)

#define trace(x...) x
#define print(x...) trace(printf(x))
#define watch(x) trace(cout << #x" = " << x << "\n")

#define INF 0x3F3F3F3F // Signed int
//#define INF 0x3F3F3F3F3F3F3F3FLL // Signed int64
#define EPS 1e-10
#define PI 3.14159265358979323846

int cmpD(double a, double b){
	return (a <= b + EPS) ? (a + EPS < b) ? -1 : 0 : 1;
}

using namespace std;

int grid[20][20];
int R,C;
int result;

int check(bool grid[100][100]){
	int ret = 0;
	fori(R)
		forj(C){
			if( j+1 < C && grid[i][j]  && grid[i][j+1]  )
				ret++;
			if( i+1 < R && grid[i][j]  && grid[i+1][j]  )
				ret++;
		}
	return ret;
}

int startR, startC;

int main(){

	int games;
	cin >> games;

	int v[100][100];
	bool used[100][100];

	fork(games){
		int t;
		cin >> R >> C >> t;
		fori(R) v[i][0] = v[i][C-1] = (C == 1 ? 2 : 3);
		fori(C) v[0][i] = v[R-1][i] = (R == 1 ? 2 : 3);
		v[0][0] = v[0][C-1] = v[R-1][0] = v[R-1][C-1] = ((C == 1 || R == 1) ? 1 : 2);
		fori(R-2) forj(C-2) v[i+1][j+1] = 4;

		fori(R) forj(C) used[i][j] = true;


		fori(R*C - t){
			int highest = 0; int indi, indj;
			fori(R) forj(C)
				if( used[i][j] && v[i][j] > highest ){
					indi = i;
					indj = j;
					highest = v[i][j];
				}
//			cout << indi << " " << indj << endl;
			used[indi][indj] = false;
			if( indi - 1 >= 0 )
				v[indi-1][indj]--;
			if( indi + 1 < R )
				v[indi+1][indj]--;
			if( indj - 1 >= 0 )
				v[indi][indj-1]--;
			if( indj + 1 < C )
				v[indi][indj+1]--;
		}

//		cout << endl;
//		fori(R){
//			forj(C) cout << used[i][j] << " ";
//			cout << endl;
//		}

		cout << "Case #" << k+1 << ": " << check(used) << endl;

	}



}
