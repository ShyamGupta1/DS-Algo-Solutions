#include <bits/stdc++.h>
using namespace std;

int cnt;
bool isVowel(char c)
{
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
        return true;
    return false;
}
void printFib(string s, int n)
{
    if (n < 0)
        return;
    printFib(s, n - 1);
    if (isVowel(s[n]))
        cnt++;
}

int main()
{
    string str;
    getline(cin, str);
    printFib(str, str.size() - 1);
    cout << cnt;
    return 0;
}