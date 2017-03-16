#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef struct {
    double x,y;
	int id;
} titik;

titik arr[1007],simpan[1007],now,prev,tmp;
stack<titik> ans;
int ctr,i,t,n,awal,siz;
double jawab;

double cross(titik pivot, titik a, titik b) {
    return (b.x - a.x) * (pivot.y - a.y) - (b.y - a.y) * (pivot.x - a.x);
}

double dist(titik a, titik b) {
    return (sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
}

bool cmp(titik a, titik b) {
    if (fabs(cross(tmp,a,b)) < 0.000001)
        return dist(tmp,a) < dist(tmp,b);
    
    double d1x = a.x - tmp.x, d1y = a.y - tmp.y;
    double d2x = b.x - tmp.x, d2y = b.y - tmp.y;
    
    return (atan2(d1y,d1x) - atan2(d2y,d2x)) < 0;
} 

vector<int> antara[1007][1007];

int main() {
	int tc,tes,num,j,k;
	int answer[1007];
	double xx[1007],yy[1007];
	
	scanf("%d",&tc);
	for (tes=1 ; tes<=tc ; tes++) {
		scanf("%d",&num);
		for (i=0 ; i<num ; i++) scanf("%lf%lf",&xx[i],&yy[i]);
		for (i=0 ; i<num ; i++) answer[i] = 999999;
		
		for (i=0 ; i<num ; i++)
			for (j=0 ; j<num ; j++) {
				antara[i][j].clear();
				antara[i][j].push_back(i);
				antara[i][j].push_back(j);
				for (k=0 ; k<num ; k++) if (fabs(sqrt((xx[i]-xx[k])*(xx[i]-xx[k]) + (yy[i]-yy[k])*(yy[i]-yy[k])) +
												 sqrt((xx[j]-xx[k])*(xx[j]-xx[k]) + (yy[j]-yy[k])*(yy[j]-yy[k])) -
												 sqrt((xx[i]-xx[j])*(xx[i]-xx[j]) + (yy[i]-yy[j])*(yy[i]-yy[j]))) < 1e-9) antara[i][j].push_back(k);
			}
		
		// NOH
		for (t=1 ; t<(1 << num) ; t++) {
			n = 0;
			for (i=0 ; i<num ; i++) if (t & (1 << i)) {
				arr[n].x = xx[i];
				arr[n].y = yy[i];
				arr[n].id = i;
				
				n++;
			}
			
			awal = 0;
			for (i=1 ; i<n ; i++) if (arr[i].y < arr[awal].y ||
				(arr[i].y == arr[awal].y && arr[i].x > arr[awal].x))
					awal = i;
					
			tmp = arr[awal];
			arr[awal] = arr[0];
			arr[0] = tmp;
			
			tmp = arr[0];
			sort(arr+1,arr+n,cmp); 
			
			//printf("N = %d\n",n);
			//for (i=0 ; i<n ; i++) printf("%.4lf %.4lf\n",arr[i].x,arr[i].y);
			
			ans.push(arr[n-1]);
			ans.push(arr[0]);
			for (i=1 ; i<n ; i++) {
				now = ans.top();
				ans.pop();
				prev = ans.top();
				ans.push(now);
				while (cross(prev,now,arr[i]) < 0) {
					ans.pop();
					now = ans.top();
					ans.pop();
					prev = ans.top();
					ans.push(now);
				}
				ans.push(arr[i]);
				siz++;
			}
			
			//printf("----\n");
			
			ctr = 0;
			while (!ans.empty()) {
				simpan[ctr] = ans.top();
				ans.pop();
				ctr++;
			}
			
			//jawab = 0;
			//for (i=1 ; i<ctr ; i++) jawab = jawab + dist(simpan[i-1],simpan[i]);
			for (i=1 ; i<ctr ; i++) {
				for (j=0 ; j<antara[simpan[i-1].id][simpan[i].id].size() ; j++) {
					answer[antara[simpan[i-1].id][simpan[i].id][j]] = min(antara[simpan[i-1].id][simpan[i].id][j],num-n);
				}
			}
			//printf("%.2lf\n",jawab);
			
			for (i=1 ; i<ctr ; i++) {
				//printf("ID = %d\n",simpan[i].id);
				answer[simpan[i].id] = min(answer[simpan[i].id],num-n);
				
			}
		}	
		
		printf("Case #%d:\n",tes);
		for (i=0 ; i<num ; i++) printf("%d\n",answer[i]);
	}
}
