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
    ifs.open("C-small-attempt1.in");
    ofs.open("C-small-attempt1.out");
    
	long T = 0;
    ifs >> T;

	rep(i, T){
        ofs << "Case #" << i + 1 << ":" << endl;;

		long N;
		ifs >> N;

		long* X = new long[N];
		long* Y = new long[N];
		rep(j, N){
			ifs >> X[j] >> Y[j];
		}

		rep(j, N){
			long res = N;
			rep(k, N){
				if(j != k){
					long a, b, c;
					if(X[j] == X[k]){
						a = 1, b = 0, c = X[j];
					}
					else{
						a = Y[k] - Y[j];
						b = X[j] - X[k];
						c = Y[k] * X[j] - X[k] * Y[j];
					}
					
					long left = 0, right = 0;
					rep(l, N){
						if(a * X[l] + b * Y[l] > c){
							right++;
						}
						else if(a * X[l] + b * Y[l] < c){
							left++;
						}
					}
				    if(res > min(left, right)){
						res = min(left, right);
					}
				}
			}

			ofs << res << endl;
		}
		
	}
	

    ifs.close();
    ofs.close();
    return 0;
}
