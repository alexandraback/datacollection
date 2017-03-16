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
	int R, C, N;
	int walls;
public:
	void read(std::istream& in) {
		in >> R >> C >> N;
		validate(R*C, 1, 10000);
		validate(N, 0, R*C);
		if( R > C ) std::swap(R, C);
	}
	void solve() {
		walls = solve_it();
	}
	int solve_it() {
		if(N <= (R*C + 1) /2) {
			return 0;
		}
		int totalwalls = 2 * C * R - C - R;
		int freerooms = R * C - N;
		if(freerooms <=  ((R-2)*(C-2) + 1) / 2) {
			return totalwalls - 4 * freerooms;
		}

		if(R == 1) {
			return totalwalls - 2 * freerooms;
		}
		/*
		if(R == 2) {
			if( N == C/2 + 1)
				return 2;
			else
				return totalwalls - 3 * freerooms;
		}
		*/
		int x4 = ((R-2)*(C-2) + 1) / 2;
		//int	x3 = 2 * ((R-2) / 2 + (C-2) / 2);
		int x3 = 0;
		if(R%2 == 1 && C%2 == 1) {
			x3 = 2 * ((R-2) / 2 + (C-2) / 2);
		}
		else if(R%2 == 0 && C%2 == 0) {
			x3 = 2 * ((R-2) / 2 + (C-2) / 2);
		}
		else {//one odd, another one even
			x3 = (R - 2) + (C-2);
		}
		if(freerooms <= x4) {
			return totalwalls - 4*freerooms;
		}
		else if(freerooms <= x4 + x3) {
			return totalwalls - 4*x4 - 3*(freerooms - x4);
		}
		else {
			int case1 = totalwalls - 4*x4 - 3*x3 - 2*(freerooms - x4 - x3);
			if(C%2 == 1 && R%2 == 1) {
				int y4 = ((R-2)*(C-2) - 1) / 2;
				int y3 = 2* ( (R-1)/2 + (C-1)/2 );
				int case2 = totalwalls - 4*y4 - 3*(freerooms - y4);
				return std::min(case1, case2);
			}
			else
				return case1;
		}


	}
	void print(std::ostream& out) {
		out << walls;
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
		validate(T, 1, 1000);
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