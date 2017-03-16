#include <bits/stdc++.h>
#define rep(a,b) for(int a = 0; a < b; a++)

using namespace std;
typedef long long ll;


struct lit
{
    char c;
    int val;
    lit(char a, int b): c(a), val(b) {}
};

bool comp(lit a, lit b)
{
    return a.val > b.val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;

    int kt = 1;
    int value, n;
    ll counts;
    vector<lit> v;
    while(kt <= t)
    {
        v.clear();
        cin >> n;
        counts = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> value;
            v.push_back(lit((char)('A'+i), value));
            counts += value;
        }


        cout << "Case #" << kt << ": ";

        sort(v.begin(), v.end(), comp);
        for(int i = 0; counts > 0;)
        {
            if(i+1 < v.size() && v[i+1].val == v[i].val)
            {
                if(i+2 < v.size() && v[i+2].val == v[i].val)
                {
                    cout << v[i].c << ' ';
                    v[i].val--;
                    counts--;
                }
                else
                {
                    cout << v[i].c << v[i+1].c << ' ';
                    v[i].val--;
                    v[i+1].val--;
                    counts -=2;
                }
            }
            else
            {
                cout << v[i].c << ' ';
                v[i].val--;
                counts--;
            }
            sort(v.begin(), v.end(), comp);
        }

        cout << "\n";
        kt++;
    }
}
