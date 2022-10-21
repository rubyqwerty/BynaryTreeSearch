
#include <iostream>
#include <vector>
#include <algorithm>
#include "BynaryTreeSearchStructure.h"
#include <ctime>
int main()
{
    BynaryTreeSearch a;
    /*
    a.push(50);
    a.push(25);
    a.push(75);
    a.push(12);
    a.push(37);
    a.push(11);
    a.push(63);
    a.push(64);
    a.push(100);
    a.push(90);
    a.push(110);
    a.push(62);
    a.push(87);
    a.push(30);
    a.push(38);
    a.push(26);
    a.push(27);
    a.push(1);
    a.push(9);
    a.push(10);
    a.push(-1);
    a.push(2);
   */
    vector<int> b;
    unsigned int start_time = clock();
    for (int i = 0; i < 100000; ++i) {
        int n = rand() % 500000 + 1;
        a.push(n);
      
    }
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << search_time << endl;
    cout << "d\n"; int k; cin >> k;

}
