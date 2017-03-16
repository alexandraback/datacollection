#include <bits/stdc++.h>

#define SZ(x) ((int(x.size())))

using namespace std;

const int maxn = 26;
int t, p, T[maxn], tmp1, tmp2;
set <pair <int, int> > s;

int main()
{
    ifstream in;
    ofstream out;
    in.open ("A-large.in", ios::in);
    out.open ("A-large.out", ios::out);
    in >> t;
    for (int i = 0; i < t; i++)
    {
        in >> p;
        for (int j = 0; j < p; j++)
        {
            in >> T[j];
            s.insert (make_pair (T[j], j));
        }
        out << "Case #" << i + 1 << ": ";
        while (!s.empty())
        {
            if (SZ(s) == 2 && s.begin() -> first == s.rbegin() -> first)
            {
                out << char (65 + s.begin() -> second) << char (65 + s.rbegin() -> second) << " ";
                T[s.begin() -> second]--;
                T[s.rbegin() -> second]--;
                if (T[s.begin() -> second] == 0)
                    break;
                else
                {
                    tmp1 = s.begin() -> second;
                    tmp2 = s.rbegin() -> second;
                    s.clear();
                    s.insert(make_pair (T[tmp1], tmp1));
                    s.insert(make_pair (T[tmp2], tmp2));
                }
            }
            else
            {
                out << char (65 + s.rbegin() -> second) << " ";
                tmp1 = s.rbegin() -> second;
                T[tmp1]--;
                s.erase (make_pair (s.rbegin() -> first, s.rbegin() -> second));
                if (T[tmp1] > 0)
                    s.insert (make_pair (T[tmp1], tmp1));
            }
        }
        s.clear();
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}
