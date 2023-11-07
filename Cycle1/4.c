/*Ex No 4
string length(int StringLengh(char *s))
string copy(void StringCopy(char *s1, char *s2))
string comparison(int StringCompare(char *s1, char*s2))
string concatenation(void StringConcat(char *s1, char*s2))
*/
#include <stdio.h>
int StringLength(char *s)
{
    int count=0;
    while (*s!='\0')
    {
        count++;
        s++;
    }
    return count;
}
void StringCopy(char *s1, char *s2)
{
    int i=0,len=StringLength(s1);
    for (i=0;i<len;i++)
        *(s2+i)=*(s1+i);
}
int StringCompare(char *s1, char*s2)
{
    int i=0;
    char c1=*(s1+i),c2=*(s2+i);
    while (c1!='\0' && c2!='\0')
    {
        c1=*(s1+i);
        c2=*(s2+i);
        if (c1>c2)
            return 1;
        if (c1<c2)
            return -1;
        i++;
    }
    return 0;
}
void StringConcatenate(char *s1,char *s2)
{
    int i,j=0,l=StringLength(s1);
    for (i=l;*(s2+j)!='\0';i++,j++)
        *(s1+i)=*(s2+j);

}
void main()
{
    char str1[100],str2[100];
    int ch;
    printf("1 : String Length\n2 : String Copy\n3 : String Comparision\n4 : String Concatenation\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    if (ch==1)
    {
        printf("Enter a string : ");
        scanf(" %[^\n]",str1);
        printf("String Length = %d\n",StringLength(str1));
    }
    if (ch==2)
    {
        printf("Enter a string : ");
        scanf(" %[^\n]",str1);
        StringCopy(str1,str2);
        printf("String Copied Successfully\n");
        printf("Str2 : %s",str2);
    }
    if (ch==3)
    {
        printf("Enter first string : ");
        scanf(" %[^\n]",str1);
        printf("Enter second string : ");
        scanf(" %[^\n]",str2);
        printf("%d\n",StringCompare(str1,str2));
    }
    if (ch==4)
    {
        printf("Enter first string : ");
        scanf(" %[^\n]",str1);
        printf("Enter second string : ");
        scanf(" %[^\n]",str2);
        StringConcatenate(str1,str2);
        printf("After Conactenation string becomes : %s",str1);
    }
}




