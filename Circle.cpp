#include "Circle.h"
#include <cmath>

#include <GL/glut.h>
#include "Rectangle.h"

void Circ::draw()
{
	// Do NOT modify this function
	if (m_bMarked)
		glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
	else
		glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);

	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < 50; i++)
	{
		float theta = i * (2.0f * (float)3.14159 / 50);
		float x = m_rad * cos(theta);
		float y = m_rad * sin(theta);
		glVertex2f(x + m_pos.x, y + m_pos.y);
	}
	glEnd();
}
void Circ::drawBbox(Shape *pshape)
{
	float leftBottomx, leftBottomy, rightUpperx, rightUppery;

	if (this->intersects(pshape))
	{ // TODO: calculate leftBottomx, leftBottomy, rightUpperx, rightUppery points for surrounding bounding box
		Circ *cemb = dynamic_cast<Circ *>(pshape);
		leftBottomx = cemb->getPos().x - cemb->getRad() < this->getPos().x - this->getRad() ? cemb->getPos().x - cemb->getRad() : this->getPos().x - this->getRad();
		leftBottomy = cemb->getPos().y - cemb->getRad() < this->getPos().y - this->getRad() ? cemb->getPos().y - cemb->getRad() : this->getPos().y - this->getRad();
		rightUpperx = cemb->getPos().x + cemb->getRad() > this->getPos().x + this->getRad() ? cemb->getPos().x + cemb->getRad() : this->getPos().x + this->getRad();
		rightUppery = cemb->getPos().y + cemb->getRad() > this->getPos().y + this->getRad() ? cemb->getPos().y + cemb->getRad() : this->getPos().y + this->getRad();
	}

	//Do NOT change this part
	glColor3f(0.0, 0.0, 1.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(leftBottomx, leftBottomy);
	glVertex2f(rightUpperx, leftBottomy);
	glVertex2f(rightUpperx, rightUppery);
	glVertex2f(leftBottomx, rightUppery);
	glEnd();
}
bool Circ::intersects(Shape *pshape)
{
	// TODO: write the implementation for this function
	if (Circ *cemb = dynamic_cast<Circ *>(pshape))
	{
		cemb->getPos().x;
		cemb->getPos().y;
		if (
			(pow(cemb->getPos().x - this->getPos().x, 2) +
			 pow(cemb->getPos().y - this->getPos().y, 2)) <
			pow(cemb->getRad() + this->getRad(), 2))
			return true;
		else
			return false;
	}
	return false;
}
