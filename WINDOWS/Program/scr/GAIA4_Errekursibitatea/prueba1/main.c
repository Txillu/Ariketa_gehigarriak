#include <stdio.h>

int batukari_rekurtsiboa(int zenb);

int main() {
	int emaitza;

	emaitza = batukari_rekurtsiboa(3);
	printf("3ren batukaria: %i\n", emaitza);

	emaitza = batukari_rekurtsiboa(4);
	printf("4ren batukaria: %i\n", emaitza);

	emaitza = batukari_rekurtsiboa(1);
	printf("1ren batukaria: %i\n", emaitza);

	///////////////////////
	printf("Sakatu return bukatzeko...\n");
	getchar();
	return 0;
}

int batukari_rekurtsiboa(int zenb) {
	int emaitza = 0;
	if (zenb == 0) {
		return 0;
	}
	else {
		emaitza = zenb + batukari_rekurtsiboa(zenb - 1);
	}
	return emaitza;

}