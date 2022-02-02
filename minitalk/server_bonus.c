#include"minitalk.h"

t_byte_struct	collect_bit;

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
    struct sigaction	act;
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO;
	printf("PID: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}