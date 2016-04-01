#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;

int searchArray(char searchFor, string arrayToSearch)
{
  int place = -1;
  for (unsigned int i = 0; i < arrayToSearch.length(); i++)
  {
    if (arrayToSearch[i] == searchFor)
    {
      place = i;
    }
  }
  return place;
}

int placeInAlphabet(int place)
{
  bool stillGoing = true;
  while (stillGoing)
  {
    if (place > 25)
    {
      place = place - 26;
    }
    if (place < 0)
    {
      place = place + 26;
    }
    if (place <= 25 && place >= 0)
    {
      stillGoing = false;
    }
  }
  return place;
}

string encrypt(string plainText, int key)
{
  int place = 0;
  string lower = "abcdefghijklmnopqrstuvwxyz";
  string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (unsigned int y = 0; y < plainText.length(); y++)
    {
      place = 0;
      if (lower.find(plainText[y]) != string::npos || upper.find(plainText[y]) != string::npos)
      {
        if (isupper(plainText[y]) != 0)
        {
          place = searchArray(plainText[y], upper);
          place = place + key;
          plainText[y] = upper[placeInAlphabet(place)];
        }
        else
        {
          place = searchArray(plainText[y], lower);
          place = place + key;
          plainText[y] = lower[placeInAlphabet(place)];
        }
      }
    }
  return plainText;
}

string decrypt(string cryptoText, int key)
{
  int place = 0;
  string lower = "abcdefghijklmnopqrstuvwxyz";
  string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (unsigned int i = 0; i < cryptoText.length(); i++)
  {
    place = 0;
    if (lower.find(cryptoText[i]) != string::npos || upper.find(cryptoText[i]) != string::npos)
    {
      if (isupper(cryptoText[i]) != 0)
      {
        place = searchArray(cryptoText[i], upper);
        place = place - key;
        cryptoText[i] = upper[placeInAlphabet(place)];
      }
      else
      {
        place = searchArray(cryptoText[i], lower);
        place = place - key;
        cryptoText[i] = lower[placeInAlphabet(place)];
      }
    }
  }
  return cryptoText;
}
