#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

int red[110][110];
string s[110];
int n;

string reduct(int pos){
	string ret("");
	for(int i = 0; i < s[pos].length(); i++){
		if(ret.length() == 0 || s[pos][i] != ret[ret.length()-1]) ret.push_back(s[pos][i]);
		red[ret.length()-1][pos]++;
	}
	return ret;
}

int main(){
	int t, count = 1;
	int r;
	string r1, r2;
	
	cin >> t;
	while(t--){
		cin >> n;
		memset(red, 0, sizeof(red));
		r = 0;
		
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}
		
		r1 = reduct(0);
		for(int i = 1; r >= 0 && i < n; i++){
			r2 = reduct(i);
			if(r1 != r2) r = -1;
		}
		
		if(r >= 0){
			for(int i = 0; i < r1.length(); i++){
				sort(red[i], red[i] + n);
				
				for(int j = 1; j < n; j++){
					r += abs(red[i][j]-red[i][j-1]);
				}
			}
		}
		
		
		cout << "Case #" << count++ << ": ";
		if(r < 0) cout << "Fegla Won" << endl;
		else cout << r << endl;
	}
	
	return 0;
}

