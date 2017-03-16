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
    int S1,S2;
    int temp;
    int i,j,k;
    bool possible[17];
    for(i=1; i<=16; i++) possible[i]=false;
    fin>>S1;
    for(i=1; i<=4; i++) for(j=1; j<=4; j++){
        fin>>temp;
        if(i==S1) possible[temp]=true;
    }
    fin>>S2;
    for(i=1; i<=4; i++) for(j=1; j<=4; j++){
        fin>>temp;
        if(possible[temp] && i!=S2) possible[temp]=false;
    }
    int count=0;
    for(i=1; i<=16; i++) if(possible[i]){
        count++;
        temp = i;
    }
    if(count==0) fout<<"Volunteer cheated!";
    else if(count>1) fout<<"Bad magician!";
    else fout<<temp;
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
