# passgen - simple CLI password generator

## Usage:

```console
$ make 
$ ./passgen [length] [options]
```
## Saving password to a file:

passgen doesn't have built-in saving passwords to files, so what you can do is 
```console 
$ ./passgen 8 -a > pass.txt
```

## List of options:

 - '-c' - capital letters
 - '-n' - numbers
 - '-cn' - capital letters with numbers
 - '-s' - special characters
 - '-a' - all options listed above

## Warning

This program is still really buggy.
