#include "stdafx.h"
#include "shObject.h"

shObject::shObject() {

}
shObject::~shObject() {

}
void shObject::initObject() {
	initVertex();
	initLine();
}

void shObject::disCentrePos() {
	cout << "Object Centre Position :\n";
	centrePos.disPosition();
}
void shObject::disVertexs() {
	vector<shVertex>::iterator itor;
	cout << "Object Vertexs Position :\n";
	for (itor = vertexVector.begin(); itor != vertexVector.end(); ++itor) {
		itor->disPosition();
	}
}