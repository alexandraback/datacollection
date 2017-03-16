#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

using namespace std;

const int maxN = 100 + 10;
const int maxL = 100 + 10;

int occur[maxN][maxL];
int real_len;
char pure[maxL];

int make_unique(char* str, int* num_char) {
	for (int i=0; str[i]; ++i) {
		while (str[i+1] == str[i]) {
			num_char[i] = 0;
			i++;
		}
		num_char[i] = 1;
	}

/*	for (int i=0; str[i]; ++i) {
		cout << str[i];
	}
	cout << endl;
	for (int i=0; str[i]; ++i)
		cout << num_char[i];
	cout << endl;
*/
	int counter = 0;
	int j = 0;
	for (int i=0; str[i]; ++i)
		if (num_char[i] == 0) {
			counter ++;
		} else {
			str[j] = str[i];
			num_char[j] = counter + 1;
			counter = 0;
			j++;
		}
	str[j] = 0;

/*	for (int i=0; str[i]; ++i) {
		cout << str[i];
	}
	cout << endl;
	for (int i=0; str[i]; ++i)
		cout << num_char[i];
	cout << endl;
*/
	return j;
}


int main () {
//	scanf("%s", pure);
//	printf ("%d\n", make_unique(pure, occur[0]));
	int T;
	cin >> T;
	for (int tt=1; tt<=T; ++tt) {
		int N;
		cin >> N;
		scanf ("%s", pure);
		real_len = make_unique(pure, occur[0]);

		int flag = true;
		for (int i=1; i<N; ++i) {
			char temp[maxL];
			scanf ("%s", temp);
			make_unique(temp, occur[i]);
			if (strcmp(pure, temp) != 0)
				flag = false;
		}

		if (!flag)
			cout << "Case #" << tt << ": Fegla Won" << endl;
		else {
			int total_move = 0;
			for (int k=0; k<real_len; ++k) {
				int min_move = INT_MAX;
				for (int i=0; i<N; ++i) {
					int this_move = 0;
					for (int j=0; j<N; ++j)
						this_move += abs(occur[i][k] - occur[j][k]);
					if (this_move < min_move)
						min_move = this_move;
				}
				total_move += min_move;
			}
			cout << "Case #" << tt << ": " << total_move << endl;
		}
	}
	return 0;
}
