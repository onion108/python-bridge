# python-bridge
It is a simple library for Python and C.

Version Information:
```
By 27(Onion108)
Version : 0.0 Beta 2
```

# New Feature in Beta 2.0

Add new function `winPyExecute`;
Add `pyRuntime`;

# Documentation

## Types

```
pBool
```
It is a boolean type,and it has two values:(Look at PBridge.h line 8~9)
```
...
7  typedef unsigned char pBool;
8  #define pTrue (pBool)1
9  #define pFalse (pBool)0
...
```

## Functions

### Execute
#### Prototype
```
pBool pyExecute(char *script);
```
#### Arguments
script - The python script what you want to run.

#### Return
It return a `pBool` value,if it success the execution,return `pTrue`,else return `pFalse`.
#### Prototype
```
pBool WinPyExecute(char *script);
```
#### Arguments
script - The python script what you want to run.

#### Return
It return a `pBool` value,if it success the execution,return `pTrue`,else return `pFalse`.

### Clear Cache
```
It is for C/Cpp IDE like Online GDB (www.onlinegdb.com),they don't know what is `.pyc' file and they will try to compile the Python Library Cache File,and they will throw a lot of exceptions.So,you need call the functions to clear the `.pyc' after running,also,you need clear the shared data.
```
#### Prototype
```
void clearSharedData(void);
```
#### Arguments
None.
#### Return
None.

#### Prototype
```
void clearPyLibCache(void);
```
#### Description
It will clear the Python Library Cache File of PBridge-Python.
#### Arguments & Return
None.
#### Prototype
```
void clearPyLibWithName(char *);
```
#### Description
It will clear the Python Library Cache File by the library path.
#### Arguments
char * - The path of library(without `.pyc`).
#### Return
None.

### Runtime (**New!**)
```
void pyRuntime(void);
```
It will execute a python script file called `pyRunMain.py` and set the argument `args` for the `main` Python Funtion.

# `pyRuntimeMain.py` Example:
```
def main(args):
    print("Hello!" + args[2])
    print("Bye!")
```
