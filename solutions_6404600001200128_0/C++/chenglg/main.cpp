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


int main()
{
//==============in put=================
	ifstream curFile("A-small-attempt0.in");
	vector<int> result1;
	vector<int> result2;
	int N;
	int T; // testcases count
	if(curFile.is_open())
	{
		curFile >> T;
		for(int c = 0 ; c < T ; c++)
		{
//==============solution==================
			cout << "Enter Test case:" << c + 1 << endl;
			curFile >> N;
			int pre;
			int t;
			vector<int> src;
			int ret1 = 0;
			int ret2 = 0;
			curFile >> pre;
			int minSpeed = 0;
			src.push_back(pre);
			for (int i = 1 ; i < N ; i ++) {
				curFile >> t;
				minSpeed = max(minSpeed, pre - t);
				if ( pre > t) {
					ret1 +=  pre - t;
				}
				pre = t;
				src.push_back(pre);
			}
			for (int i = 1 ; i < N ; i ++) {
				ret2 += min(src[i - 1], minSpeed);
			}
			result1.push_back(ret1);
			result2.push_back(ret2);
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
		for(int i = 0; i < result1.size() ; i++) {
			outfile << "Case #" << i + 1<< ": " <<result1[i]<<" "<<result2[i] << endl;
			cout << "Case #" << i + 1<< ": "<<result1[i]<<" "<<result2[i]<< endl;
		}
	}
	outfile.close();
	return 0;
}
