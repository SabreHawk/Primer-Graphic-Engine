#include "stdafx.h"
#include "shLine.h"


void shLine::rePositionPoint() {
	shScreenPoint tempPoint = beginPoint;
	if (tempPoint.getX() > endPoint.getX()) {
		beginPoint = endPoint;
		endPoint = tempPoint;
	}
}
void shLine::drawVetcialLine() {
	if (beginPoint.getX() != endPoint.getX()) {
		std::cout << "Line Is Not Vertical " << std::endl;
		disPosition();
		return;
	}
	GLint beginY = beginPoint.getY();
	GLint endY = endPoint.getY();
	GLint yOffset = abs(endY - beginY);
	if (endY < beginY) {
		beginY = endPoint.getY();
	}

	shScreenPoint tempPoint(beginPoint.getX(), beginY);
	for (GLint step = 0; step < yOffset; ++step) {
		tempPoint.drawPoint();
		tempPoint.incrementY();
	}
}

shLine::shLine() :lineColor() {
}
shLine::shLine(shScreenPoint _p1, shScreenPoint _p2)
	: beginPoint(_p1), endPoint(_p2), lineColor() {
	rePositionPoint();
}
shLine::shLine(GLint _x1, GLint _y1, GLint _x2, GLint _y2)
	: beginPoint(_x1, _y1), endPoint(_x2, _y2) {
	rePositionPoint();
}
shLine::shLine(shScreenPoint _point1, shScreenPoint _point2, shColorf & _color)
	: beginPoint(_point1), endPoint(_point2), lineColor(_color) {
	rePositionPoint();
}
shLine::shLine(GLint _x1, GLint _y1, GLint _x2, GLint _y2, shColorf & _color)
	: beginPoint(_x1, _y1), endPoint(_x2, _y2), lineColor(_color) {
	rePositionPoint();
}
//Important Function 	 - setColor Uncomplete
shScreenPoint shLine::getPoint(GLint _index) {
	if (!_index) {
		return beginPoint;
	} else if (_index) {
		return endPoint;
	} else {
		return NULL;
	}
}
void shLine::getPoints(GLint pArr[4]) {
	pArr[0] = beginPoint.getX();
	pArr[1] = beginPoint.getY();
	pArr[0] = beginPoint.getX();
	pArr[1] = beginPoint.getY();
}
GLfloat shLine::getSlope() {
	GLfloat k = (GLfloat)(beginPoint.getY() - endPoint.getY()) / (beginPoint.getX() - endPoint.getX());
	return k;
}
void shLine::setPosition(shScreenPoint _p1, shScreenPoint _p2) {
	beginPoint = _p1;
	endPoint = _p2;
	rePositionPoint();
}
void shLine::setPosition(GLint _x1, GLint _y1, GLint _x2, GLint _y2) {
	beginPoint.setCoords(_x1, _y1);
	endPoint.setCoords(_x2, _y2);
	rePositionPoint();
}
void shLine::setColor(shColorf & _color) {
	lineColor = _color;
}
void shLine::setColor(GLfloat _color[]) {
	lineColor.setColor(_color);
}
void shLine::drawLineDDA() {
	GLint startX = beginPoint.getX();
	GLint startY = beginPoint.getY();
	GLint endX = endPoint.getX();
	GLint endY = endPoint.getY();
	if (startX == endX) {
		if (startY == endY) {
			return;
		}
		//Case 1: The Gradient Of The Line Is 0 - The line is vertical  
		drawVetcialLine();
		return;
	} else {
		//Calculate Gradient Of The Line		
		GLfloat k = (GLfloat)(startY - endY) / (startX - endX);
		GLfloat curX = (float)startY; GLfloat curY = (float)startY;
		shScreenPoint tempPoint(startX, startY);
		//Case 2: The Absolute Value Of Gradient Of The Line Is Between 0 And 1
		if (0 <= abs(k) && abs(k) < 1) {
			for (GLint curX = startX; curX <= endX; ++curX) {
				tempPoint.setCoords(curX, (GLint)round(curY));
				tempPoint.drawPoint();
				curY += k;

			}
		} else if (abs(k) >= 1) {
			//Case 3: The Absolute Value Of Gradient Of The Line Is Greater Than 1
			GLfloat recK = (GLfloat)(startX - endX) / (startY - endY);
			for (GLint curY = startY; curY <= endY; ++curY) {
				tempPoint.setCoords((GLint)round(curX), curY);
				tempPoint.drawPoint();
				curX += recK;
			}
		}
	}
}
void shLine::drawLineBresensham() {
	//
	int xOffset = abs(beginPoint.getX() - endPoint.getX());
	int yOffset = abs(beginPoint.getY() - endPoint.getY());
	if (!xOffset) {
		if (!yOffset) {
			return;
		}
		drawVetcialLine();
		return;
	}

	GLfloat k = (GLfloat)(beginPoint.getY() - endPoint.getY()) / (beginPoint.getX() - endPoint.getX());

	//
	int conValue = -xOffset;
	int lowOffset = 2 * yOffset;
	int upOffset = -2 * xOffset;
	//
	int stepDir = 1;
	int step = 0;
	int stepLength = xOffset;
	if (k < 0) {
		stepDir = -1;
	}
	shScreenPoint mainDir(1, 0);
	shScreenPoint secDir(0, 1 * stepDir);
	if (abs(k) > 1) {
		lowOffset = 2 * xOffset;
		upOffset = -2 * yOffset;
		stepLength = yOffset;
		mainDir.setCoords(0, 1 * stepDir);
		secDir.setCoords(1, 0);
	}
	shScreenPoint tempPoint = beginPoint;
	for (; step < stepLength; ++step) {
		tempPoint.drawPoint();
		tempPoint.transPosition(mainDir);
		conValue += lowOffset;
		if (conValue >= 0) {
			tempPoint.transPosition(secDir);
			conValue += upOffset;
		}
	}

}
void shLine::drawLine() {
	glColor3fv(lineColor.getColor());
	glBegin(GL_LINES);
	glVertex2iv(beginPoint.getPosition());
	glVertex2iv(endPoint.getPosition());
	glEnd();
	glFlush();
}
void shLine::disPosition() {
	std::cout << "Line Position: " << std::endl;
	std::cout << "Begin : ";
	beginPoint.disPosition();
	std::cout << "End : ";
	endPoint.disPosition();
}
void shLine::transPosition(GLint _xOffset, GLint _yOffset) {
	beginPoint.transPosition(_xOffset, _yOffset);
	endPoint.transPosition(_xOffset, _yOffset);
}