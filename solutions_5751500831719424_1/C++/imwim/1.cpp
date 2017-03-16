#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <float.h>
#include <iomanip>
#include <ctime>
#include <stack>
//#define FOR( i, N ) for( int (i) = 0; (i) < (N); (i)++ )
//#define FOR_( i, start, endplusone ) for( int (i) = (start); (i) < (endplusone); (i)++ )
const double EPS = 1e-10;
const double PI = 3.141592653589793;
using namespace std;
string trim( string s ){
	if( s.size() <= 1 ){
		return s;
	}
	int i = 1;
	while( i < s.size() ){
		if( s[i] == s[i-1] ){
			s.erase(i,1);
			continue;
		}
		i++;
	}
	return s;
}
int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}
int main(){
	ifstream ifs( "A-large.in" );
	int T;
	ifs >> T;
	const int Nmax = 100;
	string s[Nmax];
	string strim[Nmax];
	ofstream ofs( "out" );
	for( int i = 0; i < T; i++ ){
		int N;
		ifs >> N;
		ifs >> s[0];
		strim[0] = trim( s[0] );
		bool failbit = false;
		for( int j = 1; j < N; j++ ){
			ifs >> s[j];
			strim[j] = trim( s[j] );
			if( !failbit && strim[j].compare( strim[j-1] ) != 0 ){
				failbit = true;
			}
		}
		if( failbit ){
			ofs << "Case #" << i+1 << ": Fegla Won" << endl;
			continue;
		}
		string model = strim[0];
		int steps = 0;
		int *dist = new int[N];
		while( model.size() > 0 ){
			for( int j = 0; j < N; j++ ){
				dist[j] = -1;
				while( s[j][0] == model[0] ){
					dist[j]++;
					s[j].erase(0,1);
				}
			}
			model.erase(0,1);
			qsort (dist, N, sizeof(int), compare);
			int median = dist[N/2];
			for( int j = 0; j < N; j++ ){
				steps += abs(median-dist[j]);
			}
		}
		delete[] dist;
		ofs << "Case #" << i+1 << ": " << steps << endl;
	}
	ifs.close();
	//char buf[32];
	//for( int i = 0; i < T; i++ ){
	//	sprintf(buf,"%.7f", t[i] );
	//	ofs << "Case #" << i+1 << ": " << buf << endl;
	//}
	ofs.close();
	system( "pause" );
	return 0;
}
