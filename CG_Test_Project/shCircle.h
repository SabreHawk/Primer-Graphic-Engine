#pragma once
#ifndef _SH_CIRCLE_H_
#define _SH_CIRCLE_H_
#include "shScreenPoint.h"
#include "shLine.h"
class shCircle {
private:
	shScreenPoint centrePos;
	GLfloat radius;
	shColorf circleColor;
	void circlePointMapping(shScreenPoint &, GLint);
public:
	shCircle();
	shCircle(shScreenPoint, GLfloat);
	shCircle(shScreenPoint, GLfloat, shColorf);
	shCircle(shCircle &);
	shScreenPoint getCentre();
	GLfloat getRadius();
	shColorf getColor();
	void drawWireframe();
	void paint();

	void rotateCentre(GLfloat, shScreenPoint);
	void rotateCentre(GLfloat, GLfloat, GLfloat, GLfloat);
	void scaleRadius(GLfloat);
};

#endif // !_SH_CIRCLE_H_

