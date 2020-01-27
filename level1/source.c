#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void run()
{
	fwrite(1, "Good... Wait what?\n", 19);
	system("/bin/sh");
}

int main()
{
	char buf[80];

	gets(buf);
}
