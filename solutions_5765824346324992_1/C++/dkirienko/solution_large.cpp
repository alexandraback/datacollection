#include<iostream>
#include<set>
#include<vector>

using namespace std;

const int MAX = 2000000;


int solve()
{
    int n, b, i, m;
    cin >> b >> n;
    vector<int> M(b);
    set<pair<long long, int> > S;
    pair<long long, int> t;
    for (i = 0; i < b; ++i)
    {
        cin >> M[i];
    }
    if (n <= MAX)
    {
        for (i = 0; i < b; ++i)
            S.insert(make_pair(0, i));
    }
    else
    {
        n -= MAX;
        // Ищем время, за которое можно обслужить полностью n покупателей
        long long left = 0;
        long long right = (long long) n * 1000000;
        while (left + 1 < right)
        {
            long long middle = (left + right) / 2;
            long long count = 0;
            for (i = 0; i < b; ++i)
                count += middle / M[i];
            if (count >= n)
                right = middle;
            else
                left = middle;
        }
        long long start_time = right;
        for (i = 0; i < b; ++i)
        {
            int c = start_time / M[i];
            n -= c;
            S.insert(make_pair(c * M[i], i));
        }
        n += MAX;
    }
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
