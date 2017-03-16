#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;


void solve_case(ifstream &fin, ofstream &fout)
{
    int n, x = 0, y = 0, md = 0;
    fin >> n;
    int m[n];
    for (auto &i : m)
        fin >> i;
    for (int i = 1; i < n; i++) {
        if (m[i] < m[i - 1]) {
            x += m[i - 1] - m[i];
            md = max(md, m[i - 1] - m[i]);
        }
    }
    for (int i = 0; i < n-1; i++) {
        y += min(m[i], md);
    }

    fout << x << ' ' << y << endl;
}


int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name)-2] = 0;
    strcat(name, "out");
    ofstream fout(name);

    if (!fin.is_open() || !fout.is_open())
        return 1;

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t) {
        cerr << "Solving case " << t1 << endl;
        fout << "Case #" << t1 << ": ";
        solve_case(fin, fout);
    }

    return 0;
}