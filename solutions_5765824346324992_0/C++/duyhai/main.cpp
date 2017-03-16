#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <set>
#include <numeric>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	for (;;)
	{
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

unsigned long long lcm(unsigned long long a, unsigned long long b)
{
	unsigned long long temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

int main() {
	ifstream ifs("input.in");
	ofstream ofs("output.out");
	unsigned long long T;
	ifs >> T;
	for (unsigned long long tt = 1; tt <= T; tt++){
		unsigned long long B, N;
		ifs >> B >> N;
		unsigned long long maxbarber = 0;
		vector<unsigned long long> barbers(B, 0);
		for (unsigned long long i = 0; i < B; i++){
			ifs >> barbers[i];
			maxbarber = max(maxbarber, barbers[i]);
		}

		unsigned long long result = std::accumulate( barbers.begin(), barbers.end(), 1, lcm );
		unsigned long long acc = 0;
		for (unsigned long long i = 0; i < B; i++){
			acc += result / barbers[i];
		}
		N--;
		N %= acc;

		vector< vector< pair< unsigned long long, unsigned long long > > > Q(maxbarber + 1);
		for (unsigned long long i = 0; i < B; i++){
			Q[0].push_back({ i, barbers[i] });
		}

		ofs << "Case #" << tt << ": ";
		bool stop = false;
		unsigned long long iter = 0;
		unsigned long long customerid = 0;
		unsigned long long latestbarber = 1;
		while (!stop){
			sort(Q[iter].rbegin(), Q[iter].rend());
			while (!Q[iter].empty()){
				auto p = Q[iter].back();
				if (customerid == N){
					stop = true;
					ofs << p.first+1 << endl;
					break;
				}
				Q[iter].pop_back();
				unsigned long long newiter = (iter + p.second) % Q.size();
				Q[newiter].push_back(p);
				customerid++;
			}
			iter = (iter + 1) % Q.size();
		}
	}
	return 0;
}
