#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "line.h"
#include "constants.h"
#include "tools.h"

Line::Line() : m_O(Vector3::ZERO), m_d(Vector3::UNIT_Y) {}
Line::Line(const Vector3 &o, const Vector3 &d) : m_O(o), m_d(d) {}
Line::Line(const Line &line) : m_O(line.m_O), m_d(line.m_d) {}

Line &Line::operator=(const Line &line)
{
	if (&line != this)
	{
		m_O = line.m_O;
		m_d = line.m_d;
	}
	return *this;
}

// @@ TODO: Set line to pass through two points A and B
//
// Note: Check than A and B are not too close!

void Line::setFromAtoB(const Vector3 &A, const Vector3 &B)
{
	/* =================== PUT YOUR CODE HERE ====================== */
	m_O = A;
	m_d = B - A;

	if (m_d.isZero())
	{
		printf("Son valores sospechosamente ceranos, vamos a poner un 0!");
		m_d = 0;
	}

	m_d = m_d.normalize();
	/* =================== END YOUR CODE HERE ====================== */
}

// @@ TODO: Give the point corresponding to parameter u

Vector3 Line::at(float u) const
{
	Vector3 res;
	/* =================== PUT YOUR CODE HERE ====================== */
	res = m_O + u * m_d;
	/* =================== END YOUR CODE HERE ====================== */
	return res;
}

// @@ TODO: Calculate the parameter 'u0' of the line point nearest to P
// COMPROBAR QUE NO HAY DIVISION POR CERO. EN ESTE CASO, DEVOLVER UN 0.
// u0 = m_d*(P-m_o) / m_d*m_d , where * == dot product

float Line::paramDistance(const Vector3 &P) const
{
	float res = 0.0f;
	/* =================== PUT YOUR CODE HERE ====================== */
	// devolver Uo y usarlo en distance
	float prod_esc1, prod_esc2;
	Vector3 p_mo;
	p_mo = P - m_O;
	prod_esc1 = m_d.dot(p_mo);
	prod_esc2 = m_d.dot(m_O);

	if (prod_esc2 == 0){
		return 0.0;
	}

	res = prod_esc1 / prod_esc2;

	/* =================== END YOUR CODE HERE ====================== */
	return res;
}

// @@ TODO: Calculate the minimum distance 'dist' from line to P
//
// dist = ||P - (m_o + u0*m_d)||
// Where u0 = paramDistance(P)

float Line::distance(const Vector3 &P) const
{
	float res = 0.0f;
	/* =================== PUT YOUR CODE HERE ====================== */

	float Uo;
	Vector3 dist;
	Uo = paramDistance(P);
	dist = P - (m_O + Uo * m_d);
	res = dist.length();
	
	/* =================== END YOUR CODE HERE ====================== */
	return res;
}

void Line::print() const
{
	printf("O:");
	m_O.print();
	printf(" d:");
	m_d.print();
	printf("\n");
}
