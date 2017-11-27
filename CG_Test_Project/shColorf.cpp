#include "stdafx.h"
#include "shColorf.h"
const GLint shColorf::channelNum = 4;
shColorf::shColorf() {
	memset(Colorf, 0, 4);
}
shColorf::shColorf(GLfloat _r, GLfloat _g, GLfloat _b, GLfloat _a) {
	Colorf[0] = _r;
	Colorf[1] = _g;
	Colorf[2] = _b;
	Colorf[3] = _a;
}
shColorf::shColorf(const shColorf &_color) {
	memcpy(Colorf, _color.getColor(), sizeof(_color));
}
shColorf::shColorf(const GLfloat colorArr[]) {
	memcpy(Colorf, colorArr, sizeof(colorArr));
	if (sizeof(colorArr) == 3) {
		Colorf[3] = 1;
	} else if (sizeof(colorArr) != 4) {
		shColorf();
	}
}
void shColorf::setColor(GLfloat _r, GLfloat _g, GLfloat _b, GLfloat _a) {
	Colorf[0] = _r;
	Colorf[1] = _g;
	Colorf[2] = _b;
	Colorf[3] = _a;
}
void shColorf::setColor(GLfloat _color[]) {
	memcpy(Colorf, _color, sizeof(_color));
}
void shColorf::setColor(shColorf & _color) {
	memcpy(Colorf, _color.getColor(), sizeof(_color));
}
const GLfloat * shColorf::getColor() const {
	return Colorf;
}
GLfloat shColorf::getR() const {
	return Colorf[0];
}
GLfloat shColorf::getG() const {
	return Colorf[1];
}
GLfloat shColorf::getB() const {
	return Colorf[2];
}
GLfloat shColorf::getA() const {
	return Colorf[3];
}
bool shColorf::isLegal() {
	for (int colorIndex = 0; colorIndex < channelNum; ++colorIndex) {
		if (Colorf[colorIndex] < 0 || Colorf[colorIndex] > 1) {
			return false;
		}
	}
	return true;
}