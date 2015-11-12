#ifndef TWOLISTS
#define TWOLISTS

#include <forward_list>
#include <unordered_set>

/* In order to find missing element
 * add all elements to Hash Set
 * with O(1) insertion complexity for non-collision insertion
 * and check its size every time during insertions from second list
 * Changed size shows missing element
 * Complexity is defined by ~2*N insertion and N size checking -> O(N)
*/
void twolists()
{
    std::forward_list<int> a, b;

    for (int i = 0; i < 10; i++)
    {
        a.push_front(i);
        b.push_front(i);
    }

    std::forward_list<int>::iterator lit = a.begin();

    lit++;
    lit++;
    a.erase_after(lit);

    std::unordered_set<int> s;

    lit = a.begin();
    for (; lit != a.end(); ++lit)
    {
        s.insert(*lit);
    }

    std::cout << "Set size: " << s.size() << std::endl;
    unsigned int size = s.size();

    lit = b.begin();
    for (; lit != b.end(); ++lit)
    {
        s.insert(*lit);
        if (s.size() != size)
        {
            std::cout << "Missing element: " << *lit << std::endl;
            break;
        }
    }

}

#endif // TWOLISTS

