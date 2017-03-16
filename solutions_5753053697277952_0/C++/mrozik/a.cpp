#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<string> result;

int actual[26];
int tbd[26];
int tbdsum, actualsum, largest;
int N;

bool canAdd(int ix) {
    if (tbd[ix] <= 0) return false;
    int newlargest = max(actual[ix]+1, largest);
    int newsum = actualsum +1;
    return newlargest*2 <= newsum;
}


bool canAdd(int ix, int iy) {
    if (ix == iy) {
        if (tbd[ix] <= 1) return false;
    }
    else {
        if (tbd[ix] <= 0 || tbd[iy] <= 0) return false;

    }
        
    int newlargest;
    if (ix == iy)
        newlargest = max(actual[ix]+2, largest);
    else
        newlargest = max(max(actual[ix]+1, actual[iy]+1), largest);
    int newsum = actualsum +2;
    return newlargest*2 <= newsum;
}

void add(int ix) {
    actual[ix]++;
    tbd[ix]--;
    actualsum++;
    tbdsum--;
    string s = "X";
    s[0] = 'A'+ix;
    result.push_back(s);
}

void add(int ix, int iy) {
    actual[ix]++;
    tbd[ix]--;
    actual[iy]++;
    tbd[iy]--;
    actualsum+=2;
    tbdsum-=2;
    string s = "XY";
    s[0] = 'A'+ix;
    s[1] = 'A'+iy;
    result.push_back(s);
}


int main() {
    int Z; scanf("%d", &Z);
    for (int z=1; z<=Z; z++) {
        scanf("%d", &N);
        actualsum = tbdsum = 0;
        for (int i=0; i<N; i++) scanf("%d", &tbd[i]), tbdsum += tbd[i], actual[i]=0;;
        largest = 0;
        result.clear();
                
        while (tbdsum > 0) {
            for (int ix=0; ix<N; ix++)
                if (canAdd(ix)) {
                    add(ix);
                    break;
                }
            for (int ix=0; ix<N; ix++)
                for (int iy=0; iy<N; iy++)
                    if (canAdd(ix, iy)) {
                        add(ix, iy);
                        break;
                    }
        }
        
        printf("Case #%d:", z);
        for (int i=result.size()-1; i>=0; i--) {
            printf(" %s", result[i].c_str());
            
        }
        printf("\n");
        
    }
    return 0;
}
