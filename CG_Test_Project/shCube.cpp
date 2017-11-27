#include "stdafx.h"
#include "shCube.h"


void shCube::initVertex() {
	shVertex* tempVertex = new shVertex();
	for (int i = 0; i < 8; ++i) {
		GLint temp_index = i;
		for (int j = 0; j < 3; ++j) {
			GLint tempSign = temp_index % 2 ? 1 : -1;
			tempVertex->setValue(j, tempSign*dimensionArr[j]/2 + centrePos.getValue(j));
			temp_index /= 2;
		}
		vertexVector.push_back(*tempVertex);
	}
}
void shCube::initLine() {
	vertexPair* temp_pair = new vertexPair(0, 1);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(0, 2);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(0, 4);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(1, 3);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(1, 5);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(2, 3);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(2, 7);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(3, 6);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(4, 5);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(4, 7);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(5, 6);
	lineIndexVector.push_back(*temp_pair);
	temp_pair->setPair(6, 7);
	lineIndexVector.push_back(*temp_pair);
}
shCube::shCube()
{
}


shCube::shCube(GLfloat _x,GLfloat _y, GLfloat _z, GLfloat _l, GLfloat _w, GLfloat _h) {
	centrePos.setPosition(_x, _y, _z);
	dimensionArr[0] = _l;
	dimensionArr[1] = _w;
	dimensionArr[2] = _h;
	initObject();
}
shCube::~shCube()
{
}

