#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void p(char **buff)
{
	char tmp[4096];

	puts(" - ");
	read(0, tmp, 4096);
	strchr(tmp, '\n');
	strncpy(*buff, tmp, 20);
	buff[strlen(tmp)] = '\0';
}

char *pp(char dest[54])
{
	char *buff1; //0xbffff688
	char *buff2; //0xbffff69c  // $ebp-0x1c

	p(&buff1);
	p(&buff2);
	strcpy(dest, buff1);
	dest[strlen(dest) - 1] = 40;
	strcat(dest, buff2);
}

int main()
{
	char dest[54]; //0x40 (64)

	pp(dest);
	puts(dest);
	return(0);
}
