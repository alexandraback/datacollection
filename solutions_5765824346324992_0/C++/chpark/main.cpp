#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <functional>
#include <numeric>

using namespace std;

//const char* INPUT_FILE_NAME  = "B-large.in";
//const char* OUTPUT_FILE_NAME = "B-large.out";
const char* INPUT_FILE_NAME  = "B-small-attempt1.in";
const char* OUTPUT_FILE_NAME = "B-small-attempt1.out";
//const char* INPUT_FILE_NAME  = "B-small.in";
//const char* OUTPUT_FILE_NAME = "B-small.out";

int gcd(int a, int b)
{
	for (;;)
	{
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

int lcm(int a, int b)
{
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

/*
int main()
{
	int arr[] = { 5, 7, 9, 12 };

	int result = std::accumulate(arr, arr + 4, 1, lcm);

	std::cout << result << '\n';
}
*/

struct BARBER_INFO
{
	BARBER_INFO(int i)
	: index(i), next_available_time(0)
	{}

	int index;
	int next_available_time;
};
bool operator< (const BARBER_INFO& lhs, const BARBER_INFO& rhs)
{
	if (lhs.next_available_time == rhs.next_available_time)
		return lhs.index < rhs.index;
	else
		return lhs.next_available_time < rhs.next_available_time;
}
bool operator> (const BARBER_INFO& lhs, const BARBER_INFO& rhs)
{
	if (lhs.next_available_time == rhs.next_available_time)
		return lhs.index > rhs.index;
	else
		return lhs.next_available_time > rhs.next_available_time;
}

int main()
{
	int T;
	string strOutput;
	string strInput;

	fstream inputFileStream(INPUT_FILE_NAME, ios_base::in);
	fstream outputFileStream(OUTPUT_FILE_NAME, ios_base::out|ios_base::trunc);
	outputFileStream.setf(ios_base::floatfield, ios_base::fixed);
	outputFileStream.precision(7);
	cout.setf(ios_base::floatfield, ios_base::fixed);
	cout.precision(7);

	inputFileStream >> T;

	
	for (int i = 0; i < T; ++i)
	{
		int B, N;

		inputFileStream >> B >> N;

		std::vector<int> M(B);
		for (int j = 0; j < B; ++j)
		{
			inputFileStream >> M[j];
		}

		int LCM = std::accumulate(M.begin(), M.end(), 1, lcm);
		int people_count = 0;
		for (int j = 0; j < B; ++j)
		{
			int pc = LCM / M[j];
			people_count += pc;
		}

		int need_to_compute = N % people_count;
		if (need_to_compute != 0)
			N = need_to_compute;
		else
			N = need_to_compute + people_count;

		std::priority_queue<BARBER_INFO, vector<BARBER_INFO>, greater<BARBER_INFO> > barber_queue;
		for (int j = 0; j < B; ++j)
		{
			barber_queue.push(BARBER_INFO(j));
		}

		std::vector<bool> (B, true);
		for (int j = 0; j < N - 1; ++j)
		{
			BARBER_INFO info = barber_queue.top();
			barber_queue.pop();

			info.next_available_time += M[info.index];
			barber_queue.push(info);
		}

		int pos = barber_queue.top().index;

		cout << "Case #" << i + 1 << ": " << pos + 1 << endl;
		outputFileStream << "Case #" << i + 1 << ": " << pos + 1 << endl;
	}

	inputFileStream.close();
	outputFileStream.flush();
	outputFileStream.close();

	return 0;
}
