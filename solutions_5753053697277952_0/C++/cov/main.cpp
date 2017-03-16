#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int T;
int n;

char tochar(int arg)
{
    return char(arg + 65);
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> T;

    for (int t = 0; t < T; ++t)
    {
        in >> n;
        vector<int> s;
        int total = 0;

        for (int i = 0; i < n; ++i)
        {
            int p;
            in >> p;
            total += p;
            s.push_back(p);
        }

        out << "Case #" << t + 1 << ": ";

        int k = 0;
        while (total > 0)
        {
            int idx = distance(s.begin(), max_element(s.begin(), s.end()));
            k++;

            if (k == 2 || (s[idx] == 1 && total > 2))
            {
                k = 0;
                out << tochar(idx) << " ";
            }
            else if (k == 1)
            {
                out << tochar(idx);
            }

            s[idx]--;
            total--;
        }

        out << endl;
    }

    in.close();
    out.close();
}