void n()
{
	system("/bin/cat /home/user/level7/.pass");
}

void m()
{
	puts("Nope");
}

int main(int ac , char **av)
{
	char *str = malloc(64);
	void (*tmp)(void) = malloc(4);

	tmp = m;
	strcpy(str, av[1]);
	tmp();
}
