#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.first<n2.first;
    }
};

int T;

int main(){
    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t){
        printf("Case #%d: ", t);
        priority_queue<pair<int,int>,vector<pair<int,int> >,CompareDist> parties;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i){
            int num;
            scanf("%d", &num);
            parties.push(make_pair(num, i));
        }
        while(!parties.empty()){
            pair <int,int> top1 = parties.top();
            parties.pop();
            pair <int,int> top2 = parties.top();
            parties.pop();
            if (top1.first > top2.first + 1){
                printf("%c%c ", top1.second + 'A', top1.second + 'A');
                top1.first -= 2;
            } else if (top1.first == top2.first + 1 || parties.empty()){
                printf("%c%c ", top1.second + 'A', top2.second + 'A');
                top1.first--; top2.first--;
            } else {
                printf("%c ", top1.second + 'A');
                top1.first--;
            }
            if (top1.first != 0) parties.push(top1);
            if (top2.first != 0) parties.push(top2);
        }

        printf("\n");
    }
}
