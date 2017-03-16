#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct barber
{
	unsigned long long int num;
	unsigned long long int time0;
	unsigned long long int time;
} Barber;

int compare1(const void *a, const void *b)
{
	Barber *p1 = (Barber *)a;
	Barber *p2 = (Barber *)b;
	
	if(p1->time < p2->time)
		return -1;
	else if(p1->time > p2->time)
		return 1;
	else if(p1->num < p2->num)
		return -1;
	else if(p1->num > p2->num)
		return 1;
	else
		return 0;
}

int lcm(unsigned long long int a, unsigned long long int n)
{
	unsigned long long int multiplier = a * n;
	unsigned long long int k;
	
	while (a % n != 0)
	{
		k = a % n;
		a = n;
		n = k;
	}
	
	return multiplier / n;
}

int main()
{
	int t;
	unsigned long long int b;
	unsigned long long int n;
	Barber m[10000];
	unsigned long long int answer1 = 0;
	unsigned long long int ans_lcm;
	unsigned long long int lcm_temp = 0;
	unsigned long long int temp = 1;
	cin >> t;
	
	for(int i = 0; i < t; i++)
	{
		answer1 = 0;
		lcm_temp = 0;
		temp = 1;

		cin >> b >> n;
		
		cin >> m[0].time;
		m[0].time0 = m[0].time;
		m[0].num = 1;
		ans_lcm = m[0].time;
		
		for(int j = 1; j < b; j++)
		{
			cin >> m[j].time;
			m[j].time0 = m[j].time;
			m[j].num = j + 1;
			ans_lcm = lcm(ans_lcm, m[j].time);
		}
		
		for(int j = 0; j < b; j++)
		{
			lcm_temp += ans_lcm / m[j].time;
		}
		
		n %= lcm_temp;
		
		if(n == 0)
			n += lcm_temp;
		
		if(b >= n)
		{
			answer1 = n;
			cout << "Case #" << i + 1 << ": " << answer1 << "\n";
			continue;
		}
		
		temp += (b - 1);
		
		while(temp <= n)
		{
			qsort(m, b, sizeof(Barber), compare1);
			temp++;
			m[0].time += m[0].time0;
			if(temp == n)
			{
				answer1 = m[0].num;
				break;
			}
			for(int j = 1; j < b; j++)
			{
				if(m[j].time != (m[j - 1].time - m[j - 1].time0))
					break;
				temp++;
				m[j].time += m[j].time0;
				if(temp == n)
				{
					answer1 = m[j].num;
					break;
				}
			}
		}		
		
		cout << "Case #" << i + 1 << ": " << answer1 << "\n";
	}
	
	return 0;
}