

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
		std::cout << t << endl;
		int64 res = 0;
		
		int64 b, n;
		cin >> b >> n;
		vector<int64> data(b);
		F2(i, data) cin >> data[i];

		double avg = 0;
		F2(i, data)  avg += double(1) / data[i];

		//avg = avg / data.size();
		int64 time = max(int64(0), int64(floor((n - 1 - data.size())/ avg)));
		
		vector<int64> curr(b, 0);
		if (n > data.size() && time > 0)
		{
			F2(j, data)
			{
				curr[j] = data[j] - time % data[j];
				n -= time / data[j];
			}
			assert(n > 0);
			F2(j, data)
			{
				if (data[j] > 0) n--;
			}
			assert(n > 0);
		}
		while (n != 0)
		{
			F2(i, curr)
			{
				curr[i] = max(curr[i] - 1, int64(0));

				if (curr[i] == 0)
				{
					curr[i] = data[i];
					n--;
					if (n == 0)
					{
						res = i + 1;
						break;
					}
				}
			}
		}




		cout << "Case #" << t + 1 << ": " << res << " "  << endl;
	}
	return 0;
}