#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>

struct TestCase
{
    std::vector<std::string> strings;
};

struct Item
{
    char symbol;
    int count;
};

struct String
{
    std::vector<Item> items;
};

struct Solution
{
    std::vector<String> strings;
};

std::vector<TestCase> ReadCases(std::istream& stream)
{
    int totalCases;
    std::vector<TestCase> result;

    stream >> totalCases;

    for (size_t i = 0; i < totalCases; i++)
    {
        TestCase testCase;

        int strings;
        stream >> strings;

        for (int i = 0; i < strings; i++)
        {
            std::string str;
            stream >> str;
            testCase.strings.push_back(str);
        }

        result.push_back(testCase);
    }

    return result;
}

String Convert(const std::string& str)
{
    String result;
    for (auto c : str)
    {
        if ((result.items.size() == 0) || (result.items.back().symbol != c))
        {
            Item item = { c, 1 };
            result.items.push_back(item);
        }
        else
        {
            result.items.back().count++;
        }
    }

    return result;
}

int FindMinPath(const Solution& s, size_t pos)
{
    int minChars = s.strings[0].items[pos].count;
    int maxChars = s.strings[0].items[pos].count;

    for (size_t i = 1; i < s.strings.size(); i++)
    {
        minChars = std::min(minChars, s.strings[i].items[pos].count);
        maxChars = std::max(maxChars, s.strings[i].items[pos].count);
    }

    int best = -1;
    for (int t = minChars; t <= maxChars; t++)
    {
        int current = 0;
        for (size_t i = 0; i < s.strings.size(); i++)
        {
            current += abs(s.strings[i].items[pos].count - t);
        }

        if ((best < 0) || (current < best))
        {
            best = current;
        }
    }

    return best;
}

int Solve(const TestCase& testCase)
{
    Solution sol;

    int minSymbols = -1;
    int maxSymbols = -1;
    for (auto& str : testCase.strings)
    {
        auto s = Convert(str);
        sol.strings.push_back(s);

        minSymbols = (minSymbols < 0) ? s.items.size() : std::min(minSymbols, (int)s.items.size());
        maxSymbols = (maxSymbols < 0) ? s.items.size() : std::max(maxSymbols, (int)s.items.size());
    }

    if (minSymbols != maxSymbols)
    {
        return -1;
    }

    int result = 0;
    for (int i = 0; i < minSymbols; i++)
    {
        char c = sol.strings[0].items[i].symbol;

        for (size_t j = 1; j < sol.strings.size(); j++)
        {
            if (sol.strings[j].items[i].symbol != c)
            {
                return -1;
            }
        }

        result += FindMinPath(sol, i);
    }

    return result;
}


int main(int argc, char* argv[])
{
    std::vector<TestCase> cases;

    if (argc == 1)
    {
        cases = ReadCases(std::cin);
    }
    else if (argc == 2)
    {
        std::ifstream stream(argv[1]);
        if (!stream.good())
        {
            return 1;
        }

        cases = ReadCases(stream);
    }
    else
    {
        return 1;
    }

    int testNum = 1;
    for (auto& testCase : cases)
    {
        std::cout << "Case #" << testNum << ": ";

        int res = Solve(testCase);
        if (res < 0)
        {
            std::cout << "Fegla Won" << std::endl;
        }
        else
        {
            std::cout << res << std::endl;
        }

        testNum++;
    }

    return 0;
}

