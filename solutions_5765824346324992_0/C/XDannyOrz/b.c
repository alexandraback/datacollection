#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long gcd(long, long);
long lcm(long, long);

int main(void) {
	int TestCase, T;
    int B, N;
    int i;
    long Bmin[1020];
    long Bnow[1020];
    int result;
    int min;
    int thismin;
    int found;
    long lcmval;
    long period;
    //FILE* in_file = fopen("b.in", "r");
    FILE* in_file = fopen("b-small3.in", "r");
    //FILE* in_file = fopen("b-large.in", "r");
    
    //FILE* out_file = fopen("b.out", "w");
    FILE* out_file = fopen("b-small3.out", "w");
    //FILE* out_file = fopen("b-large.out", "w");

	fscanf(in_file, "%d", &TestCase);
    
    for (T = 1; T <= TestCase; T++) {
        result = 1;
        min = 100000;
        found = 0;
        lcmval = 0;
        period = 0;
        
        fscanf(in_file, "%d", &B); // total num of Barbers
        fscanf(in_file, "%d", &N); // my position
        // main program here
        
        for (i = 0; i < B; i++) {
            fscanf(in_file, "%ld", &Bmin[i]);
            if (Bmin[i] < min) {
                min = Bmin[i];
            }
            Bnow[i] = 0;
            if (lcmval == 0) {
                lcmval = Bmin[i];    
            }
            else {
                lcmval = lcm(lcmval, Bmin[i]);   
            }
        }
        
        for (i = 0; i < B; i++) {
            period += (lcmval / Bmin[i]);
        }
        
        if (N > period) {
           N = N % period + period;
        }
        
        //fprintf(out_file,"LCM: %d\n", lcmval);
        //fprintf(out_file,"N: %d\n", N);
        //for (i = 0; i < B; i++) {
            //fprintf(out_file,"B(%d): %d\n",i, Bmin[i]);
        //}
        
        if (N > B) {
            // Find LCM reduce N
            
            for (i = 0; i < B; i++) {
                Bnow[i] += Bmin[i];
                N--;
                if (N == 0) { // My turn
                    result = (i+1); // the #i+1 barber serve me
                    found = 1;
                }
            }
            
            while (found == 0) {
                thismin = min;
                min = 100000;
                for (i = 0; i < B; i++) { // X minite passed
                    Bnow[i] -= thismin;
                    if (Bnow[i] == 0) {
                        Bnow[i] += Bmin[i]; // Reset cutting time
                        if (Bnow[i] < min) {
                            min = Bnow[i];
                        }
                        N--;     // -1 customer
                        if (N == 0) { // My turn
                            result = (i+1); // the #i+1 barber serve me
                            found = 1; // Exit loop
                            break;
                        }
                        else {
                            if (Bnow[i] < min) {
                                min = Bnow[i];    
                            }
                        }
                    }
                    else {
                        if (Bnow[i] < min) {
                            min = Bnow[i];    
                        }
                    } 
                }
            }
        }
        else // B >= N
        {
            result = N;
        }
        
        fprintf(out_file ,"Case #%d: %d\n", T, result);
    }
    
    fclose(in_file);
    fclose(out_file);
	return 0;
}

 long gcd( long x, long y) {
  if (x == 0) {
    return y;
  }
 
  while (y != 0) {
    if (x > y) {
      x = x - y;
    }
    else {
      y = y - x;
    }
  }
 
  return x;
}

 long lcm(long x, long y) {
    long hcf;
    long lcm;
     hcf = gcd(x, y);
    lcm = (x*y)/hcf; 
    return lcm;  
}
