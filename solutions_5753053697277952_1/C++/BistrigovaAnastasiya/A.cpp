#include <bits/stdc++.h>
using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
#define xx real()
#define yy imag()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

#define DEBUG 0
#define dout if(DEBUG) cout

set<pair<int, int> > st;
int cnt[100];

void solve(){
    st.clear();
    int n;
    scanf("%d", &n);
    int v;
    for(int i = 0; i < n; i++){
        scanf("%d", &v);
        st.insert(mp(-v, i));
        cnt[i] = v;
    }
    while(!st.empty()){
        int v = st.begin()->second;
        st.erase(st.begin());
        if(st.empty()){
            if(cnt[v] == 1){
                printf("%c ", (char)('A' + v));
                cnt[v] = 0;
            }
            else{
                printf("%c%c ", (char)('A' + v), (char)('A' + v));
                cnt[v] -= 2;
            }
            if(cnt[v]){
                st.insert(mp(-cnt[v], v));
            }
        }
        else{
            int v2 = st.begin()->second;
            st.erase(st.begin());
            if(cnt[v] == cnt[v2] && st.empty()){
                cnt[v]--;
                cnt[v2]--;
                printf("%c%c ", (char)('A' + v), (char)('A' + v2));
            }
            else{
                printf("%c ", (char)('A' + v));
                cnt[v]--;
            }
            if(cnt[v]){
                st.insert(mp(-cnt[v], v));
            }
            if(cnt[v2]){
                st.insert(mp(-cnt[v2], v2));
            }
        }
    }
}

int main()
{
	#ifdef NASTYA
    assert(freopen("input.txt","r",stdin));
    assert(freopen("output.txt","w",stdout));
    #else
    //assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
    #endif
	int t = 1;
	int cs = 1;
	cin >> t;
	while(t--){
        printf("Case #%d: ", cs++);
		solve();
        printf("\n");
	}
	return 0;
}
