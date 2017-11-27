#include "stdafx.h"
#include "shMatrix.h"

shMatrix::shMatrix() {
	this->rowNum = 0;
	this->colNum = 0;
}
shMatrix::shMatrix(const int _r, const int _c) {
	rowNum = _r;
	colNum = _c;
	matrix.resize(_r);
	for (int i = 0; i < _r; ++i) {
		matrix[i].resize(_c);
	}
	for (int i = 0; i < _r; ++i) {
		for (int j = 0; j < _c; ++j) {
			if (i == j) {
				matrix[i][j] = 1;
			}
			
		}
	}
}
shMatrix::shMatrix(const int _r,const int _c,const float _n) {
	rowNum = _r;
	colNum = _c;
	matrix.resize(_r);
	for (int i = 0; i < _r; ++ i) {
		matrix[i].resize(_c);
	}
	for (int i = 0; i < _r; ++ i) {
		for (int j = 0; j < _c; ++ j) {
			matrix[i][j] = _n;
		}
	}
}
shMatrix::shMatrix(const int _r, const int _c,const float _matrix[]) {
	rowNum = _r;
	colNum = _c;
	int counter = 0;
	matrix.resize(_r);
	for (int i = 0; i < _r; ++i) {
		matrix[i].resize(_c);
	}
	for (int i = 0; i < _r; ++i) {
		for (int j = 0; j < _c; ++j) {
			matrix[i][j] = _matrix[counter++];
		}
	}
}
void shMatrix::dispMatrix() {
	for (int i = 0; i < rowNum; ++ i) {
		for (int j = 0; j < colNum; ++ j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int shMatrix::getRowNum() const{
	return rowNum;
}
int shMatrix::getColNum() const{
	return colNum;
}

shMatrix shMatrix::add(shMatrix & _matrix) {
	shMatrix tempMatrix = *this;
	float tempValue = 0;
	if (this->rowNum != _matrix.getRowNum() || this->colNum != _matrix.getColNum()) {
		printf("ERROR : matrix dimensions must agree!");
		return tempMatrix;
	}
	for (int i = 0; i < this->rowNum; ++ i) {
		for (int j = 0; j < this->colNum; ++j) {
			tempValue = this->matrix[i][j] + _matrix.getValue(i, j);
			tempMatrix.setValue(i, j, tempValue);
		}
	}
	return tempMatrix;
}
shMatrix shMatrix::subtract(shMatrix & _matrix) {
	shMatrix tempMatrix = *this;
	float tempValue = 0;
	if (this->rowNum != _matrix.getRowNum() || this->colNum != _matrix.getColNum()) {
		printf("ERROR : matrix dimensions must agree!");
		return tempMatrix;
	}
	for (int i = 0; i < this->rowNum; ++ i) {
		for (int j = 0; j < this->colNum; ++j) {
			tempValue = this->matrix[i][j] - _matrix.getValue(i, j);
			tempMatrix.setValue(i, j, tempValue);
		}
	}
	return tempMatrix;
}
shMatrix shMatrix::preMulti(shMatrix & _matrix) {
	shMatrix tempMatrix(_matrix.getRowNum(), this->colNum,float(0));
	if ( _matrix.getColNum()!= this->rowNum) {
		printf("ERROR : matrix dimensions must agree !");
		return tempMatrix;
	}

	for (int i = 0; i < tempMatrix.getRowNum(); ++i) {
		for (int j = 0; j < tempMatrix.getColNum(); ++j){
			float tempValue = 0;
			for (int multi_i = 0; multi_i < _matrix.getColNum(); ++multi_i) {
				tempValue += _matrix.getValue(i, multi_i) * this->getValue(multi_i, j);
			}
			tempMatrix.setValue(i, j, tempValue);
		}
	}
	return tempMatrix;
}
shMatrix shMatrix::postMulti(const shMatrix & _matrix) {
	shMatrix tempMatrix(this->rowNum, _matrix.getColNum(),float(0));
	if (this->colNum != _matrix.getRowNum()) {
		printf("ERROR : matrix dimensions must agree !");
		return tempMatrix;
	}
	for (int i = 0; i < tempMatrix.getRowNum(); ++ i) {
		for (int j = 0; j < tempMatrix.getColNum(); ++ j) {
			float tempValue = 0;
			for (int multi_i = 0; multi_i < this->colNum; ++ multi_i) {
				tempValue += this->getValue(i, multi_i) * _matrix.getValue(multi_i,j);
			}
			tempMatrix.setValue(i, j, tempValue);
		}
	}
	return tempMatrix;
}
shMatrix shMatrix::conversion() {
	shMatrix temp_con_matrix(this->colNum, this->rowNum,float(0));
	for (int i = 0; i < rowNum; ++i) {
		for (int j = 0; j < colNum; ++j) {
			temp_con_matrix.setValue(j, i, this->getValue(i, j));
		}
	}
	return temp_con_matrix;
}
float shMatrix::getValue(const int _i, const int _j) const {
	return matrix[_i][_j];
}
void shMatrix::setValue(const int _i, const int _j, const float _value) {
	matrix[_i][_j] = _value;
}
void shMatrix::setMatrix(const int  _row, const int _col, const float _matrix[]) {
	int counter = 0;
	this->rowNum = _row;
	this->colNum = _col;
	for (int i = 0; i < _row; ++i) {
		for (int j = 0; j < _col; ++j) {
			matrix[i][j] = _matrix[counter++];
		}
	}
}