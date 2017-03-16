#include <cstdio>
#include <vector>
using namespace std;

const int INFINI = 1000000000;

struct car {
	char c;
	int n;
};

typedef vector<car> chaine;

bool pareil(chaine c1, chaine c2) {
	if (c1.size() != c2.size())
		return false;
	for (int i = 0; i < c1.size(); i++)
		if (c1[i].c != c2[i].c)
			return false;
	return true;
}

int main(void) {
	int nbTests;
	scanf("%d", &nbTests);
	getchar();
	for (int iTest = 1; iTest <= nbTests; iTest++) {
		int nbChaines, cout = 0;
		bool ok = true;
		chaine chaines[100];
		scanf("%d", &nbChaines);
		getchar();
		for (int i = 0; i < nbChaines; i++) {
			char c, cour = ' ';
			while ((c = getchar()) != '\n') {
				if (c == cour)
					chaines[i][chaines[i].size()-1].n++;
				else {
					car nouv = {c, 1};;
					cour = c;
					chaines[i].push_back(nouv);
				}
			}
		}
		for (int i = 1; i < nbChaines; i++)
			if (pareil(chaines[0], chaines[i]) == false)
				ok = false;
		if (ok == false) {
			printf("Case #%d: Fegla Won\n", iTest);
			continue;
		}
		for (int lettre = 0; lettre < chaines[0].size(); lettre++) {
			int coutLettre = INFINI;
			for (int taille = 0; taille <= 100; taille++) {
				int coutTaille = 0;
				for (int i = 0; i < nbChaines; i++)
					coutTaille += abs(chaines[i][lettre].n-taille);
				if (coutTaille <= coutLettre)
					coutLettre = coutTaille;
			}
			cout += coutLettre;
		}
		printf("Case #%d: %d\n", iTest, cout);
	}
	return 0;
}
