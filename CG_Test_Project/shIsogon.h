#pragma once
#ifndef _SH_ISOGON_H_
#define _SH_ISOGON_H_
#include "shPolyon.h"
#ifndef SH_PI
#define SH_PI 3.14159265358979323846
#endif // !SH_PI

class shIsogon :public shPolyon {
private:
	shScreenPoint centrePos;
	GLfloat sideLength;
	GLint vertexNum;
	std::vector<shScreenPoint> pointVector;
	std::vector<shEdge> edgeVector;
	GLint minY, maxY;
public:
	shIsogon();
	shIsogon(shScreenPoint, GLfloat, GLint);
	shIsogon(GLint[], GLfloat, GLint);
	void initVertex();
	void initEdgeVector();
	void setCentrePos(shScreenPoint);
	void setCentrePos(GLint[]);
	void setCentrePos(GLint, GLint);
	void setSideLength(GLfloat);
	void setVertexNum(GLint);
	shScreenPoint getCentrePos();
	GLfloat getSideLength();
	GLint getVertexNum();
	void drawWirefame();
	void paint();
	void customDraw();
	void rotateCentre(GLfloat, shScreenPoint);
	void rotateEntity(GLfloat, shScreenPoint);
	void scaleEntity(GLfloat);
};

#endif // !_SH_ISOGON_H_

