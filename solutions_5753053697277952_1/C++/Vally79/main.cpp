#include <iostream>
#include <fstream>
using namespace std;
ifstream ka("A-large.in");
ofstream ki("ceva.out");
const int N_MAX = 1000;
int t, s, n, v[N_MAX + 1];
int main()
{
    ka >> t;
    for(int i = 1; i <= t; i++)
    {
        ka >> n;
        s = 0;
        for(int j = 1; j <= n; j++)
        {
            ka >> v[j];
            s += v[j];
        }
        ki << "Case #" << i << ": ";
        while(s)
        {
            int maxim = -1, poz, poz1;
            for(int j = 1; j <= n; j++)
            {
                if(v[j] > maxim)
                {
                    maxim = v[j];
                    poz = j;
                    poz1 = 0;
                }
                else if(v[j] == maxim)
                    poz1 = j;
            }
            if(poz1 == 0 || maxim <= (s - 1) / 2)
            {
                ki << (char)('A' + poz - 1) << " ";
                s--;
                v[poz]--;
            }
            else
            {
                ki << (char)('A' + poz - 1) << (char)('A' + poz1 - 1) << " ";
                s -= 2;
                v[poz]--;
                v[poz1]--;
            }
        }
        ki << '\n';
    }
}
