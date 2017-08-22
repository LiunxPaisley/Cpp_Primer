#include <iostream>
#include <vector>
#include <string>

#include "Blob.h"
#include "Sales_data.h"

using std::cin;
using std::cerr;
using std::endl;

int main()
{
	Sales_data item1, item2, sum;
	while (cin >> item1 >> item2)
	{
		try 
		{
			sum = item1 + item2;
		}
		catch(const isbn_mismatch& e)
	    {
			cerr << e.what() << ": left isbn(" << e.left
				<< ") right isbn(" << e.right << ")" << endl;
	    }
	}
}