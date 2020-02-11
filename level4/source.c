void p(char *str)
{
	printf(str);
}

void n()
{
	char *str;
	int i;

	fgets(str, 512, stdin);
	p(str);
	i = m();
	if (i == 16930116)
		system("/bin/cat /home/user/level5/.pass");
}

int main()
{
	n();
}
