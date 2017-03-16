#include <cstdio>
#include <queue>

using namespace std;

int totalSize;

char popOneOut(priority_queue<pair<char, int>> & mm) {
	if (mm.size() == 0) return 0;

	totalSize--;

	char chr = mm.top().second;
	int size = mm.top().first;

	mm.pop();
	if (size > 1) mm.push(make_pair(size - 1, chr));

	return chr;
}

void problemCase() {
	int partyCount;
	int i;
	int in;

	priority_queue<pair<char, int>> mm;

	scanf("%d", &partyCount);
	totalSize = 0;
	for (i = 0; i < partyCount; i++) {
		scanf("%d", &in);
		mm.push(make_pair(in, 'A' + i));
		totalSize += in;
	}

	while (mm.size() > 0) {
		printf(" ");
		char a = popOneOut(mm);
		char b = 0;
		if (totalSize != 2) b = popOneOut(mm);
		
		printf("%c", a);
		if (b != 0) printf("%c", b);
	}
	printf("\n");
}

int main() {
	int tc, t;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		printf("Case #%d:", t);
		problemCase();
	}
	return 0;
}