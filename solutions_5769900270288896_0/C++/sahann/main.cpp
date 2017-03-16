#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


#include <fstream>
//#include <iostream>
using namespace std;

ifstream cin("/users/naginahas/Downloads/GCJ2015round1B/B-small-attempt0.in");
ofstream cout("/users/naginahas/Documents/Codeforces205/GCJ2015Round1BProbB/Bsmallout.txt");



int grid[100][100];
int evalg(int R,int C){
    int sum=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            for(int k=-1;k<=1;k++){
                for(int m = -1;m<=1;m++){
                    if(abs(k)+abs(m)==1){
                        if(0<=i+k && i+k<R){
                            if(0<=j+m&&  j+m <C){
                                if(grid[i+k][j+m]=='x'&&grid[i][j]=='x'){
                                    sum++;
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }
    return sum/2;
    
}
int best = 1000*1000;
int f(int R,int C,int curi, int curj, int curn,int N){
    if(curi == R && curj == 0){
        if(curn!=N) return 0;
        int cand = evalg(R,C);
        best = min(best,cand);
        return 0;
    }
    int nexti, nextj;
    if(curj==C-1) {
        nexti = curi+1;
        nextj=0;
    }
    else{
        nexti = curi;
        nextj = curj+1;
    }
    grid[curi][curj] = 'x';
    f(R,C,nexti,nextj,curn+1,N);
    grid[curi][curj] = 'o';
    f(R,C,nexti, nextj,curn,N);
    return 0;
    
    
}

int main(){
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int R,C, N;
        cin >> R >> C >> N;
        best = 1000*1000;
        f(R,C,0,0,0,N);
        cout << "Case #" << t+1 << ": " << best << endl;
    }
    return 0;
}