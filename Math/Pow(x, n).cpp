// T.C : O(log n)
// S.C : O(1)

class Solution
{
public:
    double getPower(double base, long power)
    {
        if (power == 0)
            return 1;
        double half = getPower(base, power / 2);
        double result = half * half;
        if (power % 2)
            result *= base;
        return result;
    }
    double myPow(double x, int n)
    {

        long val = n;
        if (n < 0)
            val = -val;
        double ans = getPower(x, val);
        if (n < 0)
            return (1 / ans);
        return ans;
    }
};

// T.C : O(log n)
// S.C : O(1)

class Solution
{
public:
    double myPow(double x, int n)
    {

        long val = n;
        bool checkNeg = false;
        if (n < 0)
            val = -val, checkNeg = true;
        double ans = 1;
        while (val)
        {
            if (val & 1)
                ans = ans * x;
            x = x * x;
            val >>= 1;
        }
        if (checkNeg)
            return 1 / ans;
        return ans;
    }
};