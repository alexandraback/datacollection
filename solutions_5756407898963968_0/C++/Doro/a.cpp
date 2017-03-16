#include <cstdio>
#include <vector>
using namespace std;

void read_card_row(vector<int> &out){
    int row;
    scanf("%d",&row);
    --row;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int a;
            scanf("%d", &a);
            if(i == row)
                out.push_back(a);
        }
    }
}

void intersect(const vector<int> &x, const vector<int> &y, vector<int> &out){
    for(int i=0;i<x.size();i++){
        int s = x[i];
        for(int j=0;j<y.size();j++){
            if(y[j] == s){
                out.push_back(s);
                break;
            }
        }
    }
}

void test_case(){
    vector<int> row1, row2, res;
    read_card_row(row1);
    read_card_row(row2);
    intersect(row1, row2, res);
    if(res.empty()){
        printf("Volunteer cheated!\n");
    } else if(res.size() > 1){
        printf("Bad magician!\n");
    } else {
        printf("%d\n", res[0]);
    }
}

int main(){
    int z;
    scanf("%d", &z);
    for(int t=1;t<=z;++t){
        printf("Case #%d: ", t);
        test_case();
    }
    return 0;
}
