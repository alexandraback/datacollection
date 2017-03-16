#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
#define int ll
int gcd(int a , int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int n , m;
int a[1000];
int count_valid(int b , int cnt)
{
    int base = a[b];
    int epl = base * cnt;
    int total = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        total += epl / a[i] + ( i < b || epl % a[i] > 0);
    }
    return total;
}
bool check_valid(int b)
{
    int l = 0;
    int r = m;
    int last = (l + r) / 2;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int ret = count_valid(b, mid);
        if (ret >= m - 1)
        {
            last = mid;
            r = mid - 1;
            if (ret == m - 1)
                return true;
        } else
            l = mid + 1;
    }
    return count_valid(b, last) == m - 1;
}
void process(int test_case)
{
    cin >> n >> m;
    if (n >= m) {
        cout << "Case #" << test_case << ": " << m << endl;
        return ;
    }
    for (int i = 0 ; i < n ; ++i)
        cin >> a[i];
    for (int i = 0 ; i < n ; ++i)
        if (check_valid(i))
        {
            cout << "Case #" << test_case << ": " << i + 1<< endl;
            return ;
        }
    assert(!"FUCK YOU");
    
}
#undef int
int main()
{
    int t;
    cin >> t;
    for (int i = 0 ; i < t ; ++i)
        process(i + 1);
    return 0;
}