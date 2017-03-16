#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int m2 = 0x5555;
const int m4 = 0x3333;
const int m8 = 0x0F0F;
const int m16 = 0x00FF;

int cnt(int x)
{
    int x2 = (x & m2) + ((x >> 1) & m2);
    int x4 = (x2 & m4) + ((x2 >> 2) & m4);
    int x8 = (x4 & m8) + ((x4 >> 4) & m8);
    return (x8 & m16) + ((x8 >> 8) & m16);
}

int num(int , int C, int i, int j)
{
    return i * C + j;
}

void solve(const int t)
{
    int R, C, N;
    vector<int> masks;
    int res = 10000000;
    
    cin >> R >> C >> N;
    
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
        {
            if(j + 1 < C)
                masks.push_back((1 << num(R, C, i, j)) | (1 << num(R, C, i, j + 1)));
            if(i + 1 < R)
                masks.push_back((1 << num(R, C, i, j)) | (1 << num(R, C, i + 1, j)));
        }
    /*for(size_t i = 0; i < masks.size(); ++i)
        cerr << masks[i] << " ";
    cerr << "\n";*/
    for(int x = 0; x < (1 << R * C); ++x)
    {
        int tmp = 0;
        if(cnt(x) != N)
            continue;
        for(size_t i = 0; i < masks.size(); ++i)
            if((x & masks[i]) == masks[i])
                ++tmp;
        if(res > tmp)
        {
            //cerr << tmp << " " << x << "\n";
            res = tmp;
        }
    }
    cout << "Case #" << t << ": " << res << "\n";
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        cerr << "Solving #" << t << "\n";
        solve(t);
    }
    return 0;
}
