#include <iostream>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    int z;
    cin >> z;
    for(int t = 1; t <= z; ++t)
    {
        cout << "Case #" << t << ":";
        int tb[26];
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> tb[i];
        while(1)
        {
            int maxi = 0, ct = 0;
            for(int i = 0; i < n; ++i)
            {
                if(tb[i] == maxi) ++ct;
                else if(tb[i] > maxi) maxi = tb[i], ct = 1;
            }
            if(maxi == 0) break;
            if(maxi == 1 && ct == 3)
            {
                for(int i = 0; i < n; ++i)
                {
                    if(tb[i] == maxi)
                    {
                        --tb[i];
                        cout << ' ' << (char)(i+'A');
                        break;
                    }
                }
            }
            else if(ct == 1)
            {
                for(int i = 0; i < n; ++i)
                {
                    if(tb[i] == maxi)
                    {
                        --tb[i];
                        cout << ' ' << (char)(i+'A');
                        break;
                    }
                }
            }
            else
            {
                for(int i = 0; i < n; ++i)
                {
                    if(tb[i] == maxi)
                    {
                        --tb[i];
                        cout << ' ' << (char)(i+'A');
                        break;
                    }
                }
                for(int i = 0; i < n; ++i)
                {
                    if(tb[i] == maxi)
                    {
                        --tb[i];
                        cout << (char)(i+'A');
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
