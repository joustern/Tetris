#include "point.h"
#include "Rect.h"

point::point(void)
	: x(0)
	, y(0)
{
	
}

point::point(const int a, const int b)
	:x(a)
	,y(b)
{
	
}

point point ::operator+(const point &rhs)const
{
	return point(x+rhs.x,y+rhs.y);
}

point::~point(void)
{
}

bool point::isInside(const Rect &rect)
{
	Rect a;
	a=rect;
	if(x<a.get_right()&&x>a.get_left()&&y<a.get_bottom()&&y>a.get_top()){
		return true;
	}
	else return false;
}


int point::getx(void)
{
	return x;
}


int point::gety(void)
{
	return y;
}


void point::change_y(void)
{
	y=y+1;
}


void point::rotate_xy(void)
{
	int t=x;
	x=y;
	y=(-1)*t;
}
