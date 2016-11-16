#include "t_stack.h"
#include <iostream>

using namespace std;

void main()
{
	Stack<int> iStack;
	Stack<char> cStack;

	for (int i = 0; i < 100; ++i)
	{
		iStack.pushTop(i);
		cStack.pushTop(i);
	}
	
	for (int i = 1; i < 101; ++i)
	{
		iStack + i;
		cStack + i;
	}

	cout << "int Stack:" << endl;
	
	//cout << iStack.getSize();
	cout << iStack << endl << endl;

	cout << " char Stack:" << endl;
	
	cout << cStack << endl << endl;

	
	system("pause");

	

}