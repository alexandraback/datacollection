#ifdef __GNUC__
#include <ext/hash_map>
#include <ext/hash_set>
#else
#include <hash_map>
#include <hash_set>
#endif

namespace std
{
 using namespace __gnu_cxx;
}

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <climits>
#include <iomanip> 
using namespace std;

typedef long long LL;
typedef long double LD;
template<class T>

T prime(T a , T b)
{
	cout << a << "\t"<<b << endl;
	if ( a >= b)
		return (prime(b , a));
	if(a == 0)
		return b;
	return prime(a , b%a);
}

string its(int n)
{
	string ret;
	if(n == 0)
	{
		ret = "0";
		return ret;
	}
	while(n > 0)
	{
		ret += (n % 10 + '0');
		n /= 10;
	}
	reverse(ret.begin() , ret.end());
	return ret;
}

struct bab {
	int num;
	long long t;	
	bab(int n , long long t) : num(n),t(t) {}
};

struct babCMP {
	bool operator() (const bab & a, const bab & b) const {
		if (a.t != b.t) {
			return a.t < b.t;
		}
		return a.num < b.num;
	}
};

long long cc(long long x, long long y) {
	if (x < y) {
		return cc(y, x);
	}
	long long t = x % y;
	if (t == 0)
		return y;
	return cc(y, t);
}

long long cp(long long x, long long y)
{
	return x*y/cc(x,y);
}

int main()
{
//==============in put=================
	ifstream curFile("B-small-attempt2.in");
	vector<int> result;
	int B;
	int N;
	int T; // testcases count
	if(curFile.is_open())
	{
		curFile >> T;
		for(int c = 0 ; c < T ; c++)
		{
//==============solution==================
			cout << "Enter Test case:" << c + 1 << endl;
			curFile >> B;
			curFile >> N;
			vector<int> time (B, 0);
			int t;
			set<bab, babCMP> que;
			long long mag = 1;
			for (int i = 0 ; i < B ; i ++) {
				curFile >> t;
				bab x(i + 1, 0);
				que.insert(x);
				time[i] = t;
				mag = cp(mag, t);
			}
			int circle = 0;
			for (int i = 0 ; i < B ; i ++) {
				circle += mag/time[i];
			}
			N = N % circle;
			if (N == 0)
				N = circle;
			bab y(0,0);
			while (N -- > 0) {
				y = *que.begin();
				que.erase(que.begin());
				y.t += time[y.num - 1];
				que.insert(y);
			}
			result.push_back(y.num);
//==============solution end==============
		}	
	}
	curFile.close();
//==============out put==================
	ofstream outfile;
	outfile.open("result.txt");
	if(outfile.is_open())
	{
//		outFile << setprecision(6);
		for(int i = 0; i < result.size() ; i++) {
			outfile << "Case #" << i + 1<< ": " <<result[i] << endl;
			cout << "Case #" << i + 1<< ": " <<result[i] << endl;
		}
	}
	outfile.close();
	return 0;
}
