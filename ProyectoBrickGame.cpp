
// ProyectoBrickGame.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "brick.h"
#include <Windows.h>



int main()
{

	brick a;

	int opc;

	cout << "<<<<<BrikGame>>>>>\n";

	do
	{
		cout << "1 NewGame\n2 Board\n3 Exit\n";
		cin >> opc;

		switch (opc)
		{
		case 1:
			a.carro();
			break;
			

		case 2:
			a.board();
			break;

		case 3:
			break;

		}


	} while (opc!=3);

	
	system("pause");
    return 0;
}

