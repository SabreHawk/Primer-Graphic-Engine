#pragma once
#ifndef _SH_VERTEX_H_
#define _SH_VERTEX_H_
#define shVertex shVector
#include "shColorf.h"
#include "shScreenPoint.h"
class shVertex {
private:
	GLfloat vertex[3];
	shColorf vertexColor;
public:
	shVertex();
	shVertex(GLfloat[]);
	shVertex(GLfloat, GLfloat, GLfloat);
	shVertex(GLfloat[], shColorf &);
	shVertex(GLfloat, GLfloat, GLfloat, shColorf &_);
	shVertex(const shVertex &);
	void setPosition(GLfloat, GLfloat, GLfloat);
	void setPosition(GLfloat[]);
	void setPosition(shVertex);
	shColorf getColor() const;
	void setValue(GLint, GLfloat);
	void setX(GLfloat);
	void setY(GLfloat);
	void setZ(GLfloat);
	GLfloat getValue(GLint);
	GLfloat getX() const;
	GLfloat getY() const;
	GLfloat getZ() const;
	GLfloat * getPosition();
	void incrementX(GLfloat = 1);
	void incrementY(GLfloat = 1);
	void incrementZ(GLfloat = 1);
	void decrementX(GLfloat = 1);
	void decrementY(GLfloat = 1);
	void decrementZ(GLfloat = 1);
	void traxnsPosition(GLfloat, GLfloat, GLfloat);
	void transPosition(GLfloat[]);
	void transPosition(shVertex);
	void disPosition();
	void drawPoint();
	void drawPoint(GLfloat, GLfloat, GLfloat);
	void drawPoint(GLfloat[]);
	void drawPoint(shColorf &);
	shVertex crossProduct(shVertex &);
	GLfloat dotProduct(shVertex &);
	GLfloat getScalar();
	shVertex getNormalized();
	shVertex getProjection(char);;
	GLfloat getCosine(shVertex & );
	GLfloat getSine(shVertex & );
	void rotate(GLdouble, shVector);
	void rotate(GLdouble, shScreenPoint);
	void rotate(GLdouble, GLfloat, GLfloat);
	shScreenPoint trans2ScreenPoint();
};
#endif // ! _SH_VERTEX_H