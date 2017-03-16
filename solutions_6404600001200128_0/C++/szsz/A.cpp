#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
using namespace std;


void sol(ifstream& sr, ofstream& sw) {
	int n;

	static int d[10003];
	sr >> n;
	for (int i = 0; i < n; i++)
	{
		sr >> d[i];
	}
	int r = 0, s = 0, q = 0;
	for (int i = 1; i < n; i++)
	{
		if (d[i - 1] > d[i]){
			r += d[i - 1] - d[i];
			q = std::max(q, d[i - 1] - d[i]);
		}
	}
	for (int i = 1; i < n; i++)
	{
		s += std::min(q, d[i - 1]);
	}
	sw << r << " " << s;

}

int main(){

	ifstream sr = ifstream("D:\\in.in");
	ofstream sw = ofstream("D:\\out.out");

	int T;
	sr >> T;
	for (int i = 0; i < T; i++)
	{
		sw << "Case #" << i + 1 << ": ";
		sol(sr, sw);
		sw << endl;
		cout << i << endl;
	}
	sr.close();
	sw.close();
	cout << "FINISHED type a number and enter to exit";
	cin >> T;

	return 0;
}
