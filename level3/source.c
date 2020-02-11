void v()
{
	char *str;
	int i;

	fgets(str, 512, stdin);
	printf(str);
	i = m();
	if (i == 64)
	{
		fwrite(1, "Wait what?!", 12);
		system("/bin/sh");
	}
}

int main()
{
	v();
}
