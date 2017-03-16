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
	int B, N;
	int* M;
	int answer;
public:
	void read(std::istream& in) {
		in >> B >> N;
		validate(B, 1, 1000);
		validate(N, 1, 1000000000);
		M = new int[B];
		for(int i = 0;i < B; ++i) {
			in >> M[i];
			validate(M[i], 1, 100000);
		}
	}
	//void testdata() { B = 5; N = 448257424; M = new int[B]; M[0] = 1; M[1] = 2; M[2] = 3; M[3] = 4; M[4] = 5;}
	void testdata() { B = 3; N = 448257424; M = new int[5]; M[0] = 1; M[1] = 2; M[2] = 3; M[3] = 4; M[4] = 5;}

	void solve() {
		int* busy = new int[B];
		for(int i = 0; i < B; ++i) busy[i] = 0;

		busy[0] = M[0];//to prevent to get to all zero initially

		for(int todo = N - 1; todo > 0;) {
			int min = INT_MAX;
			bool allzero = true;

			for(int i = 0; i < B; ++i) {
				if(busy[i] == 0) {
					busy[i] = M[i];
					--todo;
					if(0 == todo) {
						answer = (i+1);
						break;
					}
				}
				else {
					allzero = false;
				}
				if(busy[i] < min) min = busy[i];
			}

			if(todo > 0 && allzero) {
				int passed = N - (todo + B);
				std::cerr << "cicle: " << passed << std::endl;
				todo = todo % passed;
				if(0 == todo) answer = B;
			}

			for(int i = 0; i < B; ++i) busy[i] -= min;
		}
	}
	void print(std::ostream& out) {
		out << answer;
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