#include <map>
#include <iostream>
#include <array>
#include <iostream>
#include <iomanip>

using namespace std;

class Car
{
	public:
		int x;
		int y;

	public :
		Car()
		{
			cout << "default  constructor" << endl;
		}
		Car(int x, int y) : x(x), y(y)
		{
			cout << "Car constructor" << x << y << endl;
		}
		~Car()
		{
			cout << "d1 destructor" << endl;
		}
		void	print()
		{
			cout << "hello world" << endl;
		}
		class Engine
		{
			public:
				int h;
				Engine()
				{
					cout << " nested default  constructor" << endl;
				}
				void	print()
				{
					Car car;
					car.x = 10;
					cout << "hello world" << car.x << endl;
				}
		};
};

#include <iostream>  
using namespace std;  

class Parent  
{  
    public:
	int a;
	int b;
		Parent() {
			cout << "parent constructor\n";
		}
        void display()  
        {  
            cout << "It is the function of the Parent class "<< endl;   
        }
        void d()  
        {  
            cout << "It is the function of the Parent class    ddddsdsdsdsdsd"<< endl;   
        }
};  
 
class Child : public Parent  
{  
    public:  
		Child() {
			cout << "child constructor\n";
		}
        void display()  
        {
			int a  = 10;
            cout << "it is the function of the Child class " << a << endl;  
        }
};  
  
class Fake 
{
	private:
		int value;
    public:  
		Fake(int a): value(a){};
        void display()  
        {
			int a  = 10;
			value = 20;
            cout << "it is the function of the Child class " << a << endl;  
        }
		Fake&	operator=(const Fake& copy)
		{
			cout << copy.value << endl;
			return (*this);
		}
};

 
int main()
{
	Fake obj(10);

	cout << obj.value << endl;
	return 0;
}

/*
	float n = 3.75
	0.001
	11.11 ==> 1.111 * 2^1


	0 10000001 111000000000000000000
	1 0000000 11100000000000000000000

	11
	0 00000000 000000000000000000000011

    char* ch = reinterpret_cast<char*>(p);
    int* p = new int(65);
    char* ch = new char[100];
	const char c = 50;
	ch[0] = c;
	ch[1] = 'g';
    cout << *p << endl;
    cout << *ch << endl;
    cout << p << endl;
    cout << ch << endl;
	Test *base = new d1();

	base->add();
	delete base;
	cout << "size of test : " << sizeof(Test) << endl;
	cout << "size of d1 : " << sizeof(d1) << endl;
	cout << "size of d2 : " << sizeof(d2) << endl;
	cout << "size of d3 : " << sizeof(d3) << endl;
*/