#include <Matrix.h>

static int cut_spaces(const char *str) {
	int i = 0;

	for (; str[i]; ++i)
		if (!mx_isspace(str[i]))
			break ;
	return i;
}
int mx_atoi(const char *str)
{
	int neg = 1;
	int i = cut_spaces(str);
	int result = 0;

	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	for(; str[i]; ++i) {
		if(mx_isdigit(str[i])) {
			result *= 10;
			result += str[i] - '0';
		}
		else
			break ;
    }
	return result * neg;
}

