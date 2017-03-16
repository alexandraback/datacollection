#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
long long barbers[1020];
int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int k = 1; k <= T;k++)
	{
		int m, N;
		cin >> m >> N;
		for (int i = 0; i<m; i++)
		{
			cin >> barbers[i];
		}
		long long a = barbers[0], b = barbers[1];
		for (int i = 1; i<m; i++)
		{
			b = barbers[i];
			a = a*b / gcd(a, b);
		}
		int p = 0;
		for (int i = 0; i<m; i++)
		{
			p += a / barbers[i];
		}
		int res = N%p + p;
		int t[1005], cnt = 0;
		for (int i = 0; i<m; i++)
		{
			t[i] = 0;
		}
		int flag = 0;
		for (int j = 0; j<1000000; j++)//violent try
		{
			if (flag == 1) break;

			for (int i = 0; i<m; i++)
			{
				if (t[i] == 0)
				{
					t[i] = barbers[i];
					t[i]--;
					cnt++;
				}
				else
					t[i]--;
				if (cnt == res)
				{
					cout << "Case #" << k << ": " << i + 1 << endl;
					flag = 1;
					break;
				}
			}
		}

	}
	return 0;
}
/*
long long mc(int a, int b)
{
	long long result = a*b;
	if (a < b)
	{
		int k = b;
		b = a;
		a = k;
	}
	int r = a%b;
	while (r>0)
	{
		a = b; b = r;
		r = a%b;
	}
	result /= b;
	return result;
}
class barber
{

public:
	int number;
	int t;
	barber()
	{
		t = 0; number = 0;
	}
	barber(const barber& b)
	{
		t = b.t;
		number = b.number;
	}
	bool operator<(const barber& b) const
	{
		if (this->t > b.t)
			return true;
		else return false;
	}

};

barber barbers[10];
barber nodes[500];
int main()
{
	//freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small.out", "w", stdout);
	int T; cin >> T; 
	for (int k = 1; k <= T; k++)
	{
		int B; cin >> B; long long N; cin >> N;
		priority_queue<barber> b;
		int time[10]; long long ma = 1;
		for (int i = 0; i < B; i++)
		{
			cin >> barbers[i].t; barbers[i].number = i+1;
			time[i] = barbers[i].t;
			ma = mc(ma, barbers[i].t);
			
		}
		long long index = 0;
		for (int i = 0; i < B; i++)
		{
			barber temp=barbers[0];
			if (i>0)
			{
				if (b.top().t < barbers[i].t)
					temp = b.top();
				else if (b.top().t>barbers[i].t)
					temp = barbers[i];
				else
				{
					if (b.top().number < barbers[i].number)
						temp = b.top();
					else
						temp = barbers[i];
				}
			}
			nodes[index++] = temp;
			temp.t += time[i];
			b.push(temp);
		}
		barber temp = b.top(); b.pop();
		

		while (index<N-1)
		{
			index++;
			temp.t += time[temp.number-1];
			b.push(temp);
			temp = b.top(); b.pop();
		}
		cout << "Case #" << k << ": " << temp.number << endl;
		
	

	}
	return 0;
}*/