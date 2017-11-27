#pragma once

#ifndef _SH_CAMREA_H
#define _SH_CAMERA_H
#include  "shVertex.h"
using namespace std;

enum projectionType {
	prespective, orthogonal
};
class shCamera {
private:
	shVector uvnFrame[3];	 //The Direction Of UVN Viewing-coordinate reference frame
	shVertex uvnPos;
	projectionType projectionModel;
	void initViewCoord();
public:
	shCamera();
	shCamera(shVertex, shVector, shVector, projectionType);
	~shCamera();
	void setFrame(shVector, shVector);
	void setPos(GLfloat, GLfloat, GLfloat);
	void setPos(shVertex);
	shVector getU();
	shVector getV();
	shVector getN();
	shVertex getPos();
};

#endif // !1


