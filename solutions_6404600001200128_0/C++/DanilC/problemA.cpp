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
	int* plate;
	int m1, m2;
public:
	void read(std::istream& in) {
		in >> N;
		validate(N, 2, 1000);
		plate = new int[N];
		for(int i = 0; i < N; ++i) {
			in >> plate[i];
			validate(plate[i], 0, 10000);
		}
	}
	void solve() {
		m1 = 0;
		m2 = 0;
		int rate = 0;
		for(int i = 1; i < N; ++i) {
			if(plate[i-1] > plate[i]) {
				int delta = plate[i-1] - plate[i];
				m1 += delta;
				if(delta > rate) rate = delta;
			}
		}
		for(int i = 0; i < N - 1; ++i) {
			m2 += std::min(plate[i], rate);
		}
	}
	void print(std::ostream& out) {
		out << m1 << ' ' << m2;
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