#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector< std::vector<int> > m;

int find_minimum(int index)
{
    std::vector<int> counts;
    for (int i = 0; i < m.size(); ++i)
    {
        counts.push_back(m[i][index]);
    }

    int min = INT_MAX;

    std::map<int, int> possible_results;
    for (int i = 0; i < counts.size(); i++)
    {
        int target = counts[i];
        if (possible_results.find(target) != possible_results.end())
            continue;

        int current_result = 0;
        for (int j = 0; j < counts.size(); ++j)
        {
            current_result += abs(target - counts[j]);
            if (current_result > min)
            {
                break;
            }
        }

        if (current_result < min)
            min = current_result;

        possible_results[target] = current_result;
    }

    return min;
}

std::string compress(const std::string& input, int index)
{
    std::string result;
    char last = input[0];
    int count = 0;
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == last)
        {
            count++;
            continue;
        }
        result += last;
        last = input[i];
        m[index].push_back(count);
        count = 1;
    }
    result += last;
    m[index].push_back(count);
    return result;
}

void solve(int case_no)
{
    m.clear();
    std::cout << "Case #" << case_no << ": ";
    int string_count;
    std::cin >> string_count;

    std::vector<std::string> strings(string_count);
    for (int i = 0; i < string_count; ++i){
        std::cin >> strings[i];
        m.push_back(std::vector<int>());
    }

    std::vector<std::string> compressed(string_count);
    for (int i = 0; i < string_count; ++i){
        compressed[i] = compress(strings[i], i);
    }

    std::string common = compressed[0];
    for (int i = 0; i < string_count; ++i)
    {
        if (compressed[i] != common)
        {
            std::cout << "Fegla Won" << std::endl;
            return;
        }
    }

    int result = 0;
    for (int index = 0; index < common.size(); ++index)
    {
        result += find_minimum(index);
    }
    std::cout << result << std::endl;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    for (int i = 1; i <= test_cases; ++i)
        solve(i);
}