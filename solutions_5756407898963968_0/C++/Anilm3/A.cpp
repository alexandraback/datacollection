#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int T;

    std::cin >> T;

    for (int idx = 1; idx <= T; idx ++)
    {
        int aux, answer, valid_cards = 0, card;
        std::vector<int> row;

        std::cin >> answer;

        --answer;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cin >> aux;
                if (i == answer)
                {
                    row.push_back(aux);
                }
            }
        }

        std::cin >> answer;

        --answer;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cin >> aux;
                
                if (i == answer)
                {
                    if (find(row.begin(), row.end(), aux) != row.end())
                    {
                        valid_cards++;
                        card = aux;
                    }
                }
            }
        }

        switch(valid_cards)
        {
            case 0:
                std::cout << "Case #" << idx << ": Volunteer cheated!" << std::endl;
                break;
            case 1:
                std::cout << "Case #" << idx << ": " << card << std::endl;
                break;
            default:
                std::cout << "Case #" << idx << ": Bad magician!" << std::endl;
                break;
        }
    }

    return 0;
}