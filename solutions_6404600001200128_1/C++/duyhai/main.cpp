#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int main() {
    ifstream ifs( "input.in" );
    ofstream ofs( "output.out" );
    int T;
    ifs >> T;
    for ( int tt = 1; tt <= T; tt++ ){
    	int N;
    	ifs >> N;
    	vector<int> nums( N, 0 );
    	for ( int i = 0; i < N; i++ ){
    		ifs >> nums[i];
    	}
    	ofs << "Case #" << tt << ": ";
    	unsigned long sum1 = 0, sum2 = 0;
    	int maxdiff = -1;

    	for ( int i = 1; i < N; i++ ){
    		int diff = nums[i-1] - nums[i];
    		maxdiff = max( maxdiff, diff );
    		sum1 += max( 0, diff );
    	}

    	for( int i = 0; i+1 < N; i++ ){
    		sum2 += min( maxdiff, nums[i] );
    	} 
    	ofs << sum1 << ' ' << sum2 << endl;
    }
    return 0;
}
