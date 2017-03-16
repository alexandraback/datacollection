#include <array>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    int cases = 0;
    std::cin >> cases;

    for (int i = 1; i <= cases; ++i)
    {
        int n = 0;
        std::string newline;
        std::cin >> n;
        std::getline(std::cin, newline);
        std::vector<std::vector<std::pair<char, int>>> inputs;
        for (int j = 0; j < n; ++j)
        {
            std::string s;
            std::getline(std::cin, s);
            std::vector<std::pair<char, int>> v;
            for (auto c : s)
            {
                auto iter = v.rbegin();
                if (v.empty() || c != iter->first)
                {
                    v.push_back(std::make_pair(c, 1));
                }
                else if (c == iter->first)
                {
                    ++(iter->second);
                }
            }
            inputs.push_back(v);
        }

        std::vector<int> ans(inputs[0].size());
        for (auto& v : ans)
        {
            v = -1;
        }

        bool noans = false;
        for (int j = 0; !noans && j < n; ++j)
        {
            for (size_t k = 0; !noans && k < inputs[j].size(); ++k)
            {
                auto base = inputs[j][k];
                int count = 0;
                for (int l = 0; l < n; ++l)
                {
                    if (inputs[l].size() != inputs[j].size())
                    {
                        noans = true;
                        break;
                    }

                    if (inputs[l][k].first != base.first)
                    {
                        noans = true;
                        break;
                    }

                    count += std::abs(inputs[l][k].second - base.second);
                }
                if (ans[k] == -1 || count < ans[k])
                {
                    ans[k] = count;
                }
            }
        }

        std::cout << "Case #" << i << ": ";
        if (!noans)
        {
            int total = 0;
            for (auto a : ans)
            {
                total += a;
            }
            std::cout << total << std::endl;
        }
        else
        {
            std::cout << "Fegla Won" << std::endl;
        }
    }

    return 0;
}
