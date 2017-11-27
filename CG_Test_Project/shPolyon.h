#pragma once
#ifndef _SH_POLYON_H_
#define _SH_POLYON_H_
#include "stdafx.h"
#include "shScreenPoint.h"
#include "shEdge.h"

class shPolyon {

private:
	std::vector<shScreenPoint> pointVector;
	std::vector<shEdge> edgeVector;
	GLint minY, maxY;
	void initEdgeVector();
protected:
	struct scope {
		GLint left;
		GLint right;
		GLboolean isEmpty;
		scope()
			:left(0), right(0), isEmpty(true) {
		}
		scope(GLint _l, GLint _r)
			:left(_l), right(_r), isEmpty(true) {
		}
	};
	friend bool sortEdgeByBottomX(shEdge, shEdge);
	friend bool sortEdgeByBottomY(shEdge, shEdge);
public:
	shPolyon();
	shPolyon(shPolyon &);
	void addPoint(shScreenPoint  );
	void addPoint(GLint , GLint );
	void erase(GLint );
	void erase(GLint , GLint );
	void pop_back();
	bool empty();
	shScreenPoint getPoint(GLint );
	GLint getPointNum() const;

	void drawPolyLine();
	void paint();

	void rotateCentre(GLfloat , shScreenPoint );
	void rotateEntity(GLfloat , shScreenPoint );
	void scaleEntity(shScreenPoint , GLfloat , GLfloat );

};

#endif // !_SH_POLYON_H_

