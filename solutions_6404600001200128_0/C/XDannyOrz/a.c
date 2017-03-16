#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int TestCase, T;
	int i;
    int N;
    int Mush[10010];
    int y, z;
    int rate;
    //FILE* in_file = fopen("a.in", "r");
    FILE* in_file = fopen("a-small.in", "r");
    //FILE* in_file = fopen("a-large.in", "r");
    
    //FILE* out_file = fopen("a.out", "w");
    FILE* out_file = fopen("a-small.out", "w");
    //FILE* out_file = fopen("a-large.out", "w");

	fscanf(in_file, "%d", &TestCase);
    
    for (T = 1; T <= TestCase; T++) {
        y = 0;
        z = 0;
        rate = 0;
        fscanf(in_file, "%d", &N); // N intervals
        for (i = 0; i < N; i++) {
            fscanf(in_file, "%d", &Mush[i]); // Scan values of intervals
            if (i != 0) {
                if ((Mush[i-1] - Mush[i]) > 0) {
                    y = y + Mush[i-1] - Mush[i];
                    if (Mush[i-1] - Mush[i] > rate) {
                        rate = Mush[i-1] - Mush[i];
                    }    
                }
            }  
        }
        
        for (i = 0; i < N-1; i++) {
            if (Mush[i] >= rate) {
                z = z + rate; 
            }
            else {
                z = z + Mush[i];    
            }
        }
        
        
        // main program here
        fprintf(out_file ,"Case #%d: %d %d\n", T, y, z);
    }
    
    fclose(in_file);
    fclose(out_file);
	return 0;
}
