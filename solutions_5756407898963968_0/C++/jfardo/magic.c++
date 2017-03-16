#include <iostream>
#include <fstream>
#include <stdint.h>

const unsigned NUM_COLS = 4;
const unsigned NUM_ROWS = 4;

uint16_t IntersectionToNum(uint16_t intersection)
{
    const uint16_t b[] = {
        0xAAAA,
        0xCCCC,
        0xF0F0, 
        0xFF00,
        0x0000
    };
    uint16_t r = (intersection & b[0]) != 0;
    for (unsigned i = 4; i > 0; i--) {
        r |= ((intersection & b[i]) != 0) << i;
    }
    return r + 1;
}            

void DoMagicTrick(uint16_t* cards1,
                  uint16_t* cards2,
                  unsigned  rowChosen1,
                  unsigned  rowChosen2)
{
    uint16_t first_row_chosen  = *(cards1+rowChosen1-1);
    uint16_t second_row_chosen = *(cards2+rowChosen2-1);

    uint16_t intersection = first_row_chosen & second_row_chosen;

    // Check if the second row chosen contains at least one of the numbers
    // from the first row chosen. If it doesn't print 'Volunteer cheated!'
    if (intersection == 0) {
        std::cout << "Volunteer cheated!\n";
        return;
    }

    // Check that the intersection of the 2 rows only contains a single number.
    // The intersection should be a power of 2.
    // If not, print 'Bad magician!'
    if ((intersection & (intersection-1)) != 0) {
        std::cout << "Bad magician!\n";
        return;
    }

    // Print the number that is only in both rows.
    std::cout << IntersectionToNum(intersection) << '\n';
}

void GetAnswerAndCards(std::istream& istr,
                       unsigned*     chosenRow,
                       uint16_t*     cards)
{
    istr >> *chosenRow;

    for (unsigned i = 0; i < NUM_ROWS; ++i) {
        // Use a bit mask to represent each number
        uint16_t row = 0;
        for (unsigned j = 0; j < NUM_COLS; ++j) {
            unsigned num;
            istr >> num;
            row |= 1 << (num-1);
        }
        *(cards+i) = row;
    }
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cout << "Missing file containing input\n";
        return -1;
    }

    std::ifstream istr(argv[1]);

    // Read in the number of test cases.
    unsigned T;
    istr >> T;

    // Each row is represented by a single uint16_t with 4 bits set.
    // Each bit represents one of the numbers between 1-16 (bits 0-15).
    for (unsigned i = 1; i <= T; ++i) {
        unsigned row_chosen1;
        uint16_t cards1[NUM_ROWS];

        GetAnswerAndCards(istr, &row_chosen1, &cards1[0]);

        unsigned row_chosen2;
        uint16_t cards2[NUM_ROWS];

        GetAnswerAndCards(istr, &row_chosen2, &cards2[0]);

        std::cout << "Case #" << i << ": ";
        DoMagicTrick(&cards1[0], &cards2[0], row_chosen1, row_chosen2);
    }

    return 0;
}
