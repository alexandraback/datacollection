#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

void calculate(const int &n, const vector<string> &words)
{
    vector<vector<pair<char, int> > > tokens(n);
    for(int i=0; i<n; ++i)
    {
        tokens[i].push_back(make_pair(words[i][0], 1));
        for(int j=1; j<words[i].length(); ++j)
        {
            if(words[i][j] == words[i][j-1])
                tokens[i][tokens[i].size()-1].second += 1;
            else
                tokens[i].push_back(make_pair(words[i][j], 1));
        }
    }

    /*for(int i=0; i<n; ++i)
    {
        for(int j=0; j<tokens[i].size(); ++j)
            cout<<tokens[i][j].first<<tokens[i][j].second;
        cout<<endl;
    }*/

    bool valid = true;
    for(int i=1; i<n; ++i)
    {
        if(tokens[i].size() != tokens[0].size())
        {
            valid = false;
            break;
        }
        for(int j=0; j<tokens[i].size(); ++j)
            if(tokens[i][j].first != tokens[0][j].first)
            {
                valid = false;
                break;
            }
    }
    if(!valid)
    {
        cout<<"Fegla Won"<<endl;
        return;
    }
    int ans = 0;

    for(int i=0; i<tokens[0].size(); ++i)
    {
        int minimum = -1;
        for(int j=1; j<=100; ++j)
        {
            int tmp = 0;
            for(int k=0; k<n; ++k)
            {
                tmp += abs(tokens[k][i].second - j);
            }
            if(minimum == -1 || minimum > tmp)
                minimum = tmp;
        }
        ans+=minimum;
    }

    cout<<ans<<endl;
}

int main()
{
    int numOfCases;
    cin>>numOfCases;
    for(int t=1; t<=numOfCases; ++t)
    {
        cout<<"Case #"<<t<<": ";
        int n;
        cin>>n;
        vector<string> words(n);
        for(int i=0; i<n; ++i)
            cin>>words[i];
        calculate(n, words);
    }
    return 0;
}
