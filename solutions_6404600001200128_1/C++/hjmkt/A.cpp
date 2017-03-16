#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

#define rep(i,n) for(long i=0;i<n;i++)

using namespace std;


ifstream ifs;
ofstream ofs;
string buf;

int main(int argc, char **argv){
    ifs.open("A-large.in");
    ofs.open("A-large.out");
    
	long T = 0;
    ifs >> T;

	rep(i, T){
        ofs << "Case #" << i + 1 << ": ";

		long N;
		ifs >> N;

		long* m = new long[N];
		rep(j, N){
			ifs >> m[j];
		}

		//first
		long sum = 0;
		for(long k = 1; k < N; k++){
			if(m[k - 1] > m[k]){
				sum += m[k - 1] - m[k];
			}
		}
		ofs << sum << " ";

		//second
		long max = 0;
	    for(long k = 1; k < N; k++){
			if(m[k - 1] - m[k] > max){
				max = m[k - 1] - m[k];
			}
		}
		sum = 0;
		for(long k = 1; k < N; k++){
			sum += min(max, m[k - 1]);
		}

		ofs << sum << endl;

		delete[] m;
	}
	

    ifs.close();
    ofs.close();
    return 0;
}
