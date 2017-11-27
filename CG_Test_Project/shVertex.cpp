#include "stdafx.h"
#include "shVertex.h"
#include "shMatrix.h"


shVertex::shVertex()
	: vertexColor() {
	memset(vertex, 0, 3);
}
shVertex::shVertex(GLfloat _vertex[]) 
:vertexColor(){
	memcpy(vertex, _vertex, sizeof(_vertex));
}
shVertex::shVertex(GLfloat _x, GLfloat _y, GLfloat _z)
	:vertexColor(){
	vertex[0] = _x;
	vertex[1] = _y;
	vertex[2] = _z;
}
shVertex::shVertex(GLfloat _vertex[], shColorf & _color)
	:vertexColor(_color) {
	memcpy(vertex, _vertex, sizeof(_vertex));
}
shVertex::shVertex(float _x, float _y, float _z, shColorf &_color)
	:vertexColor(_color) {
	vertex[0] = _x;
	vertex[1] = _y;
	vertex[2] = _z;
}
shVertex::shVertex(const shVertex &_vertex) {
	vertex[0] = _vertex.getX();
	vertex[1] = _vertex.getY();
	vertex[2] = _vertex.getZ();
	vertexColor.setColor(_vertex.getColor());
}
void shVertex::setPosition(GLfloat _xPos, GLfloat _yPos, GLfloat _zPos) {
	vertex[0] = _xPos;
	vertex[1] = _yPos;
	vertex[2] = _zPos;
}
void shVertex::setPosition(GLfloat _vertex[]) {
	memcpy(vertex, _vertex, sizeof(_vertex));
}
void shVertex::setPosition(shVertex _vertex) {
	vertex[0] = _vertex.getX();
	vertex[1] = _vertex.getY();
	vertex[2] = _vertex.getZ();
}
shColorf shVertex::getColor() const {
	return vertexColor;
}
void shVertex::setValue(GLint _i,GLfloat _v) {
	vertex[_i] = _v;
}
void shVertex::setX(GLfloat _x) {
	vertex[0] = _x;
}
void shVertex::setY(GLfloat _y) {
	vertex[1] = _y;
}
void shVertex::setZ(GLfloat _z) {
	vertex[2] = _z;
}
GLfloat shVertex::getValue(GLint _i) {
	return vertex[_i];
}
GLfloat shVertex::getX() const {
	return vertex[0];
}
GLfloat shVertex::getY() const {
	return vertex[1];;
}
GLfloat shVertex::getZ() const {
	return vertex[2];
}
GLfloat * shVertex::getPosition() {
	return vertex;
}
void shVertex::incrementX(GLfloat _offset) {
	vertex[0] += _offset;
}
void shVertex::incrementY(GLfloat _offset ) {
	vertex[1] += _offset;
}
void shVertex::incrementZ(GLfloat _offset) {
	vertex[2] += _offset;
}
void shVertex::decrementX(GLfloat _offset) {
	vertex[0] -= _offset;
}
void shVertex::decrementY(GLfloat _offset) {
	vertex[1] -= _offset;
}
void shVertex::decrementZ(GLfloat _offset) {
	vertex[2] -= _offset;
}
void shVertex::traxnsPosition(GLfloat _xDir, GLfloat _yDir, GLfloat _zDir) {
	vertex[0] += _xDir;
	vertex[1] += _yDir;
	vertex[2] += _zDir;
}
void shVertex::transPosition(GLfloat _dir[]) {
	vertex[0] += _dir[0];
	vertex[1] += _dir[1];
	vertex[2] += _dir[2];
}
void shVertex::transPosition(shVertex _vertex) {
	vertex[0] += _vertex.getX();
	vertex[1] += _vertex.getY();
	vertex[2] += _vertex.getX();
}
void shVertex::disPosition() {
	cout << "Vertex : ( " << vertex[0] << " , " << vertex[1] << " , " << vertex[2] << " )" << endl;
}
void shVertex::drawPoint() {
	glColor3fv(vertexColor.getColor());
	glBegin(GL_POINTS);
	glVertex3f(vertex[0], vertex[1], vertex[2]);
	glEnd();
	glFlush();
}
void shVertex::drawPoint(GLfloat _r, GLfloat _g, GLfloat _b) {
	glColor3f(_r, _g, _b);
	glBegin(GL_POINTS);
	glVertex3f(vertex[0], vertex[1], vertex[2]);
	glEnd();
	glFlush();
}
void shVertex::drawPoint(GLfloat _color[]) {
	glColor3fv(_color);
	glBegin(GL_POINTS);
	glVertex3f(vertex[0], vertex[1], vertex[2]);
	glEnd();
	glFlush();
}
void shVertex::drawPoint(shColorf & _color) {
	glColor3fv(_color.getColor());
	glBegin(GL_POINTS);
	glVertex3f(vertex[0], vertex[1], vertex[2]);
	glEnd();
	glFlush();
}
shVertex shVertex::crossProduct(shVertex & _vertex) {
	shVertex tempV;
	tempV.setX(this->getY()*_vertex.getZ() - this->getZ()*_vertex.getY());
	tempV.setY(this->getZ()*_vertex.getX() - this->getX() * _vertex.getZ());
	tempV.setZ(this->getX()* _vertex.getY() - this->getY()*_vertex.getX());
	return tempV;
}
GLfloat shVertex::dotProduct(shVertex & _vertex) {
	return this->getX() * _vertex.getX() + this->getY() * _vertex.getY() + this->getZ() * _vertex.getZ();
}
GLfloat shVertex::getScalar() {
	return sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
}
shVertex shVertex::getNormalized() {
	GLfloat norm = this->getScalar();
	shVertex tempV(this->getX() / norm, this->getY() / norm, this->getZ() / norm);
	return tempV;
}
shVertex shVertex::getProjection(char _n) {
	shVertex temp_v = *this;
	switch (_n) {
	case 'x':
		temp_v.setX(0); break;
	case 'y':
		temp_v.setY(0); break;
	case 'z':
		temp_v.setZ(0); break;
	default:
		break;
	}
	return temp_v;
}

