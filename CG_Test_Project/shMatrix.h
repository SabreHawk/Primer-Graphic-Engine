#pragma once
#ifndef	_SH_SHMATRIX_H_
#define _SH_SHMATRIX_H_
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class shMatrix {
private:
	int rowNum;
	int colNum;
	vector<vector<float> > matrix;
public:
	shMatrix();
	shMatrix(const int, const int);
	shMatrix(const int, const int,const float);
	shMatrix(const int, const int, const float[]);
	void dispMatrix();
	int getRowNum() const;
	int getColNum() const;
	float getValue(const int ,const int) const;
	shMatrix subtract(shMatrix &);
	shMatrix add(shMatrix &);
	shMatrix preMulti(shMatrix &);
	shMatrix postMulti(const shMatrix &);
	shMatrix conversion();
	void setValue(const int, const int,const float _value);
	void setMatrix(const int, const int, const float[]);
};
#endif

