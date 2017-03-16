#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	ifstream fin ("B-large.in");
	ofstream fout ("B-output.txt");
	int T, N, R, C, k, l, s;
	fin >> T;
	for(int x = 1; x <= T; x++){
        fin >> R >> C >> N;
        if(N <= round(ceil(R*C/2.0))){
            fout << "Case #" << x << ": 0\n";
            continue;
        }
        if(C==1||R==1){
            l = C*R;
            fout << "Case #" << x << ": " << N - (l - N) - 1 << '\n';
            continue;
        }
        k = s = 0;
        l = N - R*C/2;
        if(C%2==1 && R%2==1){
            if(l==2) k = 3;
            else if(l<=4) k += l*2;
            else k += 8;
            l -= 4;
        }else if(C%2==1 || R%2==1){
            s++;
            if(l<=2) k += l*2;
            else k += 4;
            l -= 2;
        }else{
            if(l<=2) k += l*2;
            else k += 4;
            l -= 2;
        }
        if(l>0){
            s += ((R-2)/2)*2 + ((C-2)/2)*2;
            //cout << s << '\n';
            if(l<=s) k += l*3;
            else k += s*3;
            l -= s;
        }
        if(l>0) k += l*4;
        fout << "Case #" << x << ": " << k << "\n";
	}
}
