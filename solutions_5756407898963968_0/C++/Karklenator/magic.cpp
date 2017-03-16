
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){

    int TC,c,d,a,b;

    scanf("%d",&TC);
    int casenum =1 ;
    while(TC--){
        int ans1,ans2;
        cin >> ans1;
        set<int> s1,s2;
        int array1[4][4];
        int array2[4][4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> array1[i][j];
                if(i == ans1-1) {
                    //cout << array1[i][j] << endl;
                    s1.insert(array1[i][j]);
                }
            }
        }
        
        cin >> ans2;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> array2[i][j];
                if(i == ans2-1) {
                    //cout << array2[i][j] << endl;
                    s2.insert(array2[i][j]);
                }
            }
        }
        vector<int> ans;
        for(int i = 1; i <= 16; i++){
            if(s1.count(i) > 0 && s2.count(i) > 0){
                ans.push_back(i);
                //cout << i << endl;
            }
        }
        if(ans.size() == 1){
            cout << "Case #" << casenum << ": " << ans[0] << endl;
        }else if(ans.size() > 1){
             cout << "Case #" << casenum << ": " << "Bad magician!" << endl;
        }else{
            cout << "Case #" << casenum << ": " << "Volunteer cheated!" << endl;
        }
        casenum++;
    }
}
