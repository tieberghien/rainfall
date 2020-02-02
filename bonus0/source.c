char *p(char *dash)
{
	char buf[4096];

	puts(dash);
	read(0, buf, 4096);
	strchr(buf, '\n');
	char *ret = strncpy(ret, buf, 4096);
	return (ret);
}

char *pp()
{
	char *dash = " - ";

	char *str = p(dash);
}

int main()
{
	puts(pp());
}
