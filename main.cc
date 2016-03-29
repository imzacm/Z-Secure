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
  if (argc == 4)
  {
    string args;
    for (unsigned int i = 0; i < argc; i++)
    {
      args[i] = argv[i];
    }
    int key = atoi(argv[3]);
    if (args[1] == "encrypt")
    {
      string cryptoText = encrypt(string(argv[2]), key);
      cout << cryptoText << "\n";
    }
    if (args[1] == "decrypt")
    {
      string plainText = decrypt(string(argv[2]), key);
      cout << plainText << "\n";
    }
    if (args1] != "encrypt" && string(argv[1]) != "decrypt")
    {
      cout << "usage: main encrypt/decrypt <text> <key>\n";
    }
  }
  else
  {
    if (argc == 2 || argc == 3 || argc > 4)
    {
      cout << "usage: main encrypt/decrypt <text> <key>\n";
    }
    else
    {
      cout << "Please choose:\n1) Encrypt\n2) Decrypt\n";
      int choice;
      cin >> choice;
      if (choice != 1 && choice != 2)
      {
        cout << "Invalid choice\n";
        exit(0);
      }
      if (choice == 1)
      {
        cout << "Enter text to encrypt\n";
        string plainText;
        cin.ignore(1000, '\n');
        getline(cin, plainText);
        if (plainText != "\0")
        {
          cout << "Enter your key\n";
          int key;
          cin >> key;
          string cryptoText;
          cryptoText = encrypt(plainText, key);
          cout << "Encrypted text\n" << cryptoText << "\n";
        }
        else
        {
          cout << "No text entered\n";
          exit(0);
        }
      }
      if (choice == 2)
      {
        cout << "Enter text to decrypt\n";
        string cryptoText;
        cin.ignore(1000, '\n');
        getline(cin, cryptoText);
        if (cryptoText != "\0")
        {
          cout << "Enter your key\n";
          int key;
          cin >> key;
          string plainText;
          plainText = decrypt(cryptoText, key);
          cout << "Encrypted text\n" << plainText << "\n";
        }
        else
        {
          cout << "No text entered\n";
          exit(0);
        }
      }
    }
  }
  return 0;
}
