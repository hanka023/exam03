// filter:
// Allowed functions: read, strlen, malloc, calloc, realloc, free, printf, perror
// ------------------------------------------------------------------------------

// Write a programm that will take one and only one argument s.

// Your programm will then read from stdin and write all the content read in stdout
// except that every occurence of s must be replaced by '*'.

// For example :

// ./filter bonjour
// will behave the same way as:
// sed 's/bonjour/*******/g'

// in case of error during read or a malloc you must write "Error: " followed by
// the error message in stderr and return 1.

// $> echo 'abcdefgaaaabcdefabc' | ./filter abc | cat -e
// ***defgaaa***def***

// If the program is called whitout argument or with an empty argument or with
// multiples arguments it must return 1.


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

ssize_t read (int fd, void *buf, size_t cont);

int main(int argc, char *argv[])
{
    char buffer[1024];
    ssize_t bytes_read;
    int i;
    int j;
    char *s = argv[1];

    if (argc != 2)
        return (0);
    while ((bytes_read = read(0, buffer, sizeof (buffer))) > 0 )
    {
        i = 0;
        while (i < bytes_read)
        {
            j = 0;
            if (buffer[i] == s[j])
            {
                while (buffer[i + j] == s[j])
                    ++j;
                if (s[j] == '\0')
                {
                    j = i + j;
                    while (i < j)
                    {
                        write (1,"*", 1);
                        ++i;
                    }
                }
                else 
                {
                    write (1, &buffer[i], 1);
                    ++i;
                }
            }
            else
            {
                write (1, &buffer[i], 1);
                ++i;
            }
        }
    }
    return (0);
}