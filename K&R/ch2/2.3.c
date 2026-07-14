#include <stdio.h>
#include <limits.h>
#include <float.h>

int htoi(char hex[]) {
	int result, hex_current_multiplayer, hex_number;	
	int i = 0;

	if (hex[0] != '0' && (hex[1] != 'x' || hex[1] != 'X')) {
		return 0;
	}
	else {
		i = i+2;
	}
	while (hex[i] != '\0') {
		i++;
	}
	i--;

	result = 0;
	hex_current_multiplayer = 1;
	for (; (hex[i] != 'x' || hex[i] != 'X'); i--) {
		if (hex[i] >= '0' && hex[i] <= '9') {
			hex_number = hex[i] - '0';	
			result = result + (hex_number * hex_current_multiplayer);
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F') {
			hex_number = hex[i] - 'A' + 10;
			result = result + (hex_number * hex_current_multiplayer);
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f') {
			hex_number = hex[i] - 'a' + 10;
			result = result + (hex_number * hex_current_multiplayer);
		}
		else {
			return 0;
		}
		hex_current_multiplayer = hex_current_multiplayer * 16;
		printf("%c\t%d\t%d\n", hex[i], hex_number, result);
	}

	return result;
}

