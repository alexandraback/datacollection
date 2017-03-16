#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct b
{
    char c;
    int v;
};

struct _less
{
     bool operator() (const int x, const int y) const
        {return x<y;}
};

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int t;
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        fout << "Case #" << i + 1 << ": ";
        int n;
        fin >> n;
//        map<char, int> mm;
//        multiset<b, _less> ss;
//        for (int j = 0; j < n; j++)
//        {
//            int x;
//            fin >> x;
//            mm['A' + j] = x;
//        }
//        char c;
//        int m = 0;
//        for (int i : mm)
//        {

//        }
        vector<b> v;
        set<char> se;
        for (int j = 0; j < n; j++)
        {
            int x;
            fin >> x;
            v.push_back({'A' + j, x});
            se.insert('A' + j);
        }
        while (!se.empty())
        {
            int mmax = 0;
            int max1 = 0;
            b bb = {'a', 0};
            b bb1;
            int ii;
            int ii1;
            for (int j = 0; j < n; j++)
            {
                if (v[j].v >= mmax)
                {
                    bb1 = bb;
                    ii1 = ii;
                    max1 = mmax;
                    bb = v[j];
                    ii = j;
                    mmax = v[j].v;

                }
            }
            if (mmax == 1 && se.size() % 2 == 1)
            {
                fout << bb.c << ' ';
                v[ii].v--;
                if (v[ii].v == 0)
                    se.erase(v[ii].c);
            }
            else
            {
                if (max1 == mmax && bb1.v != 0)
                {
                    fout << bb.c << bb1.c << " ";
                    v[ii].v--;
                    if (v[ii].v == 0)
                        se.erase(v[ii].c);
                    v[ii1].v--;
                    if (v[ii1].v == 0)
                        se.erase(v[ii1].c);
                }
                else
                {
                    fout << bb.c << ' ';
                    v[ii].v--;
                    if (v[ii].v == 0)
                        se.erase(v[ii].c);
                }
            }
        }
        fout << '\n';
    }
    return 0;
}

