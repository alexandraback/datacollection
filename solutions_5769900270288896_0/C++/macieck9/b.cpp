#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        int r,c,n;
        cin >> r >> c >> n;
        int z = r*c;
        int ans = 1000000;
        for (int i = 0; i < (1<<z); i++)
        {
            if (__builtin_popcount(i) != n) continue;
            int u = 0;
            for (int j = 0; j < z; j++)
            {
                if ((i&(1<<j)) == 0) continue;
                if (j%c != 0) if ((i&(1<<(j-1)))) u++;
                if (j%c != c-1)  if((i&(1<<(j+1)))) u++;
                if (j/c != 0)  if((i&(1<<(j-c)))) u++;
                if (j/c != r-1)  if((i&(1<<(j+c)))) u++;
            }
            ans = min(ans,u/2);
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    
    
    return 0;
}
