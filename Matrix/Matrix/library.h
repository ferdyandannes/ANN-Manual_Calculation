#pragma once
#include <iostream>
using namespace std;
class matrix
{
private:

public:
	int r1, c1, r2, c2, r3, c3, i, j, r, c;
	float matriks1[100][100], matriks2[100][100], matriks3[100][100];
	float pmin, pmax, normfp[100][100], w1[100][100], b1[100][100], w2[100][100], b2[100][100], o[100][100], wp[100][100], bo[100][100], h[100][100], n[100][100], y[100][100];
	int nnhl = 4;
	int kons, kons1, kons2;
	float wh[100][100], denormf[100][100];
	float tmax, tmin;
	void inputMatrix();
	void ann();
};