#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

int T;

int n;



int main() {
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    cin>>T;
    for(int C=0;C<T;C++) {
        cin>>n;
        vector<pair<int, char>> s;
        int p;
        int sum=0;
        for(int i=0;i<n;i++) {
            int p;
            cin>>p;
            sum+=p;
            s.push_back(make_pair(p,'A'+i));
        }
        cout<<"Case #"<<C+1<<":";
        while(sum>0) {
            sort(s.begin(),s.end());
            if(s[n-1].first>s[n-2].first) {
                cout<<" "<<s[n-1].second;
                s[n-1].first--;
                sum--;
            } else {
                if(n==2 || s[n-3].first==0) {
                    cout<<" "<<s[n-1].second<<s[n-2].second;
                    s[n-1].first--;
                    s[n-2].first--;
                    sum-=2;
                } else {
                    cout<<" "<<s[n-1].second;
                    s[n-1].first--;
                    sum--;
                }
            }
        }
        cout<<endl;

    }
}
