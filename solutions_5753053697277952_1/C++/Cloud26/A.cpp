#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define eps 1e-9
#define PB push_back
#define LL long long
#define INF 0x3f3f3f3f

template<class T> void checkMax(T &a, T b)
{
    a = max(a, b);
}
template<class T> void checkMin(T &a, T b)
{
    a = min(a, b);
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--)
    {
        int n, cnt[26], sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> cnt[i];
            sum += cnt[i];
        }
        cout << "Case #" << cas++ << ":";
        while(sum > 0)
        {
            for(int i = 2; i >= 1; i--)
            {
                int next_sum = sum - i;
                string moves = "";
                for(int j = 0; j < n; j++)
                {
                    if(cnt[j] > next_sum / 2)
                        moves = moves.append(cnt[j] - next_sum / 2, 'A' + j);
                }
                if(moves.size() <= i)
                {
                    for(int j = 0; j < moves.size(); j++)
                        cnt[moves[j] - 'A']--;
                    for(int j = 0; j < n; j++)
                    {
                        while(cnt[j] > 0 && moves.size() < i)
                        {
                            moves.append(1, 'A' + j);
                            cnt[j]--;
                        }
                    }
                    sum -= moves.size();
                    cout << " " << moves;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
