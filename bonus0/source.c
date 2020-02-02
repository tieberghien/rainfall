char *p(char *dash)
{
	char buf[4096];

	puts(dash);
	read(0, buf, 4096);	
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
