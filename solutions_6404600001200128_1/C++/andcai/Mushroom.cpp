#include <fstream>

using namespace std;

int main(){
	ifstream fin ("A-large.in");
	ofstream fout ("A-output.txt");
	int T, N, totsub, maxsub, tot2;
	int m[1001];
	m[0] = 0;
	fin >> T;
	for(int c = 1; c <= T; c++){
        fin >> N;
        totsub = maxsub = tot2 = 0;
        for(int i = 1;i <= N; i++){
            fin >> m[i];
            if(m[i]<m[i-1]){
                totsub += m[i-1] - m[i];
                if(m[i-1] - m[i] > maxsub) maxsub = m[i-1] - m[i];
            }
        }
        for(int i = 1;i < N; i++){
            if(m[i]<maxsub){
                tot2 += m[i];
            }else tot2 += maxsub;
        }
        fout << "Case #" << c << ": " << totsub << " " << tot2 << '\n';
	}
}
