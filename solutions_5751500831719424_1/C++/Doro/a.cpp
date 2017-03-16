#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

typedef pair<char,int> pCI;

void to_char_groups(char word[], vector<pCI> &out){
    int ind = 0;
    // read group
    while(word[ind] != 0){
        char v = word[ind++];
        int s = 1;
        while((word[ind] != 0) && (v == word[ind])){
            ++ind;
            ++s;
        }
        out.push_back(make_pair(v, s));
    }
}

void print_group(const vector<pCI> &out){
    for(int i=0;i<out.size();i++){
        printf("(%c, %d) <-- ", out[i].first, out[i].second);
    }
    printf("\n");
}

bool are_matching_groups(const vector<pCI> &v1, const vector<pCI> &v2){
    if(v1.size() != v2.size())
        return false;
    for(int i=0;i<v1.size();i++){
        if(v1[i].first != v2[i].first)
            return false;
    }
    return true;
}

int solve_group(const vector<int> &len){
    int cost = (1<<30);
    for(int fix=0;fix<len.size();fix++){
        int cut_to = len[fix];
        int cur_cost = 0;
        for(int j=0;j<len.size();j++){
            int add = (cut_to - len[j]);
            if(add < 0)
                add = -add;
            cur_cost += add;
        }
        if(cur_cost < cost)
            cost = cur_cost;
    }
    return cost;
}

void test_case(){
    int n;
    char buff[101];
    scanf("%d",&n);
    // read WORDS
    vector<vector<pCI> > words(n);
    for(int i=0;i<n;i++){
        scanf("%s", buff);
        to_char_groups(buff, words[i]);
    }
    //printf("\n"); for(int i=0;i<n;i++){ print_group(words[i]); } // DEBUG !

    // test if possible
    for(int j=1; j<n; j++){
        if(!are_matching_groups(words[0], words[j])){
            printf("Fegla Won\n");
            return;
        }
    }
    // compute solution
    int res = 0;
    for(int gr=0;gr<words[0].size();gr++){
        vector<int> sizes;
        for(int s=0;s<n;s++){
            sizes.push_back(words[s][gr].second);
        }
        res += solve_group(sizes);
    }
    printf("%d\n", res);
}

const bool LINE_AFTER_CASE = false;
int main(){
    int z;
    scanf("%d", &z);
    for(int t=1;t<=z;++t){
        printf("Case #%d:%s", t, LINE_AFTER_CASE ? "\n" : " ");
        test_case();
    }
    return 0;
}
