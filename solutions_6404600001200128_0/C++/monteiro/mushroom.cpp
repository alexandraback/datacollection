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

int main(){

	int T;

	scanf("%d", &T);

	vint numbers;

	fork(T){

		int N;
		scanf("%d", &N);
		numbers.resize(N);

		fori(N) scanf("%d", &numbers[i]);

		int ret = 0;
		fori(N-1) ret += numbers[i] > numbers[i+1] ? numbers[i] - numbers[i+1] : 0;

		printf("Case #%d: %d ", k+1, ret);

		int higher = 0; ret = 0;
		fori(N-1) higher = max( higher, numbers[i] - numbers[i+1] );
		fori(N-1) ret += min(numbers[i], higher);
		printf("%d\n", ret);
		



		

	}

	return 0;

}
