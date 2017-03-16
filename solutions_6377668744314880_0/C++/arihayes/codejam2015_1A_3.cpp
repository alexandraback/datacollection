#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef struct tree {
	int x;
	int y;
} tree;

//Note: I made use of gift wrapping algorithm (jarvis march), based on pseudo-code from wikipedia

int dist(tree a, tree b) {
	int val = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool sameDirection(tree p, tree q, tree r) {
	return dist(q, r) < dist(p, q);
}

bool betterAngle(tree p, tree q, tree r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) {
		return (dist(p, q) > dist(p, r) && sameDirection(p, q, r));
	} else if(val > 0) {
		return false;
	} else {
		return true;
	}
}

int main() {
	int numCases;
	cin >> numCases;
	
	tree trees[3000];
	int depths[3000];
	
	for(int x = 1; x <= numCases; x++) {
		int numTrees;
		cin >> numTrees;
		
		for(int t = 0; t < numTrees; t++) {
			cin >> trees[t].x >> trees[t].y;
			depths[t] = 3000;
		}
		
		int unProcced = 0;
		int leftMost = -1;
		for(int t = 0; t < numTrees; t++) {
			if(leftMost < 0) {
				leftMost = t;
			} else if(trees[t].x < trees[leftMost].x) {
				leftMost = t;
			} else if(trees[t].x == trees[leftMost].x && trees[t].y > trees[leftMost].y) {
				leftMost = t;
			}
			unProcced++;
		}
		
		if(leftMost < 0) {
			cerr << "SANITY CHECK ERROR\n";
		}
		
		if(unProcced < 4) {//all points are used in hull
			for(int t = 0; t < numTrees; t++) {
				depths[t] = 0;
			}
		} else {
			int onHull = leftMost;
			while(true) {
				depths[onHull] = 0;
				int endPoint = 0;
				if(onHull == 0) {
					endPoint = 1;
				}
				for(int t = 0; t < numTrees; t++) {
					if(t == onHull || t == endPoint) continue;
					if(betterAngle(trees[onHull], trees[endPoint], trees[t])) {
						endPoint = t;
					}
				}
				
				if(onHull == endPoint || endPoint < 0) {
					cerr << "OH GOD WHY\n";
				}
				
				for(int a = 0; a < numTrees; a++) {
					int temp = 0;
					if(a == endPoint) {
						continue;
					}
					for(int b = 0; b < numTrees; b++) {
						if(a != b && b != onHull && betterAngle(trees[onHull], trees[b], trees[a])) {
							temp++;
						}
					}
					if(temp && depths[a] > temp - 1) {
						depths[a] = temp - 1;
					}
				}
				
				onHull = endPoint;
				if(!depths[onHull]) {
					break;
				}
			}
		}
		
		cout << "Case #" << x << ":\n";
		for(int t = 0; t < numTrees; t++) {
			cout << depths[t] << "\n";;
		}
		cout << "\n";
	}
}
