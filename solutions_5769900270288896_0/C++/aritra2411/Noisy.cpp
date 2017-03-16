#include <iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<math.h>

int gcd(int a, int b)
{
	if(a%b==0)
	return a;
	else
	return gcd(b,a%b);
}
int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}


using namespace std;

int cont[1 << 18];
int A, B, C;

int john(int petrucci)
{
	int answer = 0;
	for (int p = 0; p<A; p++)
	{
		for (int c = 0; c<B; c++)
		{
			if (c > 0 and (petrucci & (1 << (p * B + c))) and (petrucci & (1 << (p *B + c - 1))))
				answer++;
			if (p > 0 and (petrucci & (1 << (p * B + c))) and (petrucci & (1<<(p * B + c - B))))
				answer++;
		}
	}
	return answer;
}

int main()
{
    freopen("question.txt","r",stdin);
 	freopen("answer.txt","w",stdout);

	int D;
	cin >>D;
	for (int n = 1; n<= D; n++)
	{
		cin >>A>>B>>C;

		int best = A*B*C * 100;
		for (int petrucci = 1; petrucci<(1 <<(A*B)); petrucci++)
		{
			 cont[ petrucci] = cont[petrucci - (petrucci & -petrucci)] + 1;
			if (cont[petrucci] == C) best = min(best, john(petrucci));
		}
		cout<<"Case #"<<n<<": "<<best<<endl;
	}
}
