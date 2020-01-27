// global i?
int i = 0

void v()
{
	char *str;

	str = fgets(str, 512, stdin);
	printf(str);
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
