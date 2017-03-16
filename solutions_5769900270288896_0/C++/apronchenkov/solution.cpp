#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>


int CountBits(int value)
{
    int result = 0;
    while (value > 0) {
        if (value & 1) {
            ++result;
        }
        value /= 2;
    }
    return result;
}

int NoiseLevel(int rows, int columns, int mask)
{
    int result = CountBits(mask & (mask >> columns)); // up & down
//    std::cout << "#" << result << '\n';
    for (int i = 0; i < rows; ++i) {
        for (int j = 1; j < columns; ++j) {
            const int bit = 1 << ((i * columns) + j);
            const int left_bit = 1 << ((i * columns) + j - 1);
            if ((mask & bit) && (mask & left_bit)) {
                result += 1;
            }
        }
    }
    return result;
}

int FindMinNoiseLevel(int rows, int columns, int population)
{
    int result = INT_MAX;
    const int number_of_bits = rows * columns;
    for (int mask = 0; 0 == (mask >> number_of_bits); ++mask) {
        if (CountBits(mask) == population) {
            result = std::min(result, NoiseLevel(rows, columns, mask));
        }
    }
    return result;
}

int main()
{
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        int rows, columns, population;
        std::cin >> rows >> columns >> population;
        std::cout << "Case #" << (case_no + 1) << ": " << FindMinNoiseLevel(rows, columns, population) << '\n';        
    }
    return 0;

}
