#pragma once
#include "Rect.h"
#include "point.h"

class obj
{
public:
	obj(void);
	obj(const char face, const point position, const point dat[4]);
	virtual ~obj(void);
	bool move( point *offset, Rect &boundary);
	bool isInside(const Rect &rect);
	void draw(bool show);
	int get_datax(int i);
	int get_datay(int i);
	bool x_inside(const Rect &rect,point t);
private:
	point center;
	point data[4];
public:
	void rotate(Rect &rect);
	bool is_right(const Rect &rect);
	bool is_left(const Rect &rect);
	bool is_bottom(const Rect &rect);
	bool is_top(const Rect &rect);
	bool is_rotate(void);
	bool if_create(Rect rect);
	void draw_obj(bool s);
};

