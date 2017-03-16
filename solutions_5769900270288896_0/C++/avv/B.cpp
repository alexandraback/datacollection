// CodeJam2015_1B.cpp : Defines the entry point for the console application.
//

#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include  <climits>

#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index = 0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int index = from + 1; index  < vec.size(); ++index)

int64 mi;

/*int64 rec(int64 target, int64 c)
{

	str.clear();

}*/

int main(int argc, char* argv[])
{
	int T; 
	fstream cin("input.txt");
	fstream cout("out.txt", fstream::out);
	cin >> T;
	

	for (int t = 0; t < T; ++t)
	{
		std::cout << t << endl;
		int r,c, n;
		cin >> r >> c >> n;

		
		int s = r * c;
		int mi = r * c * 4;

		for (int i = 0; i < (1 << s); ++i)
		{
			int res = 0;
			int num = 0;
			for (int j = 0; j < r; ++j)
			for (int k = 0; k < c; ++k)
			{
				int pos = j * c + k;
				int el = (i >> pos) & 1;
				if (el) num++;
				if (j + 1 < r)
				{
					int pos2 = (j + 1) * c + k;
					int el2 = (i >> pos2) & 1;

					if (el && el2) res++;
				}
				if (k + 1 < c)
				{
					int pos3 = j * c + k + 1;
					int el3 = (i >> pos3) & 1;

					if (el && el3) res++;
				}
			}
			if (num == n)
			{
				mi = min(mi, res);
			}

		}

		cout << "Case #" << t + 1 << ": " << mi << endl;
	}
	return 0;
}