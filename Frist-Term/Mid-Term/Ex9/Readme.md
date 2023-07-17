# Ex9 :
### function to count the max number of ones between two zeros?
# solution :
```c
#include<stdio.h>
#include<string.h>
void rev(char *buf,int len);
void main()
{
    char buf[100];
    gets(buf);
    rev(buf,strlen(buf));

}
void rev(char *buf,int len)
{
    char a[100],b[100],*res;
    int i,n=0;

   
   do
    {
        a[n]=buf[n];
        n++;
    } while (buf[n]!=' ');

    for(i=0;n<len;i++,n++)
    {
        b[i]=buf[n];
    }
    b[i]=' ';
    b[i+1]='\0';
    res=strcat(b,a);
   for (i=0;i<=len;i++)
   {
    printf("%c",res[i]);
   }

    
}
```