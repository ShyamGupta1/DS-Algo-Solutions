// T.C : O(n)
// S.C : O(1)

class Solution
{
public:
    pair<Node *, Node *> splitList(struct Node *head)
    {
        // Find Middle using slow fast
        Node *slow = head;
        Node *fast = head;
        while (fast->next != head and fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *secondHalf = slow->next;
        slow->next = head;
        Node *temp = secondHalf;
        while (temp->next != head)
            temp = temp->next;
        temp->next = secondHalf;
        return {head, secondHalf};
    }
};