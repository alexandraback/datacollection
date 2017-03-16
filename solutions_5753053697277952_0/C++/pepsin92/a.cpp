#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    
    int cn;
    cin >> cn;
    for (int c=0; c<cn; c++){
        priority_queue<vector<int>> senate;
        int n;
        cin >> n;
        int s = 0;
        for (int i=0; i<n; i++){
            int temp;
            cin >> temp;
            s+=temp;
            senate.push({temp, i});
        }

        vector<vector<int>> res;
        
        if (s%2) {
            vector<int> temp = senate.top();
            senate.pop();
            res.push_back({temp[1]});
            temp[0]--;
            if (temp[0] != 0) senate.push(temp);
        }

        while(!senate.empty()) {
            vector<int> temp = senate.top();
            senate.pop();
            res.push_back({temp[1]});
            temp[0]--;
            if (temp[0] != 0) senate.push(temp);
            
            temp = senate.top();
            senate.pop();
            res.back().push_back(temp[1]);
            temp[0]--;
            if (temp[0] != 0) senate.push(temp);
        }

        cout << "Case #"<<c+1<<":";
        for (int i=0; i<res.size(); i++){
            cout << ' ';
            for (int j=0; j<res[i].size(); j++){
                cout<<(char)('A'+res[i][j]);
            }
        }
        cout << endl;
    }
    return 0;
}
