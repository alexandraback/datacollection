#include <iostream>
#include <vector>
using namespace std;

bool any(vector<int>& hist)
{
    for (int i = 0; i < hist.size(); ++i)
    {
        if (hist[i] > 0) return true;
    }
    return false;
}

int findMax(vector<int>& hist)
{
    int m = -1;
    int j = -1;
    for (int i = 0; i < hist.size(); ++i)
    {
        if (hist[i] > m)
        {
            m = hist[i];
            j = i;
        }
    }
    return j;
}

bool isValid(vector<int>& hist, int total)
{
    for (int i = 0; i < hist.size(); ++i)
    {
        if (hist[i] * 2 > total)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int numParties;
        cin >> numParties;
        vector<int> hist;
        int total = 0;
        for (int p = 0; p < numParties; ++p)
        {
            int v;
            cin >> v;
            total += v;
            hist.push_back(v);
        }
        cout << "Case #" << i+1 << ": ";
        while (true)
        {
            int maxIndex = findMax(hist);
            hist[maxIndex]--;
            total--;
            cout << char('A' + maxIndex);
            if (!isValid(hist, total))
            {
                maxIndex = findMax(hist);
                hist[maxIndex]--;
                total--;
                cout << char('A' + maxIndex);
            }
            if (any(hist))
            {
                cout << ' ';
            }
            else
            {
                cout << endl;
                break;
            }
        }
    }
}