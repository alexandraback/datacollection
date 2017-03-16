#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int T;
	ifstream input;
	ofstream output;
	input.open("a.txt");
	output.open("output.txt");
	input >> T;
	forn (i, T){
		printf("break\n");
		int R,C, N;
		input >> R >>C >> N;
		if (N == 0) {
			
			output << "Case #"<< i+1 <<": " << 0	 << endl;	
			continue;
		}
		int v[R][C];
		int TU = R*(C-1) + C*(R-1);
		printf("%d\n",R);
		forn(j, R)
			forn(k,C){
				v[j][k] = 0;
				if (j > 0) v[j][k] +=1;
				if (j < R-1) v[j][k] +=1;
				if (k > 0) v[j][k] +=1;
				if (k < C-1) v[j][k] +=1;
				printf("%d\n", v[j][k]);
			}
		forn(j, R*C-N){
			int bk = 0;
			int bl = 0;
			int a = 0;
			forn(k,R)
				forn(l, C){
					printf("%d\n", v[k][l]);
					if (v[k][l] > a){
						bk = k;
						bl = l;
						a = v[k][l];
					}
				}
			printf("%d\n", a);
			TU = TU - a;
			v[bk][bl] = 0;
			if (bk > 0) v[bk-1][bl] = max(v[bk-1][bl]-1 ,0);
			if (bk < R-1) v[bk+1][bl] = max(v[bk+1][bl]-1 ,0);
			if (bl > 0) v[bk][bl-1] = max(v[bk][bl-1]-1 ,0);
			if (bl < C-1) v[bk][bl+1] = max(v[bk][bl+1]-1 ,0);
		}
		
		output << "Case #"<< i+1 <<": " << TU	 << endl;	
	}		

}
