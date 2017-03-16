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

// Simdi onlar dusunsun
int solve(int r,int c,int n){
    if(r==1 || c==1){
        if(r*c%2){
            if(n>r*c/2+1) return (n-(r*c/2+1))*2;
            else return 0;
        }else{
            if(n>r*c/2) return 1+(n-(r*c/2)-1)*2;
            else return 0;
        }
    }
    int dd=r*c/2+r*c%2;
    n-=dd;
    if(n<=0) return 0;
    int x=0;
    int h2=2*((r*c+1)%2);
    if(r*c%2 && n>1){
        n++;
        dd--;
        h2=4;
    }
    int h3=((r+c)*2-4)/2-h2;
    int h4=r*c-dd-h2-h3;
    while(n!=0){
        if(h2>0){
            h2--;
            n--;x+=2;
        }else if(h3>0){
            h3--;
            n--;x+=3;
        }else if(h4>0){
            h4--;
            n--;x+=4;
        }
    }
    return x;
}

int main(){
    int T;
    fin>>T;
    for(int iT=1;iT<=T;iT++){
        int R,C,N;
        fin>>R>>C>>N;
        fout<<"Case #"<<iT<<": "<<solve(R,C,N)<<endl;
    }
	return 0;
}
// https://www.youtube.com/watch?v=BZfDbYEkd9w
