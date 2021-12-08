/* Basic functions library */


#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>



int string_to_number(const char *src) 
{
  int isdigit( int arg );
  
  while(*src)
  {
    // While there are more characters to process...
    if ( isdigit(*src) || ( (*src =='-'||*src=='+') && isdigit(*(src+1)) )) 
    {
      // Found a number
      long val = strtol(src, &src, 10); // Read number
      return val; // and print it.
    }
    else 
    {
      // Otherwise, move on to the next character.
      src++;
    }   
  }
}

