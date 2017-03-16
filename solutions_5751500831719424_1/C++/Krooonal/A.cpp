#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <string>
#include <cstring>

using namespace std;

#define DEBUG 0
#define all(C) (C).begin() , (C).end()
#define tr(C , it) for(typeof((C).begin()) it = (C).begin() ; it != (C).end() ; it++)
#define present(C , key) ((C).find(key) != (C).end())
#define cpresent(C , key) (find(all(C) , key) != (C).end())
#define sz(a) int((a).size())
#define pb push_back
#define MOD 1000000007


typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int , int> PI;

struct crap
{
	char c;
	int freq;
};
vector<string> S;
string testS , tempS;
vector< vector< crap > > VVC;
vector<crap> VC;
crap C;
int N;

string findSeq(string s)
{
	int i;
	string ret;
	ret = "";
	VC.clear();
	
	for(i=0 ; i<s.size() ; i++)
	{
		if(i == 0 || s[i] != s[i-1]) 
		{
			ret += s[i]; 
			C.freq = 1 ; 
			C.c = s[i];
			VC.pb(C);
		}
		else
		{
			VC[VC.size()-1].freq++;
		}
	}
	
	return ret;
}

int main()
{
	int __A;
	scanf("%d" , &__A);
	
	
	int flag , i , j , k;
	int sum , minC , ans;
	
	for(int _i = 1 ; _i <= __A ; _i++)
	{
		printf("Case #%d: " , _i);
		scanf("%d" , &N);
		S.clear();
		flag = 1;
		VVC.clear();
		for(i=0 ; i<N ; i++)
		{
			cin >> testS;
			S.pb(testS);
		}
		
		//find the sequence
		testS = findSeq(S[0]);
		VVC.pb(VC);
		for(i=1 ; i<N ; i++)
		{
			tempS = findSeq(S[i]);
			VVC.pb(VC);
			if(tempS != testS)
			{
				flag = 0;
				break;
			}
		}
		if(flag == 0)
		{
			printf("Fegla Won\n");
			continue;
		}
		
		//find the minimim frequency for each charactor
		ans = 0;
		for(i=0 ; i<VC.size() ; i++)
		{
			minC = MOD;
			for(j=1 ; j<= 300 ; j++)
			{
				sum = 0;
				for(k=0 ; k<N ; k++)
				{
					sum += abs(VVC[k][i].freq - j);
				}
				minC = min(minC , sum);
			}
			ans += minC;
			//printf("\nat step %d %d\n" ,i ,  ans);
		}
		printf("%d\n" , ans);
	}
	return 0;
}
