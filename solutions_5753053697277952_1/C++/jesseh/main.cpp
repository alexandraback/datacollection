#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int testCase=0; testCase<T; testCase++){
        int n;
        vector<pair<int, int> > parties;
        int total = 0;
        scanf("%d", &n);
        for(int i =0; i<n; i++){
       		int temp;
       		scanf("%d", &temp);
       		parties.push_back(make_pair(temp,i));
       		total+=temp;
        }    
        int done = 0;
        //sort(parties.begin(), parties.end());
        /*for(auto t: parties){
        	char ch = 'A' + t.second;
        	cout << ch << " " << t.first << endl;
        }*/
        cout << "Case #" << testCase+1 << ":";
        while(done < total){
       		cout << " ";
        	sort(parties.begin(), parties.end());
        	int i = parties.size() -1;
        	parties[i].first -= 1;
        	done+=1;
        	char ch = 'A' + parties[i].second;
        	cout << ch;
        	if(total-done > 2 || total-done == 1){
        		parties[i-1].first -= 1;
        		done+=1;
        		char ch = 'A' + parties[i-1].second;
        		cout << ch;
        	}
        }
        cout << endl;
        
        //char ch = 'A' + i;
        //printf("Case #%d: %d\n",testCase+1, oplossing);
    }
    return 0;
}

