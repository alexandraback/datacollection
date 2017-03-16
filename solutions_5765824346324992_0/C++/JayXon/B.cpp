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

uint64_t gcd(uint64_t n1, uint64_t n2)
{
    while (n2)
        swap(n1 %= n2, n2);
    return n1;
}

void solve_case(ifstream &fin, ofstream &fout)
{
    int b, n, y = 0;
    fin >> b >> n;
    int m[b];
    for (auto &i : m)
        fin >> i;
    uint64_t lcm = m[0], l = 0;
    for (int i = 1; i < b; i++) {
        lcm = (lcm * m[i]) / gcd(lcm, m[i]);
    }
    for (int i = 0; i < b; i++) {
        l += lcm / m[i];
        if (l > n)
            break;
    }
    n = (n - 1) % l;
    int t[b];
    for (int i = 0; i < b; i++) {
        t[i] = m[i];
        y = i;
        if (--n < 0)
            break;
    }
    while (n >= 0) {
        for (int i = 0; i < b; i++) {
            if (--t[i] == 0) {
                t[i] = m[i];
                y = i;
                if (--n < 0)
                    break;
            }
        }

    }


    fout << y+1 << endl;
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