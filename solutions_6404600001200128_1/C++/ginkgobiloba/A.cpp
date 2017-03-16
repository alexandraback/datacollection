#include <iostream>
#include <vector>
using namespace std;

int method1(int n, const vector<int>& m)
{
    int s = 0;
    for (int i = 1; i < n; ++i)
        if (m[i] < m[i - 1])
            s += m[i - 1] - m[i];
    return s;
}

int method2(int n, const vector<int>& m)
{
    int r = 0, s = 0;
    for (int i = 1; i < n; ++i)
        if (m[i] < m[i - 1])
        {
            int t = m[i - 1] - m[i];
            r = r > t ? r : t;
        }
    for (int i = 0; i < n - 1; ++i)
        s += m[i] < r ? m[i] : r;
    return s;
}

int main()
{
    int cases;
    cin >> cases;
    for (int t = 1; t <= cases; ++t)
    {
        int n;
        cin >> n;
        vector<int> m;
        m.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> m[i];
        cout << "Case #" << t << ": " << method1(n, m) << " " << method2(n, m) << endl;
    }
    return 0;
}
