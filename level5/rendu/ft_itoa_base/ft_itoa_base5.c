#include <unistd.h>
#include <stdlib.h>
char	*ft_itoa_base(int value, int base)
{
	char tab[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D','E', 'F'};
	char	*str;
	int		flag;
	int		len;
	int		v;

	if (base < 2 && base > 36)
		return (0);
	flag = (value < 0 && base == 10) ? 1  : 0;
	len = 1 + flag;
	v = value;
	while (v /= base)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 2));
	str[0] = '-';
	str[len] = 0;
	if (len-- > flag)
	{
		v = (value < 0) ? -(value % base) : (value % base);
		str[len] = tab[v];
		value /= base;
	}
	return (str);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	else 
		write(1, "\n", 1);
	return (0);
}
