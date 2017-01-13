#include <unistd.h>
#include <stdlib.h>

void	brainfuck(char *str)
{
	char	tab[2048] = {0};
	char	*ptr = tab;
	int		i;
	int		lpcnt;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
		   	ptr++;
		else if (str[i] == '<')
			ptr--;
		else if (str[i] == '+')
			++*ptr;
		else if (str[i] == '-')
			--*ptr;
		else if	(str[i] == '.')
			write(1, ptr, 1);
		else if (str[i] == '[')
		{
			if (!*ptr)
			{
				lpcnt = 1;
				while (lpcnt)
				{
					i++;
					if (str[i] == '[')
						lpcnt++;
					else if (str[i] == ']')
						lpcnt--;
				}
			}
		}
		else if (str[i] == ']')
		{
			if (*ptr)
			{
				lpcnt = 1;
				while (lpcnt)
				{
					i--;
					if (str[i] == ']')
						lpcnt++;
					else if (str[i] == '[')
						lpcnt--;
				}
			}
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		brainfuck(argv[1]);
	else if (argc != 2)
		write (1, "\n", 1);
	return (0);
}
