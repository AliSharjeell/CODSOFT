#include <iostream>
using namespace std;
class calculator
{
    double num1, num2;
    char op;

public:
    double results;
    calculator() {}
    void calc()
    {
        cout << "enter calculation (e.g: 10+32, use any of these +,-,*,/): " << endl;
        cin >> num1 >> op >> num2;
        switch (op)
        {
        case '+':
        {
            results = num1 + num2;
            break;
        };
        case '-':
        {
            results = num1 - num2;
            break;
        };
        case '*':
        {
            results = num1 * num2;
            break;
        };
        case '/':
        {
            results = num1 / num2;
            break;
        };
        default:
        {
            cout << "enter a correct  operator (+,-,*,/)" << endl;
        };
        }
        cout << "The result is : " << results << endl;
    }
};
int main()
{
    calculator cal;
    while (1)
    {
        cal.calc();
    }
}