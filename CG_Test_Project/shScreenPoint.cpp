#include "stdafx.h"
#include "shScreenPoint.h"

shScreenPoint::shScreenPoint():pointColor() {
	memset(point, 0, 2);
}

shScreenPoint::shScreenPoint(GLint _point[])
	: pointColor() {
	memcpy(point, _point, sizeof(_point));
}
shScreenPoint::shScreenPoint(GLint _x, GLint _y)
	: pointColor() {
	point[0] = _x;
	point[1] = _y;
}
shScreenPoint::shScreenPoint(GLint _point[], shColorf & _color )
	:pointColor(_color) {
	memcpy(point, _point, sizeof(_point));
}
shScreenPoint::shScreenPoint(GLint _x, GLint _y, shColorf & _color)
	:pointColor(_color) {
	point[0] = _x;
	point[1] = _y;
}
shScreenPoint::shScreenPoint(const shScreenPoint &_point) {
	point[0] = _point.getX();
	point[1] = _point.getY();
	pointColor.setColor(_point.getColor());
}
void shScreenPoint::setCoords(GLint xCoord, GLint yCoord) {
	point[0] = xCoord;
	point[1] = yCoord;
}
void shScreenPoint::setCoords(GLint _point[]) {
	memcpy(point, _point, sizeof(_point));
}
void shScreenPoint::setCoords(shScreenPoint _point) {
	point[0] = _point.getX();
	point[1] = _point.getY();
}
shColorf shScreenPoint::getColor() const {
	return pointColor;
}
void shScreenPoint::setX(GLint _x) {
	point[0] = _x;
}
void shScreenPoint::setY(GLint _y) {
	point[1] = _y;
}
GLint shScreenPoint::getX() const {
	return point[0];
}
GLint shScreenPoint::getY() const {
	return point[1];;
}
GLint * shScreenPoint::getPosition() {
	return point;
}
void shScreenPoint::incrementX(GLint _offset ) {
	point[0] += _offset;
}
void shScreenPoint::incrementY(GLint _offset ) {
	point[1] += _offset;
}
void shScreenPoint::decrementX(GLint _offset ) {
	point[0] -= _offset;
}
void shScreenPoint::decrementY(GLint _offset ) {
	point[1] -= _offset;
}
void shScreenPoint::transPosition(GLint _xDir, GLint _yDir) {
	point[0] += _xDir;
	point[1] += _yDir;
}
void shScreenPoint::transPosition(GLint _dir[]) {
	point[0] += _dir[0];
	point[1] += _dir[1];
}
void shScreenPoint::transPosition(shScreenPoint _point) {
	point[0] += _point.getX();
	point[1] += _point.getY();
}
void shScreenPoint::disPosition() {
	std::cout << "Screen Point : ( " << point[0] << " , " << point[1] << " )" << std::endl;
}
void shScreenPoint::drawPoint() {
	glColor3fv(pointColor.getColor());
	glBegin(GL_POINTS);
	glVertex2i(point[0], point[1]);
	glEnd();
	glFlush();
}
void shScreenPoint::drawPoint(GLfloat _r, GLfloat _g, GLfloat _b) {
	glColor3f(_r, _g, _b);
	glBegin(GL_POINTS);
	glVertex2i(point[0], point[1]);
	glEnd();
	glFlush();
}
void shScreenPoint::drawPoint(GLfloat _color[]) {
	glColor3fv(_color);
	glBegin(GL_POINTS);
	glVertex2i(point[0], point[1]);
	glEnd();
	glFlush();
}
void shScreenPoint::drawPoint(shColorf & _color) {
	glColor3fv(_color.getColor());
	glBegin(GL_POINTS);
	glVertex2i(point[0], point[1]);
	glEnd();
	glFlush();
}
void shScreenPoint::rotatePoint(GLfloat _d, shScreenPoint _p = shScreenPoint()) {
	GLdouble cosTheta = cos(_d);
	GLdouble sinTheta = sin(_d);
	if (abs(cosTheta) < 0.0001) {
		cosTheta = 0;
	}
	GLint tempX = point[0];
	GLint tempY = point[1];
	point[0] = GLint(_p.getX() + (tempX - _p.getX()) * cosTheta - (tempY - _p.getY()) * sinTheta);
	point[1] = GLint(_p.getY() + (tempX - _p.getX()) * sinTheta + (tempY - _p.getY()) * cosTheta);
}
void shScreenPoint::rotatePoint(GLfloat _d, GLint _x, GLint _y) {
	GLdouble cosTheta = cos(_d);
	if (abs(cosTheta) < 0.0001) {
		cosTheta = 0;
	}
	GLdouble sinTheta = sin(_d);
	GLint tempX = point[0];
	GLint tempY = point[1];
	point[0] = (GLint)(_x + (tempX - _x) * cosTheta - (tempY - _y) * sinTheta);
	point[1] = (GLint)(_y + (tempX - _x) * sinTheta + (tempY - _y) * cosTheta);
}
