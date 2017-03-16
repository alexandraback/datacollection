#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T, winner, runnerup, N, sum, A, B, x;
vector<pair<int, int> > V;

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        sum = 0;
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
            cin >> x;
            sum = sum + x;
            V.push_back(make_pair(x, i));
        }
        
        cout << "Case #" << t << ": ";
        while(sum > 0)
        {
            sort(V.rbegin(), V.rend());
            string str;
            winner = V[0].second;
            A = V[0].first;
            B = 0;
            runnerup = 0;
            if(V.size() > 1)
            {
                runnerup = V[1].second;
                B = V[1].first;
            }
            
            if(A > 0)
            {
                str.push_back(winner + 'A' - 1);
                sum--;
                V[0].first = V[0].first - 1;
                A = A - 1;
                if(A > B)
                {
                    B = A;
                    runnerup = winner;
                }
            }
            if(B > 0 && min(V[0].first, V[1].second) * 2 <= sum && sum != 2)
            {
                str.push_back(runnerup + 'A' - 1);
                sum--;
                if(runnerup == winner)
                    V[0].first = V[0].first - 1;
                else
                    V[1].first = V[1].first - 1;
                
            }
            
            cout << str << " ";
        }
        cout << "\n";
    }
    return 0;
}
