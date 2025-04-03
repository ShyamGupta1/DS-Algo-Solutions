#include <bits/stdc++.h>
using namespace std;

void printSpace(int n)
{
    if (n == 0)
        return;
    printSpace(n - 1);
    cout << " ";
}
void printStar(int n)
{
    if (n == 0)
        return;
    cout << "*";
    printStar(n - 1);
}
void printFib(int n, int current = 1)
{
    if (current > n)
        return;
    printFib(n, current + 1);
    printSpace(n - current);
    printStar(2 * current - 1);
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    printFib(t);
    return 0;
}