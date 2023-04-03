// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Empty {
};
struct X :Empty {
    int a;
};
int main()
{
    std::cout << "Hello World!\n";
    Empty a1, a2;
    if (&a1 == &a2)
        std::cout << "impossible: report error to compiler supplier";
    else
        std::cout << "empty object address is not the same";

    auto p1 = new Empty;
    auto p2 = new Empty;
    if (p1 == p2)
        std::cout << "impossible: report error to compiler supplier\n";
    else
        std::cout << "empty object address is not the same\n";

    auto p = new X;
    void* q1 = p;
    void* q2 = &p->a;
    if (q1 == q2)
        std::cout << "good optimizer\n";
    else
        std::cout << "no optimizer\n";
    getchar();
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
