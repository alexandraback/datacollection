#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int solve(int n, vector<int>& m) {

	long double average = 0;

	for(int i = 0; i < m.size(); i++) {
		average += (1.0L / m[i]);
	}

	long long min_time = ((long double)n - 1.0L) / average;

	int total = 0;
	vector<long long> endtime;


	for(int i = 0; i < m.size(); i++) {
		long long count = min_time / m[i];
		endtime.push_back(count * m[i]);
		total += count;
	}


	long long min_endtime = endtime[0];
	for(int i = 1; i < m.size(); i++) {
		if(endtime[i] < min_endtime) {
			min_endtime = endtime[i];
		}
	}

	for(int i = 0; i < m.size(); i++) {
		while(endtime[i] >= min_endtime && endtime[i] > 0) {
			endtime[i] -= m[i];
			total--;
		}
	}


	while(total < n - 1)
	{
		int next = 0;
		for(int i = 1; i < m.size(); i++) {
			if(endtime[i] < endtime[next]) {
				next = i;
			}
		}
		endtime[next] += m[next];
		total++;
	}

	while(total > n - 1)
	{
		int prev = m.size() - 1;
		for(int i = m.size() - 2; i >= 0; i--) {
			int endtime1 = endtime[i] - m[i];
			int endtime2 = endtime[prev] - m[prev];
			if(endtime1 < 0) endtime1 = 0;
			if(endtime2 < 0) endtime2 = 0;
			if(endtime1 < endtime2) {
				prev = i;
			}
		}
		endtime[prev] -= m[prev];
		if(endtime[prev] < 0) endtime[prev] = 0;
		total--;
	}


	int sol = 0;
	for(int i = 1; i < m.size(); i++) {
		if(endtime[i] < endtime[sol]) {
			sol = i;
		}
	}

	return sol + 1;
}

int main(int argc, char** argv) {

	ifstream fin(argv[1]);
	int n;

	fin >> n;
	for(int i = 1; i <= n; i++) {
		vector<int> mk;
		int b, m;
		fin >> b >> m;
		mk.resize(b);
		for(int j = 0; j < b; j++) {
			fin >> mk[j];
		}

		cout << "Case #" << i << ": " << solve(m, mk) << endl;
	}
	fin.close();
}