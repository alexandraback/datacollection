#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <climits>
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
    ifs.open("B-large.in");
    ofs.open("B-large.out");
    
	long T;
    ifs >> T;

	rep(i, T){
        ofs << "Case #" << i + 1 << ": ";

		long B, N;
		ifs >> B >> N;

		long* M = new long[B];
		rep(j, B){
			ifs >> M[j];
		}

		if(B >= N){
			ofs << N << endl;
			delete[] M;
			continue;
		}

		long long left = 0, right = 1000000000000000;;
		long long leftSum = 0, rightSum = 0;

		while(true){
			long long mid = (left + right) / 2;
			long long sum = 0;
			rep(j, B){
				sum += mid / M[j] + 1;
			}
			if(sum >= N){
				right = mid;
				rightSum = sum;
			}
			else{
				left = mid;
				leftSum = sum;
			}

			if(right == left + 1){
				break;
			}
		}

		
		long k = N - leftSum - 1;

		rep(j, B){
			if(right % M[j] == 0){
				if(k == 0){
					k = j;
					break;
				}
				k--;
			}
		}

		ofs << k + 1 << endl;

		delete[] M;
	}
	

    ifs.close();
    ofs.close();
    return 0;
}
