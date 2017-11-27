#include "stdafx.h"
#include "shScene.h"



shVertex shScene::vertexTrans(shVertex * _v) {
	GLfloat tempA = _v->dotProduct(viewCamera.getU());
	GLfloat tempB = _v->dotProduct(viewCamera.getV());
	GLfloat tempC = _v->dotProduct(viewCamera.getN());
	GLfloat tempMatrix[16] = { viewCamera.getU().getX(),viewCamera.getU().getY() ,viewCamera.getU().getZ(),tempA,
							   viewCamera.getV().getX(),viewCamera.getV().getY(),viewCamera.getV().getZ(),tempB,
						       viewCamera.getN().getX(),viewCamera.getN().getY(),viewCamera.getN().getZ(),tempC,
							   0,0,0,1 };
	shMatrix* rotateMatrix = new shMatrix(4, 4, tempMatrix);
	shMatrix* tempVector = new shMatrix(4, 1, 1);
	for (int i = 0; i < 3; ++i) {
		tempVector->setValue(i, 0, _v->getValue(i));
	}
	shMatrix * result = new shMatrix(4, 4);
	*result = rotateMatrix->postMulti(*tempVector);
	shVertex resultVertex = *_v;
	for (int i = 0; i < 3; ++i) {
		resultVertex.setValue(i, result->getValue(i, 0));
	}
	delete tempVector;
	delete rotateMatrix;
	return resultVertex;
}
shScene::shScene() {
}
shScene::~shScene() {
}

void shScene::setViewCamera(shVertex _pos, shVector _n, shVector _v, projectionType) {
	viewCamera.setPos(_pos);
	viewCamera.setFrame(_n, _v);
}
void shScene::setViewCamera(shCamera* _c) {
	viewCamera.setPos(_c->getPos());
	viewCamera.setFrame(_c->getN(), _c->getV());
}

void shScene::addObject(shObject* _o) {
	renderPipeline.push_back(*_o);
}
void shScene::projection() {
	vector<shVertex> temp_vector;
	vector<shObject>::iterator itor;
	for (itor = renderPipeline.begin(); itor != renderPipeline.end(); ++itor) {
		
	}
}
