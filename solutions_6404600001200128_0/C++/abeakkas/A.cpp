/*
* abeakkas
* Google CodeJam 2015 - Round 1A
* Problem A
* Kisfmet
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>

#define pi pair<int,int>
#define vpi vector<pair<int,int> >

//DEBUGGING
#define _s cout<<
#define _d <<" "<<
#define _e <<endl;

//(int *)calloc(1000000,sizeof(int));
//(int *)malloc(1000000*sizeof(int));

using namespace std; 
ifstream fin ("A.in");
ofstream fout ("A.out");

int main(){
    int T;
    fin>>T;
    for(int iT=1;iT<=T;iT++){
        int N;
        fin>>N;
        int m[N];
        for(int i=0;i<N;i++) fin>>m[i];
        int y=0;
        for(int i=1;i<N;i++) if(m[i-1]-m[i]>0)y+=m[i-1]-m[i];
        int max=0;
        for(int i=1;i<N;i++)if(m[i-1]-m[i]>max)max=m[i-1]-m[i];
        int z=0;
        for(int i=1;i<N;i++)if(m[i-1]>max) z+=max; else  z+=m[i-1];
        fout<<"Case #"<<iT<<": "<<y<<" "<<z<<endl;
    }
	return 0;
}
