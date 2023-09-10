#include <iostream>

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

int main()
{
	Car::Engine nested;
	nested.print();
}

/*	
	Test *base = new d1();

	base->add();
	delete base;
	cout << "size of test : " << sizeof(Test) << endl;
	cout << "size of d1 : " << sizeof(d1) << endl;
	cout << "size of d2 : " << sizeof(d2) << endl;
	cout << "size of d3 : " << sizeof(d3) << endl;
*/