#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int allTot, n;
string s[505];
char P[505][505];
int N[505][505];

void compress(int w)
{
    string cs = "$" + s[w];
    int len = cs.size();

    int tot(0), num(0);
    for (int i = 1; i < len; ++i)
    {
        if (cs[i] != cs[i - 1])
        {
            ++tot;
            P[w][tot] = cs[i - 1];
            N[w][tot] = num;
            num = 0;
        }
        ++num;
    }
    ++tot;
    P[w][tot] = cs[len - 1];
    N[w][tot] = num;

    allTot = max(allTot, tot);
}

bool checkSame()
{
    for (int i = 1; i <= allTot; ++i)
        for (int j = 2; j <= n; ++j)
            if (P[j][i] != P[j - 1][i])
                return false;
    return true;
}

int abs(int x)
{
    if (x < 0) return -x;
    return x;
}

int calc()
{
    int res(0), num[505];
    for (int i = 1; i <= allTot; ++i)
    {
        for (int j = 1; j <= n; ++j)
            num[j] = N[j][i];
        sort(num + 1, num + n + 1);
        int mid = num[(n + 1) / 2];
        for (int j = 1; j <= n; ++j)
            res += abs(num[j] - mid);
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int Cas = 1; Cas <= T; ++Cas)
    {
        cin >> n;

        allTot = 0;
        memset(N, 0, sizeof(N));

        for (int i = 1; i <= n; ++i)
        {
            cin >> s[i];
            compress(i);
        }
        cout << "Case #" << Cas << ": ";
        if (checkSame())
            cout << calc() << endl;
        else
            cout << "Fegla Won" << endl;
    }
    return 0;
}
