/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"

int main(int argc, char* argv[])
{
		ULListStr test1; //testing push_front
		test1.push_front("1");
		test1.push_front("2");
		test1.push_front("3");

		int size = test1.size();
		std::cout << "Pushing front 1 2 3: " << std::endl;
  	for (int i = 0; i < size; i++) {
    		std::cout << test1.get(i) << " ";
  	}
		std::cout << std::endl;
		
		test1.push_back("4"); //testing it with push_back 
		test1.push_back("5");
		test1.push_back("6"); 

		size = test1.size();
		std::cout << "Pushing back 4 5 6: " << std::endl;
		for (int i = 0; i < size; i++) {
    		std::cout << test1.get(i) << " ";
  	}
		std::cout << std::endl;

		test1.pop_front(); //testing pop front and back
		test1.pop_back();

		size = test1.size();
		std::cout << "Popped front and back once: " << std::endl;
		for (int i = 0; i < size; i++) {
    		std::cout << test1.get(i) << " ";
  	}

		test1.clear();

		std::cout << std::endl << "Cleared list and populating with numbers 1-14" << std::endl;

		test1.push_back("1");
		test1.push_back("2");
		test1.push_back("3");
		test1.push_back("4");
		test1.push_back("5");
		test1.push_back("6");
		test1.push_back("7");
		test1.push_back("8");
		test1.push_back("9");
		test1.push_back("10"); 
		test1.push_back("11"); //new Item
		test1.push_back("12");
		test1.push_back("13");
		test1.push_back("14");

		std::cout << "Testing front and back" << std::endl << "Front: " << test1.front();
		std::cout << std::endl << "Back: " << test1.back() << std::endl;
		

		for (int i = 0; i < 14; i++) //popping front until empty
		{
			test1.pop_front();
		}

		std::cout << "Size after popping front 14 times: " <<  test1.size() << std::endl;

}
