#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int r;
        vector<bool> possibility(17, true);
        cin >> r;
        for(int y = 1; y <= 4; y++){
            for(int x = 1; x <= 4; x++){
                int v;
                cin >> v;
                if(y != r) possibility[v] = false;
            }
        }
        cin >> r;
        for(int y = 1; y <= 4; y++){
            for(int x = 1; x <= 4; x++){
                int v;
                cin >> v;
                if(y != r) possibility[v] = false;
            }
        }
        vector<int> cands;
        for(int i = 1; i <= 16; i++){
            if(possibility[i]) cands.push_back(i);
        }
        cout << "Case #" << t << ": ";
        if(cands.empty()){
            cout << "Volunteer cheated!" << endl;
        }else if(cands.size() > 1){
            cout << "Bad magician!" << endl;
        }else{
            cout << cands[0] << endl;
        }
    }
    return 0;
}



