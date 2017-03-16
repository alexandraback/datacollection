#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int t;
void solve()
{
    int N;
    cin >> N;

    int cur[N] = {0};
    int total = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> cur[i];
        total += cur[i];
    }

    bool three = total == 3;


    while(three || total > 4)
    {
        if(N == 2 && cur[0] == cur[1])
        {
            cout << "AB ";
            cur[0] -= 1;
            cur[1] -= 1;
            total -= 2;
            continue;
        }
        three = false;
        int largest = 0;
        int l = 0;
        for(int i = 0; i < N; i++)
        {
            if(cur[i] > largest)
            {
                largest = cur[i];
                l = i;
            }
        }
        cout << char('A' + l) << ' ';
        total -= 1;
        cur[l] -= 1;

        for(int i = 0; i < N; i++)
        {
            if(cur[i] > total/2)
            {
                cerr << "case " << t << "\n";
                cerr << "Failed " << cur[i] << " " << i << " " << total << "\n";
            }
        }

    }

    while(total > 0)
    {
        int a = -1, b = -1;
        for(int i = 0; i < N; i++)
        {
            if(cur[i])
            {
                if(a == -1)
                    a = i;
                else if(b == -1)
                    b = i;
                else if(a != -1 && b != -1 && cur[i] > 1)
                    a = i;
            }
        }
        cout << char('A'+a) << char('A'+b) << ' ';
        cur[a] -= 1;
        cur[b] -= 1;
        total -= 2;
        for(int i = 0; i < N; i++)
        {
            if(cur[i] > total/2)
                cerr << "Failed " << cur[i] << " " << i << " " << total << "\n";
        }
    }
    

}

int main()
{
    cout.precision(8);
    int T;
    cin >> T;
    for(t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

