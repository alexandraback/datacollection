
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm> 

using namespace std;

#define MAX_RC 10000

#define MAX(a,b) ((a>=b)?(a):(b))
#define MIN(a,b) ((a<b)?(a):(b))

typedef struct Node {
    struct Node *edges[4];
    int walls;
} Node;

#define L 0
#define T 1
#define R 2
#define B 3
#define WALL(x)     (1<<(x))
#define OP_WALL(x)  (1<<((x+2)%4))

int t;
int ans;
Node *node_source, **node;


int max_rc = 0;

void initNodes(int r, int c) {

	node = (Node **)calloc(r, sizeof(Node *));
    for (int i=0; i<r; i++) {
		memset(&node_source[i*c], 0, sizeof(Node)*c);
		node[i] = &node_source[i*c];
    }

	for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            node[i][j].walls = 0xF;
            if (j > 0) node[i][j].edges[L] = &node[i][j-1];
            if (i > 0) node[i][j].edges[T] = &node[i-1][j];
            if (j < c-1) node[i][j].edges[R] = &node[i][j+1];
            if (i < r-1) node[i][j].edges[B] = &node[i+1][j];
        }
    }
}


void get_index_saving_most_walls_if_removed(int r, int c, int *max_r, int *max_c) {

	Node *cur;
	int max_cnt = 0;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			int cnt = 0;
			cur = &node[i][j];
			if (cur->walls == 0) continue;
			for (int k=0; k<=3; k++) {
				if (cur->edges[k]) {
					if (cur->edges[k]->walls & OP_WALL(k))
						cnt ++;
				}
			}
			if (cnt > max_cnt) {
				max_cnt = cnt;
				*max_r = i;
				*max_c = j;
			}
		}
	}
}

void remove_wall_at_index(int i, int j) {
	node[i][j].walls = 0;
}

int get_min_walls(int r, int c, int n) {

	int n_remove = r*c - n;
	for (int k=0; k<n_remove; k++) {
		int r_max = 0, c_max = 0;
		get_index_saving_most_walls_if_removed(r, c, &r_max, &c_max);
		remove_wall_at_index(r_max, c_max);
	}

	int cnt = 0;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			Node *cur = &node[i][j];
			if (cur->walls == 0) continue;
			for (int k=0; k<=3; k++) {
				if (cur->edges[k]) {
					if (cur->edges[k]->walls & OP_WALL(k)) {
						cur->walls &= ~WALL(k);
						cur->edges[k]->walls &= ~OP_WALL(k);
						cnt ++;
					}
				}
			}
		}
	}

	return cnt;
}


int main(void) {

	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	node_source = (Node *)calloc(MAX_RC, sizeof(Node));

	fscanf(fp, "%d", &t);
	for (int tc=1; tc<=t; tc++) {
		int r, c, n;
		fscanf(fp, "%d %d %d", &r, &c, &n);

		initNodes(r, c);		
		ans = get_min_walls(r, c, n);

		fprintf(ofp, "Case #%d: %d\n", tc, ans);
	}

	return 0;
}
