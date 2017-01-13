#include <unistd.h>

int	ft_isspace(int c)
{
	return((c == ' ') || (c == '\t'));
}

void	print_word(char *str)
{
	while (*str && !ft_isspace(*str))
		write(1, str++, 1);
}

int main(int argc, char **argv)
{
	int i;
	
	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		while (argv[1][i] && i > 0)
		{
			while (!ft_isspace(argv[1][i]) && i > 0)
				i--;
			print_word(argv[1] + i + (i == 0 ? 0 : 1));
			if (i > 0)
				write(1, " ", 1);
			while (ft_isspace(argv[1][i]) && i > 0)
				i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
