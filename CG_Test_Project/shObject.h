#pragma once
#ifndef _SH_OBJECT_H_
#define _SH_OBJECT_H_
#include "shVertex.h"

struct vertexPair {
	GLint v01;
	GLint v02;
	vertexPair(GLint _v01, GLint _v02) {
		v01 = _v01;
		v02 = _v02;
	}
	void setPair(GLint _v01, GLint _v02) {
		v01 = _v01;
		v02 = _v02;
	}
};
class shObject
{
protected:
	shVertex centrePos;
	vector<shVertex> vertexVector;
	vector<vertexPair> lineIndexVector;

	virtual void initObject();
	virtual void initVertex() = 0;
	virtual void initLine() = 0;
public:
	shObject();
	~shObject();
	shVertex getCentrePos();
	void setCentrePos(GLfloat, GLfloat, GLfloat);
	void disCentrePos();
	void disVertexs();
};


#endif // !_SH_OBJECT_H_

