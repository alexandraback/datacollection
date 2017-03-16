/*
* abeakkas
* Google CodeJam 2015 - Round 1A
* Problem B
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
ifstream fin ("B.in");
ofstream fout ("B.out");
typedef unsigned long long ull;

int main(){
    ull T;
    fin>>T;
    for(ull iT=1;iT<=T;iT++){
        ull B,N;
        fin>>B>>N;
        ull M[B];
        ull Q[B];
        for(ull i=0;i<B;i++) fin>>M[i];
        for(ull i=0;i<B;i++) Q[i]=0;
        bool flag=true;
        ull n=0;
        for(ull t=0;flag;t++){
            for(ull i=0;i<B && flag;i++){
                if(Q[i]==0){
                    Q[i]=M[i];
                    n++;
                    if(N==n){
                        fout<<"Case #"<<iT<<": "<<(i+1)<<endl;
                        cout<<iT<<endl;
                        flag=false;
                        break;
                    }
                }
            }
            ull min=100000;
            for(ull i=0;i<B && flag;i++){
                if(Q[i]<min) min=Q[i];
            }
            for(ull i=0;i<B && flag;i++){
                Q[i]-=min;
            }
            ull s=0;
            for(ull i=0;i<B && flag;i++) s+=Q[i];
            if(s==0 && flag){
                ull nn=n;
                if(N/n>1)
                n=(N/n-1)*n;
            }
        }
    }
	return 0;
}
