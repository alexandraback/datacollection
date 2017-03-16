#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

#define ABS(x) ((x)<0?-(x):(x))

using namespace std;

struct testcase {
	int N;
	vector<string> words;

	static testcase* read() {
		testcase *c = new testcase();

		cin >> c->N;
		for (int i = 0; i < c->N; i++) {
			string s;
			getline(cin, s);
			if (s == "") getline(cin, s);
			c->words.push_back(s);
		}

		return c;
	}

	string isolate(const string &in, vector<int> &rep) {
		char begin = 0;
		string out(in, 0, 1);

		for (int i = 1; i < in.length(); i++) {
			if (in[i] != in[begin]) {
				assert(i > begin);
				rep.push_back(i - begin);
				out += string(in, i, 1);
				begin = i;
			}
		}
		rep.push_back(in.length() - begin);

		return out;
	}

	void solve() {
		vector< vector<int> > reps(N, vector<int>());;

		string s = isolate(words[0], reps[0]);
		for (int i = 1; i < N; i++) {
			if (isolate(words[i], reps[i]) != s) {
				cout << "Fegla Won" << endl;
				return;
			}
			assert(reps[i].size() == s.length());
		}

		int score = 0;

		for (unsigned i = 0; i < reps[0].size(); i++) {
			int min = 100, max = 0;
			for (unsigned w = 0; w < N; w++) {
				int c = reps[w][i];
				if (c < min) min = c;
				if (c > max) max = c;
			}
			assert(min <= max);

			int bestscore = -1;
			for (int num = min; num <= max; num++) {
				int score = 0;
				for (unsigned w = 0; w < N; w++) {
					score += ABS(reps[w][i] - num);
				}
				if (bestscore == -1 || score < bestscore) bestscore = score;
			}
			assert(bestscore != -1);
			score += bestscore;
		}

		cout << score << endl;
	}
};

struct problem {
	int ncases;
	vector<testcase*> cases;

	void read() {
		cases.clear();
		cin >> ncases;
		for (int i = 0; i < ncases; i++) {
			cases.push_back(testcase::read());
		}
	}
	void solve() {
		for (int i = 0; i < ncases; i++) {
			cout << "Case #" << (i+1) << ": ";
			cases[i]->solve();
		}
	}
};

int main() {
	problem p;
	p.read();
	p.solve();

	return 0;
}
