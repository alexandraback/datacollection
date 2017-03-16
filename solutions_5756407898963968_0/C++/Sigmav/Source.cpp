#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <queue>
#include <set>	
#include <cstring>
using namespace std;
typedef long long		ll;
typedef pair<int, int>	ii;
typedef pair<ii, int>	iii;
typedef vector<ii>		vii;
typedef vector<iii>		viii;
typedef vector<int>		vi;
typedef vector<char>	vc;
typedef vector<vc>		vvc;
typedef vector<string>	vs;
typedef unsigned long long	ull;
typedef vector<ull>		vul;
typedef vector<bool>	vb;
typedef vector<vi>		vvi;
typedef vector<vii>		vvii;
typedef vector<double>	vd;
#define INF 1000000000
#define PI 3.14159265


int main(int argc, char *argv[]){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {

		int q1;
		vi candidates;

		cin >> q1;
		for (int i=1; i<=4; i++) {
			for (int j=1; j<=4; j++) {
				int a;
				cin >> a;
				if (q1==i) {
					candidates.push_back(a);
				}
			}
		}

		int number = -1;
		int candidates_count = 0;

		cin >> q1;
		for (int i=1; i<=4; i++) {
			for (int j=1; j<=4; j++) {
				int a;
				cin >> a;
				if (q1==i) {
					// check if in canditates
					if (a==candidates[0] ||
						a==candidates[1] ||
						a==candidates[2] ||
						a==candidates[3]) {
						number = a;
						candidates_count ++;
					}
				}
			}
		}

		string out = "";
		if (candidates_count == 0) {
			cout << "Case #"<< t<< ": " << "Volunteer cheated!" << endl;
		} else if (candidates_count == 1) {
			cout << "Case #"<< t<< ": " << number << endl;
		} else {
			cout << "Case #"<< t<< ": " << "Bad magician!" << endl;
		}
	}



	return EXIT_SUCCESS;
}