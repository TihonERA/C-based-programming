#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
	double val, power, exp, result;
	int i, sign, direction;

	for (i = 0; isspace(s[i]); i++) {
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	result = sign * val / power;
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
	}
	else {
		return result;
	}
	direction = 1;
	if (!(isdigit(s[i]))) {
		if (s[i] == '-') {
			direction = !direction;
			i++;
		}
		else {
			i++;
		}
	}
	for (exp = 0.0; isdigit(s[i]); i++) {
		exp = exp * 10.0 + (s[i] - '0');	
	}
	if (direction) {
		for (; exp > 0.0; exp--) {
			result *= 10.0;
		}
	}
	for (; exp > 0.0; exp--) {
		result /= 10.0;
	}
	return result;
}
