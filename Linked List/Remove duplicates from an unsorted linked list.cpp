// T.C : O(n)
// S.C : O(n)

class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        Node *result = new Node(0);
        Node *ans = result;
        unordered_set<int> st;
        Node *temp = head;
        for (; temp; temp = temp->next)
            st.insert(temp->data);

        temp = head;
        while (!st.empty() and temp)
        {
            if (st.find(temp->data) != st.end())
            {
                result->next = temp;
                result = result->next;
                st.erase(st.find(temp->data));
            }
            temp = temp->next;
        }
        result->next = NULL;
        return ans->next;
    }
};