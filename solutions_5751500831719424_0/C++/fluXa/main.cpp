#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

struct Entry {
    char chr;
    int count;
};

void solve(int count) {
    printf("Case #%d: ", count);
 
    int numStrings = 0;
    scanf("%d\n", &numStrings);

    char str[101];
    vector<Entry*> entries[101];
    int numChars = -1;
    for (int i = 0; i < numStrings; ++i) {
        scanf("%s\n", str);
        Entry* last = nullptr;
        
        for (int j = 0; j < strlen(str); ++j) {
            if (last == nullptr || str[j] != last->chr) {
                last = new Entry;
                last->chr = str[j];
                last->count = 1;
                entries[i].push_back(last);
            } else {
                last->count++;
            }
        }
        
        if (numChars == -1) numChars = entries[i].size();
        else if (numChars != entries[i].size()) {
            printf("Fegla Won\n");
            return;
        }
        
        for (int j = 0; j < entries[i].size(); ++j) {
            //printf("%d*%c ", entries[i][j]->count, entries[i][j]->chr);
        }
        //printf("\n");
    }
    
    int sum2 = 0;
    for (int j = 0; j < numChars; ++j) {
        int sum = 0;
        char chr = entries[0][j]->chr;
        for (int i = 0; i < numStrings; ++i) {
            if (entries[i][j]->chr != chr) {
                printf("Fegla Won\n");
                return;
            }
            sum += entries[i][j]->count;
        }
        float medianF = ((float)sum)/((float)numStrings);
        int median = (int)(medianF + 0.5f);
        for (int i = 0; i < numStrings; ++i) {
            int d = entries[i][j]->count - median;
            if (d < 0) d = -d;
            sum2 += d;
        }
    }
    
    printf("%d\n", sum2);
}

int main(int argc, const char * argv[]) {
	int numCases = 0;
  	scanf("%d\n", &numCases);
    
    for (int count = 1; count <= numCases; ++count) {
        solve(count);
    }
    return 0;
}

