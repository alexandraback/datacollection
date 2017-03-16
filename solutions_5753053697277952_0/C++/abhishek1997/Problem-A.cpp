#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define eps 1e-13
#define endl '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pcc pair<char, char>
#define mp make_pair
#define F first
#define S second
#define pb push_back
ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
ll modx(ll Base,ll exponent)
{
	ll ans = 1;
	while(exponent)
	{
		if(exponent & 1)
			ans = (ans * Base)%mod;
		Base = (Base * Base)%mod;
		exponent = exponent >> 1;
	}
	return ans;
}
bool cmp()
{

}
int a[26];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-0.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t, i, n, j, k, m;
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];
        cout << "Case #" << j << ": ";
        if(n == 2)
        {
            for(i = 0; i < a[0]; i++)
                cout << "AB ";
            cout << '\n';
            continue;
        }
        m = 0;
        while(m != 1)
        {
            m = 0;
            k = 0;
            for(i = 0; i < n; i++)
            {
                if(a[i] > m)
                {
                    m = a[i];
                    k = i;
                }
            }
            if(m == 1)
            {
                if(n % 2 == 0)
                {
                    for(i = 0; i < n; i+=2)
                        cout << char(i+65) << char(i+66) << " ";
                }
                else
                {
                    cout << char(65) << " ";
                    for(i = 1; i < n; i+=2)
                        cout << char(i+65) << char(i+66) << " ";
                }
                break;
            }
            a[k]--;
            cout << char(k + 65) << " ";
        }
        cout << '\n';
    }
	return 0;
}
