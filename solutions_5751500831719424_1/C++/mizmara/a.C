#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string reduce(string full, vector<int> & count)
{
    string result = "";
    char last = full[0];
    int c = 1;
    result += last;
    for(int i = 1; i < full.length(); ++i)
    {
        ++c;
        if(full[i] == last)
            continue;
        --c;

        count.push_back(c);
        last = full[i];
        result += last;
        c = 1;
    }
    count.push_back(c);
    return result;
}

int getMinDiffs(vector<vector<int> > counts)
{
    int best = 0;
    for(int k = 0; k < counts[0].size(); ++k)
    {
        int min = -1;
        for(int j = 1; j <= 100; ++j)
        {
            int count = 0;
            for(int i = 0; i < counts.size(); ++i)
            {
                count += abs(counts[i][k] - j);
            }

            if(min == -1 || count < min)
                min = count;
        }

        best += min;
    }

    return best;
}

int main()
{
    int numTests, numStrings;
    cin >> numTests;

    for(int t = 0; t < numTests; ++t)
    {
        cin >> numStrings;
        vector<string> strings(numStrings);

        vector<vector<int> > counts;
        bool possible = true;
        string order = "";
        for(int i = 0; i < numStrings; ++i)
        {
            cin >> strings[i];
            vector<int> count;
            if(order == "")
                order = reduce(strings[i], count);

            count.clear();
            if(order != reduce(strings[i], count))
                possible = false;
            counts.push_back(count);
        }

        cout << "Case #" << t+1 << ": ";
        if(!possible)
        {
            cout << "Fegla Won" << endl;
            continue;
        }

        int result = getMinDiffs(counts);

        cout << result << endl;
    }
    return 0;
}
