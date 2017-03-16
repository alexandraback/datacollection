#include <cstdlib>
#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int min(vector<int> v) {
	int min=v[0],min_i=0;
	for (int i=0;i<v.size();i++) {
		if (v[i]<min) {
			min = v[i];
			min_i = i;
		}
	}
	return min_i;
}

bool zero(vector<int> v) {
	for (int i=0;i<v.size();i++) {
		if (v[i]!=0) return false;
	}
	return true;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for (int n=0;n<T;n++) {
		//priority_queue<int> q;
		int B,N;
		cin >> B >> N;
		vector<int> b (B,0);
		for (int i=0;i<B;i++) {
			cin >> b[i];
		}
		vector<int> bb (B,0);
		int N_=N;
		while (N>1) {
			/*cerr << N << " : ";
			for (int i=0;i<B;i++) cerr << bb[i] << " ";
			cerr << "\n";*/
			if (zero(bb) && N!=N_) {
				cerr << N << " > ";
				//N=N%(N_-N);//+N_-N;
				if (N%(N_-N)!=0) {
					N=N%(N-N_);
				} else {
					N=N_-N;
				}
				cerr << N << "\n";
			}
			for (int i=0;i<B;i++) {
				if (bb[i]==0) {
					bb[i]+=b[i];
					N--;
					if (N==1) break;
					//break;
				}
			}
			//if (found) N--;
			int m = bb[min(bb)];
			for (int i=0;i<B;i++) {
				//if (bb[i]) bb[i]-=bb[min(bb)];
				bb[i] -= m;
			}

		}

			/*cerr << N << " : ";
			for (int i=0;i<B;i++) cerr << bb[i] << " ";
			cerr << "\n";*/
		cerr << n << "\n";
		int sol=-1;
		for (int i=0;i<B;i++) {
			if (bb[i]==0) {
				sol=i;
				break;
			}
		}
		if (sol==-1) {
			int min=bb[0],min_i=0;
			for (int i=0;i<B;i++) {
				if (bb[i]<min) {
					min = bb[i];
					min_i=i;
				}
			}
			sol=min_i;
		}
		printf("Case #%d: %d\n",n+1,sol+1);
	}

	return 0;
}

