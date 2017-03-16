#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <fstream.h>

int main()
{
	/*
	T=Number of test cases
	a=array of 1st arrangement
	b=array of 2nd arrangement
	n1=row 1
	n2=row 2
	*/

	int T, n1, n2, a[4][4], b[4][4], c[4], d[4], m=0, i, j, answer;
	ifstream input;
	ofstream output;
	input.open("input.in");
	output.open("output.txt");
	input>>T;
	for (int l = 1; l <= T; l++) {
		input>>n1;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				input>>a[i][j];
			}
		}
		input>>n2;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				input>>b[i][j];
			}
		}
		for (i = 0; i < 4; i++) {
			c[i]=a[n1-1][i];
		}
		for (i = 0; i < 4; i++) {
			d[i]=b[n2-1][i];
		}
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (c[i]==d[j]) {
					m++;
					answer=c[i];
				}
			}
		}
		if (!m) {
			output<<"Case #"<<l<<": Volunteer cheated!\n";
		}
		else if (m==1) {
			output<<"Case #"<<l<<": "<<answer<<"\n";
		}
		else {
			output<<"Case #"<<l<<": Bad magician!\n";
		}
		m=0;
	}
	input.close();
	output.close();
	getch();
	return 0;
}

