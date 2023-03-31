#include "List.h"
#include <iostream>
#include <list>

using namespace std;

int main()
{
    List<int> l; // Створюємо об'єкт класу List
    
    
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.insert(4, 10);
    for (int i = 0; i < l.getSize(); i++)
    {
        cout << l[i] << endl;
    }
    return 0;
}
