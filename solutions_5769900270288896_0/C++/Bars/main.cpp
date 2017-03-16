#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <functional>
#include <map>
#include <memory>
#include <sstream>
#include <string.h>
#include <cstring>


using namespace std;

int main () 
{
	ifstream in("in.in");
	ofstream out("out.txt");

	int T;

	in >> T;

	for (int t = 1; t <= T; ++t)
	{
		out << "Case #" << t << ": ";

		int r, c, n;

		in >> r >> c >> n;
		int ans = 2*1000*1000*1000;

		if (n <= 1) 
		{ 
			out << 0 << endl; 
			continue; 
		}

		for (long long mask = (1 << (r * c)) - 1; mask > 0; --mask)
		{
			long long k = 0;
			long long u = 0;

			for (int i = 0; i < 17; ++i)
				if ((mask & (1 << i)) != 0)
				{
					k++;

					if ((i + 1) % r != 0)
					{
					    if ( (mask & (1 << (i + 1))) != 0)
							++u;
					}

					if ((i / r + 1) < c)
						if ( (mask & (1<<(i + r))) != 0) 
							++u;
				}

			if ((k == n) && u < ans) 
				ans = u;
		}

		out<<ans<<endl;

	}


	in.close();
	out.close();

	return 0;
}