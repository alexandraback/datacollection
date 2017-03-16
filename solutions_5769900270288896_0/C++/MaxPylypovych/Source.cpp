#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int bitCounter(int n) {
	int count = 0;
	while (n != 0) {
		count++;
		n = n & (n - 1);
	}
	return count;
}

int pp(int p)
{
	int a = 1;
	for (int i = 0; i < p; ++i)
		a *= 2;
	return a;
}

int main()
{
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");

	//	FILE * input;
	//	input = fopen("input.txt","r");

	int T;

	//	fread(&n, sizeof(int), 1, input);cout<<n<<endl; char cc=getchar();

	input >> T;// cout<<n<<endl;
	//cin >> T;

	//ull N=1000001;
	//int* a = new int[N];
	//int* a = (int*)malloc(sizeof(int)*N);


	//cout << N;

	//	a[0] = 0;


	//	for (ull i = 1; i < N; ++i)
	//	{
	//if ((reverse(i) < i) && (i%10))
	//			a[i] = 1 + min(a[i - 1], a[reverse(i)]);
	//		else
	//			a[i] = 1 + a[i - 1];
	//	}
	//system("pause");

	int r,c,n;
	int m,cur,tmp;
	int** a = new int*[20];
	for (int i = 0; i < 20; ++i)
		a[i] = new int[20];

	for (int t = 0; t < T; ++t)
	{
		input >> r>>c>>n;
		
		m = 9999;
		for (int i = 0; i < pp(r*c); ++i)
		{
			if (bitCounter(i) == n)
			{
				for (int j = 1,p=0; j <= pp(r*c); j<<=1,++p)
				{
					a[p / c][p%c] = (j&i?1:0);
				}

				for (int X = 0; X < r; ++X)
				{
					for (int Y = 0; Y < c; ++Y)
					{
					//	cout << a[X][Y];

					}
				//	cout << endl;
				}
			//	cout << endl;

				cur = 0;
				tmp = 0;
				for (int x = 0; x < r; ++x)
				{
					tmp = 0;
					for (int y = 0; y < c; ++y)
					{
						tmp = 0;
						if (a[x][y])
						{

							if (x - 1 >= 0)
								tmp += a[x - 1][y];
							if (x + 1 < r)
								tmp += a[x + 1][y];
							if (y - 1 >= 0)
								tmp += a[x][y - 1];
							if (y + 1 < c)
								tmp += a[x][y + 1];
							cur += tmp;//(tmp > 0);
						}
					}
				}
				if (cur/2 < m)
					m = cur/2;
			}
		}

		//output << "Case #" << t + 1 << ": " << a[x] << endl;
		output << "Case #" << t + 1 << ": " << m << endl;
		//cout  << "Case #" << t + 1 << ": " << a[x] << endl;

		//system("pause");
	}
	//system("pause");
	//	fclose(input);
	input.close();
	output.close();
	//	system("pause");
	return 0;
}
