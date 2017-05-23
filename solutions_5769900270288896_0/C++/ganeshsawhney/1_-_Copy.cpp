#include <iostream>
#include<stdio.h>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int arr[1 << 18];



int main()
{
    int aarrwer;
    ifstream in("input.txt");
    ofstream out("output.txt");
	int test;
	in >> test;
	int t=1;
int a, b, N;
	while(test--)
	{
		in >> a >> b >> N;
        int best = a * b * N * 100;
		for (int i = 1; i < (1 << (a * b)); i++)
		{
			arr[i]=arr[i-(i&-i)] + 1;
			if (arr[i] == N)
                {
                    aarrwer = 0;
	for (int r = 0; r < a; r++)
	for (int c = 0; c < b; c++)
		{
			if (c > 0 && (i & (1 << (r * b + c))) && (i & (1 << (r * b+ c - 1))))
				aarrwer++;
			if (r > 0 && (i & (1 << (r * b + c))) && (i & (1 << (r * b + c - b))))
				aarrwer++;
		}best = min(best, aarrwer);}
		}
		out<<"Case #"<<t++<<": "<<best<<endl;
	}

    in.close();
    out.close();
}
