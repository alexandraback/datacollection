#include<iostream>
#include<fstream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

struct party
{
	int count;
	int index;

	party()
	{
	}

	party(int index, int count)
	{
		this->count = count;
		this->index = index;
	}
};

bool compare (party p1, party p2)
{
	return p1.count > p2.count;
}

int main() {
	bool outputToFile = true;
	string inputFile = "senate.in";
	string outputFile = "senate.out";

	/* Merging input/output streams with filestreams */
	streambuf *coutbuff;
	ofstream out;
	streambuf *cinbuff;
	ifstream in;

	if(outputToFile)
	{
		out.open(outputFile);
		coutbuff = out.rdbuf();

		in.open(inputFile);
		cinbuff = in.rdbuf();
	}
	else
	{
		coutbuff = cout.rdbuf();
		cinbuff = cin.rdbuf();
	}
	
	ostream fout(coutbuff);
	istream fin(cinbuff);

	/* Merging ends */

    long long int testCases;
	fin >> testCases;

	long long int tc = 0;
    while (++tc <= testCases)
    {
		fout << "Case #" << tc << ": ";
		
		int n;
		fin >> n;

		vector<party> heap(n);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int count;
			fin >> count;
			heap[i] = party(i, count);
			sum += count;
		}

		sort(heap.begin(), heap.end(), compare);

		string result = "";
		while (heap[0].count > 0)
		{
			for (int i = 0; i < 2; i++)
			{
				if (heap[0].count > 0)
				{
					result += (char)(heap[0].index + (int)'A');
					heap[0].count--;
					sum--;

					int index = 0;
					while (index < n - 1 && heap[index].count < heap[index + 1].count)
					{
						party p = heap[index];
						heap[index] = heap[index + 1];
						heap[index + 1] = p;
						index++;
					}
				}

				if (sum == 2)
				{
					break;
				}
			}

			result += " ";
		}

		fout << result;

		fout << endl;
    }

	if(outputToFile)
	{
		out.close();
		in.close();
	}
    
    return 0;
}
