#include <cstdio>

int probe(int mask) {
    int ans, n, m;
    
    scanf("%d", &ans);
    m = 0;
    
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &n);
            if (i == ans) {
                m |= (1<<n);
            }
        }
    }
    
    return mask & m;
}

int main() {
    int ntests;

    scanf("%d", &ntests);
    for (int test = 1; test <= ntests; test++) {
        printf("Case #%d: ", test);
    
        int mask = probe( (1<<17) - 1 );
        mask = probe(mask);
        
        int bits = __builtin_popcount(mask); 
        
        if (bits > 1) {
            printf("Bad magician!");
        } else if (bits == 0) {
            printf("Volunteer cheated!");
        } else {
            for (int i = 0; i <= 16; i++) {
                if (mask & (1<<i)) {
                    printf("%d", i);
                }
            }
        }
        
        printf("\n");
    }
    return 0;
}

