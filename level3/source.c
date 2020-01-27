void v()
{
	char *str;

	str = fgets(str, 512, stdin);
	printf(str);
	if (str == "64")
	{
		fwrite(1, "Wait what?!", 12);
		system("/bin/sh");
	}
}

int main()
{
	v();
}
