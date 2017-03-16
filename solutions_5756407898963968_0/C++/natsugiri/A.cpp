#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

void F(bool A[16]) {
    int R, B;
    scanf("%d", &R);
    for (int i=0; i<4; i++) {
	for (int j=0; j<4; j++) {
	    scanf("%d", &B);
	    if (i != R-1) A[B-1] = true;
	}
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	bool A[16] = {};
	F(A); F(A);
	vector<int>guess;

	for (int i=0; i<16; i++)
	    if (!A[i]) guess.push_back(i+1);


	printf("Case #%d: ", tc);
	
	if (guess.size() == 0) puts("Volunteer cheated!");
	else if (guess.size() > 1) puts("Bad magician!");
	else printf("%d\n", guess[0]);
    }
    return 0;
}
