#include<iostream>
#include<set>
#include<vector>

using namespace std;

int gcd(int a, int b)
{
    while (b > 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int nok(int a, int b)
{
    return a * b / gcd (a, b);
}

int solve()
{
    int n, b, i, m, p, per;
    cin >> b >> n;
    vector<int> M(b);
    set<pair<long long, int> > S;
    pair<long long, int> t;
    p = 1;
    for (i = 0; i < b; ++i)
    {
        cin >> M[i];
        S.insert(make_pair(0, i));
        p = nok(p, M[i]);
    }
    per = 0;
    for (i = 0; i < b; ++i)
        per += p / M[i];
    n %= per;
    if (n == 0)
        n = per;
    for (i = 0; i < n - 1; ++i)
    {
        t = *S.begin();
        S.erase(S.begin());
        t.first += M[t.second];
        S.insert(t);
    }
    return S.begin() -> second + 1;
}

int main()
{
    int T,t;
    cin >> T;
    for (t = 1; t <= T; ++t)
        cout << "Case #" << t << ": " << solve() << endl;
}
