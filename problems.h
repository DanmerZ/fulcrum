#ifndef PROBLEMS_H
#define PROBLEMS_H


#include <iostream>
#include <list>
#include <unordered_set>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

/* Problem 1
 * Reverse a singly linked list with and without recursion
 *
 * Reconnect node->next pointers in inverse direction
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
        root = NULL;
    }
    ~SimpleList()
    {
        if (root == NULL) return;
        Node* n1 = root->next;
        Node* n2;
        while (n1 != NULL)
        {
            n2 = n1->next;
            //std::cout << "From Destructor: delete element " << n1->data << std::endl;
            delete n1;
            n1 = n2;
        }
        delete root;
    }
    Node* getRoot()
    {
        return root;
    }
    bool isEmpty()
    {
        return root == NULL;
    }

    void push_front(Node* n)
    {
        Node* node = new Node;
        node->data = n->data;
        if (root == NULL)
        {
            root = node;
            root->next = NULL;
        }
        else
        {
            node->next = root->next;
            root->next = node;
        }
    }
    void push_front(int i)
    {
        Node* n = new Node(NULL,i);
        push_front(n);
    }

    void print_list()
    {
        Node* cur = root;
        while (cur != NULL)
        {
            std::cout << cur->data << std::endl;
            cur = cur->next;
        }
    }
    void reverse()
    {
        Node* curr = root;
        Node* prev = NULL;
        while(curr != NULL)
        {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        root = prev;
    }
    void reverse_recursion()
    {
        if (root == NULL) return;
        Node* last = reverseHelper(root,root->next);
        root->next = NULL;
        root = last;
    }
};

void problem_1()
{
    SimpleList lst;

    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);

    std::cout << "Before reversing:\n";
    lst.print_list();

    //lst.reverse();
    lst.reverse_recursion();

    std::cout << "After reversing:\n";
    lst.print_list();
}

/* Problem 2
 * Find the min value in a sorted cycled singly linked list
 *
 * Using Floyd's cycle-finding algorithm to detect cycle
 * with fast and slow pointers
 *
 * */

bool isCycledList(Node* root)
{
    Node* fast = root;
    Node* slow = root;
    int minimum = root->data;
    do
    {
        slow = slow->next;
        minimum = std::min(minimum,slow->data);
        if (slow == NULL) return false;
        fast = fast->next->next;
        if (fast == NULL) return false;
        std::cout << "Slow: " << slow->data << ", fast: " << fast->data << std::endl;

    } while(fast != slow);
    std::cout << "Minimum value in list is: " << minimum << std::endl;
    return true;
}

void problem_2()
{
    // create cycled ordered list
    Node* root = new Node(NULL,0);
    Node* n1 = new Node(NULL,1);
    Node* n2 = new Node(NULL,2);
    Node* n3 = new Node(NULL,3);
    Node* n4 = new Node(NULL,4);
    Node* n5 = new Node(NULL,5);
    Node* n6 = new Node(NULL,6);
    Node* n7 = new Node(NULL,7);

    root->next = n1;
    n1->next = n2; // cycle from here
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = root; // to there
    //n7->next = NULL;
    std::cout << "isCycled: " << isCycledList(root) << std::endl;

    // delete root; ...
}

/* Problem 3
 * Write a function to determine if an int array is an arithmetical progression
 *
 * Comparing two adjucent elements
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

/* Problem 4
 * Write a function to leave only one node for nodes with duplicate values.
 *
 * I guess the problem is about a list's node.
 * The idea is to store every element of list in a hash set (unordered_set)
 * and check if some next element is already in hash set, then remove it from the list
*/

void problem_4()
{
    std::list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(2);
    list.push_back(2);
    list.push_back(4);
    list.push_back(1);

    std::unordered_set<int> set;

    std::list<int>::iterator lit;
    std::unordered_set<int>::iterator sit;

    for (lit = list.begin(); lit != list.end(); )
    {
        sit = set.find(*lit);
        if (sit != set.end()) // if duplicate
        {
            std::cout << "Erase duplicate: " << *lit << std::endl;
            lit = list.erase(lit);
        }
        else
        {
            set.insert(*lit);
            ++lit;
        }
    }
    std::cout << "finished" << std::endl;
}

/* Problem 5
 * Write a function which can count how many times every char is present in a string
 *
 * Insert every char into map<char,int>
*/

void problem_5()
{
    std::string str = "Write a function which can count how many times every char is present in a string";
    std::map<char,int> map;

    for (auto c : str)
    {
        map[c]++;
    }
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

/* Problem 6
 * Write a function that returns only chars that appears in two given strings
 *
 * Using std::set_intersection
 *
*/

std::string intersectStrings(std::string s1, std::string s2)
{
    std::string result;

    std::set<char> set1, set2;

    for (auto c : s1)
        set1.insert(c);

    for (auto c : s2)
        set2.insert(c);


    std::set<char> intersection;
    std::set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),
                          std::inserter(intersection,intersection.begin()));

    for (auto c : intersection)
        result += c;

    return result;
}

void problem_6()
{
    std::string s1 = "Hello";
    std::string s2 = "world";
    std::cout << "Intersection of " << s1 << " and " << s2 << " is ";
    std::cout << intersectStrings(s1,s2) << std::endl;
}




/* Problem 7
 * Find the value of the predecessor of min element
 * ... I guess "in singly linked list"
 *
 * Moving along the list and storing previous element
 *
 * */

int predOfMin(Node* root)
{
    Node* current = root, *pred = NULL;
    int minimum = root->data;
    while (current != NULL)
    {
        if (current->next && current->next->data < minimum)
            pred = current;
        current = current->next;
    }
    if (pred != NULL)
        return pred->data;
    else
    {
        std::cout << "The minimum element does not have the predecessor\n";
        return -1e5;
    }
}

void problem_7()
{
    // create singly linked list
    SimpleList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);


    std::cout << "Predecessor of minimal element: " << predOfMin(list.getRoot()) << std::endl;

}

#endif // PROBLEMS_H

