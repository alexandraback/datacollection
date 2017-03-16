#include <iostream>
#include <fstream>
using namespace std;
fstream fin("b1.in");
fstream fout("output.txt");
int place[16], answer;
int r,c,m;
int calc() {
    int cc=0;
    for (int i=0;i<r*c;i++)
        if (place[i])
        {
            if (i<(c-1)*r) cc+=place[i+r];
            if ((i%r)<r-1) cc+=place[i+1];
        }
    return cc;
    }
int sea(int i,int re) {
    if (re==0) return (calc());
    if (i==r*c) return r*c*10;
    place[i] = 0;
    int ans = sea(i+1,re);
    place[i] = 1;
    return (min(ans,sea(i+1,re-1)));
}
int calc(int m) {
    if (m*2<=r*c) return 0;
    return sea(0,m);
}
int main() {
    int t;
    fin >> t;
    for (int i=0;i<t;i++)
        {
            fin >> r >> c >> m;
            fout << "Case #" << i+1 << ": " << calc(m) << endl;
        }
    fin.close();
    fout.close();
}
