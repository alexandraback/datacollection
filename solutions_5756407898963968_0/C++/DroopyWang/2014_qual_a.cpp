#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>

void solve(int id) {
	// local variables
    int rowa, rowb;
    int a[4], b[4];
	// read data
    std::cin>>rowa;
    int temp;
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin>>temp;
            if (i == rowa) a[j] = temp;
        }
    }
    
    std::cin>>rowb;
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin>>temp;
            if (i == rowb) b[j] = temp;
        }
    }
    int count = 0;
    int ret = -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i] == b[j]) {
                count++;
                ret = a[i];
            }
        }
    }
    if (count == 0) printf("Case #%d: Volunteer cheated!\n", id);
    else if (count > 1) printf("Case #%d: Bad magician!\n", id);
    else printf("Case #%d: %d\n", id, ret);
}

int main(int argc, char *argv[]) {
	int t = 0;
	std::cin>>t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}