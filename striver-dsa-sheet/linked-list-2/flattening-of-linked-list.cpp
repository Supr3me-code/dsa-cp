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
