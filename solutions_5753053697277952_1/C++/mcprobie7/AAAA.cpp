#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, char> a[26];



int main()
{
    freopen("A-large.in","r",stdin);
    freopen("AAAAlarge.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int iT  = 1; iT <= T; iT++)
    {


    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        a[i] = make_pair(k, (char) ('A' + i));

    }
    printf("Case #%d:", iT);
    while  (1)
    {
        sort(a, a + n);
        if (a[n - 1].first > 0)
        {
            if (a[n - 1].first >= (a[n - 2].first + 2)) { a[n - 1].first -= 2; printf(" %c%c", a[n - 1].second, a[n - 1].second); }
            else if (a[n - 1].first >= (a[n - 2].first + 1)) { a[n - 1].first--; printf(" %c", a[n - 1].second); }
            else if (n == 2) { a[n -1].first--; a[n-2].first--; printf(" %c%c", a[n - 1].second, a[n - 2].second); }
            else if (a[n - 3].first <= (a[n - 1].first + a[n - 2].first - 2))
            {

               a[n-1].first--; a[n-2].first--; printf(" %c%c", a[n - 1].second, a[n - 2].second);

            }
            else { a[n - 1].first--; printf(" %c", a[n - 1].second); }
        }
        else break;
    }
    printf("\n");


    }
    return 0;
}
