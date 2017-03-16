/*
* abeakkas
* Google CodeJam 2015 - Round 1B
* Problem B
* Bu da mi gol degil
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>

typedef long long int ll;

#define pr pair<ll,ll>
#define vpr vector<pair<ll,ll> >

//DEBUGGING
#define _s cout<<
#define _d <<" "<<
#define _e <<endl;

//(int *)calloc(1000000,sizeof(int));
//(int *)malloc(1000000*sizeof(int));

using namespace std; 
ifstream fin ("B.in");
ofstream fout ("B.out");

int arr[16][16];
int R,C,N;
int minn=1000000;

// rikorsif yabarim, kafam rahat
int rec(int x,int d){
    if(x<N){
        for(int i=d;i<R*C;i++){
            arr[i/C][i%C]=1;
            rec(x+1,i+1);
            arr[i/C][i%C]=0;
        }
    }else{
        int n=0;
        for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            if(i<R-1) if(arr[i][j]) if(arr[i+1][j]) n++;
            if(j<C-1) if(arr[i][j]) if(arr[i][j+1]) n++;
        }
        if(n<minn) minn=n;
    }
}

int main(){
    int T;
    fin>>T;
    for(int iT=1;iT<=T;iT++){
        fin>>R>>C>>N;
        minn=1000000;
        for(int i=0;i<R;i++)
        for(int j=0;j<C;j++) arr[i][j]=0;
        rec(0,0);
        fout<<"Case #"<<iT<<": "<<(minn==1000000?0:minn)<<endl;
    }
	return 0;
}
