void p()
{
	str = fflush(stdout);
	//lea    eax,[ebp-0x4c]
	gets(str);

	if ()
	{
		printf("(%p)\n");
		exit(1);
	}
	else
	{
		puts(str);
		strdup(str);
	}
}

int main()
{
	p();
}
