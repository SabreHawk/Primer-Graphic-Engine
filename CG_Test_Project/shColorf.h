#pragma once
#ifndef _SH_COLOR_H
#define _SH_COLOR_H
#include <GL/glut.h>

class shColorf {
private:
	GLfloat Colorf[4];
	const static GLint channelNum ;
public:
	shColorf();
	shColorf(GLfloat, GLfloat, GLfloat, GLfloat);
	shColorf(const shColorf &);
	shColorf(const GLfloat []);
	void setColor(GLfloat,GLfloat,GLfloat,GLfloat);
	void setColor(GLfloat []);
	void setColor(shColorf &);
	const GLfloat * getColor() const;
	GLfloat getR() const;
	GLfloat getG() const;
	GLfloat getB() const;
	GLfloat getA() const;
	bool isLegal();
};

#endif // !_SH_COLOR_H
