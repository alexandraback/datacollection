#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


int T;
int N, B;
long long M[1005];
long long time[1005];


long long upper(long long a, long long b)
{
	return (a / b) + 1;
}

long long sum(long long B, long long time)
{
	long long res = 0;
	for (int i = 0; i < B; i++)
	{
		res += upper(time, M[i]);
	}
	return res;
}

long long bisearch(long long B, long long N, long long low, long long upp)
{
	if (low == upp || low == upp - 1)
	{
		if (sum(B, low) >= N)
			return low;
		else return upp;
	}
	else
	{
		long long mid = (low + upp) / 2;
		if (sum(B, mid) >= N)
			return bisearch(B, N, low, mid);
		else return bisearch(B, N, mid, upp);
	}
}

long long min(long long a, long long b)
{
	if (a < b)
		return a;
	else
		return b;
}

long long get_res2(long long B, long long N)
{
	if (N <= B)
		return N;
	long long res = -1;
	long long temp = 1e15;
	long long time = bisearch(B, N, 0, 1e15);
	long long finish = 0;
	for (long long i = 0; i < B; i++)
	{
		if (M[i] * (time / M[i]) == time)
		{
			finish += time / M[i];
		}
		else
			finish += upper(time, M[i]);
	}
	if (finish == N)
	{
		for (long long i = 0; i < B; i++)
		{
			if (M[i] * (time / M[i]) == time && M[i] < temp)
			{
				temp = M[i];
				res = i + 1;
			}
		}
		return res;
	}
	for (long long i = 0; i < B; i++)
	{
		if (M[i] * (time / M[i]) == time)
			finish++;
		if (finish == N)
			return i + 1;
	}
}

int main()
{
	ifstream ifile;
	ofstream ofile;
	ifile.open("B-small-attempt2.in");
	ofile.open("output.txt");

	ifile >> T;
	int casenum = 0;
	while (casenum < T)
	{
		casenum++;
		ifile >> B >> N;
		for (int i = 0; i < B; i++)
			ifile >> M[i];
		ofile << "Case #" << casenum << ": " << get_res2(B, N) << endl;
	}
}