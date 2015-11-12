#ifndef PROBLEMS_H
#define PROBLEMS_H


#include <iostream>

/* Reverse a singly linked list with and without recursion
 *
 * Reconnect node->next pointers to inverse direction
 * from next to prev
*/
struct Node
{
    Node* next;
    int data;
    Node(Node* n = NULL, int d = 0) : next(n), data(d) {}
};

class SimpleList
{
private:
    Node* root;
    Node* reverseHelper(Node* prev, Node* next)
    {
        if (next == NULL) return prev;
        Node* tmp = next->next;
        next->next = prev;
        return reverseHelper(next,tmp);
    }

public:
    SimpleList()
    {
        root = new Node;
        root->next = NULL;
    }
    ~SimpleList()
    {
        Node* n1 = root->next;
        Node* n2;
        while (n1 != NULL)
        {
            n2 = n1->next;
            std::cout << "From Destructor: delete element " << n1->data << std::endl;
            delete n1;
            n1 = n2;
        }
        delete root;
    }

    void push_front(Node* n)
    {
        Node* node = new Node;
        node->data = n->data;
        node->next = root->next;
        root->next = node;
    }
    void print_list()
    {
        Node* cur = root->next;
        while (cur != NULL)
        {
            std::cout << cur->data << std::endl;
            cur = cur->next;
        }
    }
    void reverse()
    {
        Node* n1, *n2, *n3;
        n1 = root->next;
        if (n1 == NULL) return;
        n2 = n1->next;
        if (n2 == NULL) return;
        n3 = n2->next;

        n1->next = NULL;
        while (n2 != NULL)
        {
            n3 = n2->next;
            n2->next = n1;

            n1 = n2;
            n2 = n3;
        }
        root->next = n1;
    }
    void reverse_recursion()
    {
        if (root->next == NULL) return;
        Node* last = reverseHelper(root->next,root->next->next);
        root->next->next = NULL;
        root->next = last;
    }
};

void problem_1()
{
    SimpleList lst;

    Node n1(NULL,1), n2(NULL,2), n3(NULL,3), n4(NULL,4);
    lst.push_front(&n1);
    lst.push_front(&n2);
    lst.push_front(&n3);
    lst.push_front(&n4);
    std::cout << "Before reversing:\n";
    lst.print_list();

    //lst.reverse();
    lst.reverse_recursion();

    std::cout << "After reversing:\n";
    lst.print_list();
}

#endif // PROBLEMS_H

