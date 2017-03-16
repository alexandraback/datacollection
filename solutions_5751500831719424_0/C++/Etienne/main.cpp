#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void testCase()
{
    int numstrings;
    cin >> numstrings;
    cin.ignore(1, '\n');
    vector<string> strings;
    vector<int> idx;
    for(int i=0; i<numstrings; i++)
    {
        string s;
        getline(cin, s);
        strings.push_back(s);
        idx.push_back(0);
    }

    int moves=0;
    while(true)
    {
        if(idx[0] == strings[0].length())
        {
            for(int i=1; i<numstrings; i++)
            {
                if(idx[i] != strings[i].length())
                {
                    cout << " Fegla Won" << endl;
                    return;
                }
            }
            cout << " " << moves << endl;
            return;
        }

        char c = strings[0][idx[0]];
        vector<int> repeats;
        for(int i=0; i<numstrings; i++)
        {
            int repeat = 0;
            if(idx[i] == strings[i].length())
            {
                cout << " Fegla Won" << endl;
                return;
            }
            while(strings[i][idx[i]] == c)
            {
                idx[i]++;
                repeat++;
            }
            if(repeat == 0)
            {
                std::cout << " Fegla Won" << endl;
                return;
            }
            repeats.push_back(repeat);
        }
        int bestmoves = numeric_limits<int>::max();
        for(int i=0; i<numstrings; i++)
        {
            int totmoves = 0;
            for(int j=0; j<numstrings; j++)
            {
                totmoves += abs(repeats[j]-repeats[i]);
            }
            if(totmoves < bestmoves)
                bestmoves = totmoves;
        }
        moves += bestmoves;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cout << "Case #" << i+1 << ":";
        testCase();
    }
}


