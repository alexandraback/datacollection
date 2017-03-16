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
#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F_S(vec, index, start) for (int index = start; index  < vec.size(); ++index)



int main(int argc, char* argv[])
{

	ofstream out ("output.txt");
	ifstream in("input.txt");

	int T;
	in >> T;

	for (int t = 0; t < T; ++t)
	{
		int row;
		in >> row;
		row--;
		int arr[4][4];
		for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			in >> arr[i][j];
		}

		int row2;
		in >> row2;
		row2--;
		int arr2[4][4];
		for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			in >> arr2[i][j];
		}

		int equal = 0;
		int saveLastEqual;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (arr[row][i] == arr2[row2][j])
				{
					equal++;
					saveLastEqual = arr[row][i];
					break;
				}
			}
		}
		if (equal == 0)
		{
			out << "Case #" << t + 1 << ": " << "Volunteer cheated!" << endl;
		}
		else if (equal == 1)
		{
			out << "Case #" << t + 1 << ": " << saveLastEqual << endl;
		}
		else
		{
			out << "Case #" << t + 1 << ": " << "Bad magician!" << endl;
		}
		

	}




	return 0;
}
