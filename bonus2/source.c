void greetuser(char *dest, int n, char *str)
{
	char *greet;

	switch (n)
	{
    	case 1:
    	    greet = "Hyvää päivää ";
    	case 2:
    	    greet = "Goedemiddag! ";
    	default:
			greet = "Hello ";
	}
	dest = strcat(greet, str);
	puts(dest);
}

int main(int ac, char **av)
{
	char 	*dest;
	char 	*lang;
	int		n = 0;

	if (ac != 3)
		return (0);
	strncpy(dest, av[1], 40);
	strncpy(*(dest)+40, av[2], 32);
    lang = getenv("LANG");
	if (lang)
	{
    	if (memcmp(lang, "fi", 2))
			n = 1;
		if (memcmp(lang, "nl", 2))
			n = 2;
	}
	greetuser(dest, n, av[1]);
}
