char *p(char *buff, char *str)
{
	char tmp[4096];

	puts(str);
	read(0, tmp, 4096);
	strchr(tmp, '\n');
	strncpy(buff, tmp, 20);
	return ;
}

char *pp(dest)
{
	char *str = " - ";
	char *buff1; //0xbffff688
	char *buff2; //0xbffff69c  // $ebp-0x1c

	p(buff1, str);
	p(buff2, str);
	strcpy(dest, buff1);
	dest[strlen(dest)] = " ";
	strcat(dest, buff2);
}

int main()
{
	char dest[54]; //0x40 (64)

	puts(&dest);
	return(0);
}
