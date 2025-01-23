// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
// substring.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int getSeqLen(char *s, int *i) {
    int count = 0;
    while (s[*i]){
        if (s[*i] == ')') {
            *i+=1;
            return 2 + count;
        }
        else {
            *i+=1;
            count += getSeqLen(s, i);
        }
    }
    return count;
}
int longestValidParentheses(char* s) {
    int i = 0;
    int max = 0;
    int count = 0;
    while (s[i]){
        if (s[i] == ')') {
            if (count > max) max = count;
            ++i;
            count = 0;
        }
        else {
            ++i;
            count += getSeqLen(s, &i);
        }
    }
    if (count > max) max = count;
    return max;
}

int main(){
    char s[] = "((())(((()))";
    int ans = longestValidParentheses(s);
    printf("%d\n", ans);
}
// ((())(((()))