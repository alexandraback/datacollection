#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;

string solve(vector<int> P)
{
	string ans;

	int total = 0;
	for( uint i = 0; i < P.size(); i++ ) {
		total += P[i];
	}

	while(total) {
		int max = *std::max_element(P.begin(), P.end());
		if( max == 1 ) {
			if( total == 2 ) {
				for( uint i = 0; i < P.size(); i++ ) {
					if(P[i] > 0) {
						ans += i + 'A';
						P[i]--;
						total--;
					}
					if( total == 0 ) break;
				}
			} else {
				for( uint i = 0; i < P.size(); i++ ) {
					if(P[i] > 0) {
						ans += i + 'A';
						P[i]--;
						total--;
						break;
					}
				}
			}
		} else {
			int num = 0;
			for( uint i = 0; i < P.size(); i++ ) {
				if( P[i] == max ) {
					ans += i + 'A';
					P[i]--;
					total--;
					num++;
				}
				if( num == 2 ) {
					break;
				}
			}
		}
		ans += ' ';
	}
	return ans;
}

int main(int argc, char *argv[]) {

    int T;

    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);

    string line;
    std::getline(ifs, line);
    T = stoi(line);

    for( int i = 1; i <= T; i++ ) {
    	std::getline(ifs, line);
    	int N = stoi(line);
    	std::getline(ifs, line);
    	stringstream ss(line);
    	vector<int> P;
    	for( int j = 0; j < N; j++ ) {
    		int tmp;
    		ss >> tmp;
    		P.push_back(tmp);
    	}
    	ofs << "Case #" << i << ": " << solve(P) << endl;
    }

    ifs.close();
    ofs.close();

    return 0;
}







