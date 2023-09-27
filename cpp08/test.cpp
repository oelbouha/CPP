#include <iostream>
#include <array>
#include <vector>

int main() 
{
    std::vector<int> myArray(10);

	myArray.push_back(10);
	myArray.push_back(10);
	myArray.push_back(10);
	myArray.push_back(10);
    // Access elements using index
    std::cout << "Element at index 2: " << myArray[2] << std::endl;
	/*
    // Iterate using a range-based for loop
	for (const int& element : myArray)
	{
        std::cout << element << " ";
    }
	*/
    myArray.end();

    // Get the size of the array
    std::cout << "Array size: " << myArray.size() << std::endl;

    return 0;
}
