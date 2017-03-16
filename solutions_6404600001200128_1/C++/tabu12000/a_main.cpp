#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    FILE * out;
    FILE * f;

    f = fopen("large.txt", "r");
    out = fopen("large_out.txt", "w");

    int t;
    fscanf(f, "%i", &t);
    for(int i = 0; i < t; i++){
        vector<int> thing;
        int n;
        fscanf(f, "%i", &n);
        int last = 0;
        int current;
        int eaten = 0;
        int max_dif = 0;
        for(int j = 0; j < n; j++){
            fscanf(f, "%i", &current);
            if(current < last){
                eaten += last - current;
            }
            if(last - current > max_dif){
                max_dif = last - current;
            }
            thing.push_back(current);
            last = current;

        }
        int eatan2 = 0;
        for(int j = 0; j < n - 1; j++){
                eatan2 += min(thing[j], max_dif);
        }
        fprintf(out, "Case #%i: %i %i\n", i + 1, eaten, eatan2);
    }


    fclose(f);
    fclose(out);
    return 0;
}
