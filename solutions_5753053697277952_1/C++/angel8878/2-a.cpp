#include<string>
#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main(void)
{
	ifstream file;
	file.open("A-large.in");
	ofstream output;
	output.open("result.out");

	int caseNo;
	file >> caseNo;

	for (int c = 1; c <= caseNo; c++)
	{
		int n;
		file >> n;
		int pi[26];
		int sum = 0;
		char out[2] = {};
		for (int cc = 0; cc < n; cc++)
		{
			file >> pi[cc];
			sum += pi[cc];
		}

		output << "Case #" << c << ": ";

		while (sum != 0)
		{

			int biggest = 0;
			for (int cc = 1; cc < n; cc++)
			{
				if (pi[cc] > pi[biggest])
					biggest = cc;
			}
			pi[biggest] -= 1;
			sum -= 1;
			out[0] = 65 + biggest;
			out[1] = '0';

			if (sum != 0)
			{
				for (int cc = 1; cc < n; cc++)
				{
					if (pi[cc] > sum / 2)
					{
						pi[cc] -= 1;
						sum -= 1;
						out[1] = 65 + cc;
						break;
					}
				}
			}
			if (out[1] != '0')
				output << out[0] << out[1] << " ";
			else 
				output << out[0] << " ";
		}

		output << "\n";
	}
}