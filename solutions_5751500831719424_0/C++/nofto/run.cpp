#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

class Word{
  public:
	vector <char> letter;
	vector <int> count;
	Word(string word){
		char prev='0';
		int size=0;
		for(int i=0;i<word.length();i++){
			if(word[i]==prev){
				count[size-1]++;
			}
			else{
				size++;
				prev=word[i];
				letter.push_back(prev);
				count.push_back(1);
			}
		}
	}
	Word(){};
};

int main()
{
	int T;
	//scanf("%d",&T);  
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		int N;
		cin >> N;
		vector <Word> word(N);
		for(int i=0;i<N;i++){
			string line;
			cin >> line;
			word[i]=Word(line);
		}
		int L=word[0].letter.size();
		bool feglawon=false;
		for(int i=1;i<N;i++){
			if(word[i].letter.size()!=L){
				feglawon=true;
				break;
			}
			for(int j=0;j<L;j++){
				if(word[i].letter[j]!=word[0].letter[j]){
					feglawon=true;
					break;
				}
			}
			if(feglawon) break;
		}
		int steps=0;
		if(!feglawon){
			for(int i=0;i<L;i++){
				vector <int> number(N);
				for(int j=0;j<N;j++) number[j]=word[j].count[i];
				sort(number.begin(),number.end());
				int median=number[N/2];
				for(int j=0;j<N;j++) steps+=abs(median-number[j]);
			}
		}
		if(feglawon) printf("Case #%d: Fegla Won\n",t);
		else  printf("Case #%d: %d\n",t,steps);
	}
  return 0;
}
