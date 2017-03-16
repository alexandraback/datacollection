#include <exception>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

template<typename T>
void validate(T parameter, T min, T max) {
	if(parameter < min && parameter > max)
		throw std::exception("invalid parameter");
}

class Problem {
	int N;
	std::pair<int, int>* trees;
	int* answer;
public:
	void read(std::istream& in) {
		in >> N;
		validate(N, 1, 3000);
		trees = new std::pair<int, int>[N];
		for(int i = 0; i < N; ++i) {
			in >> trees[i].first >> trees[i].second;
		}
	}
	int to_cut(const std::pair<int, int>& t1, const std::pair<int, int>& t2) { //0 means already on the border
		int left = 0;
		int right = 0;
		long long dx = t1.first - t2.first;
		long long dy = t1.second - t2.second;
		for(int i = 0; i < N; ++i) {
			long long d2x = trees[i].first - t1.first;
			long long d2y = trees[i].second - t1.second;
			long long mult = dx * d2y - dy * d2x;
			if(mult > 0)
				++left;
			else if(mult < 0)
				++right;
			//0 - on line, do not need to cut either case
		}
		return std::min(left, right);
	}
	void solve() {
		answer = new int[N];
		for(int i = 0;  i < N; ++i) {
			int min = INT_MAX;
			for(int j = 0; j < N; ++j) {
				if(j == i) continue;
				int tc = to_cut(trees[i], trees[j]);
				if(tc < min) {
					min = tc;
					if(0 == min) break;
				}
			}
			answer[i] = min;
		}
	}
	void print(std::ostream& out) {
		for(int i = 0; i < N; ++i)
			out << std::endl << answer[i];
	}
};


int main(int argc, char** argv) {
	std::istream* in = &std::cin;
	std::ostream* out = &std::cout;
	if(argc > 1) {
		in = new std::ifstream(argv[1]);

		std::string fout(argv[1]);
		int ext = fout.rfind('.');
		fout = fout.substr(0, ext);
		fout += ".out";
		out = new std::ofstream(fout);
	}

	try {
		int T;
		(*in) >> T;
		validate(T, 1, 100);
		(*out) << std::setprecision(7) << std::fixed;

		for(int iT = 1; iT <= T; ++iT) {
			Problem p;
			p.read(*in);
			p.solve();
			(*out) << "Case #" << iT << ": ";
			p.print(*out);
			(*out) << std::endl;
		}

	}
	catch(std::exception& x) {
		std::cerr << "something went wrong: " << x.what();
	}
	catch(...) {
		std::cerr << "unknown exception";
	}
	return 0;
}