#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct node{
    int x,y;
    bool operator<(const node& p)const{
        return y<p.y;
    }
};
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
    int t; cin>>t;
    for(int ca=1;ca<=t;ca++){
        priority_queue<node>q;
        int x,y,n;
        cin>>n;
        for(int x=1;x<=n;x++){
            cin>>y;
            node tmp;
            tmp.x=x;
            tmp.y=y;
            q.push(tmp);
        }
        cout<<"Case #"<<ca<<": ";
        while(!q.empty()){
        	int n=q.size();
        	if(n==2){
        		node tmp1=q.top();
        		q.pop();
        		node tmp2=q.top();
        		q.pop();
        		while(tmp1.y<tmp2.y){
        			printf("%c ",tmp2.x+'A'-1);
        			tmp2.y--;
				}
				while(tmp1.y>tmp2.y){
        			printf("%c ",tmp1.x+'A'-1);
        			tmp1.y--;
				}
				for(int i=0;i<tmp1.y;i++){
					printf("%c%c ",tmp1.x+'A'-1,tmp2.x+'A'-1);
				}
				break;
			}
        	node tmp=q.top();
        	q.pop();
        	if(tmp.y>0){
        		printf("%c ",tmp.x+'A'-1);
        		tmp.y--;
			}
			if(tmp.y>0){
				q.push(tmp);
			}
		}
		cout<<endl;
    }
    return 0;
}
