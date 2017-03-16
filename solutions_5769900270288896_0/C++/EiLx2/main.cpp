#include <iostream>
#include <fstream>
using namespace std;

int R,C,N,T,a[40][40],MIN;

void bck(int x, int y, int cnt){
    if (x>R){
        if (cnt>0) return;
        int i,j,t=0;
        for (i=1; i<=R; i++)
            for (j=1; j<=C; j++)
                if (a[i][j]==1){
                    if (a[i-1][j]==1) t++;
                    if (a[i+1][j]==1) t++;
                    if (a[i][j-1]==1) t++;
                    if (a[i][j+1]==1) t++;
                }
        MIN=min(MIN,t/2);
        return;
    }

    int nx=x,ny=y+1;
    if (ny>C) { ny=1; nx=x+1; }
    bck(nx,ny,cnt);
    a[x][y]=1;
    bck(nx,ny,cnt-1);
    a[x][y]=0;
}

int main(){
    ifstream fin("input.in");
    ofstream fout("output.out");
    fin >> T;

    int i,k,t;
    for (t=1; t<=T; t++){
        fin >> R >> C >> N;
        fout << "Case #" << t <<": ";

        MIN=1000000;
        bck(1,1,N);
        fout << MIN << "\n";
    }
    return 0;
}
