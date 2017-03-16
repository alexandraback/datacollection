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

struct point {	
	long long x;
	long long y;
	point(long long x, long long y) : x(x),y(y) {}
};

int main()
{
//==============in put=================
	ifstream curFile("C-small-attempt2.in");
	vector<vector<int> > result;
	int T; // testcases count
	int N;
	if(curFile.is_open())
	{
		curFile >> T;
		for(int c = 0 ; c < T ; c++)
		{
//==============solution==================
			cout << "Enter Test case:" << c + 1 << endl;
			curFile >> N;
			vector<point> ps;
			long long X;
			long long Y;
			for (int i = 0 ; i < N ; i ++ ) {
				curFile >> X;
				curFile >> Y;
				point t(X, Y);
				ps.push_back(t);
			}
			vector<int> ret;
			if (N == 1) {
				ret.push_back(0);
				result.push_back(ret);
				continue;
			}
			int z = -1;
			for (int i = 0 ; i < N ; i++) {
				z = -1;
				for (int j = 0 ; j < N ; j ++) {
					if (j == i)
						continue;
					int a = 0;
					int b = 0;
					long long p1 = ps[i].x * ps[j].y - ps[i].y * ps[j].x;
					long long p2 = ps[j].x - ps[i].x;
					long long p3 = ps[i].y - ps[j].y;
					for (int k = 0 ; k < N ; k ++) {
						long long TT = p1 + p2 * ps[k].y + p3 * ps[k].x;
						if (TT > 0)
							a ++;
						else if (TT < 0)
							b ++;  
					}
					a = min(a , b);
					if (z == -1)
						z = a;
					else
						z = min(z , a);
				}
				ret.push_back(z);
			}
			result.push_back(ret);
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
			vector<int> ret = result[i];
			outfile << "Case #" << i + 1<< ": " << endl;
			cout << "Case #" << i + 1<< ": " << endl;
			for (int j = 0 ; j < ret.size() ; j ++) {
				outfile << ret[j]<< endl;
				cout << ret[j]<< endl;
			}
		}
	}
	outfile.close();
	return 0;
}
