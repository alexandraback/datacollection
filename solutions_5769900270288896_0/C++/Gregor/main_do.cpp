#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "]";
    return out;
}

long int unhappy(long int R, long int C, long int N, vector<bool> &belegung){
	long int uhappy = 0;
	//std::cout << "belegung = "<<belegung << "\n";

	for(long int i=0; i<R*C; i++){
		if(i+1 < R*C and i%R != R-1 and belegung[i] and belegung[i+1]){
		//cout << "C " << i << "\n";
			uhappy++;
		}
		if(i+R < R*C and belegung[i] and belegung[i+R]){
		//cout << "R " << i << "\n";
			uhappy++;
			}
	}
	//cout << "uhappy = "<< uhappy << "\n";
	return uhappy;
}

long int solve_sub(long int R, long int C, long int N, long int S, long int min_i, vector<bool> &belegung){
	if(S == N){
		long int happy = unhappy(R, C, N, belegung);
//		std::cout << "belegung = "<<belegung << ", happy = "<< happy << "\n";
		return happy;
	}else{
		long int m = N*4;
		for(long int i=min_i; i<R*C; i++){

			if(not belegung[i]){
				belegung[i] = true;
			//	cout << i << " = true\n";
				m = std::min(m, solve_sub(R, C, N, S+1, i+1, belegung));
				//cout << i << " = false\n";
				belegung[i] = false;
			}
		}
		return m;
	}
}

long int solve(long int R, long int C, long int N){
	vector<bool> belegung(R*C, false);
	return solve_sub(R, C, N, 0, 0, belegung);
}

int main (int argn, char** args){
	if(argn != 3){
		std::cout << "Parameter falsch\n";
		return -1;
	}
	std::string in = args[1];
	std::string out = args[2];

	std::fstream input(in, std::ios_base::in);
	std::fstream output(out, std::ios_base::out);
	
	unsigned int cases;
	input >> cases;
	for(unsigned i=0; i<cases; i++){
		unsigned int R, C, N;
		input >> R >> C >> N;
		
		output << "Case #" << (i+1) << ": " << solve(R, C, N) << "\n";
	}


	return 0;
}