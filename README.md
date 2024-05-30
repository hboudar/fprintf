<h1 align="center">
	📖 fprintf
</h1>

<p align="center">
	<b><i>printing data in the given file descriptor</i></b><br>
</p>
<p align="center">
<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Cloneg7/fprintf?color=lightblue" />
<img alt="Code language count" src="https://img.shields.io/github/languages/count/Cloneg7/fprintf?color=yellow" />
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Cloneg7/fprintf?color=blue" />
</p>

## 📜 Table of Contents

- [💡 Mandatory Part](#m)

# 💡 Mandatory Part with Bonus<a name = "m"></a>

> _This Function :_
    is used to print formatted output in numerous ways to the standard output stdout.

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries**.

### Instructions

**1. To use the function in your code, simply include a main() with its header:**

```C
#include "ft_printf.h"
```
```C
int  main()
{
  ft_printf("%s\n", "hello world");
  return (0);
}
```

#### 📋 Testing
> _Simply run this command (change X with the file of the main function):_
```shell
make && gcc X
```
-------
# The Bonus

> _As a <code>bonus</code> to the Mandatory requirement, the function should :_
	<ul>
         <li>Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.</li>
         <li>Manage all the following flags: ’# +’ (Yes, one of them is a space)</li>
	<ul/>
 ### main example :
```C
#include <stdio.h>

int main()
{
    printf("%-7d\n", 1337);
    printf("%07s\n", "1337");
    printf("%+7d\n", 1337);
    return 0;
}
```
### Running :
```shell
./a.out | cat -e
1337   $
0001337$
