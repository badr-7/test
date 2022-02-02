#include"minitalk.h"
int	ft_atoi(const char *str)
{
	int	i;
	int	cp;
	int	r;

	i = 0;
	cp = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			cp = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * cp);
}
void	ft_send_caractere(int pid, unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(120);
	}
}

int main(int ac, char **av)
{
    char *text;
    int pid;
    int i;

    pid = ft_atoi(av[1]);
    text = av[2];
    while(i < strlen(text))
    {
        ft_send_caractere(pid,text[i]);
		i++;
		usleep(200);
    }
    
}