#include <stdio.h>

int any(char s1[], char s2[]) {
	int i, j;

	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	char pi[100] = "pidorokpidorokpidorokkA";
	char pida[100] = "2222222222A2222k";

	printf("%d\n", any(pi, pida));
	return 0;
}
