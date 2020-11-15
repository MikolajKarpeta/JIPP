#include <iostream>
#include <algorithm> //swap
#include <cassert>
#include <typeinfo>
using std::cout;
using std::endl;

template < typename T >
void swap( T & a, T & b ){
    T temp = a;
    a = b;
    b = temp;
}

template < typename T >
void test( T a, T b ){
    T aAfter = b;
    T bAfter = a;
    std::string type = typeid(T).name();
    std::string msg = type;
    msg.append(" test failed");

    cout << "Type: " << type << endl;
    cout << "Before " << a << " " << b << endl;
    swap(a,b);
    assert(a == aAfter && b == bAfter && msg.c_str());
    cout << "After " << aAfter << " " << bAfter << endl <<endl;
}


int main(){
    int a = 3, b = 5;
    test(a,b);

    double c = 2.43, d = 5.7438;
    test(c,d);

    float e = 5.5432, f = 543.52;
    test(e,f);

    char g = 'b',h = 'g';
    test(g,h);
}