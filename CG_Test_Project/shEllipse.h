#pragma once
#ifndef _SH_ELLIPSE_H_
#define _SH_ELLIPSE_H_
#include "shScreenPoint.h"
#include "shLine.h"

class shEllipse {
private:
	shScreenPoint centrePos;
	GLint majorAxisLength;
	GLint minorAxisLength;
	shColorf ellipseColor;

	void ellipsePointPlot(shScreenPoint &, GLint);
public:
	shEllipse();
	shEllipse(GLint, GLint, GLint, GLint);
	shEllipse(shScreenPoint, GLint, GLint);
	shEllipse(GLint, GLint, GLint, GLint, shColorf &);
	shEllipse(shScreenPoint, GLint, GLint, shColorf &);
	shEllipse(shEllipse &);

	shScreenPoint getCentre();
	GLint getMajorAxisLength();
	GLint getMinorAxisLength();
	shColorf getColor();

	void drawWireframe();
	void paint();

	void rotateCentre(GLfloat, shScreenPoint);
	void rotateCentre(GLfloat, GLfloat, GLfloat, GLfloat);
	void scaleAxisLength(GLfloat, GLfloat);
};


#endif // !_SH_ELLIPSE_H_
