#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>

std::pair <std::string, std::vector <int>> parse(std::string string) {
    int n = string.size();
    std::string result;
    std::vector <int> lengths;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && string[i] == string[j]) {
            j ++;
        }
        result.push_back(string[i]);
        lengths.push_back(j - i);
        i = j;
    }
    return std::make_pair(result, lengths);
}

int main() {
    int test_count;
    scanf("%d", &test_count);
    for (int t = 1; t <= test_count; ++ t) {
        int n;
        scanf("%d", &n);
        std::vector <std::string> strings;
        for (int i = 0; i < n; ++ i) {
            static char buffer[101];
            scanf("%s", buffer);
            strings.push_back(buffer);
        }
        auto ret = parse(strings[0]);
        std::string goal = ret.first;
        std::vector <std::vector <int>> lengths(ret.second.size());
        int result = 0;
        for (int i = 0; i < n && ~result; ++ i) {
            auto ret = parse(strings[i]);
            if (ret.first != goal) {
                result = -1;
            } else {
                for (int j = 0; j < (int)ret.second.size(); ++ j) {
                    lengths[j].push_back(ret.second[j]);
                }
            }
        }
        printf("Case #%d: ", t);
        if (result == -1) {
            puts("Fegla Won");
        } else {
            for (int i = 0; i < (int)lengths.size(); ++ i) {
                std::vector <int> tmp = lengths[i];
                std::sort(tmp.begin(), tmp.end());
                int mid = tmp[n / 2];
                for (int v : tmp) {
                    result += std::abs(v - mid);
                }
            }
            printf("%d\n", result);
        }
    }
}
