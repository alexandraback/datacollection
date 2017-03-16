#include <iostream>
#include<stdio.h>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int arr[1 << 18];

    int aarrwer;

int a, b, N;

void fun(int i)
{
aarrwer = 0;
	for (int r = 0; r < a; r++)
	for (int c = 0; c < b; c++)
		if ((c > 0 && (i & (1 << (r * b + c))) && (i & (1 << (r * b+ c - 1)))) || (r > 0 && (i & (1 << (r * b + c))) && (i & (1 << (r * b + c - b)))))
				aarrwer++;
}
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
	int test;
	in >> test;
	int t=1;
	while(test--)
	{in >> a >> b >> N;
        int best = a * b * N * 100;
		for (int i = 1; i < (1 << (a * b)); i++)
		{
			arr[i]=arr[i-(i&-i)] + 1;
			if (arr[i] == N)
                {
                    fun(i);

				best = min(best, aarrwer);}
		}
		out<<"Case #"<<t++<<": "<<best<<endl;
	}

    in.close();
    out.close();
}
