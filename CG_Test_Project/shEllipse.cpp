#include "stdafx.h"
#include "shEllipse.h"


void shEllipse::ellipsePointPlot(shScreenPoint & _p, GLint _type = 0) {
	shScreenPoint _p0(centrePos.getX() + _p.getX(), centrePos.getY() + _p.getY());
	shScreenPoint _p1(centrePos.getX() - _p.getX(), centrePos.getY() + _p.getY());
	shScreenPoint _p2(centrePos.getX() + _p.getX(), centrePos.getY() - _p.getY());
	shScreenPoint _p3(centrePos.getX() - _p.getX(), centrePos.getY() - _p.getY());
	if (_type) {
		shLine tempLine(_p0, _p1);
		tempLine.drawLine();
		tempLine.setPosition(_p2, _p3);
		tempLine.drawLine();
	} else if (!_type) {
		_p0.drawPoint();
		_p1.drawPoint();
		_p2.drawPoint();
		_p3.drawPoint();
	}

}

shEllipse::shEllipse() {
}
shEllipse::shEllipse(GLint _x, GLint _y, GLint _a, GLint _b)
	: centrePos(_x, _y), majorAxisLength(_a), minorAxisLength(_b) {
}
shEllipse::shEllipse(shScreenPoint _p, GLint _a, GLint _b)
	: centrePos(_p), majorAxisLength(_a), minorAxisLength(_b) {
}
shEllipse::shEllipse(GLint _x, GLint _y, GLint _a, GLint _b, shColorf &_color)
	: majorAxisLength(_a), minorAxisLength(_b), ellipseColor(_color) {
	centrePos.setCoords(_x, _y);
}
shEllipse::shEllipse(shScreenPoint _centre, GLint _a, GLint _b, shColorf &_color)
	: centrePos(_centre), majorAxisLength(_a), minorAxisLength(_b), ellipseColor(_color) {
}
shEllipse::shEllipse(shEllipse &_ellipse)
	: centrePos(_ellipse.getCentre()),
	majorAxisLength(_ellipse.getMajorAxisLength()), minorAxisLength(_ellipse.getMinorAxisLength()),
	ellipseColor(_ellipse.getColor()) {
}

shScreenPoint shEllipse::getCentre() {
	return centrePos;
}
GLint shEllipse::getMajorAxisLength() {
	return majorAxisLength;
}
GLint shEllipse::getMinorAxisLength() {
	return minorAxisLength;
}
shColorf shEllipse::getColor() {
	return ellipseColor;
}

void shEllipse::drawWireframe() {
	shScreenPoint tempPoint(0, minorAxisLength);
	GLint disValue = (GLint)((minorAxisLength ^ 2) - (majorAxisLength ^ 2) * minorAxisLength + 0.25 * (majorAxisLength ^ 2));
	//GLint temp = 2 * (minorAxisLength ^ 2) * tempPoint.getX() <= 2 * (majorAxisLength ^ 2) * tempPoint.getY();
	while (2 * (minorAxisLength ^ 2) * tempPoint.getX() <= 2 * (majorAxisLength ^ 2) * tempPoint.getY()) {
		ellipsePointPlot(tempPoint);
		tempPoint.incrementX();
		disValue += 2 * (minorAxisLength ^ 2) * tempPoint.getX() + (majorAxisLength ^ 2);
		if (disValue > 0) {
			tempPoint.decrementY();
			disValue -= 2 * (majorAxisLength ^ 2)* tempPoint.getY();
		}
	}
	disValue = (GLint)((minorAxisLength ^ 2) * ((tempPoint.getX() + 1 / 2) ^ 2) + (majorAxisLength ^ 2) * ((tempPoint.getY() - 1) ^ 2) - (majorAxisLength ^ 2) * (minorAxisLength ^ 2));
	while (tempPoint.getY() >= 0) {
		ellipsePointPlot(tempPoint);
		tempPoint.decrementY();
		disValue -= 2 * (majorAxisLength ^ 2) * tempPoint.getY() - (majorAxisLength ^ 2);
		if (disValue < 0) {
			tempPoint.incrementX();
			disValue += 2 * (minorAxisLength ^ 2) * tempPoint.getX();
		}
	}
}
void shEllipse::paint() {
	shScreenPoint tempPoint(0, minorAxisLength);
	GLint disValue = (GLint)((minorAxisLength ^ 2) - (majorAxisLength ^ 2) * minorAxisLength + 0.25 * (majorAxisLength ^ 2));
	//GLint temp = 2 * (minorAxisLength ^ 2) * tempPoint.getX() <= 2 * (majorAxisLength ^ 2) * tempPoint.getY();
	while (2 * (minorAxisLength ^ 2) * tempPoint.getX() <= 2 * (majorAxisLength ^ 2) * tempPoint.getY()) {
		ellipsePointPlot(tempPoint, 1);
		tempPoint.incrementX();
		disValue += 2 * (minorAxisLength ^ 2) * tempPoint.getX() + (majorAxisLength ^ 2);
		if (disValue > 0) {
			tempPoint.decrementY();
			disValue -= 2 * (majorAxisLength ^ 2)* tempPoint.getY();
		}
	}
	disValue = (GLint)((minorAxisLength ^ 2) * ((tempPoint.getX() + 1 / 2) ^ 2) + (majorAxisLength ^ 2) * ((tempPoint.getY() - 1) ^ 2) - (majorAxisLength ^ 2) * (minorAxisLength ^ 2));
	while (tempPoint.getY() >= 0) {
		ellipsePointPlot(tempPoint, 1);
		tempPoint.decrementY();
		disValue -= 2 * (majorAxisLength ^ 2) * tempPoint.getY() - (majorAxisLength ^ 2);
		if (disValue < 0) {
			tempPoint.incrementX();
			disValue += 2 * (minorAxisLength ^ 2) * tempPoint.getX();
		}
	}
}

void shEllipse::rotateCentre(GLfloat _degree, shScreenPoint _centrePoint = shScreenPoint()) {
	centrePos.rotatePoint(_degree, _centrePoint);
}
void shEllipse::rotateCentre(GLfloat _degree, GLfloat _x, GLfloat _y, GLfloat _z) {
	centrePos.rotatePoint(_degree, (GLint)_x,(GLint)_y);
}
void shEllipse::scaleAxisLength(GLfloat _majorScale, GLfloat _minorScale) {
	majorAxisLength = GLint(majorAxisLength * _majorScale);
	minorAxisLength = GLint(minorAxisLength * _minorScale);
}