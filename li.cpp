#include<iostream>
using std::cout;
using std::cin;

class A
{
public:
    A(int val1 = 2, int val2 = 5)
        : m_val1(val1)
        , m_val2(val2)
    {
    }
 
public:
    int m_val1;
    int m_val2;
};

int main(){
    
    A a(3);
    cout<<a.m_val2;
    cin.get();
    return 0;
}