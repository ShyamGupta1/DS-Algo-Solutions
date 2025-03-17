// T.C : O(n)
// S.C : O(n)

class Solution
{

public:
    Node *sortList(Node *head)
    {
        deque<int> dq;
        Node *temp = head;
        for (; temp; temp = temp->next)
        {
            if (temp->data < 0)
                dq.push_front(temp->data);
            else
                dq.push_back(temp->data);
        }
        temp = head;
        Node *result = new Node(0);
        Node *ans = result;
        while (!dq.empty())
        {
            ans->next = new Node(dq.front());
            ans = ans->next;
            dq.pop_front();
            temp = temp->next;
        }
        ans->next = NULL;
        return result->next;
    }
};

// T.C : O(n)
// S.C : O(1)

class Solution
{

public:
    Node *sortList(Node *head)
    {
        // Your Code Here
        if (!head || !head->next)
            return head;

        Node *temp = head;
        while (temp->next)
        {
            if (temp->next->data < 0)
            {
                Node *insertFront = temp->next;
                temp->next = temp->next->next;
                insertFront->next = head;
                head = insertFront;
            }
            else
                temp = temp->next;
        }
        return head;
    }
};