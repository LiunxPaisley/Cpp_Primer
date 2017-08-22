#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a, val;

void foo(int val)
{
	static int si;
	enum Loc { a = 1024, b };
	struct Bar
	{
		Loc locVal;
		int barVal;
		void foorBar(Loc l = a)
		{
			//barVal = val; // wrong
			barVal = ::val;
			barVal = si;
			locVal = b;
		}
	};
}

int main()
{

}