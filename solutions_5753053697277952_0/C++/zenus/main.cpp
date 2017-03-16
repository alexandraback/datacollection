#include <bits/stdc++.h>

using namespace std;

int tests , T , n , i , a , m;
priority_queue < pair < int , int > > ip;
pair < int , int > x , y;

int main()
{
freopen("test.in" , "r" , stdin);
freopen("test.out" , "w" , stdout);

cin >> tests;
for (T = 1 ; T <= tests ; ++T)
{
    cin >> n;
    m = 0;

    for (i = 0 ; i < n ; ++i)
    {
        cin >> a;
        ip.push(make_pair(a , i));

        m += a;
    }

    cout << "Case #" << T << ": ";

    while (ip.size())
    {
        x = ip.top();
        ip.pop();
        y = ip.top();
        ip.pop();

        m--;
        if (y.first > m / 2)
        {
            m--;
            x.first-- , y.first--;
            cout << (char)('A' + x.second) << (char)('A' + y.second) << " ";

            if (x.first) ip.push(x);
            if (y.first) ip.push(y);
        }
        else
        {
            x.first--;
            cout << (char)('A' + x.second) << " ";

            ip.push(y);
            if (x.first) ip.push(x);
        }
    }

    cout << '\n';
}


return 0;
}
