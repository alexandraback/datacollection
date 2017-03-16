#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <functional>
#include <math.h>
#include <utility>
#include <sstream>
#pragma comment(linker, "/STACK:133217728")

using namespace std;

int n;
int x[44];
int main() {  
	freopen("A-large.in", "r", stdin);
	freopen("ans.txt", "w", stdout);
	
	int T;
	cin >> T;
	

	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		cin >> n;
		int s = 0;
		for(int i=0; i<n; i++) {
			cin >> x[i];
			s += x[i];
		}
		while(s > 0) {
			string ans = "";
			int ind = 0;
			for(int i=1; i<n; i++)
				if(x[i] > x[ind]) ind = i;
			s--; x[ind]--;
			ans = char('A' + ind);
			if(s == 2 || x[ind] * 2 >= s) {
				cout << ans << " ";
				continue;
			}
			ind = 0;
			for(int i=1; i<n; i++)
				if(x[i] > x[ind]) ind = i;
			s--; x[ind]--;
			ans += char('A' + ind);
			cout << ans << " ";
		}
		cout << endl;
	}
	
	return 0;
}