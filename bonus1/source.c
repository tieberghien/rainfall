int main(int ac, char **av)
{
    char buff[64];
    int res;

    res = atoi(av[1]);
    if (res <= 9)
    {
        buff = '\r';
        memcpy(buff, av[2], res * 4);
        if (esp+0x3c == "FLOW")
			execl("/bin/sh", "sh", NULL);
        return (0);
    }
    return (1);
}
