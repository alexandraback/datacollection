#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

template<typename T>
ostream& operator << (ostream& o, vector<T>& v)
{
    o << "[";
    for(size_t i = 0; i < v.size(); i++)
    {
        o << v[i];
        if(i != v.size() - 1)
            o << ", ";
    }
    o << "]";
    return o;
}

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    FILE* useless;
    (void)useless;
    useless=freopen("A-large.in", "r", stdin);
    useless=freopen("A-large.out", "w", stdout);
    int n_casi;
    cin >> n_casi;
    for(int caso = 1; caso <= n_casi; caso++)
    {
        cout << "Case #" << caso << ": ";
        vector<lli> mushrooms;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            lli tmp;
            cin >> tmp;
            mushrooms.push_back(tmp);
        }
        lli solution1 = 0;
        for(size_t i = 1; i < mushrooms.size(); i++)
        {
            if(mushrooms[i] < mushrooms[i-1])
                solution1 += mushrooms[i-1] - mushrooms[i];
        }
        cout << solution1 << " ";
        lli max_rate = 0;
        for(size_t i = 1; i < mushrooms.size(); i++)
        {
            if(mushrooms[i] < mushrooms[i-1])
            {
                max_rate = max(max_rate, mushrooms[i-1] - mushrooms[i]);
            }
        }
        lli solution2 = 0;
        for(size_t i = 0; i < mushrooms.size() - 1; i++)
        {
            solution2 += min(max_rate, mushrooms[i]);
        }
        cout << solution2 << endl;
    }
    return EXIT_SUCCESS;
}
