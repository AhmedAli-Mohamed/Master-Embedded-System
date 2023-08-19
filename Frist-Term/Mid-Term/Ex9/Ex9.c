#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse_words(char buf[]);
void reverse (char begin[],char end []);
int main()
{
    char buf[30];
    gets(buf);
    reverse_words(buf);
    puts(buf);
    
    return 0;
}

void reverse_words(char buf[])
{
    char  *begin,*temp;
    begin=temp=buf;
    while(*temp)
    {
        temp++;
        if(*temp==NULL)
        {
            reverse(begin,temp-1);
        }
        else if (*temp==' ')
        {
            reverse(begin,temp-1);
            begin=temp+1;
        }
    }
    reverse(buf,temp-1);

}

void reverse (char begin[],char end [])
{
    char temp;
    while(begin<end)
    {
        temp=*begin;
        *begin++=*end;
        *end--=temp;
    }
}
