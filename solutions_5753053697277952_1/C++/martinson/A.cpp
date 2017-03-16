#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

int n;
int sum;
pair<int, char> p[30];

void read(){
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++){
        cin >> p[i].first;
        sum += p[i].first;
        p[i].second = char('A' + i);
    }
}

void run(){
    read();
    sort(p, p + n);
    while (p[n - 1].first > p[n - 2].first){
        printf("%c ", p[n - 1].second);
        p[n - 1].first--;
        sum--;
    }
    for (int i = 0; i < n - 2; i++){
        for (int j = 0; j < p[i].first; j++){
            printf("%c ", p[i].second);
        }
    }
    for (int i = 0; i < p[n - 1].first; i++){
        printf("%c%c ", p[n - 1].second, p[n - 2].second);
    }
}

int main(){
    freopen("output_A_large.txt", "w", stdout);
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; i++){
        printf("Case #%d: ", i);
        run();
        printf("\n");
    }
    return 0;
}

