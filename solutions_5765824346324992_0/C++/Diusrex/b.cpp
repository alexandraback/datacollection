#include <iostream>
#include <vector>

using namespace std;

int barberTime[6];
// Absolute worst case
int position[25 * 25 * 25 * 25 *25 + 25];

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int numBarbers, pos;
        cin >> numBarbers >> pos;
        
        int maxTime = 1;
        for (int i = 0; i < numBarbers; ++i)
        {
            cin >> barberTime[i];
            maxTime *= barberTime[i];
        }
        
        int numUnique = 0;
        
        for (int m = 0; m < maxTime; ++m)
        {
            for (int b = 0; b < numBarbers; ++b)
            {
                if (m % barberTime[b] == 0)
                {
                    position[numUnique] = b;
                    ++numUnique;
                }
            }
        }
        --pos;
        if (pos >= numUnique)
            pos %= numUnique;
        
        cout << "Case #" << t << ": " << position[pos] + 1 << '\n';
    }
}