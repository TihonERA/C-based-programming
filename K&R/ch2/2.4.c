#include <stdio.h>

void alt_squeeze(char array1[], char array2[]) {
   	int i, j, l;

	for (i = 0; array1[i] != '\0'; i++) {
		j = 0;

		while (array2[j] != '\0' && array2[j] != array1[i]) {;
			j++;
		}

		if (array2[j] == '\0') {
			array1[l++] = array1[i];
		}
	}

	array1[l] = '\0';
}
int main() {
	char string1[50] = "pidorokpidorok";
	char string2[50] = "orokorokorokorok";

	alt_squeeze(string1, string2);

	printf("%s\n", string1);

	return 0;
}

    
