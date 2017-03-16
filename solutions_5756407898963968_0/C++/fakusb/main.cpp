#include <iostream>
#include <vector>
#include <set>

using namespace std;

int T;
vector<vector<int>> results;

int main(){
    cin>>T;
    for(int t=1;t<=T;t++){
        set<int> row1;
        int ans1;
        cin>>ans1;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int tmp;
                cin>>tmp;
                if(i+1==ans1)
                    row1.emplace(tmp);
            }
        }
        vector<int> result;
        int ans2;
        cin>>ans2;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int tmp;
                cin>>tmp;
                if(i+1==ans2){
                    if(row1.count(tmp)>0)
                        result.emplace_back(tmp);
                }
            }
        }
        results.push_back(result);
    }
    int t=0;
    for(vector<int> result : results){
        t++;
        cout<<"Case #"<<t<<": "; 
        if(result.size()==0){
            cout<<"Volunteer cheated!"<<endl;
        }
        else if(result.size()==1){
            cout<<result[0]<<endl;
        }
        else if(result.size()>1){
            cout<<"Bad magician!"<<endl;
        }
    }
    return 0;
}