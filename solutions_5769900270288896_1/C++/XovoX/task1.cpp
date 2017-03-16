#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
int main()
{
	ifstream fin;
	fin.open("B-large.in");
	if (fin.is_open())
	{
		ofstream fout;
		fout.open("B-large.out");
		long long T;
		fin >> T;
		for (int i = 0; i < T; i++)
		{
			int N,R,C;
			fin >> R>>C>>N;
			int half = (int)ceil((double)C*R / 2);
			if (N <= half) fout << "Case #" << i + 1 << ": 0" << endl; else
			{
				// вариант 1
				// есть угловые C%2 или R%2
				int rest = N - half;
				if (R == 1 || C == 1)
				{
					if (R % 2 == 0 || C % 2 == 0)
					{
						fout << "Case #" << i + 1 << ": " << (rest-1) * 2+1 << endl;
					}
					else
					{
						fout << "Case #" << i + 1 << ": " << rest * 2 << endl;
					}

		
				} else
				if (R % 2 == 0 || C % 2 == 0)
				{
					if (rest == 1) fout << "Case #" << i + 1 << ": 2" << endl; else
						if (rest == 2) fout << "Case #" << i + 1 << ": 4" << endl; else
						{
							int res = 4;
							if (rest <= R + C - 2)
							{
								res += (rest - 2) * 3;
								fout << "Case #" << i + 1 << ": "<< res << endl;
							}
							else
							{
								res += (R + C - 4) * 3;
								res += (rest - (R + C - 2)) * 4;
								fout << "Case #" << i + 1 << ": " << res << endl;
							}
						}
				} else 
				{
					int res1 = 0;
					if (rest <= R + C - 2) res1 += rest * 3; else
					{
						res1 += (R + C - 2) * 3 + (rest - (R + C - 2)) * 4;
					}
					int res2 = 0;
					rest++;
					if (rest <= 4) res2 = 2 * rest; else
					{
						if (rest <= R + C - 2) res2 = 4 * 2 + 3 * (rest - 4); else
						{
							res2 = 4 * 2 + (R + C - 2 - 4) * 3 + (rest - (R + C - 2)) * 4;
						}
					}
					if (res1<res2) fout << "Case #" << i + 1 << ": " << res1 << endl; else fout << "Case #" << i + 1 << ": " << res2 << endl;
				}
			}

			cout << "Case #" << i + 1 << ":"<<N << endl;
			
		}
		fin.close();
		fout.close();
	}
	return 0;
}