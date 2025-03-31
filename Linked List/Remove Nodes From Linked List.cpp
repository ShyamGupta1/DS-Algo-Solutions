class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {

        stack<int> st;
        ListNode *temp = head;
        ListNode *dummy = head;
        ListNode *prev = NULL;
        while (temp)
        {
            dummy = temp->next;
            temp->next = prev;
            prev = temp;
            temp = dummy;
        }
        head = prev;
        temp = head;
        ListNode *ans = NULL;
        while (temp)
        {
            if (st.empty())
            {
                st.push(temp->val);
                ListNode *newNode = new ListNode(st.top(), ans);
                ans = newNode;
                temp = temp->next;
                continue;
            }
            else if (!st.empty() and temp->val >= st.top())
            {
                st.push(temp->val);
                ListNode *newNode = new ListNode(temp->val, ans);
                ans = newNode;
            }
            temp = temp->next;
        }
        return ans;
    }
};