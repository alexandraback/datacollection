#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<ctime>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

void _main(){
    int N;
    int64_t X[3005], Y[3005];
    fin>>N;
    for(int i=0; i<N; i++) fin>>X[i]>>Y[i];

    for(int i=0; i<N; i++){
        int mm = N;
        for(int j=0; j<N; j++){
            if(i == j) continue;
            int pos = 0;
            int neg = 0;
            int line = 0;
            for(int k=0; k<N; k++){
                if(k == i or k == j) continue;
                int64_t left = (X[j]-X[i])*(Y[k]-Y[i]);
                int64_t right = (X[k]-X[i])*(Y[j]-Y[i]);
                if(left > right) pos += 1;
                else if(right > left) neg += 1;
                else line += 1;
            }
            //fout<<i<<" "<<j<<" "<<pos<<" "<<neg<<" "<<line<<endl;
            //if(pos + neg + line != N) cout<<"ERROR!\n";
            if(pos < mm) mm = pos;
            if(neg < mm) mm = pos;
        }
        if(N <= 3) mm = 0;
        fout<<mm<<endl;
    }
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<":\n";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            //fout<<endl;
    }
}
