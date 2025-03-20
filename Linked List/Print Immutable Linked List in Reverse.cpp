// T.C : O(n)
// S.C : O(n) recursion stack holds n function calls

void printLinkedListInReverse(ImmutableListNode *head)
{
    if (head == NULL)
        return;
    printLinkedListInReverse(head->getNext());
    head->printValue();
}