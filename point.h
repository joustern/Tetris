#pragma once

class Rect;
class point
{
public:
	point(void);
	point(const int a, const int b);
	point operator+(const point &rhs)const;
	virtual ~point(void);
	bool isInside(const Rect &rect);
	int getx(void);
	int gety(void);
	void change_y(void);
private:
	Rect* ptr;
	int x;
	int y;
public:
	void rotate_xy(void);
};

