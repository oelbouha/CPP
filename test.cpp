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

template <typename T>
void printcoll (T const& coll)
{
    typename T::const_iterator pos;  			// iterator to iterate over coll
    typename T::const_iterator end(coll.end());	// end position

    for (pos=coll.begin(); pos!=end; ++pos)
	{
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}


#include <vector>
#include <array>

#define NAN 1;

int main()
{
	double n = 10.111111111;;
	cout << std::setprecision(8) ;
	cout << n << endl;
}

/*	
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