#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int T, r1, r2;

int main() {
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int count = 0, ans = 0, aux;
        set<int> n1;
        
        cin >> r1;
        
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                if (r1 == j+1) {
                    cin >> aux;
                    n1.insert(aux);
                } else
                    cin >> aux;
        
        cin >> r2;
        
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                if (r2 == j+1) {
                    cin >> aux;
                    if (n1.count(aux)!=0) {
                        count++;
                        ans = aux;
                    }
                } else
                    cin >> aux;
                
        printf("Case #%d: ", i+1);
        if (count == 0)
            printf("Volunteer cheated!\n");
        else if (count > 1 )
            printf("Bad magician!\n");
        else
            printf("%d\n", ans);
    
    }
        
    
    return 0;
} 
