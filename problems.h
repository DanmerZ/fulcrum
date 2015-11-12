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
        Node* curr = root->next;
        Node* prev = NULL;
        while(curr != NULL)
        {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        root->next = prev;
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

    lst.reverse();
    //lst.reverse_recursion();

    std::cout << "After reversing:\n";
    lst.print_list();
}

/* Write a function to determine if an int array is an arithmetical progression
 *
 *
 *
 * */

bool isArithmeticalProgression(int arr[], int size)
{
    int diff = arr[1] - arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i]-arr[i-1] != diff) return false;
    }
    return true;
}

void problem_3()
{
    int progression[] = {2,4,6,8,10};
    int notProgression[] = {2,4,6,8,9};

    std::cout << "A Progression: " << isArithmeticalProgression(progression,5) << std::endl;
    std::cout << "Not a Progression: " << isArithmeticalProgression(notProgression,5) << std::endl;
}


#endif // PROBLEMS_H

