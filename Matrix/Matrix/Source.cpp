#include "stdio.h"
#include "iostream"
#include "library.h"
#include "conio.h"

char c;
int a, b, x;

int main()
{
	using namespace std;

	while (1)
	{
		matrix mat;

		switch (c)
		{
		case 0:
			cout << "Ferdyan Dannes K" << endl;
			cout << "07111440000025" << endl;
			cout << "ANN QUIZ 1" << endl;
			cout << "Input Matrix		: i " << endl;
			cout << "Proses ANN		: a " << endl;
			cout << "Pilih Proses		: "; cin >> c; cout << endl;
			if (c == 'i' || c == 'a')
			{
				//do nothing
			}
			else
			{
				cout << "Tidak dapat diproses" << endl << endl << endl;
				c = 0;
			}
			break;

		case 'i':
			cout << "Matrik Input "; cout << endl;
			mat.inputMatrix();
			c = 0;
			break;

		case 'a':
			cout << "Proses ANN" << endl;
			mat.ann();
			c = 0;
			break;
		}
	}
}