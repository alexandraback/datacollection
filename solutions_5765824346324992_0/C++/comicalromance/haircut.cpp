#include <cstdio>
#include <functional>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int barbp[1001];
int GCD(int a,int b) {
	int c=1,e=2;
	while(e<=a) {
		if(!(a%e||b%e)) {
			a/=e;
			b/=e;
			c*=e;
		} 
		else e++;
	}
	return c;
}
int main() {
    int t,i,a,b,j,cur,cur2,time,temp;
    freopen("hey.in","r",stdin);
    freopen("wow.in","w",stdout);
    scanf("%d",&t);
    priority_queue<int,vector<int>, greater<int> >barber;
    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > >timet;
    for(i=0;i<t;i++) {
        scanf("%d%d",&a,&b);
        time=cur2=cur=0;
        for(j=0;j<a;j++) {
            scanf("%d",&barbp[j]);
            barber.push(j);
        }
        temp=barbp[0];
        for(j=1;j<a;j++) temp=temp*barbp[j]/GCD(temp,barbp[j]);
        for(j=0;j<a;j++) {
            cur+=(temp/barbp[j]);
        }
        b=(b%cur);
        if(b==0) b=cur; 
        while(cur2<=b) {
            while(!barber.empty()) {
                timet.push(make_pair(time+barbp[barber.top()],barber.top()));
               // cout<<time+barbp[barber.top()]<<endl;
                cur2++;
                if(cur2==b) printf("Case #%d: %d\n",i+1,barber.top()+1);
                barber.pop();
            }
            time=timet.top().first;
        //    cout<<time<<endl;
            while(!timet.empty()&&timet.top().first==time) {
                barber.push(timet.top().second);
                timet.pop();
            }
        }
        while(!barber.empty())barber.pop();
        while(!timet.empty())timet.pop();
    }
}
