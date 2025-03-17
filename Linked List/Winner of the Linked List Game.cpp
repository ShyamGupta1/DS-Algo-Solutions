// T.C : O(n)
// S.C : O(1)

class Solution
{
public:
    string gameResult(ListNode *head)
    {

        int even = 0, odd = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp->val > temp->next->val ? ++even : ++odd;
            temp = temp->next->next;
        }
        if (even > odd)
            return "Even";
        else if (even == odd)
            return "Tie";
        else
            return "Odd";
    }
};