#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
int n;
vector<int> a;
int method_one()
{
    vector<int> b(a);
    int current = b.front();
    int ans = 0;
    b.erase(b.begin());
    for (auto it = b.begin() ; it != b.end() ; ++it)
    {
        int val = *it;
        if (val < current)
            ans += current - val;
        current = val;
    }
    return ans;
}

int method_two()
{
    vector<int> b(a);
    int ans = 0;
    int speed = 0;
    int current = b.front();
    int start = current;
    b.erase(b.begin());
    for (auto it = b.begin() ; it != b.end() ; ++it)
    {
        int val = *it;
        speed = max(current - val , speed);
        current = val;
    }
    current = start;
    for (auto it = b.begin() ; it != b.end() ; ++it)
    {
        int val = *it;
        assert(current - val <= speed);
        ans += min(speed,  current);
        current = val;
    }
    return ans;
}
void process(int test_case)
{
    cin >> n;
    a.clear();
    for (int i = 0 ; i < n ; ++i)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    cout << "Case #" << test_case << ": " << method_one() << " " << method_two() << endl;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0 ; i < t ; ++i)
        process(i + 1);
    return 0;
}