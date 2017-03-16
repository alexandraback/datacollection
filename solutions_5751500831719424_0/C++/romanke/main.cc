#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <string>
#include <cmath>

//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int bigint;

size_t reps (const std::string &str, size_t i) {
    size_t init = i;
    char curr = str[i];
    while (curr == str[i])
        ++i;
    return i-init;
}

int actions (const std::vector<std::string> &words, const std::vector<size_t> &indices) {
    int minres = 1000000;
    for (size_t i=0;i<words.size();++i) {
        int currres = 0;
        size_t r = reps(words[i], indices[i]);
        for (size_t j=0; j<words.size() && currres < minres; ++j) {
            if (i==j)
                continue;
            currres += std::abs((int)r - (int)reps(words[j], indices[j]));
        }
        if (currres < minres)
            minres = currres;
    }
    return minres;
}

int solve (std::vector<std::string> &words) {
    int res = 0;
    std::vector<size_t> indices(words.size(), 0);
    

    while (indices[0] < words[0].size()) {
        for (size_t j=0; j<words.size(); ++j)
            if (words[j][indices[j]] != words[0][indices[0]])
                return -1;
        res += actions(words, indices);
        for (size_t j=0; j<words.size(); ++j)
            indices[j] += reps(words[j], indices[j]);
    }

    for (size_t i=0;i<words.size();++i)
        if (indices[i] < words[i].size())
            return -1;

    return res;
}

void play () {
    size_t n;
    std::cin >> n;
    std::vector<std::string> words;
    while (n--) {
        std::string word;
        std::cin >> word;
        words.push_back(word);
    }
    int res = solve(words);
    if (res < 0)
        std::cout << "Fegla Won" << std::endl;
    else
        std::cout << res << std::endl;
}

int main () {
    size_t cases;
    std::cin >> cases;
    for (size_t i=1; i<=cases; ++i) {
        std::cout << "Case #" << i << ": ";
        play();
    }
    return 0;
}

