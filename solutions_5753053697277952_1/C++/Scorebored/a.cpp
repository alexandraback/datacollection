#include <bits/stdc++.h>
using namespace std;

void solve(int N) {
    int parties;
    cin >> parties;
    vector<pair<int, char>> members(parties);
    int temp=0;
    int total = 0;
    for(int i=0; i<parties; ++i) {
        cin >> temp;
        members[i].first=temp;
        members[i].second = (char) 'A'+i;
        total+=temp;
    }
    //for(int i=0; i<parties; ++i) {
    //    cout << members[i].second << " : " << members[i].first << endl;
    //}
    cout << "Case #" << N << ":";
    while(total>0) {
        cout << " ";
        sort(members.begin(), members.end(), greater<pair<int,char>>());
        int affected = 0;
        if(members[0].first - members[1].first >= 2) {
            members[0].first -= 2;
            total -= 2;
            cout << members[0].second << members[0].second;
            //according to the input, this should not eliminate any parties
        } else if(members[0].first - members[1].first == 1) {
            members[0].first -= 1;
            total -=1;
            cout << members[0].second;
            //should never eliminate parties
        } else if(parties%2==0) { //Save the largest parties
            members[0].first -=1;
            members[1].first -=1;
            total -= 2;
            cout << members[0].second << members[1].second;
            if(members[0].first ==0) --parties;
            if(members[1].second == 0) --parties;
        } else { //Save the first of the odd number of parties
            members[0].first -= 1;
            total -=1;
            cout << members[0].second;
            if(members[0].first ==0)--parties;
        }
        parties = 0;
        for(int i=0; i<members.size(); ++i) {
            if(members[i].first>0)++parties;
        }
    }
    cout << endl;
}

int main() {
    int testcases = 0;
    cin >> testcases;
    for(int i=0; i<testcases; ++i) {
        solve(i+1);
    }
}
