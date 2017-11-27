#include "stdafx.h"
#include "shEdge.h"




shEdge::shEdge() {
}
shEdge::shEdge(GLint _tY, GLfloat _bX, GLint _by, GLfloat _rK)
	:topY(_tY), bottomX(_bX), bottomY(_by), recK(_rK) {
}
shEdge::shEdge(shLine & _line) {
	GLint pArr[4];
	_line.getPoints(pArr);
	if (pArr[1] < pArr[3]) {
		topY = pArr[3];
		bottomX = (GLfloat)pArr[0];
		bottomY = pArr[1];
	} else {
		topY = pArr[1];
		bottomX = (GLfloat)pArr[2];
		bottomY = pArr[3];
	}
	recK = GLfloat((pArr[0] - pArr[2]) / (pArr[1] - pArr[3]));
}
shEdge::shEdge(shScreenPoint &_p1, shScreenPoint &_p2) {
	GLint pArr[4] = { _p1.getX(),_p1.getY(),_p2.getX(),_p2.getY() };
	if (pArr[1] < pArr[3]) {
		topY = pArr[3];
		bottomX = (GLfloat)pArr[0];
		bottomY = pArr[1];
	} else {
		topY = pArr[1];
		bottomX = (GLfloat)pArr[2];
		bottomY = pArr[3];
	}
	recK = GLfloat((pArr[0] - pArr[2]) / (pArr[1] - pArr[3]));
}
void shEdge::setEdge(shScreenPoint _p1, shScreenPoint _p2) {
	GLint pArr[4] = { _p1.getX(),_p1.getY(),_p2.getX(),_p2.getY() };
	if (pArr[1] < pArr[3]) {
		topY = pArr[3];
		bottomX = (GLfloat)pArr[0];
		bottomY = pArr[1];
	} else {
		topY = pArr[1];
		bottomX = (GLfloat)pArr[2];
		bottomY = pArr[3];
	}
	recK = (GLfloat)(pArr[0] - pArr[2]) / (pArr[1] - pArr[3]);
}
GLfloat shEdge::getBottomX() const{
	return this->bottomX;
}
GLint shEdge::getBottomY() const {
	return this->bottomY;
}
GLint shEdge::getTopY() const {
	return this->topY;
}
GLfloat shEdge::getRecK() const {
	return this->recK;
}

void shEdge::decrementTopY() {
	--topY;
}
void shEdge::incrementBottomX(GLfloat _v) {
	bottomX += _v;
}