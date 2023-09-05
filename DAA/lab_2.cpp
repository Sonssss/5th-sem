//fibonacii series
#include <iostream>
using namespace std;
int count = 1;
int fib(int a)
{
    int f1 = 1, f2 = 1, f = 0, i;
    for (i = 3; i <= a; i++)
    {
        count++;
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }

    count++;
    return f;
}
int main()

{
    int a, b;
    cout << "Program by: Sagar Thapa" << endl;
    cout << "enter any no.";
    cin >> a;
    cout << "The fiboacci of " << a << " is " << fib(a) << endl;
    cout << "The time complexity is " << count;
}