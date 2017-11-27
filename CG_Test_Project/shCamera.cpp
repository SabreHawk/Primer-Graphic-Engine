#include "stdafx.h"
#include "shCamera.h"
//

//PRIVATE MEMBER FUNCTION
void shCamera::initViewCoord() {
		shVector _n = uvnFrame[2].getNormalized();
		shVector temp_u = uvnFrame[1].crossProduct(_n);
		temp_u = temp_u.getNormalized();
		shVector _v = _n.crossProduct(temp_u);
		uvnFrame[0] = temp_u;
		uvnFrame[1] = _v;
		uvnFrame[2] = _n;
	}

//PUBLIC MEMBER FUNCTION
shCamera::shCamera() {
}
shCamera::shCamera(shVertex _pos,shVector _n, shVector _v,projectionType _p)
	:projectionModel(_p) {
	uvnFrame[1] = _v;
	uvnFrame[2] = _n;
	uvnPos = _pos;
	initViewCoord();
}

shCamera::~shCamera() {
}
void shCamera::setFrame(shVector _n, shVector _v) {
	uvnFrame[1] = _v;
	uvnFrame[2] = _n;
	initViewCoord();
}
void shCamera::setPos(GLfloat _x, GLfloat _y, GLfloat _z) {
	uvnPos.setPosition(_x, _y, _z);
}
void shCamera::setPos(shVertex _p) {
	uvnPos = _p;
}

shVector shCamera::getU() {
	return uvnFrame[0];
}
shVector shCamera::getV() {
	return uvnFrame[1];
}
shVector shCamera::getN() {
	return uvnFrame[2];
}
shVertex shCamera::getPos() {
	return uvnPos;
}