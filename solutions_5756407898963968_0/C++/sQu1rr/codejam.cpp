#include <iostream>


int main() {
    int size;
    std::cin >> size;

    for(int i = 0; i < size; ++i) {
        int row;
        std::cin >> row;

        bool test[16];
        for(int j = 0; j < 16; ++j) test[j] = false;

        int temp;
        for(int j = 0; j < 4; ++j) {
            for(int z = 0; z < 4; ++z) {
                std::cin >> temp;
                if(j == row - 1) {
                    test[temp - 1] = true;
                }
            }
        }

        int card;
        int count = 0;
        std::cin >> row;
        for(int j = 0; j < 4; ++j) {
            for(int z = 0; z < 4; ++z) {
                std::cin >> temp;
                if(j == row - 1) {
                    if(test[temp - 1]) {
                        card = temp;
                        count++;
                    }
                }
            }
        }
        std::cout << "Case #" << i + 1 << ": ";
        if(count == 1) std::cout << card;
        else if(count > 0) std::cout << "Bad magician!";
        else std::cout << "Volunteer cheated!";
        std::cout << std::endl;
    }
}
