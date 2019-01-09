#include "library.h"
#include <math.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void matrix::inputMatrix()
{
	cout << "Masukkan Jumlah Baris: "; cin >> r;
	cout << "Masukkan Jumlah Kolom: "; cin >> c; cout << endl;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			cout << "input baris ke " << i << " kolom ke " << j << "= ";
			cin >> matriks1[i][j];
		}
	}
	//cetak
	cout << "Nilai Matrix " << endl;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			cout << matriks1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}


void matrix::ann()
{
	cout << "Nilai Input" << endl;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			cout << matriks1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//Proses Normalisasi

	//Normalisasi Input
	pmin = 100;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (matriks1[i][j] > pmax)
				pmax = matriks1[i][j];
			if (matriks1[i][j] < pmin)
				pmin = matriks1[i][j];
		}
	}
	cout << endl;
	cout << "Nilai Maximum P :" << pmax;
	cout << endl;
	cout << "Nilai Minimum P :" << pmin;
	cout << endl;
	cout << "Hasil Normalisasi p:" << endl;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			normfp[i][j] = (2 * (matriks1[i][j] - pmin) / (pmax - pmin)) - 1;
			cout << normfp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//Inisialisasi nilai w & b
	w1[1][1] = 2.2693;
	w1[1][2] = 0.5865;
	w1[1][3] = 2.3852;
	w1[2][1] = -0.5192;
	w1[2][2] = 2.0259;
	w1[2][3] = 1.1233l;
	w1[3][1] = 1.3964;
	w1[3][2] = -3.0309;
	w1[3][3] = 0.5255;
	w1[4][1] = -0.5526;
	w1[4][2] = 0.8239;
	w1[4][3] = -0.4767;
	cout << "Matiks w1" << endl;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			cout << w1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	b1[1][1] = 1.4758;
	b1[2][1] = 1.1246;
	b1[3][1] = 1.3421;
	b1[4][1] = 0.2367;
	cout << "Matiks b1" << endl;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 1; j++)
		{
			cout << b1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	w2[1][1] = -2.1927;
	w2[1][2] = 1.8469;
	w2[1][3] = 2.7873;
	w2[1][4] = -0.4511;
	w2[2][1] = -1.5336;
	w2[2][2] = 1.4998;
	w2[2][3] = -0.3008;
	w2[2][4] = 0.9795;
	cout << "Matiks w2" << endl;
	for (i = 1; i <= 2; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			cout << w2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	b2[1][1] = -0.9249;
	b2[2][1] = 0.2414;
	cout << "Matiks b2" << endl;
	for (i = 1; i <= 2; i++)
	{
		for (j = 1; j <= 1; j++)
		{
			cout << b2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//Mencari nilai n = w*x + b
	//Menghitung nilai w*x
	//nilai w*p
	cout << "W * P :" << endl;
	for (i = 1; i <= nnhl; i++)
	{
		for (j = 1; j <= 1; j++)
		{
			wp[i][j] = 0;
			for (kons = 1; kons <= 3; kons++)
			{
				wp[i][j] += w1[i][kons] * normfp[kons][j];
			}
			cout << wp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//Nilai h
	cout << "h :" << endl;
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 1; j++) {
			n[i][j] = wp[i][j] + b1[i][j];
			cout << n[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//Menghitung nilai f(n)
	cout << "Nilai fn" << endl;
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 1; j++) {
			h[i][j] = 1 / (1 + exp(-n[i][j]));
			cout << h[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//Menghitung nilai y(n)
	//Mencari nilai w2 * h
	cout << "Nilai w2*h" << endl;
	for (i = 1; i <= 2; i++)
	{
		for (j = 1; j <= 1; j++)
		{
			wh[i][j] = 0;
			for (kons2 = 1; kons2 <= 4; kons2++)
			{
				wh[i][j] += w2[i][kons2] * h[kons2][j];
			}
			cout << wh[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//Mencari nilai w2*h + n2
	cout << "Nilai yn: " << endl;
	for (i = 1; i <= 2; i++) {
		for (j = 1; j <= 1; j++) {
			y[i][j] = wh[i][j] + b2[i][j];
			cout << y[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//Denormalisasi
	cout << "Nilai y: " << endl;
	for (i = 1; i <= 2; i++)
	{
		for (j = 1; j <= 1; j++)
		{
			denormf[i][j] = (0.5 * (y[i][j] + 1) * (10 + 10) - 10);
			cout << denormf[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
}