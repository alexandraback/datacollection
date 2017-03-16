

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


int main(int argc, char* argv[])
{
	int T; 
	fstream cin("input.txt");
	fstream cout("out.txt", fstream::out);
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int res = 0;
		int res2 = 0;
		int N;
		cin >> N;
		vector<int> data(N);
		F2(i, data) cin >> data[i];

		double speed = 0;
		for (int i = 0; i < data.size() - 1; ++i)
		{
			if (data[i + 1] < data[i])
			{
				int delta = data[i] - data[i + 1];
				res += delta;
				
				double currSpeed = delta;
				//if (delta % 10 != 0) currSpeed++;
				//if (currSpeed == 0) currSpeed = 1;
				speed = max(speed, currSpeed); 
			}
		}
		
		for (int i = 0; i < data.size() - 1; ++i)
		{
			res2 += min(speed, (double)data[i]); 
		}


		cout << "Case #" << t + 1 << ": " << res << " " << res2 << endl;
	}
	return 0;
}