// BruteForce
// T.C : O(n)
// S.C : O(1)

class Solution
{
public:
    int countGoodNumbers(long long n)
    {

        long mod = 1e9 + 7;
        int ans = 1;
        for (long i = 1; i <= n; i++)
        {
            if (i % 2)
                ans = (ans % mod * 5) % mod;
            else
                ans = (ans % mod * 4) % mod;
        }
        return ans % mod;
    }
};

// binary exponentiation method (or fast exponentiation) recursive
// T.C: O(logN)
// S.C: O(logN)

class Solution
{
public:
    long findPower(int base, long power, int mod)
    {
        if (power == 0)
            return 1;
        long half = findPower(base, power / 2, mod);
        long result = (half % mod * half % mod) % mod;
        if (power % 2)
            result = (result % mod * base % mod) % mod;
        return result;
    }
    int countGoodNumbers(long long n)
    {
        long totalEven = (n + 1) / 2;
        long totalPrime = n / 2;
        int mod = 1e9 + 7;
        long AllEven = findPower(5, totalEven, mod);
        long AllPrime = findPower(4, totalPrime, mod);
        int ans = (AllEven % mod * AllPrime % mod) % mod;
        return ans;
    }
};

// binary exponentiation method (or fast exponentiation) iterative
// T.C: O(logN)
// S.C: O(1)

class Solution
{
public:
    int mod = 1e9 + 7;
    long long findPower(long a, long b)
    {
        long long ans = 1;
        while (b)
        {
            if (b & 1)
                ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
    int countGoodNumbers(long long n)
    {
        return (findPower(5, (n + 1) / 2) % mod * findPower(4, n / 2) % mod) % mod;
    }
};