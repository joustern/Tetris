#pragma once
#include <vector>
#include "point.h"
using namespace std;
class obj;
class Rect
{
public:
	Rect(void);
	Rect(const int left, const int top, const int right, const int bottom);
	virtual ~Rect(void);
	bool contains(const point &pt) const;
	void const drawBoundary();
	int get_left(void);
	int get_right(void);
	int get_bottom(void);
	int get_top(void);
	bool contains(const obj& obj)const;
	bool is_block(point a[],point b,point offset);
	void set_block(point a,point b[]);
private:
	obj* ptr2;
	point ptr1;
	int left;
	int top;
	int right;
	int bottom;
	vector<point> block;
public:
	void draw_block(bool s);
	void del_block(void);
};

