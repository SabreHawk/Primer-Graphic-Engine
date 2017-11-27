#include "stdafx.h"
#include "shIsogon.h"

shIsogon::shIsogon() {
}
shIsogon::shIsogon(shScreenPoint _p, GLfloat _l, GLint _n)
	:centrePos(_p), sideLength(_l), vertexNum(_n) {
	initVertex();
	initEdgeVector();
}
shIsogon::shIsogon(GLint _point[], GLfloat _l, GLint _n)
	:sideLength(_l), vertexNum(_n) {
	centrePos.setCoords(_point);
	initVertex();
	initEdgeVector();
}
void shIsogon::initVertex() {
	//cout << " init Vertex " << endl;
	GLfloat rDegree = GLfloat(SH_PI / vertexNum);
	GLfloat tanTheta = tan(rDegree);
	GLfloat altLength = (GLfloat)((sideLength / 2) / tanTheta);
	shScreenPoint tempPoint(GLint(centrePos.getX() + (sideLength / 2)), GLint(centrePos.getY() - altLength));
	pointVector.push_back(tempPoint);
	minY = tempPoint.getY();
	maxY = tempPoint.getY();
	for (GLint vNum = 0; vNum < vertexNum - 1; ++vNum) {
		tempPoint.rotatePoint(2 * rDegree, centrePos);
		if (tempPoint.getY() > maxY) {
			maxY = tempPoint.getY();
		}
		if (tempPoint.getY() < minY) {
			minY = tempPoint.getY();
		}
		pointVector.push_back(tempPoint);
	}
}
void shIsogon::initEdgeVector() {
	shEdge tempEdge;
	std::vector<shEdge>::iterator edgeItor;
	shScreenPoint sPoint;
	for (int i = 0; i < vertexNum; ++i) {
		if (pointVector[i].getY() == pointVector[(i + 1) % vertexNum].getY()) {
			continue;
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
		if (edgeItor->getTopY() == (edgeItor + 1)->getTopY()) {
			edgeItor->decrementTopY();
		}
	}
	sort(edgeVector.begin(), edgeVector.end(), sortEdgeByBottomY);
	//cout << edgeVector.size() << " size " << endl;
}
void shIsogon::setCentrePos(shScreenPoint _p) {
	centrePos.setCoords(_p);
	initVertex();
	initEdgeVector();
}
void shIsogon::setCentrePos(GLint _p[]) {
	centrePos.setCoords(_p);
	initVertex();
	initEdgeVector();
}
void shIsogon::setCentrePos(GLint _x, GLint _y) {
	centrePos.setCoords(_x, _y);
	initVertex();
	initEdgeVector();
}
void shIsogon::setSideLength(GLfloat _l) {
	sideLength = _l;
	initVertex();
	initEdgeVector();
}
void shIsogon::setVertexNum(GLint _n) {
	vertexNum = _n;
	initVertex();
	initEdgeVector();
}
shScreenPoint shIsogon::getCentrePos() {
	return centrePos;
}
GLfloat shIsogon::getSideLength() {
	return sideLength;
}
GLint shIsogon::getVertexNum() {
	return vertexNum;
}

void shIsogon::drawWirefame() {
	shLine tempLine;
	for (GLint vNum = 0; vNum < vertexNum - 1; ++vNum) {
		tempLine.setPosition(pointVector[vNum], pointVector[vNum + 1]);
		tempLine.drawLine();
	}
	tempLine.setPosition(pointVector[0], pointVector[vertexNum - 1]);
	tempLine.drawLine();
}
void shIsogon::paint() {
	std::vector<shEdge> activeEdgeVector; // AET
	std::vector<GLint> bottomYVector;
	std::vector<shEdge>::iterator edgeItor;
	GLint bottomScanY = minY;
	GLint topScanY = maxY;
	//	cout << minY << " - " << maxY << endl;
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
		scope tempScope;
		shLine tempLine;
		sort(activeEdgeVector.begin(), activeEdgeVector.end(), sortEdgeByBottomX);
		for (edgeItor = activeEdgeVector.begin(); edgeItor != activeEdgeVector.end();) {
			edgeItor->incrementBottomX(edgeItor->getRecK());
			//	cout << " K " << endl;
			if (tempScope.isEmpty) {
				tempScope.left = (GLint)edgeItor->getBottomX();
				tempScope.isEmpty = false;
			} else {
				tempScope.right = (GLint)edgeItor->getBottomX();
				tempScope.isEmpty = true;
				//	cout << tempScope.left << " --- " << tempScope.right << endl;
				tempLine.setPosition(GLint(tempScope.left), scanY, GLint(tempScope.right), scanY);
				tempLine.drawLine();
			}
			++edgeItor;
		}
	}
}

void shIsogon::customDraw() {
	int indexArr[1][2] = { { 1,2 } };
	for (int i = 0; i < 5; ++i) {
		GLint index1 = indexArr[i][0];
		GLint index2 = indexArr[i][1];
		GLint offset = 1000;
		shScreenPoint p1 = pointVector[index1];
		shScreenPoint p2 = pointVector[index2];
		shLine tempLine(p1, p2);
		GLfloat k = tempLine.getSlope();
		p1.incrementX(offset);
		p1.incrementY(GLint(offset*k));
		p2.decrementX(offset);
		p2.decrementY(GLint(offset*k));
		tempLine.setPosition(p1, p2);
		tempLine.drawLine();
		shScreenPoint midPoint((p1.getX() + p2.getX()) / 2, (p1.getY() + p2.getY()) / 2);
		shLine line1(midPoint, centrePos);
		line1.drawLine();

	}
}

void shIsogon::rotateCentre(GLfloat _degree, shScreenPoint _fPoint = shScreenPoint()) {
	shScreenPoint tempPoint = *pointVector.begin();
	pointVector.begin()->rotatePoint(_degree, _fPoint);
	GLint xOffset = pointVector.begin()->getX() - tempPoint.getX();
	GLint yOffset = pointVector.begin()->getY() - tempPoint.getY();
	std::vector<shScreenPoint>::iterator itor;
	for (itor = pointVector.begin() + 1; itor != pointVector.end(); ++itor) {
		itor->transPosition(xOffset, yOffset);
	}
}
void shIsogon::rotateEntity(GLfloat _degree, shScreenPoint _fPoint = shScreenPoint()) {
	std::vector<shScreenPoint>::iterator itor;
	for (itor = pointVector.begin(); itor != pointVector.end(); ++itor) {
		itor->rotatePoint(_degree, _fPoint);
	}
}

void shIsogon::scaleEntity(GLfloat _scale) {
	shScreenPoint _fixedPoint = centrePos;
	std::vector<shScreenPoint>::iterator itor;
	for (itor = pointVector.begin(); itor != pointVector.end(); ++itor) {
		GLfloat tempX = _scale * itor->getX() + (1 - _scale) * itor->getX();
		GLfloat tempY = _scale * itor->getY() + (1 - _scale) * itor->getY();
		itor->setCoords(GLint(tempX), GLint(tempY));
	}
	initEdgeVector();
}