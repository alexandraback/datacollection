#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;
int happiness(vector<int> ts, int C, int R)
{
    int h = 0;
    // verticals
    for(int c=0; c<C-1; ++c)
        for(int r=0; r<R; ++r)
        {
            if(find(ts.begin(), ts.end(), r*C+c) != ts.end()
                    &&find(ts.begin(), ts.end(), r*C+c+1) != ts.end())
                h++;
        }
    // horizontals
    for(int c=0; c<C; ++c)
        for(int r=0; r<R-1; ++r)
        {
            if(find(ts.begin(), ts.end(), r*C+c) != ts.end()
                    &&find(ts.begin(), ts.end(), (r+1)*C+c) != ts.end())
                h++;
        }
    return h;
}

int main()
{
    ifstream fin("../QB/in.txt");
    ofstream fout("../QB/out.txt");
    int T, R, C, N;
    fin >> T;
    for(int i=1; i<=T; ++i)
    {
        fin >> R >> C >> N;
        vector<bool> v(R*C);
        fill(v.begin() + R*C - N, v.end(), true);
        vector<int> ts;
        int h = 10e6;

        do {
            ts.clear();
            for (int i = 0; i < R*C; ++i) {
                if (v[i]) {
                    ts.push_back(i);
                    cout << i;
                }
            }
            int htemp = happiness(ts, C, R);
//            cout << "Temp: " << htemp << endl;
            h = min(h, htemp);
            cout << endl;
        } while (next_permutation(v.begin(), v.end()));

        cout << "Case " << "#" << i << ": " << h << endl;
        fout << "Case " << "#" << i << ": " << h << endl;
    }
    fin.close();
    fout.close();
}
