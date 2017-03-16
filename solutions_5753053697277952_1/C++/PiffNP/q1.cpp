#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define LEN 3000
#define FOR(a, b, c) for(int a = (b); a < (c); a++)

int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int tt = 0; tt < t; tt++){
        int n;
        fscanf(fp1, "%d", &n);
        int a[30] = {0};
        int sum = 0;
        FOR(i, 0, n){
            fscanf(fp1, "%d", &a[i]);
            sum += a[i];
        }        
        fprintf(fp2, "Case #%d:", tt + 1);
        while(sum > 0){
            int party, max, which;
            party = 0;
            max = 0;
            which = -1;
            for(int i = 0; i < n; i++){
                if(a[i] > 0)
                    party++;
                if(max < a[i])
                    max = a[i], which = i;
            }
            if(party > 2){
                sum--;
                a[which]--;
                fprintf(fp2, " %c", 'A' + which);
            } else if (party == 2 && sum % 2 != 0){
                sum--;
                a[which]--;
                fprintf(fp2, " %c", 'A' + which);
            } else {
                fprintf(fp2, " ");
                sum -= 2;
                for(int i = 0; i < n; i++)
                    if(a[i] != 0){
                        a[i]--;
                        fprintf(fp2, "%c", 'A' + i);           
                    }
            }
        }

        fprintf(fp2, "\n");
    }
    return 0;
}
