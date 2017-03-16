#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef map<ll,ll>::iterator mapit;
typedef set<int>::iterator setit;

const int maxn = 2e6 + 4;
const int maxlog = 20;
const ll mod = 1e9 + 7;
const int sq = 720;

int main()
{
    ifstream fin ("A-small-attempt1 (1).in");
    ofstream fout ("myoutput.txt");
    int t;
    fin >> t;
    int an = 0;
    while(t -- ){
        int n;
        fin >> n;
        an ++ ;
        vector<pair<int,char> > v;
        for(int i = 0 ; i < n ; i ++ ){
            char c = 'A' + i;
            int x;
            fin >> x;
            v.pb(mp(x , c));
        }
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());
        fout << "Case #" << an << ": ";
        while(true){
            int id = 0;
            while(id < n && v[id].first == 0)
                id ++ ;
            if(id == n)
                break;
            if(v[id].first != v[id + 1].first){
                v[id].first -- ;
                fout << v[id].second << " ";
            }
            else{
                if(id + 2 < n && v[id + 2].first == v[id].first){
                    v[id].first -- ;
                    fout << v[id].second << " ";
                }
                else{
                    v[id].first -- , v[id + 1].first -- ;
                    fout << v[id].second << v[id + 1].second << " ";
                }
            }
        }
        fout << endl;
    }
    return 0;
}






