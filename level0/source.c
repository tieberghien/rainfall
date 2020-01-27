#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

int main(int ac, char **av, char **envp)
{
	gid_t gid;
    uid_t uid;

	if (atoi(av[1]) == 423)
	{
		strdup("/bin/sh");
    	gid = getegid();
    	uid = geteuid();
 
    	setresgid(gid, gid, gid);
    	setresuid(uid, uid, uid);
		execve("/bin/sh", NULL, envp);
	}
	else
		fwrite(2, "No !\n", 5);
	return (0);
}
