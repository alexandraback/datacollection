#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void func(ifstream& in, ofstream& out)
{
    int r, tmp, count = 0, res;
    int cnt[17] = {0};

    for (int k = 0; k < 2; k++)
    {
        in >> r;
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
            {
                in >> tmp;
                if (i == r)
                    cnt[tmp]++;
            }
    }
    for (int i = 1; i <= 16; i++)
        if (cnt[i] == 2)
        {
            count++;
            res = i;
        }
    if (count < 1)
        out << "Volunteer cheated!" << endl;
    else if (count > 1)
        out << "Bad magician!" << endl;
    else
        out << res << endl;
}

int main()
{
    ifstream in;
    in.open("A-small-attempt0.in");

    ofstream out;
    out.open("code_jam_out");
    //out << fixed << showpoint << setprecision(7);

    int T;
    in >> T;

    for (int t = 1; t <= T; t++)
    {
        //cout << "Case #" << t << endl;
        out << "Case #" << t << ": ";
        func(in, out);
    }

    in.close();
    out.close();

    return 0;
}
