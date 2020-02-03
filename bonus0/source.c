char *p(buff, str)
{
	char *tmp_buff;

	puts(str);
	read(0,*tmp_buff, 4096);
	strchr(*tmp_buff, '\n');
	strncpy(buff,*tmp_buff, 20);
	return ;
}

char *pp(dest)
{
	char *str = " - ";
	char *buff1; //0xbffff688
	char *buff2; //0xbffff69c  // $ebp-0x1c
	char *tmp;
	unsigned int *n; //$ebp-0x3c
	char carac;

	p(buff1, str);
	p(buff2, str);
	strcpy(dest, buff1);
	tmp = dest;
	n = -1; //0xffffffff
	carac = *tmp;
	while(carac != '\0')        // size of buff1 before '\0'
	{
		if (n == 0)
			break;
		n--;
		tmp++;
		carac = tmp;
	}
	not n - 1;
	dest + n = " ";
	strcat(dest, buff2);
}

int main()
{
	char dest[54]; //0x40 (64)

	pp(dest);
	puts(dest);
	return(0);
}
