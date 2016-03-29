#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include "crypt.h"
using namespace std;
int main(int argc, char *argv[])
{
string args;
for (unsigned int i = 0; i < argc; i++)
{
args[i] = argv[i];
}
if (argc != 3)
{
cout << "usage: main <text> <key>\n";
}
int key = atoi(argv[3]);
string plainText = decrypt(args[2], key);
cout << plainText << "\n";
}
