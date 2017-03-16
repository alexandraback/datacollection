#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int num;
    char ch;
}no[35];
vector<string> v;

bool cmp(node a,node b){
    if(a.num != b.num)
        return a.num > b.num;
    else
        return a.ch < b.ch;
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t = 0;
    scanf("%d",&T);
    while(T--){
        int n,sum = 0;
        string str;
        v.clear();
        scanf("%d",&n);
        for(int i = 0; i < n; ++i){
            scanf("%d",&no[i].num);
            no[i].ch = 'A'+i;
            sum += no[i].num;
        }
        int flag = 1;
        while(flag){
            flag = 0;
            str = "";
            sort(no,no+n,cmp);
            if(no[0].num){
                if(sum == 3 || !no[1].num){
                    v.push_back(str+no[0].ch);
                    --no[0].num;
                    --sum;
                }
                else if(no[1].num){
                    v.push_back(str+no[0].ch+no[1].ch);
                    --no[0].num;
                    --no[1].num;
                    sum -= 2;
                }
                flag = 1;
            }
        }
        int len = v.size();
        printf("Case #%d:",++t);
        for(int i = 0; i < len; ++i)
            cout<<" "<<v[i];
        printf("\n");
    }
    return 0;
}
