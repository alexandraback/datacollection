/*
* abeakkas
* Google CodeJam 2015 - Round 1A
* Problem C
* Kisfmet
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>


//DEBUGGING
#define _s cout<<
#define _d <<" "<<
#define _e <<endl;

//(int *)calloc(1000000,sizeof(int));
//(int *)malloc(1000000*sizeof(int));
typedef long long ull;
#define pi pair<ull,ull>
#define vpi vector<pair<ull,ull> >
using namespace std; 
ifstream fin ("C.in");
ofstream fout ("C.out");

ull N;
ull xs[3000],ys[3000];
vpi dvs;

void find_dvs(ull x){
    dvs.clear();
    for(ull i=0;i<N;i++){
        if(i!=x)
        dvs.push_back(make_pair(xs[i]-xs[x],ys[i]-ys[x]));
    }
}

ull solve(ull x){
    ull min=1000000;
    find_dvs(x);
    if(N==1) min=0;
    for(ull i=0;i<N-1;i++){
        ull a=0,b=0;
        for(ull j=0;j<N-1;j++){
            if(dvs[i].first*dvs[j].second-dvs[j].first*dvs[i].second>0)a++;
            if(dvs[i].first*dvs[j].second-dvs[j].first*dvs[i].second<0)b++;
        }
        if(a<min) min=a;
        if(b<min) min=b;
    }
    return min;
}

int main(){
    ull T;
    fin>>T;
    for(ull iT=1;iT<=T;iT++){
        fin>>N;
        for(ull i=0;i<N;i++) fin>>xs[i]>>ys[i];
        fout<<"Case #"<<iT<<":"<<endl;
        for(ull i=0;i<N;i++){
            fout<<solve(i)<<endl;
        }
    }
	return 0;
}
