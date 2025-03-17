// T.C : O(n)
// S.C : O(1)

class Solution
{
public:
    Node *linkdelete(Node *head, int n, int m)
    {
        if (!head)
            return head;
        int size = 1;
        Node *temp = head;

        while (temp)
        {
            bool updated = false;
            if (size == m)
            {
                Node *end = temp;
                int upto = n;
                while (end and upto--)
                    end = end->next;
                if (!temp->next)
                    break;
                if (!end)
                {
                    temp->next = NULL;
                    break;
                }
                temp->next = end->next;
                updated = true;
            }
            temp = temp->next;
            if (updated)
                size = 1;
            else
                size++;
        }
        return head;
    }
};