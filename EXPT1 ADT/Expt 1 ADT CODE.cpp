#include <iostream>
using namespace std;
class complex
{
public:
    float real;
    float img;
    // default constructor
    complex()
    {
        real = 0;
        img = 0;
    }
    // parameterised constructor
    complex(float r, float i)
    {
        real = r;
        img = i;
    }
    void set()
    {
        cout << "real part:" << endl;
        cin >> real;
        cout << "img part:" << endl;
        cin >> img;
    }
    void get()
    {
        cout << "The complex number is: " << real << "+" << img << "i" << endl;
    }
    void add(complex a, complex b)
    {
        complex c;
        c.real = a.real + b.real;
        c.img = a.img + b.img;
        c.get();
        // return c;
    }
    void subtract(complex a, complex b)
    {
        complex diff;
        diff.real = a.real - b.real;
        diff.img = a.img - b.img;
        diff.get();
    }

    void multiply(complex a, complex b)
    {
        complex product;
        product.real = a.real * b.real - a.img * b.img;
        product.img = a.real * b.img + a.img * b.real;
        product.get();
    }

    void isEqual(complex a, complex b)
    {

        if (a.real == b.real && a.img == b.img)
        {
            cout << "z1 and z2 are equal" << endl;
        }
        else
        {
            cout << "z1 and z2 are not equal" << endl;
        }
    }
};

int main()
{
    complex a(3, 2), b(2, 3);
    complex ans;
    ans.add(a, b);
    ans.subtract(a,b);
    return 0;
}