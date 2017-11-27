#pragma once
#ifndef _SH_SCREENPOINT_H
#define _SH_SCREENPOINT_H
#include <GL/glut.h>
#include "shColorf.h"
class shScreenPoint {
private:
	GLint point[2];
	shColorf pointColor;
public:
	shScreenPoint();
	shScreenPoint(GLint[]);
	shScreenPoint(GLint, GLint);
	shScreenPoint(GLint[], shColorf &);
	shScreenPoint(GLint, GLint, shColorf &);
	shScreenPoint(const shScreenPoint &);
	void setCoords(GLint, GLint);
	void setCoords(GLint []);
	void setCoords(shScreenPoint);
	shColorf getColor() const;
	void setX(GLint _x);
	void setY(GLint _y);
	GLint getX() const;
	GLint getY() const;
	GLint * getPosition();
	void incrementX(GLint = 1);
	void incrementY(GLint = 1);
	void decrementX(GLint = 1);
	void decrementY(GLint = 1);
	void transPosition(GLint, GLint);
	void transPosition(GLint[]);
	void transPosition(shScreenPoint);
	void disPosition();
	void drawPoint();
	void drawPoint(GLfloat, GLfloat, GLfloat);
	void drawPoint(GLfloat[]);
	void drawPoint(shColorf &);
	void rotatePoint(GLfloat, shScreenPoint);
	void rotatePoint(GLfloat, GLint, GLint);
};
#endif // !_SH_SCREENPOINT_H
