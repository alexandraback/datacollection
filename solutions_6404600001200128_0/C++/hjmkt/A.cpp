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

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;


ifstream ifs;
ofstream ofs;
string buf;

int main(int argc, char **argv){
    ifs.open("A-small-attempt0.in");
    ofs.open("A-small-attempt0.out");
    
	int T = 0;
    ifs >> T;

	rep(i, T){
        ofs << "Case #" << i + 1 << ": ";

		int N;
		ifs >> N;

		int* m = new int[N];
		rep(j, N){
			ifs >> m[j];
		}

		//first
		int sum = 0;
		for(int k = 1; k < N; k++){
			if(m[k - 1] > m[k]){
				sum += m[k - 1] - m[k];
			}
		}
		ofs << sum << " ";

		//second
		int max = 0;
	    for(int k = 1; k < N; k++){
			if(m[k - 1] - m[k] > max){
				max = m[k - 1] - m[k];
			}
		}
		sum = 0;
		for(int k = 1; k < N; k++){
			sum += min(max, m[k - 1]);
		}

		ofs << sum << endl;

		delete[] m;
	}
	

    ifs.close();
    ofs.close();
    return 0;
}
