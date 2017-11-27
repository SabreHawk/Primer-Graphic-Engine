#include "stdafx.h"
#include "shCircle.h"



void shCircle::circlePointMapping(shScreenPoint & _p, GLint _type) {
	shScreenPoint _p0(centrePos.getX() + _p.getX(), centrePos.getY() + _p.getY());
	shScreenPoint _p1(centrePos.getX() - _p.getX(), centrePos.getY() + _p.getY());
	shScreenPoint _p2(centrePos.getX() + _p.getX(), centrePos.getY() - _p.getY());
	shScreenPoint _p3(centrePos.getX() - _p.getX(), centrePos.getY() - _p.getY());
	shScreenPoint _p4(centrePos.getX() + _p.getY(), centrePos.getY() + _p.getX());
	shScreenPoint _p5(centrePos.getX() - _p.getY(), centrePos.getY() + _p.getX());
	shScreenPoint _p6(centrePos.getX() + _p.getY(), centrePos.getY() - _p.getX());
	shScreenPoint _p7(centrePos.getX() - _p.getY(), centrePos.getY() - _p.getX());

	if (_type) {
		shLine tempLine(_p0, _p1);
		tempLine.drawLine();
		tempLine.setPosition(_p2, _p3);
		tempLine.drawLine();
		tempLine.setPosition(_p4, _p5);
		tempLine.drawLine();
		tempLine.setPosition(_p6, _p7);
		tempLine.drawLine();
	} else if (!_type) {
		_p0.drawPoint();
		_p1.drawPoint();
		_p2.drawPoint();
		_p3.drawPoint();
		_p4.drawPoint();
		_p5.drawPoint();
		_p6.drawPoint();
		_p7.drawPoint();
	}
}

shCircle::shCircle() {
}
shCircle::shCircle(shScreenPoint _centre, GLfloat _r)
	:centrePos(_centre), radius(_r) {
}
shCircle::shCircle(shScreenPoint _centre, GLfloat _r, shColorf _color)
	: centrePos(_centre), radius(_r), circleColor(_color) {
}
shCircle::shCircle(shCircle & _circle)
	: centrePos(_circle.getCentre()), radius(_circle.getRadius()), circleColor(_circle.getColor()) {
}

shScreenPoint shCircle::getCentre() {
	return centrePos;
}
GLfloat shCircle::getRadius() {
	return radius;
}
shColorf shCircle::getColor() {
	return circleColor;
}

void shCircle::drawWireframe() {
	shScreenPoint tempPoint(0, (GLint)radius);
	GLint disValue = 1 - (GLint)radius;		//Initial discriminant Value = 5/4 - radius;
	GLint comOffset = 2 * tempPoint.getX() + 1;
	GLint lowOffset = 2 * tempPoint.getY();
	while (tempPoint.getX() <= tempPoint.getY()) {
		circlePointMapping(tempPoint,0);
		tempPoint.incrementX();
		comOffset += 2;
		disValue += comOffset;
		if (disValue > 0) {
			tempPoint.decrementY();
			lowOffset -= 2;
			disValue -= lowOffset;
		}
	}
}
void shCircle::paint() {
	shScreenPoint tempPoint(0, (GLint)radius);
	GLint disValue = 1 - (GLint)radius;		//Initial discriminant Value = 5/4 - radius;
	GLint comOffset = 2 * tempPoint.getX() + 1;
	GLint lowOffset = 2 * tempPoint.getY();
	while (tempPoint.getX() <= tempPoint.getY()) {
		circlePointMapping(tempPoint, 1);
		tempPoint.incrementX();
		comOffset += 2;
		disValue += comOffset;
		if (disValue > 0) {
			tempPoint.decrementY();
			lowOffset -= 2;
			disValue -= lowOffset;
		}
	}
}

void shCircle::rotateCentre(GLfloat _degree, shScreenPoint _centrePoint = shScreenPoint()) {
	centrePos.rotatePoint(_degree, _centrePoint);
}
void shCircle::rotateCentre(GLfloat _degree, GLfloat _x, GLfloat _y, GLfloat _z) {
	centrePos.rotatePoint(_degree, (GLint)_x,(GLint)_y);
}
void shCircle::scaleRadius(GLfloat _scale) {
	radius *= _scale;
}

