#pragma once
#ifndef _SH_SCENE_H_
#define _SH_SCENE_H_
#include "shCamera.h"
#include "shPolyon.h"
#include "shObject.h"
class shScene {
private:
	shCamera viewCamera;
	vector<shObject> renderPipeline;
	void testVertexInit();
	shVertex vertexTrans(shVertex *);
public:
	shScene();
	~shScene();
	void setViewCamera(shVertex,shVector,shVector, projectionType);
	void setViewCamera(shCamera*);
	void addObject(shObject*);
	void projection();
};
#endif // !_SH_SCENE_H_



