// T.C :  O(M log M + N log (M + N))
// S.C : O(M + N)

class Solution
{
public:
    Node *addPolynomial(Node *head1, Node *head2)
    {

        Node *first = head1;
        Node *second = head2;
        map<int, int> mp;
        while (first)
        {
            mp[first->pow] = first->coeff;
            first = first->next;
        }
        while (second)
        {
            if (mp.find(second->pow) != mp.end())
                mp[second->pow] += second->coeff;
            else
                mp[second->pow] = second->coeff;
            second = second->next;
        }
        Node *ans = NULL;
        for (auto x : mp)
        {
            Node *newNode = new Node(x.second, x.first);
            newNode->next = ans;
            ans = newNode;
        }
        return ans;
    }
};

// Using Merging two sorted list approach
// T.C : O(m+n)
// S.C : O(1)

class Solution
{
public:
    Node *addPolynomial(Node *head1, Node *head2)
    {

        Node *first = head1;
        Node *second = head2;
        Node *result = new Node(0, 0);
        Node *ans = result;
        while (first and second)
        {
            if (first->pow == second->pow)
            {
                ans->next = first;
                ans = ans->next;
                ans->coeff += second->coeff;
                first = first->next;
                second = second->next;
                ans->next = NULL;
            }
            else
            {
                if (first->pow > second->pow)
                {
                    ans->next = first;
                    ans = ans->next;
                    first = first->next;
                    ans->next = NULL;
                }
                else
                {
                    ans->next = second;
                    ans = ans->next;
                    second = second->next;
                    ans->next = NULL;
                }
            }
        }
        while (first)
        {
            ans->next = first;
            ans = ans->next;
            first = first->next;
        }
        while (second)
        {
            ans->next = second;
            ans = ans->next;
            second = second->next;
        }
        return result->next;
    }
};