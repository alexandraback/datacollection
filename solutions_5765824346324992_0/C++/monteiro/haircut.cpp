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

long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : abs(x); }

long long mmc(long long x, long long y) {
	return (x / gcd(x,y)) * y;
}

int main(){
	
	int T;

	scanf("%d", &T);

	vector<long long> barbers;
	vector<long long> rest;

	fork(T){

		int B;
		long long N;

		scanf("%d%lld", &B, &N);
		barbers.resize(B);
		rest.resize(B);

		fori(B) scanf("%lld", &barbers[i]);

		long long mmcvalue = 1;
		fori(B) mmcvalue = mmc(mmcvalue, barbers[i]);

		long long maxvalue = 0;
		fori(B) maxvalue = max(maxvalue, barbers[i]);

		long long up = 0;
		fori(B) up += (mmcvalue/barbers[i])*maxvalue;

		long long times = (N*mmcvalue)/up;

		long long counter = (N*mmcvalue)%up;


		long long timecounter = maxvalue*times;

		

		fori(B){
			rest[i] = - (timecounter%barbers[i] );
//			cout << rest[i] << endl;
		}

		long long offset = 0;
		fori(B) offset += (maxvalue*times)/barbers[i];

//		cout <<"offset: " << offset << endl;

		if( offset == N ){
			long long lower = INF;
			int ind;
			fori(B)
				if( barbers[B-1-i] < lower ){
					lower = barbers[B-1-i];
					ind = B-1-i;
				}
			printf("Case #%d: %d\n", k+1, ind+1);
			//			cout << "fui" << endl;
			continue;
		}

		int ind = -1;
		long long lower;
		forj(N-offset){
			lower = INF;
			fori(B){
				if( rest[i] < lower ){
					lower = rest[i];
					ind = i;
				}
			}
			rest[ind] += barbers[ind];
		}

		printf("Case #%d: %d\n", k+1, ind+1);
//		cout << ind << endl;

//		cout << "--------" << endl;


	}

	return 0;
}
