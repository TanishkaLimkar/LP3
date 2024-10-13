#include <bits/stdc++.h>
using namespace std;

class Fibonacci
{
public:
    int n;

    Fibonacci(int n)
    {
        this->n = n;
    }

    // Recursive Fibonacci function
    int recursive(int i)
    {
        if (i <= 1)
        {
            return i;
        }
        return recursive(i - 1) + recursive(i - 2);
    }

    // Iterative Fibonacci function
    void iterative()
    {
        int t1 = 0;
        int t2 = 1;
        int nextTerm = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                cout << t1 << " ";
                continue;
            }
            if (i == 2)
            {
                cout << t2 << " ";
                continue;
            }
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            cout << nextTerm << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter N:" << endl;
    cin >> n;

    Fibonacci fb(n);

    // Iterative version
    cout << "Using Iteration Fibonacci series: " << endl;
    fb.iterative();

    // Recursive version
    cout << "Using Recursion Fibonacci series: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << fb.recursive(i) << " ";
    }
    cout << endl;

    return 0;
}

/*Enter N:
5
Using Iteration Fibonacci series:
0 1 1 2 3
Using Recursion Fibonacci series:
0 1 1 2 3 */
