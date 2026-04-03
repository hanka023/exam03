#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char **argv)
{
 if(argc == 2)
 {
  int l = strlen(argv[1]);
  char *buffer = (char *)malloc(l);
  int i = 0, zbytek = l, nalezeno = 0, schovej = 0;
  while(read(0,&buffer[i%l],1) == 1)
  {
   if(buffer[i%l] == argv[1][i%l])
   {
    if(++nalezeno == l)
    {
     schovej = nalezeno;
     nalezeno = 0;
    }
   }
   else nalezeno = 0;

   if(++i >= l)
   {
    if(schovej-- > 0) write(1,"*",1);  
    else write(1,&buffer[(i-l)%l],1);
   }
  }
  while(--zbytek > 0)
  {
   if(schovej-- > 0) write(1,"*",1);  
   else write(1,&buffer[(i-zbytek)%l],1);  
  }
 }
}