// T.C : O(n)
// S.C : O(n)

class Solution
{
public:
    ListNode *frequenciesOfElements(ListNode *head)
    {
        unordered_map<int, int> mp;
        ListNode *temp = head;
        while (temp)
        {
            mp[temp->val]++;
            temp = temp->next;
        }
        ListNode *result = new ListNode(0, NULL);
        temp = result;
        for (auto x : mp)
        {
            temp->next = new ListNode(x.second);
            temp = temp->next;
        }
        temp->next = NULL;
        return result->next;
    }
};