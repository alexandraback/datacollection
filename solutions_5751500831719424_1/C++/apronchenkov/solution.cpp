#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> readStrings()
{
    std::vector<std::string> result;
    int numberOfStrings;
    std::cin >> numberOfStrings;
    for (int i = 0; i < numberOfStrings; ++i) {
        std::string string;
        std::cin >> string;
        result.push_back(string);
    }
    return result;
}



std::string extractPattern(std::string string)
{
    string.erase(std::unique(string.begin(), string.end()), string.end());
    return string;
}


bool hasCommonPattern(const std::vector<std::string>& strings)
{
    if (strings.empty()) {
        return 0;
    }
    const auto pattern = extractPattern(strings[0]);
    for (const auto& string : strings) {
        if (extractPattern(string) != pattern) {
            return false;
        }
    }
    return true;
}


int extractLastGroup(std::string* string)
{
    if (string->empty()) {
        return 0;
    }
    int result = 0;
    const char character = string->back();
    do {
        ++result;
        string->pop_back();
    } while (!string->empty() && string->back() == character);
    return result;
}


std::vector<int> extractLastGroup(std::vector<std::string>* strings)
{
    std::vector<int> result;
    for (auto& string : *strings) {
        result.push_back(extractLastGroup(&string));
    }
    return result;
}


int computeMedianDistance(std::vector<std::string> strings)
{
    if (strings.empty()) {
        return 0;
    }
    if (!hasCommonPattern(strings)) {
        return -1;
    }
    int result = 0;
    while (!strings.at(0).empty()) {
        auto group = extractLastGroup(&strings);
        std::sort(group.begin(), group.end());
        const int median = group.at(group.size() / 2);
        for (int x : group) {
            result += std::abs(x - median);
        }
    }
    return result;
}




int main()
{
    int numberOfCases;
    std::cin >> numberOfCases;
    for (int caseNo = 1; caseNo <= numberOfCases; ++caseNo) {
        const int distance = computeMedianDistance(readStrings());
        if (distance < 0) {
            std::cout << "Case #" << caseNo << ": Fegla Won\n";
        } else {
            std::cout << "Case #" << caseNo << ": " << distance << '\n';
        }
    }
}
