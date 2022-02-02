#include"minitalk.h"

t_byte_struct	collect_bit;

void struct_initialisation(t_byte_struct a)
{
	a.b1 = 0;
	a.b2 = 0;
	a.b3 = 0;
	a.b4 = 0;
	a.b5 = 0;
	a.b6 = 0;
	a.b7 = 0;
	a.b8 = 0;
}

void	recive_bit(int bit, int	*i)
{
	if (*i == 1)
		collect_bit.b1 = bit;
	if (*i == 2)
		collect_bit.b2 = bit;
	if (*i == 3)
		collect_bit.b3 = bit;
	if (*i == 4)
		collect_bit.b4 = bit;
	if (*i == 5)
		collect_bit.b5 = bit;
	if (*i == 6)
		collect_bit.b6 = bit;
	if (*i == 7)
		collect_bit.b7 = bit;
	if (*i == 8)
	{
		collect_bit.b8 = bit;
		write(1, &*(unsigned char *)&collect_bit, 1);
		*i = 0;
		struct_initialisation(collect_bit);
	}
}

void	handler(int sig)
{
	static int	i;

	if (!i)
		i = 1;
	if (sig == SIGUSR1)
	{
		recive_bit(0, &i);
		i++;
	}
	if (sig == SIGUSR2)
	{
		recive_bit(1, &i);
		i++;
	}
}

int	main(void)
{
	printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, &handler);
		signal(SIGUSR2, &handler);
		pause();
	}
	return (0);
}