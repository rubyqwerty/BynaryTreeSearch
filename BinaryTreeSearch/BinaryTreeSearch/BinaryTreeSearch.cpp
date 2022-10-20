
#include <iostream>
#include "BynaryTreeSearchStructure.h"

int main()
{
    BynaryTreeSearch a;
    
    a.push(4);
    a.push(5);
    a.push(1);
    a.push(3);
    a.push(10);

    cout << a.search(9);
    a.push(1);
}
