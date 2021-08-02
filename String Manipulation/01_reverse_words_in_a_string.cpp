/** In this question we need to reverse the sequence of the words.
  * Ex. "the sky is blue" -> "blue is sky the"
  * This can be done using extra memory also.
  * But the optimsed solution is to do this in O(n) time and constant space.
  * We will reverse each and every word of the given string.
  * Then we will reverse the whole string.
  * This in short reverse the string as we require.
  * Time taken is O(n).
  */

#include<bits/stdc++.h>
using namespace std;

void reverseOneWord(string& s, int start, int end) {
    while (start < end)
        swap(s[start++], s[end--]);
}

string reverseWords(string s) {
    int len = s.length(), j = 0, l = 0;
    for (int i = 0; i < len; i++) {
        while (s[i] == ' ')
            i++;
        if (i < len && j > 0)
            s[j++] = ' ';
        l = j;
        while (i < len && s[i] != ' ')
            s[j++] = s[i++];
        reverseOneWord(s, l, j - 1);
    }
    s.resize(j);
    reverseOneWord(s, 0, j - 1);
    return s;
}