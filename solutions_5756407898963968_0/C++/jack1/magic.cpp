#include <iostream>

void read_matrix(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            std::cin >> matrix[i][j];
}

void print_matrix(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j];
            if (j < 3) std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int possible_cards(int first_answer, const int first_matrix[4][4], int second_answer, const int second_matrix[4][4], int& card)
{
    int count = 0;
    const int* first_row = &first_matrix[first_answer - 1][0];
    const int* second_row = &second_matrix[second_answer - 1][0];
    for (int i = 0; i < 4; i++)
    {
        bool found = false;
        for (int j = 0; j < 4; j++)
        {
            if (second_row[i] == first_row[j])
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            card = second_row[i];
            count++;
        }
    }
    //Debug
    //std::cout << "Card: " << card << std::endl;
    //std::cout << "Count: " << count << std::endl;
    return count;
}

int main()
{

    // Read the number of test cases
    int no_test_cases;
    std::cin >> no_test_cases;
    
    // Debug
    //std::cout << no_test_cases << std::endl;
    
    for (int i = 1; i <= no_test_cases; i++)
    {
        int first_matrix[4][4], second_matrix[4][4];
        
        // Read the first answer
        int first_answer;
        std::cin >> first_answer;
        // Read first matrix
        read_matrix(first_matrix);
        
        // Read the second answer
        int second_answer;
        std::cin >> second_answer;
        // Read second matrix
        read_matrix(second_matrix);
        
        // Debug
        //std::cout << first_answer << std::endl;
        //print_matrix(first_matrix);
        //std::cout << second_answer << std::endl;
        //print_matrix(second_matrix);
    
        std::cout << "Case #" << i << ": ";
    
        int card;
        const int cards_count = possible_cards(first_answer, first_matrix, second_answer, second_matrix, card);
        if (cards_count == 0)
            std::cout << "Volunteer cheated!";
        else if (cards_count == 1)
            std::cout << card;
        else
            std::cout << "Bad magician!";
        
        std::cout << std::endl;
        
    }
    
    return 0;
    
}
