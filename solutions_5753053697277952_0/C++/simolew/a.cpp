#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdint>
using namespace std;


bool check(vector<int>& v) {
    int sum = 0;
    for(auto& l : v) {
        sum+=l;
    }
    int majority = (sum % 2 == 0) ? sum / 2 + 1 : (sum/2);
    for(auto& l : v) {
        if(l > majority) return false;
    }
    return true;
}

int getBest(vector<int>& v) {
        int best = 0;
        int bestP;
        for(int i=0;i<v.size();i++) {
            if(v[i] > best) {
                best = v[i];
                bestP = i;
            }
        }
        return bestP;

}

void s() {
    int N;
    cin>>N;
    vector<int> v (N);
    int sum = 0;
    for(int i=0;i<N;i++) {
        cin>>v[i];
        sum += v[i];
    }
    while(sum > 0) {
        int choice = getBest(v);
        sum--;
        v[choice]--;
        cout<<(char)('A'+choice);
        if(!check(v)) {
            int b = getBest(v);
            sum--;
            v[b]--;
            cout<<(char)('A'+b);
        }
        cout<<" ";
    }

    for(int i=0;i<N;i++) {
        if(v[i]>0) cout<<(char)('A'+i);
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": ";
        s();
    }
}
