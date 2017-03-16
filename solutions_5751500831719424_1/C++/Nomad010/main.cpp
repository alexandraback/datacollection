#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef vector< pair<char, int> > stype;

stype conv(string s)
{
    stype res;
    res.push_back(make_pair(s[0], 1));
    for(int i = 0; i < int(s.size()); ++i)
    {
        if(s[i] == res.back().first)
            res.back().second++;
        else
            res.push_back(make_pair(s[i], 1));
    }
    return res;
}

int main(int argc, char** argv)
{
    int T = 0;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N >> ws;
        vector<string> Si(N);
        for(int i = 0; i < N; ++i)
        {
            cin >> Si[i] >> ws;
//             cout << Si[i] << endl;
        }
            
        vector<stype> canonicals(N);
        for(int i = 0; i < N; ++i)
            canonicals[i] = conv(Si[i]);
        
        bool can_do = true;
        stype max = canonicals[0];
        stype min = canonicals[0];
        
        for(int i = 1; i < N; ++i)
        {
            if(max.size() != canonicals[i].size())
            {
//                 cout << max.size() << " vs " << canonicals[i].size() << endl;
//                 cout << max[i].first << endl;
                can_do = false;
                goto end;
            }
            
            for(int j = 0; j < int(max.size()); ++j)
            {
                if(canonicals[i][j].first != max[j].first)
                {
                    can_do = false;
                    goto end;
                }
                
                if(max[j].second < canonicals[i][j].second)
                    max[j].second = canonicals[i][j].second;
                
                if(min[j].second > canonicals[i][j].second)
                    min[j].second = canonicals[i][j].second;
            }
        }
        end:;
        
        if(can_do)
        {
            int ans = 0;
            
            for(int j = 0; j < int(max.size()); ++j)
            {
                int all_max = 0;
                int all_min = 0;
                
                vector<int> colls;
                for(int i = 0; i < N; ++i)
                {       
                    colls.push_back(canonicals[i][j].second);
                    all_max += (max[j].second - canonicals[i][j].second);
                    all_min += (canonicals[i][j].second - min[j].second);
                }
                
                sort(colls.begin(), colls.end());
                if(colls.size() % 2 == 1)
                {
                    int a1 = 0;
                    for(int i = 0; i < N; ++i)
                        a1 += abs(colls[i] - colls[colls.size()/2]);
                    ans += a1;
                }
                else
                {
                    int a1 = 0;
                    for(int i = 0; i < N; ++i)
                        a1 += abs(colls[i] - colls[colls.size()/2]);
                    int a2 = 0;
                    for(int i = 0; i < N; ++i)
                        a2 += abs(colls[i] - colls[(colls.size()+1)/2]);
                    if(a1 < a2)
                        ans += a1;
                    else
                        ans += a2;
                }
                
//                 cout << "UMMM: " << j << " " << all_max << " " << all_min << endl;
                
//                 if(all_max < all_min)
//                     ans += all_max;
//                 else
//                     ans += all_min;
            }
            cout << "Case #" << t << ": " << ans << endl;
        }
        else
        {
            cout << "Case #" << t << ": " << "Fegla Won" << endl;
        }
        
    }
    return 0;
}