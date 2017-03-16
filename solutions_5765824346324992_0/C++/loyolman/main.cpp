#include <iostream>
#include <vector>
#include <algorithm>

//YOLO
//loyolman

using namespace std;

vector<int> v;

long long rek(long long l, long long r, long long final) {
	//<)
	long long s=(l+r)/2;
	long long people=0;//started in this minute
	long long l_people=0;//done before this minute
	
	for (int i=0;i<v.size();i++) {
		people+=s/v[i]+1;
		l_people+=(s-1)/v[i]+1;
	}
	if ((l_people<final) && (final<=people)) {
		for (int i=0;i<v.size();i++) {
			if ((s-1)/v[i]<s/v[i]) l_people++;
			if (l_people==final) return i;
		}
	}
	else {
		if (people<final) return rek(s,r,final);
		else return rek(l,s,final);
	}
}

int main() {
	int T;
	cin>>T;
	for (int j=1;j<=T;j++) {
		int B,N;
		v.clear();
		cin>>B>>N;
		for (int i=0;i<B;i++) {
			int h;
			cin>>h;
			v.push_back(h);
		}
		
		cout<<"Case #"<<j<<": "<<rek(0,10000000000000,N)+1<<endl;
	}
	return 0;
}
