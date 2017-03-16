#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


vector<ll> x;
vector<ll> y;

int main(int argc, char* argv[]){
	ifstream infile(argv[1]);
	ofstream outfile("COut");
	
	int numTrials;
	infile >> numTrials;

	for (int trial = 1; trial <= numTrials; trial++){
		outfile << "Case #" << trial << ": " << endl;
		x.clear();
		y.clear();
		int N;
		infile >> N;

		ll a,b;
		for(int i = 0; i < N; i++){
			infile >> a >> b;
			x.push_back(a);
			y.push_back(b);
		}

		if (N <= 2) {
			for (int i = 0; i < N; i++)
				outfile << 0 << endl;
			continue;
		}

		for(int i = 0; i < N; i++){
			int minCut = N+1;
			for (int j = 0; j < N; j++){
				if (i == j) continue;
				int cutBig = 0;
				int cutSmall = 0;
				for (int k = 0; k < N; k++){
					long long score = (y[k] - y[j])*(x[j] - x[i]) - (x[k] - x[j])*(y[j] - y[i]);
					if (score > 0) cutBig ++;
					else if (score < 0) cutSmall ++;
				}
				if (minCut > cutBig) minCut = cutBig;
				if (minCut > cutSmall) minCut = cutSmall;
			}
			outfile << minCut << endl;
		}

	}
}
