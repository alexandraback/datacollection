#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream& operator << (ostream& o, vector<T>& v)
{
    o << "[";
    for(size_t i = 0; i < v.size(); i++)
    {
        o << v[i];
        if(i != v.size() - 1)
            o << ", ";
    }
    o << "]";
    return o;
}

typedef vector<short> vs;
typedef vector<vs> vvs;
typedef map<short, int> msi;

#define set_bit(var, bit) \
var = var | (1 << bit);

#define get_bit(var, bit) \
((1 << bit) & var)

int map_in_bit(int r, int c, int row_length)
{
    return c*row_length+r;
}

int count_mines(short m)
{
    int c = 0;
    for(int i = 0; i < 16; i++)
    {
        if((1 << i) & m)
            c++;
    }
    return c;
}

int count_collisions(short m, int r, int c)
{
    int coll = 0;
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r - 1; j++)
        {
            if(((1 << map_in_bit(j, i, r)) & m) && ((1 << map_in_bit(j+1, i, r)) & m))
                coll++;
        }
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c - 1; j++)
        {
            if(((1 << map_in_bit(i, j, r)) & m) && ((1 << map_in_bit(i, j+1, r)) & m))
                coll++;
        }
    }
    return coll;
}

int calc(short state, int& n, int& r, int& c, msi& m)
{
    if(m.count(state))
        return m[state];
    if(count_mines(state) == n)
    {
        return m[state] = count_collisions(state, r, c);
    }
    int min_roba = INT_MAX;
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++)
        {
            if(!((1 << map_in_bit(j, i, r)) & state))
            {
                short tmp_state = state | (1 << map_in_bit(j, i, r));
                min_roba = min(min_roba, calc(tmp_state, n, r, c, m));
            }
        }
    }
    return m[state] = min_roba;
}

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int n_casi;
    cin >> n_casi;
    int input[n_casi+1][3];
    int soluzione[n_casi + 1];
    for(int caso = 1; caso <= n_casi; caso++)
    {
        for(int i = 0; i < 3; i++)
            cin >> input[caso][i];
    }
    #pragma omp parallel for schedule(dynamic)
    for(int caso = 1; caso <= n_casi; caso++)
    {
        int r = input[caso][0];
        int c = input[caso][1];
        int n = input[caso][2];
        msi sol;
        short init = 0;
        soluzione[caso] = calc(init, n, r, c, sol);
        cerr << "Case #" << caso << ": " << soluzione[caso] << endl;
    }
    for(int caso = 1; caso <= n_casi; caso++)
        cout << "Case #" << caso << ": " << soluzione[caso] << endl;
    return EXIT_SUCCESS;
}
