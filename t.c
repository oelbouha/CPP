#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	cast_to_int(float nb)
{
	int exp;
	float x  = -0.5;
	void *mem = &x;
	memmove(&exp, mem, 4);
	exp >>= 23;

	exp &= 0b11111111;
	printf("%u\n", exp);
	return (0);
}

int main()
{
	int fd[2];
	char buff[100];

	pipe(fd);
	for(int i = 0; i < 2; i++)
	{
		int pid = fork();
		if (pid == 0)
		{
			if (i == 0)
			{
				write(fd[1], "hello\n", 6);
				close(fd[1]);
				close(fd[0]);
				exit(0);
			}
			else
			{
				char buff[100];

				int r = read(fd[0], buff, 10);
				buff[r] = 0;
				printf("buff: %s", buff);
				write(fd[1], "world\n", 6);
				close(fd[1]);
				close(fd[0]);
				exit(0);
			}
		}
	}
	wait(NULL);
	int r = read(fd[0], buff, 10);
	buff[r] = 0;
	printf("buff parent: %s", buff);
	close(fd[1]);
	close(fd[0]);
}

/*
	1011.11 ===> 11.75   ==> we can write 1.01111 * 2^3
	
	10000100   ===> 132
	
	0 10000010 01011000000000000000000  float point 10.75
	0 10000010 01011000000000000000000 	===>  1093402624

	0000000 00000000 00000000 00001011

	1 01111011 10011001100110011001101
	0 10000000 10000000000000000000000
			   11111111111111111111111
	


	11001100 1100110
	11111111 1111111
	00000000 1111111

	int a = 10;

	000000000000000000000000001010
	&
	000000000000000000000011110000
	a << 4;

	1 01111111 00000000000000000000000
*/