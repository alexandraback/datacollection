#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    for(int _=0;_<T;_++){
        int row1,row2;
        scanf("%d",&row1);
        row1--;

        set<int> selected;
        for(int i = 0; i< 4 ;i++){
            for(int j = 0 ; j<4;j++){
                int x;
                scanf("%d",&x);
                if(i == row1){
                    selected.insert(x);
                }
            }
        }
        vector<int> ans;
        scanf("%d",&row2);
        row2--;
        for(int i = 0; i< 4 ;i++){
            for(int j = 0 ; j<4;j++){
                int x;
                scanf("%d",&x);
                if(i == row2 && selected.count(x)>0){
                    ans.push_back(x);
                }
            }
        }
        printf("Case #%d: ",_+1);
        if(ans.size() == 0){
            puts("Volunteer cheated!");
        }else if(ans.size() >1){
            puts("Bad magician!");
        }else{
            printf("%d\n",ans[0]);
        }
    }
    return 0;
}
