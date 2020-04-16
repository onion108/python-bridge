#ifndef PYTHON_BRG_H
#define PYTHON_BRG_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char pBool;
#define pTrue (pBool)1
#define pFalse (pBool)0
#define SHARED_DATA_PATH "_sharedData"
pBool pyExecute(char *script);
#ifdef WIN_PY
pBool winPyExecute(char *script);
#endif
void clearSharedData(void);
void clearPyLibCache(void);
void clearPyLibWithName(char *);

// new feature in beta 2.0
// pyRuntime() need a python script in the directory named "pyRunMain"
// In pyRunMain,you need a entry function that name is "main(args)"
// for Example:
// # pyRunMain.py
// def main(args):
//     print("Hello !",args)
void pyRuntime(void);
#endif
