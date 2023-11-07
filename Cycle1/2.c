/*
Ex No 2
*/
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s, char *substring) {
    int n = strlen(s);
    int maxLength = 0;
    int start = 0;
    int end = 0;
    int currentLength = 0;
    int visited[256]; // Assuming ASCII characters

    for (int i = 0; i < 256; i++) 
    {
        visited[i] = -1;
    }
    //printf("%d\n",s[end]);
    //printf("%d\n",visited[s[end]]);
    while (end < n) 
    {
        if (visited[s[end]] == -1 || visited[s[end]] < start) 
        {
            visited[s[end]] = end;
            end++;
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                strncpy(substring, s + start, maxLength);
                substring[maxLength] = '\0'; // Null-terminate the substring
            }
        }   
        else
        {
            start = visited[s[end]] + 1;
            currentLength = end - start;
        }
    }
    return maxLength;
}
void main() 
{
    char str[100],substr[256];
    int len;
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    len=lengthOfLongestSubstring(str,substr);
    printf("Longest substring without repeating characters: %s\n", substr);
    printf("Length of longest substring: %d\n", len);

}