#include<bits/stdc++.h>
using namespace std;

pair<int, int> findnext(int arr[], int sum, int n){
	int avg=sum/n;
	pair<int, int> p;
	vector<int> v;
	int i;
	for(i=0;i<n;i++){
		if(arr[i]>=sum)v.push_back(i);
	}
	int max1=0, max2=0, pos1=-1, pos2=-1;
	for(i=0;i<n;i++){
		if(arr[i]>max1)max1=arr[i], pos1=i;
	}
	for(i=0;i<n;i++){
		if(arr[i]>max2&&arr[i]<=max1&&i!=pos1)max2=arr[i], pos2=i;
	}
	if(pos2!=-1)
	v.push_back(pos2);
	if(pos1!=-1)
	v.push_back(pos1);
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	p=make_pair(-1, -1);
	if(v.size()>0)
		p.first=v[0];
	if(v.size()>1)
		p.second=v[1];
	return p;
}

int main(int argc, char const *argv[])
{
	freopen("input1small.in", "r", stdin);
	freopen("output1small.in", "w", stdout);
	int arr[50];
	int i ,j, k,n, l ,m, t, sum;
	cin>>t;
	k=1;
	pair<int, int> p;
	while(t--){
		cin>>n;
		sum=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		cout<<"Case #"<<k<<": ";
		k++;
		while(sum>0){
			p=findnext(arr, sum, n);
			cout<<(char)(p.first+'A');
			sum--;
			arr[p.first]--;
			if(p.second!=-1&&sum!=2){
				cout<<(char)('A'+p.second);
				arr[p.second]--;
				sum--;
			}
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}