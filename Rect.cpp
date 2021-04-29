#include "Rect.h"
#include "obj.h"
#include "utilwin32.h"
#include <iostream>
using namespace std;

Rect::Rect(void)
{
}

Rect::Rect(const int left, const int top, const int right, const int bottom)
	: left(left)
	, top(top)
	, right(right)
	, bottom(bottom)
{
	
}


Rect::~Rect(void)
{
	
}

bool Rect::contains(const point &pt)const
{
	point a=pt;
	if(a.getx()<right&&a.getx()>left&&a.gety()<bottom&&a.gety()>top){
		return true;
	}
	else return false;
}

void const Rect::drawBoundary()
{
	int orgX=10, orgY=5, width=25, height=16;
	int i;
    gotoxy(orgX-1, orgY-1);
    cout << '+';
    for (i=0; i<width; i++)
        cout << '-';
    cout << '+';

    for (i=0; i<height; i++)
    {
        gotoxy(orgX-1, orgY+i); cout << '|';
        gotoxy(orgX+width, orgY+i); cout << '|';
    }

    gotoxy(orgX-1, orgY+height);
    cout << '+';
    for (i=0; i<width; i++)
        cout << '-';
    cout << '+';
    gotoxy(1,23);
}


int Rect::get_left(void)
{
	return left;
}


int Rect::get_right(void)
{
	return right;
}


int Rect::get_bottom(void)
{
	return bottom;
}


int Rect::get_top(void)
{
	return top;
}


bool Rect::contains(const obj& ob)const
{
	obj a=ob;
	for(int i=0;i<4;i++){
		if(a.get_datax(i)>=right||a.get_datax(i)<=left||a.get_datay(i)>=bottom||a.get_datay(i)<=top){
			return false;
		    break;
		}
	}
	return true;
}


bool Rect::is_block(point a[],point b,point offset)
{
	vector<point>::iterator iter;
	for(iter=block.begin();iter!=block.end();iter++){
		for(int i=0;i<4;i++){
			if(iter->getx()==a[i].getx()+b.getx()+offset.getx()&&iter->gety()==a[i].gety()+b.gety()+offset.gety()){
				return false;
			}
		}
	}
	return true;
}


void Rect::set_block(point a,point b[])
{
	for(int i=0;i<4;i++){
		block.push_back(a+b[i]);
	}
}


void Rect::draw_block(bool s)
{
	vector<point>::iterator iter;
	if(s){
		for(iter=block.begin();iter!=block.end();iter++){
			gotoxy(iter->getx(),iter->gety());
			cout << '*';
		}
	}
	else{
		for(iter=block.begin();iter!=block.end();iter++){
			gotoxy(iter->getx(),iter->gety());
			cout << ' ';
		}
	}
}


void Rect::del_block(void)
{
	vector<point>::iterator iter;
	for(int i=5;i<=20;i++){
		int x=0;
		for(iter=block.begin();iter!=block.end();iter++){
			if(iter->gety()==i) x++;
		}
		if(x>=25){
			for(iter=block.begin();iter!=block.end();){
				if(iter->gety()==i){
					draw_block(false);
					iter=block.erase(iter);
					draw_block(true);
				}
				else iter++;
			}
			draw_block(false);
			for(iter=block.begin();iter!=block.end();iter++){
				if(iter->gety()<i){
					iter->change_y();		
				}
			}
			draw_block(true);
		}
	}
}