#pragma once
#ifndef _SH_CUBE_H_
#define _SH_CUBE_H_
#include "shObject.h"
class shCube:public shObject
{
private:
	GLfloat dimensionArr[3];
	virtual void initVertex();
	virtual void initLine();
public:
	shCube();
	shCube(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	shCube(shVertex, GLfloat, GLfloat, GLfloat);
	~shCube();
};
#endif
