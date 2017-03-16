#include <iostream>

static inline void game (size_t caseidx) {
    bool ruled_out[17] = {0};

    for (size_t rounds=0; rounds<2; ++rounds) {
        size_t lineidx;
        size_t line[4];
        std::cin >> lineidx;
        for (size_t l=1; l<=4; ++l) {
            std::cin >> line[0] >> line[1] >> line[2] >> line[3];
            if (l != lineidx)
                for (size_t i=0; i<4; ++i) 
                    ruled_out[line[i]] = true;
        }
    }

    size_t res = 0;
    size_t nres = 0;
    for (size_t i=1; i<=16; ++i)
        if (!ruled_out[i]) {
            res = i;
            ++nres;
        }

    std::cout << "Case #" << caseidx << ": ";
    switch (nres) {
        case 0:
            std::cout << "Volunteer cheated!";
            break;
        case 1:
            std::cout << res;
            break;
        default:
            std::cout << "Bad magician!";
    }
    std::cout << std::endl;
}

int main () {
    size_t games;
    std::cin >> games;
    for (size_t i=1; i<=games; ++i)
        game(i);

    return 0;
}
