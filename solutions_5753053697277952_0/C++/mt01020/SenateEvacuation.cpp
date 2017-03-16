#include<iostream>
#include<queue>
#include<utility>
using namespace std;

priority_queue< pair<int, char> > nmems;

int main(){
    int T, N, pi, tt;
    cin >> T;
    for(int t=1; t<=T; ++t){
	cin >> N;
	tt = 0;
	for(int i=0; i<N; ++i){
	    cin >> pi;
	    nmems.push(make_pair(pi, 'A'+i));
	    tt += pi;
	}
	cout << "Case #" << t << ":";
	int ct;
	char cp;
	while(!nmems.empty()){
	    cout << " ";
	    ct = nmems.top().first;
	    cp = nmems.top().second;
	    nmems.pop();
	    cout << cp;
	    if(ct-1 > 0) nmems.push(make_pair(ct-1, cp));
	    --tt;
	    if(nmems.top().first > tt/2){
		ct = nmems.top().first;
		cp = nmems.top().second;
		nmems.pop();
		cout << cp;
		if(ct-1 > 0) nmems.push(make_pair(ct-1, cp));
		--tt;
	    }
	}
	cout << endl;
    }
    return 0;
}
