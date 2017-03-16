

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
		vector<int> data(b);
		F2(i, data) cin >> data[i];

		int64 mult = 1;
		F2(i, data)  mult *= data[i];

		while (true)
		{
			int64 processCustom = 0;
			F2(j, data)
			{
				assert(mult % data[j] == 0);
				processCustom += mult / data[j];
			}
			if (processCustom >= n) break;
			n -= processCustom;
		}
		assert(n > 0);
		/*while (true)
		{
			int processCustom = 0;
			F2(j, data)
			{
				processCustom += 1200 / data[j];
			}
			if (processCustom > n) break;
			n -= processCustom;
		}*/

		vector<int> curr(b, 0);
		
		while (n != 0)
		{
			F2(i, curr)
			{
				curr[i] = max(curr[i] - 1, 0);

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