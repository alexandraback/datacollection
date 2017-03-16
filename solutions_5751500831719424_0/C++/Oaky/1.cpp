#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 201;
const int MAXL = 201;

typedef pair<char,int> II;

vector<II> vec[MAXN];
char str[MAXL];

int error(){
    printf("Fegla Won");
    return 0;
}

int abs(int n){
    return (n < 0) ? -n : n;
}

int solve(){
    for(int i = 0; i < MAXN; ++i) vec[i].clear();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", str);
        int len = strlen(str);
        vec[i].push_back(II(str[0], 1));
        for(int x = 1; x < len; ++x){
            if(vec[i].back().first == str[x]){
                ++vec[i].back().second;
            }else{
                vec[i].push_back(II(str[x], 1));
            }
        }
    }
    int size = vec[0].size();
    for(int i = 0; i < n; ++i){
        if(vec[i].size() != size){
            return error();
        }
    }
    int ans = 0;
    for(int x = 0; x < size; ++x){
        vector<int> arr;
        for(int i = 0; i < n; ++i){
            if(vec[i][x].first != vec[0][x].first){
                return error();
            }
            arr.push_back(vec[i][x].second);
        }
        sort(arr.begin(), arr.end());
        int median = arr[n / 2];
        for(int i = 0; i < n; ++i){
            ans += abs(median - arr[i]);
        }
    }
    printf("%d", ans);
    return 0;
}

int main(){
    int allt;
    scanf("%d", &allt);
    for(int t = 1; t <= allt; ++t){
        printf("Case #%d: ", t);
        solve();
        printf("\n");
    }
    return 0;
}