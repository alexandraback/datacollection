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

int _main(){
    int64_t B,N;
    fin>>B>>N;
    int64_t M[1005];
    //fout<<N<<endl;
    //int mmm = 0;
    for(int i=0; i<B; i++){
        fin>>M[i];
        //if(M[i]>mmm) mmm = M[i];
        //fout<<M[i]<<" ";
    }
    //fout<<endl;
/*
    int64_t mult = 1;
    for(int i=0; i<B; i++) mult *= M[i];
    int period = 0;
    for(int i=0; i<B; i++) period += (mult/M[i]);
    N %= period;
*/
    long double sum[1005];
    for(int i=0; i<B; i++){
        sum[i] = 0.0;
        for(int j=0; j<B; j++) sum[i] += double(M[i])/double(M[j]);
    }

    if(N<B) return N-1;
    //fout<<N<<endl;
    for(int i=0; i<B; i++){
        int finished;
        int64_t th = int64_t(floor((N-1)/sum[i]));
        int64_t time = (th-5) * M[i];
        do{
            time += M[i];
            finished = 0;
            for(int j=0; j<B; j++){
                finished += time/M[j] + 1;
                if(j>i && (time%M[j] == 0)) finished -= 1;
            }
            //fout<<i+1<<" "<<time<<" "<<finished<<endl;
            if(finished == N) return i;
        } while(finished < N);
    }
    cout<<"ERROR!"<<endl;
    cout<<B<<" "<<N<<endl;
    return -1;
}

int main(){
    fin.open("sample2.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            fout<<_main()+1;
            fout<<endl;
    }
}
