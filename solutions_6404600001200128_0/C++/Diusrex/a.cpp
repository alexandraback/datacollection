#include <iostream>
#include <vector>

using namespace std;

int numbers[10005];

int main()
{
    int T;
    
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        
        int differenceSum = 0, constantRate = 0;
        int largestDifference = 0;
        
        cin >> numbers[0];
            
        for (int i = 1, pos = 0; i < N; ++i, ++pos)
        {
            cin >> numbers[i];
            int difference = numbers[i - 1] - numbers[i];
            
            differenceSum += max(difference, 0);
            
            if (difference > largestDifference)
                largestDifference = difference;
        }
        
        if (largestDifference)
        {
            for (int i = 0; i < N - 1; ++i)
            {
                constantRate += min(numbers[i], largestDifference);
            }
        }
        cout << "Case #" << t << ": " << differenceSum << ' ' << constantRate << '\n';
    }
}