#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, cases = 1;
    cin >> t;
    while (t--){
        priority_queue< pair<int, int > >q;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++){
        	int a;
        	cin >> a;
        	q.push(make_pair(a,i));
        }

        cout << "Case #" << cases++ << ":";

        while (!q.empty()){
        	cout << " ";

        	pair<int, int> ret = q.top();
        	q.pop();
        	
        	cout << char(ret.second+'A');
        	ret.first--;

        	if (q.size()%2 == 1){
        		pair<int, int> ret2 = q.top();
        		q.pop();

        		cout << char(ret2.second+'A');
        		ret2.first--;

        		if (ret2.first)
        			q.push(ret2);
        	}

        	if (ret.first)
        		q.push(ret);
        	//break;
        	
        }

        cout << endl;

        
    }
    return 0;
}
