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
    int m[1005];
    fin>>N;
    for(int i=0;i<N;i++) fin>>m[i];

    int y,z;
    int rate = 0;
    y=0;
    for(int i=1;i<N;i++){
        if(m[i]<m[i-1]){
            y += m[i-1]-m[i];
            if(rate < m[i-1]-m[i]) rate = m[i-1]-m[i];
        }
    }
    z=0;
    for(int i=0;i<N-1;i++){
        if(m[i] > rate) z += rate;
        else z += m[i];
    }
    fout<<y<<" "<<z;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
