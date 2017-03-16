#include <iostream>

int eval(int R, int C, int v) {
    int ret = 0;
    int pr = 0;
    for(int i = 0; i < R; i ++) {
        //std::cout << "Row " << i << std::endl;
        int cr = v&((1<<C)-1);
        //std::cout << "\tpr: " << std::hex << pr << std::dec << std::endl;
        //std::cout << "\tcr: " << std::hex << cr << std::dec << std::endl;
        v >>= C;
        //std::cout << "\tret before: " << ret << std::endl;

        //std::cout << "\tcurrent: " << __builtin_popcount((cr & (cr>>1))) << std::endl;
        //std::cout << "\twprev: " << __builtin_popcount(cr & pr) << std::endl;
        ret += __builtin_popcount(cr & (cr >> 1));
        ret += __builtin_popcount(pr & cr);
        pr = cr;
    }
    //std::cout << ret << std::endl;
    return ret;
}

int main() {
    int T;
    std::cin >> T;
    int Ca = 1;
    while(T--) {
        int N, R, C;
        //std::cin >> N >> R >> C;
        std::cin >> R >> C >> N;

        int best = 1<<20;
        for(int i = 0; i < (1<<(R*C)); i ++) {
            if(__builtin_popcount(i) != N) continue;
            //std::cout << std::hex << i << std::dec << std::endl;
            best = std::min(best, eval(R, C, i));
        }
        std::cout << "Case #" << (Ca++) << ": " << best << std::endl;
    }
    return 0;
}
