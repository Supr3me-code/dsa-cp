// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Node *merge(Node *first, Node *second)
{
    Node *head = new Node(-1);
    head->bottom = NULL;
    Node *temp = head;
    while (first && second)
    {
        if (first->data < second->data)
        {
            temp->bottom = first;
            first = first->bottom;
        }
        else
        {
            temp->bottom = second;
            second = second->bottom;
        }
        temp = temp->bottom;
    }
    if (first)
    {
        temp->bottom = first;
    }
    if (second)
    {
        temp->bottom = second;
    }
    return head->bottom;
}

Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (!fast->next && !fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *mid = middle(head);
    Node *head2 = mid->next;
    mid->next = NULL;

    Node *first = mergeSort(head);
    Node *second = mergeSort(head2);
    return merge(first, second);
}
Node *flatten(Node *root)
{
    return mergeSort(root);
}
