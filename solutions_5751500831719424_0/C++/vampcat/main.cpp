#include <iostream>
#include <vector>
#include <cstdlib>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[i])
                swap(arr[j], arr[i]);
}

int main()
{
    int t;
    std::cin >> t;

    for (int caseNo = 0; caseNo < t; caseNo++)
    {
        int n;
        std::cin >> n;
        std::string *s = new std::string[n];

        int min = 0;

        for (int i = 0; i < n; i++)
            std::cin >> s[i];

        std::vector<char> *charList = new std::vector<char>[n];
        std::vector<int> *charCount = new std::vector<int>[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < s[i].length(); j++)
            {
                int count = 1;

                while(j+1 < s[i].length() && s[i][j] == s[i][j+1])
                {
                    count++;
                    j++;
                }
                charList[i].push_back(s[i][j]);
                charCount[i].push_back(count);
            }

            //for (int k = 0; k < charList[i].size(); k++)
            //        std::cout << charList[i][k] << charCount[i][k] << std::endl;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < charList[i].size(); k++)
                    if (charList[i].size() != charList[j].size() || charList[i][k] != charList[j][k])
                        goto FAIL;
            }
        }

        for (int k = 0; k < charList[0].size(); k++)
        {
            int min_actions = 0;
            for (int i = 0; i < n; i++)
            {
                int temp = 0;
                for (int j = 0; j < n; j++)
                {
                    temp += abs(charCount[i][k] - charCount[j][k]);
                }
                if (i == 0 || temp < min_actions)
                    min_actions = temp;
            }
            min += min_actions;
        }

        SUCCESS:
        std::cout << "Case #" << (caseNo + 1) << ": ";
        std::cout << min;
        goto ENDL;

        FAIL:
        std::cout << "Case #" << (caseNo + 1) << ": ";
        std::cout << "Fegla Won";

        ENDL:
        std::cout << std::endl;
    }

    return 0;
}
