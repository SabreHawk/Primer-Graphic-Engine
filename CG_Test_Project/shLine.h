#pragma once
#ifndef _SH_LINE_H_
#define _SH_LINE_H_
#include "shScreenPoint.h"

class shLine {
private:
	shScreenPoint beginPoint;
	shScreenPoint endPoint;
	shColorf lineColor;

	void rePositionPoint();
	void drawVetcialLine();
public:
	shLine();
	shLine(shScreenPoint, shScreenPoint);
	shLine(GLint, GLint, GLint, GLint);
	shLine(shScreenPoint, shScreenPoint, shColorf &);
	shLine(GLint, GLint, GLint, GLint, shColorf &);
	//Important Function 	 - setColor Uncomplete
	shScreenPoint getPoint(GLint);
	void getPoints(GLint[4]);
	GLfloat getSlope();
	void setPosition(shScreenPoint, shScreenPoint);
	void setPosition(GLint, GLint, GLint, GLint);
	void setColor(shColorf &);
	void setColor(GLfloat[]);
	void drawLineDDA();
	void drawLineBresensham();
	void drawLine();
	void disPosition();
	void transPosition(GLint, GLint);
};

#endif // !_SH_LINE_H_
