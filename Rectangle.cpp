#include "Rectangle.h"
#include <iostream>
#include <GL/glut.h>
#include "Circle.h"
#include <cmath>
#include <string>
void Rect::draw()
{
	// Do NOT modify this function
	if (m_bMarked)
		glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
	else
		glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);
	glRectf(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y);
}

void Rect::drawBbox(Shape *pshape)
{

	float leftBottomx, leftBottomy, rightUpperx, rightUppery;
	if (this->intersects(pshape))
	{
		// TODO: calculate leftBottomx, leftBottomy, rightUpperx, rightUppery points for surrounding bounding box
		Rect *dgen = dynamic_cast<Rect *>(pshape);
		leftBottomx = dgen->getPos().x < this->getPos().x ? dgen->getPos().x : this->getPos().x;
		leftBottomy = dgen->getPos().y < this->getPos().y ? dgen->getPos().y : this->getPos().y;
		rightUpperx = dgen->getPos().x + dgen->getSize().x > this->getPos().x + this->getSize().x ? dgen->getPos().x + dgen->getSize().x : this->getPos().x + this->getSize().x;
		rightUppery = dgen->getPos().y + dgen->getSize().y > this->getPos().y + this->getSize().y ? dgen->getPos().y + dgen->getSize().y : this->getPos().y + this->getSize().y;
	}

	//Do NOT change this part
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(leftBottomx, leftBottomy);
	glVertex2f(rightUpperx, leftBottomy);
	glVertex2f(rightUpperx, rightUppery);
	glVertex2f(leftBottomx, rightUppery);
	glEnd();
}

bool Rect::intersects(Shape *pshape)
{ // TODO: write the implementation for this function

	if (Rect *dgen = dynamic_cast<Rect *>(pshape))
	{
		if (
			dgen->getPos().y > (this->getPos().y + this->getSize().y) ||
			this->getPos().y > (dgen->getPos().y + dgen->getSize().y))
			return false;
		if (
			dgen->getPos().x > (this->getPos().x + this->getSize().x) ||
			this->getPos().x > (dgen->getPos().x + dgen->getSize().x))
			return false;
		else
			return true;
	}
	else
		return false;
}