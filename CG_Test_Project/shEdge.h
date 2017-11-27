#pragma once
#ifndef _SH_EDGE_H_
#define _SH_EDGE_H_
#include "shLine.h"

class shEdge {
private:
	GLint topY;
	GLfloat bottomX;
	GLint bottomY;
	GLfloat recK;
	shEdge * nextPtr;
public:
	shEdge();
	shEdge(GLint, GLfloat, GLint, GLfloat);
	shEdge(shLine &);
	shEdge(shScreenPoint &, shScreenPoint &);
	void setEdge(shScreenPoint, shScreenPoint);
	GLfloat getBottomX() const;
	GLint getBottomY() const;
	GLint getTopY() const;
	GLfloat getRecK() const;
	void decrementTopY();
	void incrementBottomX(GLfloat);
};

#endif // !_SH_shEdge_H_
