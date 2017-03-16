#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

struct node {
    char c;
    int n;
    node(char c, int n) { this->c = c; this->n = 1; }
    bool operator==(node n) { return this->c == n.c; }
};

std::vector< std::vector<int> > convert(std::vector<std::string> strs)
{
    std::vector<char> compress;
    std::vector< std::vector<int> > counts;
    for (int i = 0; i < strs.size(); i++) {
        //compress it
        std::vector<char> current;
        std::vector<int> count;
        current.push_back(strs[i][0]);
        count.push_back(1);
        for(int j = 1; j < strs[i].size(); j++)
            if (strs[i][j] == current.back())
                count.back()++;
            else {
                current.push_back(strs[i][j]);
                count.push_back(1);
            }
        counts.push_back(count);
        if (compress.size()) {

            if (compress.size() != current.size() || !std::equal(compress.begin(), compress.end(), current.begin()))
                return std::vector< std::vector<int> >();
        } else {
            compress = current;
        }
    }
    //for(int i = 0; i < nodelist.size(); i++) {
    //    std::cout << "nodelist[" << i << "] == ";
    //    for(int j = 0; j < nodelist[i].size(); j++) {
    //        std::cout << nodelist[i][j].c << "," << nodelist[i][j].n << " ";
    //    }
    //    std::cout << std::endl;
    //}
    return counts;
}

int editDistance(std::vector<std::string> strs)
{
    std::vector< std::vector<int> > counts = convert(strs);
    if (counts.size() == 0) return -1;
    int moves = 0;
    //find #moves required for each step
    for (int i = 0; i < counts[0].size(); i++) {
        int score = -1;
        for (int j = 0; j < counts.size(); j++) {
            int tmp = 0;
            for (int k = 0; k < counts.size(); k++) {
                tmp += abs(counts[j][i] - counts[k][i]);
            }
            if (tmp < score || score < 0) score = tmp;
        }
        moves += score;
    }
    //for (int i = 0; i < nodes[0].size(); i++) {
    //    moves += abs(nodes[0][i].n - nodes[1][i].n);
    //}
    return moves;
}

int main()
{
    int cases;
    std::cin >> cases;
    for (int i = 1; i <= cases; i++) {
        int n;
        std::cin >> n;
        std::vector<std::string> strings;
        while (n--) {
            std::string s;
            std::cin >> s;
            strings.push_back(s);
        }
        int res = editDistance(strings);
        if (res >= 0)
            printf("Case #%d: %d\n", i, res);
        else
            printf("Case #%d: Fegla Won\n", i);
    }
}