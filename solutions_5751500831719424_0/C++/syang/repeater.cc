#include <iostream>
#include <fstream>
using namespace std;

char *get_core(char *str) {
    char *core = new char[202];
    
    char last = '\0';
    int count = 1;
    int next_pos = 0;
    for (int i = 0; i < 101; i++) {
        if (str[i] != last) {
            last = str[i];
            core[next_pos++ * 2] = last;
            count = 1;
            core[next_pos * 2 - 1] = count;
        } else {
            count++;
            core[next_pos * 2 - 1] = count;
        }
        
        if (last == '\0') {
            return core;
        }
    }
}

int main(int argc, char* *argv) {
    ifstream f;
    f.open(argv[1]);
    
    int count;
    f >> count;
    //printf("There are %d cases!\n", count);
    
    for (int i = 0; i < count; i++) {
        int number;
        f >> number;
        //printf("There are %d strings!\n", number);
        f.get();
        
        char* *strs = new char*[number];
        char* *cores = new char*[number];
        for (int j = 0; j < number; j++) {
            strs[j] = new char[101];
            f.getline(strs[j], 101, '\n');
            
            
            //printf("The string is %s\n", strs[j]);
            
            cores[j] = get_core(strs[j]);
            for (int s = 0; s < 101; s++) {
                if (cores[j][s * 2] == '\0')break;
                
                //printf("%c: %d\n", cores[j][s * 2], cores[j][s * 2 + 1]);
            }
        }
        
        int total = 0;
        for (int s = 0; s < 101; s++) {
            char last = cores[0][s * 2];
            int min = 100, max = 1;
            for (int j = 0; j < number; j++) {
                if (cores[j][s * 2] != last) {
                    total = -1;
                    break;
                }
                
                if (cores[j][s * 2 + 1] < min) {
                    min = cores[j][s * 2 + 1];
                }
                
                if (cores[j][s * 2 + 1] > max) {
                    max = cores[j][s * 2 + 1];
                }
            }
            
            int attempt = number * 100;
            for (int t = min; t <= max; t++) {
                int acc = 0;
                for (int j = 0; j < number; j++) {
                    if (cores[j][s * 2 + 1] < t) {
                        acc += t - cores[j][s * 2 + 1];
                    }
                    
                    if (cores[j][s * 2 + 1] > t) {
                        acc += cores[j][s * 2 + 1] - t;
                    }
                }
                
                if (acc < attempt)attempt = acc;
            }
            if (total == -1)break;
            if (last == '\0')break;
            
            total += attempt;
            //printf("%c: %d <-> %d OPT = %d\n", cores[0][s * 2], min, max, attempt);
        }
        
        if (total == -1) {
            printf("Case #%d: Fegla Won\n", i + 1);
        } else {
            printf("Case #%d: %d\n", i + 1, total);
        }
        
        delete [] strs, cores;
    }
    
    
}