#include <bits/stdc++.h>
using namespace std;
 
long long printFib(int n)
{
    if (n == 0)
        return 1;
    return n * printFib(n - 1);
}
 
int main()
{
    int n;
    cin >> n;
    cout << printFib(n);
    return 0;
}