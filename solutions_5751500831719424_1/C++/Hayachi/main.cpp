#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    int t;
    scanf("%d", &t);
    for(int ti = 0; ti < t; ++ti) {
        int n;
        scanf("%d", &n);
        std::vector<std::string> strings(n);
        for(int i = 0; i < n; ++i) {
            std::cin >> strings[i];
        }
        std::vector<std::vector<std::pair<char, int> > > tab(n);
        for(int i = 0; i < n; ++i) {
            char curr = '#';
            for(int j = 0; j < strings[i].length(); ++j) {
                if(strings[i][j] != curr) {
                    curr = strings[i][j];
                    tab[i].push_back(std::pair<char, int>(curr, 1));
                }else {
                    tab[i].back().second++;
                }
            }
        }
        //printf("Convert done\n");
        bool done = false;
        bool res = true;
        char lett = tab[0][0].first;
        int req = 0;
        int it = 0;
        std::vector<int> sizes;
        int tmpSize = tab[0].size();
        for(int i = 0; i < n; ++i) {
            if(tab[i].size() != tmpSize) {
                done = true;
                res = false;
                break;
            }
        }
        if(!done)
        for(int it = 0; it < tmpSize; ++it) {
            sizes.clear();
            lett = tab[0][it].first;
            for(int i = 0; i < n; ++i) {
                if(tab[i][it].first != lett) {
                    done = true;
                    res = false;
                    //printf("or here\n");
                    break;
                }else {
                    sizes.push_back(tab[i][it].second);
                }
            }
            std::sort(sizes.begin(), sizes.end());
            int med = sizes[sizes.size() / 2];
            for(int i = 0; i < n; ++i) {
                req += std::abs(tab[i][it].second - med);
            }
        }
        printf("Case #%d: ", ti + 1);
        if(res == false) {
            printf("Fegla Won\n");
        }else {
            printf("%d\n", req);
        }
    }
}
