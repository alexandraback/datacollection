#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int testn;
int B, N;
int b[1005];

int gcd(int x, int y)
{
	int n;
	while (1) {
		n = x % y;
		if (n == 0)
			return y;
		x = y;
		y = n;
	}
}

int get(int lcm)
{
	int now = 0;
	for (int time = 0; time <= lcm; ++time) {
		for (int i = 0; i < B; ++i) {
			if (time % b[i] == 0) {
				// now 넣고,
				++now;
				if (now == N)
					return i+1;
			}
		}
	}
}

int main()
{
	ifstream in("B-small-attempt0.in");
	//ifstream in("input.txt");
	ofstream out("output.txt");

	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		// init

		// input
		in >> B >> N;
		for (int i = 0; i < B; ++i)
			in >> b[i];

		// process
		// lcm 구하기
		int lcm = b[0];
		for (int i = 1; i < B; ++i)
			lcm = lcm * b[i] / gcd(lcm, b[i]);

		//cout << lcm << endl;

		int roundcnt = 0;
		for (int i = 0; i < B; ++i)
			roundcnt += (lcm / b[i]);

		if (N % roundcnt == 0)
			N = roundcnt;
		else
			N %= roundcnt;

		int result = get(lcm);
		
		// output
		out << "Case #" << test << ": " << result << endl;
	}

	in.close();
	out.close();
	return 0;
}