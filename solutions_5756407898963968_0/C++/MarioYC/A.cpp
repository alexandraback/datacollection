#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int TC;
    int ans1,ans2;
    int M1[4][4],M2[4][4];
    
    cin >> TC;
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> ans1;
        --ans1;
        
        for(int i = 0;i < 4;++i)
            for(int j = 0;j < 4;++j)
                cin >> M1[i][j];
        
        cin >> ans2;
        --ans2;
        
        int ans = 0,cont = 0;
        
        for(int i = 0;i < 4;++i)
            for(int j = 0;j < 4;++j){
                cin >> M2[i][j];
                
                if(i == ans2 && (M2[i][j] == M1[ans1][0] || M2[i][j] == M1[ans1][1] || M2[i][j] == M1[ans1][2] || M2[i][j] == M1[ans1][3])){
                    ++cont;
                    ans = M2[i][j];
                }
            }
        
        cout << "Case #" << tc << ": " ;
        
        if(cont == 1) cout << ans;
        else if(cont == 0) cout << "Volunteer cheated!";
        else cout << "Bad magician!";
        
        cout << endl;
    }
    
    return 0;
}
