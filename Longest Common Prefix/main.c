/*
14. Longest Common Prefix
Attempted
Easy
Topics
premium lock icon
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char *substr_0_to_i(const char *str, int i)
{
    if (!str || i < 0) 
        return NULL;
    int len = strlen(str);
    if (i > len)
        i = len;  // agar i uzunlikdan katta bo‘lsa, oxirigacha oladi

    char *res = malloc(i + 1); // i ta belgi + '\0'
    if (!res)
        return NULL;

    for (int j = 0; j < i; j++)
        res[j] = str[j];
    res[i] = '\0';

    return res;
}

char* longestCommonPrefix(char **strs, int strsSize) {
    char *pref;
    int i = 0;
    int j = 0;
    while (strs[0][i])
    {
        j = 0;
        while (j < strsSize)
        {
            if(strs[j][i] != strs[0][i])
                return (substr_0_to_i(strs[0], i));
            j++;
        }
        i++;
    }
    return ("");
}
int main(void)
{
    char *str[] = { "flower", "flow", "flight" };
    char *habibi = longestCommonPrefix(str, 3);
    printf("%s\n", habibi);
}