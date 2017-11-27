#include "stdafx.h"
#include "shPolyon.h"

 bool sortEdgeByBottomY(shEdge _e1, shEdge _e2) {
	return _e1.getBottomY() < _e2.getBottomY();
}
 bool sortEdgeByBottomX(shEdge _e1, shEdge _e2) {
	return _e1.getBottomX() < _e2.getBottomX();
}
void shPolyon::initEdgeVector() {
	shEdge tempEdge;
	std::vector<shEdge>::iterator edgeItor;
	shScreenPoint sPoint;
	GLint vertexNum = pointVector.size();
	minY = pointVector.begin()->getY();
	maxY = pointVector.begin()->getY();
	for (int i = 0; i < vertexNum; ++i) {
		if (pointVector[i].getY() == pointVector[(i + 1) % vertexNum].getY()) {
			continue;
		}
		if (pointVector[(i + 1) % vertexNum].getY() < minY) {
			minY = pointVector[(i + 1) % vertexNum].getY();
		} else if (pointVector[(i + 1) % vertexNum].getY() > maxY) {
			maxY = pointVector[(i + 1) % vertexNum].getY();
		}
		tempEdge.setEdge(pointVector[i], pointVector[(i + 1) % vertexNum]);
		//		cout << tempEdge.bottomX << " - " << tempEdge.topY << " -" << tempEdge.recK << endl;
		edgeVector.push_back(tempEdge);
	}
	for (edgeItor = edgeVector.begin(); edgeItor < edgeVector.end() - 1; ++edgeItor) {
		if (edgeItor->getTopY() == (edgeItor + 1)->getBottomY()) {
			edgeItor->decrementTopY();
			//		cout << "g" << endl;
		}
		if (edgeItor->getBottomY() == (edgeItor + 1)->getTopY()) {
			(edgeItor + 1)->decrementTopY();
		}
	}
	std::sort(edgeVector.begin(),edgeVector.end(), sortEdgeByBottomY);
	//cout << edgeVector.size() << " size " << endl;
}

shPolyon::shPolyon() {
}
shPolyon::shPolyon(shPolyon &_polyon) {
	int pointNum = _polyon.getPointNum();
	for (int pIndex = 0; pIndex < pointNum; ++pIndex) {
		pointVector.push_back(_polyon.getPoint(pIndex));
	}
}
void shPolyon::addPoint(shScreenPoint  _point) {
	pointVector.push_back(_point);
}
void shPolyon::addPoint(GLint _x, GLint _y) {
	shScreenPoint * nPoint = new  shScreenPoint(_x, _y);
	pointVector.push_back(*nPoint);
}
void shPolyon::erase(GLint _index) {
	pointVector.erase(pointVector.begin() + _index);
}
void shPolyon::erase(GLint _beginIndex, GLint _endIndex) {
	std::vector<shScreenPoint>::iterator beginItor = pointVector.begin() + _beginIndex;
	std::vector<shScreenPoint>::iterator endItor = pointVector.begin() + _endIndex + 1;
	pointVector.erase(beginItor, endItor);
}
void shPolyon::pop_back() {
	pointVector.pop_back();
}
bool shPolyon::empty() {
	return pointVector.empty();
}
shScreenPoint shPolyon::getPoint(GLint _index = 0) {
	return pointVector[_index];
}
GLint shPolyon::getPointNum() const {
	return pointVector.size();
}

void shPolyon::drawPolyLine() {
	int pointNum = pointVector.size();
	shLine tempLine;
	for (int pIndex = 0; pIndex < pointNum; ++pIndex) {
		tempLine.setPosition(pointVector[pIndex], pointVector[(pIndex + 1) % pointNum]);
		tempLine.drawLine();
	}
}
void shPolyon::paint() {
	initEdgeVector();
	std::vector<shEdge> activeEdgeVector; // AET
	std::vector<GLint> bottomYVector;
	std::vector<shEdge>::iterator edgeItor;
	GLint bottomScanY = minY;
	GLint topScanY = maxY;
	std::cout << minY << " - " << maxY << std::endl;
	for (int scanY = bottomScanY; scanY <= topScanY; ++scanY) {
		//Append New Active Edge
		//cout << scanY << endl;
		for (edgeItor = edgeVector.begin(); edgeItor != edgeVector.end();) {
			if (scanY == edgeItor->getBottomY()) {
				activeEdgeVector.push_back(*edgeItor);
				edgeItor = edgeVector.erase(edgeItor);
			} else {
				++edgeItor;
			}
		}
		for (edgeItor = activeEdgeVector.begin(); edgeItor != activeEdgeVector.end();) {
			if (scanY == edgeItor->getTopY()) {
				edgeItor = activeEdgeVector.erase(edgeItor);
			} else {
				++edgeItor;
			}
		}
		//Erase Edge
		std::vector<scope> tempScopeVector;
		scope tempScope;
		GLint scopeNum = 0;
		shLine tempLine;
		std::sort(activeEdgeVector.begin(), activeEdgeVector.end(), sortEdgeByBottomX);
		for (edgeItor = activeEdgeVector.begin(); edgeItor != activeEdgeVector.end();) {
			edgeItor->incrementBottomX(edgeItor->getRecK());
			if (tempScope.isEmpty) {
				tempScope.left = GLint(edgeItor->getBottomX());
				tempScope.isEmpty = false;
			} else {
				tempScope.right = GLint(edgeItor->getBottomX());
				tempScope.isEmpty = true;
				//	cout << tempScope.left << " --- " << tempScope.right << endl;
				tempLine.setPosition(GLint(tempScope.left), scanY, GLint(tempScope.right), scanY);
				tempLine.drawLine();
			}
			++edgeItor;
		}
	}
}

void shPolyon::rotateCentre(GLfloat _degree, shScreenPoint _fPoint = shScreenPoint()) {
	shScreenPoint tempPoint = *pointVector.begin();
	pointVector.begin()->rotatePoint(_degree, _fPoint);
	GLint xOffset = pointVector.begin()->getX() - tempPoint.getX();
	GLint yOffset = pointVector.begin()->getY() - tempPoint.getY();
	std::vector<shScreenPoint>::iterator itor;
	for (itor = pointVector.begin() + 1; itor != pointVector.end(); ++itor) {
		itor->transPosition(xOffset, yOffset);
	}
}
void shPolyon::rotateEntity(GLfloat _degree, shScreenPoint _fPoint = shScreenPoint()) {
	std::vector<shScreenPoint>::iterator itor;
	for (itor = pointVector.begin(); itor != pointVector.end(); ++itor) {
		itor->rotatePoint(_degree, _fPoint);
	}
}

void shPolyon::scaleEntity(shScreenPoint _fixedPoint, GLfloat _xScale, GLfloat _yScale = 0) {
	if (_yScale == 0) {
		_yScale = _xScale;
	}
	std::vector<shScreenPoint>::iterator itor;
	for (itor = pointVector.begin(); itor != pointVector.end(); ++itor) {
		GLfloat tempX = _xScale * itor->getX() + (1 - _xScale) * itor->getX();
		GLfloat tempY = _yScale * itor->getY() + (1 - _yScale) * itor->getY();
		itor->setCoords((GLint)tempX, (GLint)tempY);
	}
}

