#include <iostream>
#include <climits>

int ri[4] = {-1, 0, 1, 0};
int rj[4] = {0, 1, 0, -1};

int N, R, C;

bool valid(int i, int j){
	return (0 <= i && i < R && 0 <= j && j < C);
}

void solve(int c){
	std::cin >> R >> C >> N;
	int K = (1 << (R*C))-1;
	int min_t = INT_MAX;
	//std::cout << K << std::endl;
	if(R*C > 16) {
		std::cout << "NOPE" << std::endl;
		return;
	}
	for(int i=0; i<=K; ++i){
		int c = 0;
		int t = 0;
		for(int j=0; j<R; ++j){
			for(int k=0; k<C; ++k){
				if(i & (1 << (j*C+k))){
					++c;
					for(int l=0; l<4; ++l){
						int nj = j+ri[l];
						int nk = k+rj[l];
						if(!valid(nj, nk)) continue;
						//std::cout << nj << " " << nk << std::endl;
						if(i & (1 << (nj*C+nk))) ++t;
					}
				}
			}
		}
		//std::cout << i << " " << c << " " << tmp << std::endl;
		if(c==N) {
			//if(N == 8) std::cout << t << " " << i << std::endl;
			min_t = std::min(min_t, t);
		}
	}
	if(c != INT_MAX) std::cout << "Case #" << c << ": " << min_t/2 << std::endl; 
}

int main(){
	int T;
	std::cin >> T;
	for(int i=1; i<=T; ++i) solve(i);
}