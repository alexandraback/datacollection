#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define fst first
#define snd second
#define fr(i, a, b) for(int i=a; i<b; i++)


void main2() {
    int n; cin >> n;
    vector< pair<int, char> > vs;
    int sum = 0;
    for(int i=0; i<n; i++) {
        int t; cin >> t;
        sum += t;
        vs.push_back(make_pair(t, 'A'+i));
    }

    string res = "";
    int f = 1;
    while(1) {
        sort(vs.begin(), vs.end(), greater< pair<int, char> >());
        vector< pair<int, char> > temp = vs;
        for(int i=temp.size()-1; i >= 0; i--) {
            if(temp[i].fst == 0) vs.pop_back();
        }
        if(f && ( sum % 2) == 1) {
            res += vs[0].snd;
            vs[0].fst--;
            res += " ";
            f = 0;
            continue;
        } else f = 0;

        if(vs.size()==0) break;
        res += vs[0].snd;
        if(vs.size()>1) res += vs[1].snd;
        vs[0].fst--;
        if(vs.size() > 1) vs[1].fst--;
        res += " ";
    }
    for(int i=0; i<res.size()-1; i++) cout<<res[i];
    cout<<endl;
}

int main() {
    int T;
    cin>>T;
    for(int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<": ";
        main2();
    }
}
