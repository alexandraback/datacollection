#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

pair<string, vector<int>> coalesce(const string& s)
{
    string word;
    vector<int> num;
    auto it = s.begin();
    while(it != s.end())
    {
        word += *it;
        auto nxt = find_if(it, s.end(), [&](char c) -> bool { return (c != *it);});
        num.push_back(nxt - it);
        it = nxt;
    }
    
    return make_pair(word, num);
}

int main()
{
    int t;
    cin >> t;
    for(int lp=1;lp<=t;++lp)
    {
        cout << "Case #" << lp << ": ";
        int n;
        cin >> n;
        vector<string> words(n);
        for(auto& s : words)
        {
            cin >> s;
        }
        
        vector<pair<string, vector<int>>> coalesced(n);
        transform(words.begin(), words.end(), &coalesced[0], coalesce);
        
        if(!all_of(coalesced.begin(), coalesced.end(), [&](const pair<string, vector<int>>& p) -> bool { return (p.first == coalesced[0].first);}))
        {
            cout << "Fegla Won\n";       
        }
        else
        {
            int ret = 0;
            int m = coalesced[0].second.size();
            for(size_t i=0;i<m;++i)
            {
                vector<int> v(n);
                transform(coalesced.begin(), coalesced.end(), &v[0], [&](const pair<string, vector<int>>& p) -> int { return p.second[i];});
                sort(v.begin(), v.end());
                for(auto& x : v)
                {
                    ret += abs(x - v[n/2]);         
                }
            }
            
            cout << ret << "\n";
        }
        
    }
    return 0;
}