// T.C : O(n)
// S.C : O(1)

class Solution
{
public:
    Node *sortedInsert(Node *head, int data)
    {

        Node *newNode = new Node(data);
        Node *temp = head;
        // Case 1: head == NULL
        if (!head)
        {
            newNode->next = newNode;
            return newNode;
        }

        // Case 2: Insert at middle
        while (temp->next != head)
        {
            if (temp->data <= data and temp->next->data >= data)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }

        // Case 3:  Insert at last if loop breaks early
        if (temp->next == head)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            if (data < head->data) // Update the head if the value is smaller
                head = newNode;
        }
        return head;
    }
};