GLfloat shVertex::getCosine(shVertex & _vertex) {
	GLfloat temp_scalar_pro = this->dotProduct(_vertex);
	GLfloat temp_pro_scalar = this->getScalar() * _vertex.getScalar();
	GLfloat temp_angle = temp_scalar_pro / temp_pro_scalar;
	return temp_angle;
}
GLfloat shVertex::getSine(shVertex & _vertex) {
	GLfloat temp_scalar_cp = (this->crossProduct(_vertex)).getScalar();
	GLfloat temp_cp_scalar = this->getScalar() * _vertex.getScalar();
	return temp_cp_scalar / temp_scalar_cp;
}
void shVertex::rotate(GLdouble _radian, shVector _p) {
	//Init Premise Value
	shVertex normalized_p = _p.getNormalized();
	GLfloat temp_d = sqrt(pow(normalized_p.getY(), 2) + pow(normalized_p.getZ(), 2));
	GLfloat temp_rot_cos = 0;
	GLfloat temp_rot_sin = 0;
	shMatrix rotate_matrix(4, 4);
	shMatrix inverse_xRotate_matrix(4, 4);
	//Init X-Axis Rotate Matrix
	if (temp_d) {
		temp_rot_cos = normalized_p.getZ() / temp_d;
		temp_rot_sin = normalized_p.getY() / temp_d;
		GLfloat temp_xRotate_matrix[16] = { 1,0,0,0,0,temp_rot_cos,-1 * (GLfloat)temp_rot_sin,0,0,temp_rot_sin,temp_rot_cos,0,0,0,0,1 };
		GLfloat temp_inv_xRotate_matrix[16] = { 1,0,0,0,0,temp_rot_cos,temp_rot_sin,0,0,-1 * temp_rot_sin,temp_rot_cos,0,0,0,0,1 };
		shMatrix xRotate_matrix(4, 4, temp_xRotate_matrix);
		inverse_xRotate_matrix.setMatrix(4, 4, temp_inv_xRotate_matrix);
		rotate_matrix = xRotate_matrix;
	}

	//Init Y-Axis Rotate Matrix
	temp_rot_cos = temp_d;
	temp_rot_sin = normalized_p.getX();
	GLfloat temp_yRotate_matrix[16] = { temp_rot_cos,0, -1*temp_rot_sin,0,0,1,0,0,temp_rot_sin,0,temp_rot_cos,0,0,0,0,1 };
	GLfloat temp_inv_yRotate_matrix[16] = { temp_rot_cos,0,temp_rot_sin,0,0,1,0,0,-1*temp_rot_sin,0,temp_rot_cos,0,0,0,0,1 };
	shMatrix yRotate_matrix(4, 4, temp_yRotate_matrix);
	shMatrix inverse_yRotate_matrix(4, 4, temp_inv_yRotate_matrix);
	rotate_matrix = rotate_matrix.preMulti(yRotate_matrix);
	//Init Z-Axis Rotate Matrix
	GLfloat temp_zRotate_matrix[16] = { (GLfloat)cos(_radian), -1 * (GLfloat)sin(_radian),0,0,(GLfloat)sin(_radian),(GLfloat)cos(_radian),0,0,0,0,1,0,0,0,0,1 };
	shMatrix zRotate_matrix(4, 4, temp_zRotate_matrix);
	rotate_matrix = rotate_matrix.preMulti(zRotate_matrix);
	//Reverse Rotate
	rotate_matrix = rotate_matrix.preMulti(inverse_yRotate_matrix);
	rotate_matrix = rotate_matrix.preMulti(inverse_xRotate_matrix);
	//Roatate Vertex
	shMatrix temp_vertex(4, 1, 1);
	for (int i = 0; i < 3; ++i) {
		temp_vertex.setValue(i, 0, vertex[i]);
	}
	shMatrix result_vertex = rotate_matrix.postMulti(temp_vertex);
	vertex[0] = result_vertex.getValue(0, 0);
	vertex[1] = result_vertex.getValue(1, 0);
	vertex[2] = result_vertex.getValue(2, 0);

}
void shVertex::rotate(GLdouble _d, shScreenPoint _p = shScreenPoint()) {
	GLdouble cosTheta = cos(_d);
	GLdouble sinTheta = sin(_d);
	if (abs(cosTheta) < 0.0001) {
		cosTheta = 0;
	}

	GLfloat tempX = vertex[0];
	GLfloat tempY = vertex[1];
	vertex[0] = (GLfloat)(_p.getX() + (tempX - _p.getX()) * cosTheta - (tempY - _p.getY()) * sinTheta);
	vertex[1] = (GLfloat)(_p.getY() + (tempX - _p.getX()) * sinTheta + (tempY - _p.getY()) * cosTheta);
}
void shVertex::rotate(GLdouble _d, GLfloat _x, GLfloat _y) {
	GLdouble cosTheta = cos(_d);
	if (abs(cosTheta) < 0.0001) {
		cosTheta = 0;
	}
	GLdouble sinTheta = sin(_d);
	GLfloat tempX = vertex[0];
	GLfloat tempY = vertex[1];
	vertex[1] = (GLfloat)(_y + (tempX - _x) * sinTheta + (tempY - _y) * cosTheta);
	vertex[0] = (GLfloat)(_x + (tempX - _x) * cosTheta - (tempY - _y) * sinTheta);
}
shScreenPoint shVertex::trans2ScreenPoint() {
	shScreenPoint tempPoint((GLint)vertex[0], (GLint)vertex[1]);
	return tempPoint;
}