#include <cstdio>
#include <vector>
#include <set>
#include <climits>

using namespace std;

// int main()
// {
//     int T;
//     scanf("%d", &T);
//     for (int z = 1; z <= T; ++z)
//     {
//         printf("Case #%d: ", z);
//         int n, b;
//         scanf("%d %d", &b, &n);
//         vector <int> a(b);
//         multiset<pair<int, int> > busy;
//         
//         for (int i = 0; i < b; ++i)
//         {
//             scanf("%d", &a[i]);
//             busy.insert(make_pair(0, i));
//         }
//         
//         int cur = 0;
//         for (int i = 0; i < n; ++i)
//         {
//             auto it = busy.begin();
//             cur = it->second;
//             int t = it->first;
//             busy.erase(it);
//             busy.insert(make_pair(t + a[cur], cur));
//         }
//         printf("%d\n", cur + 1);
//     }
//     return 0;
// }

int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 1; z <= T; ++z)
    {
        printf("Case #%d: ", z);
        int n, b;
        scanf("%d %d", &b, &n);
        vector <long long> m(b);
        for (int i = 0; i < b; ++i)
        {
            scanf("%lld", &m[i]);
        }
        
        long long low = -1;
        long long high = 1000000000ll * 1000000ll + 10ll;
        while (low != high - 1)
        {
            long long middle = (low + high) / 2;
            long long numberOf = 0;
            for (int i = 0; i < b; ++i)
            {
                numberOf += (middle + m[i]) / m[i];
            }
            if (numberOf < n)
            {
                low = middle;
            }
            else
            {
                high = middle;
            }
        }
        long long numberOf = 0;
        for (int i = 0; i < b; ++i)
        {
            numberOf += (high + m[i] - 1) / m[i];
        }
        //printf("%lld %lld\n", numberOf, high);
        for (int i = 0; i < b; ++i)
        {
            if (high % m[i] == 0)
            {
                if (numberOf + 1 < n)
                    ++numberOf;
                else
                {
                    printf("%d\n", i + 1);
                    break;
                }
            }
        }
    }
}