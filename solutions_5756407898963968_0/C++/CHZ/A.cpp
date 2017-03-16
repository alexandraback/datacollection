#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int row1, row2;
    int val1, val2;
    int answer;// Final answer
    int tmp;
    int high, low;
    cin >> TIME;
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	val1 = val2 = 0;
	cin >> row1;
	high = row1*4;
	low = high-5;
	for (int i = 0 ; i < 16; ++i) {
	    cin >> tmp;
	    if (low < i && i < high) {
		val1 |= (1<<(tmp-1));
	    }
	}
	cin >> row2;
	high = row2*4;
	low = high-5;
	for (int i = 0 ; i < 16; ++i) {
	    cin >> tmp;
	    if (low < i && i < high) {
		val2 |= (1<<(tmp-1));
	    }
	}
	val1 &= val2;
	//output
	if (val1 == 0) {
	    printf("Case #%d: Volunteer cheated!\n",t+1);
	}
	else {
	    int count = 0;
	    for (int i = 0 ; i< 16; ++i){
		if (val1 & (1<<i)) {
		    count++;
		    answer = i+1;
		}	
	    }
	    if (count==1) {
		printf("Case #%d: %d\n",t+1, answer);
	    }
	    else {
		printf("Case #%d: Bad magician!\n",t+1);
	    }
	}
    }
    return 0;
}
