#include "obj.h"
#include "utilwin32.h"
#include <iostream>
using namespace std;

obj::obj(void)
	:data()
	, center()
{
}

obj::obj(const char face, const point position, const point dat[4])
	: data()
	, center(position)
{
	for(int i=0;i<4;i++){
		data[i]=dat[i];
	}
}


obj::~obj(void)
{
}


bool obj::move( point *offset, Rect &boundary)
{
	boundary.draw_block(false);
	draw(false);
	if(isInside(boundary)){
		if(boundary.is_block(data,center,*offset)){
			center=center.operator+(*offset);
			draw(true);
			boundary.draw_block(true);
			return true;
		}
		else if(!boundary.is_block(data,center,*offset)){
			if(offset->getx()==0){
				boundary.set_block(center,data);
				boundary.draw_block(true);
				return false;
			}
			else if(offset->getx()!=0){
				point a(0,1);
				if(boundary.is_block(data,center,a)){
					center=center.operator+(a);
					draw(true);
					boundary.draw_block(true);
					delay(450);
					return true;
				}
				else{
					boundary.set_block(center,data);
					boundary.draw_block(true);
					delay(450);
					return false;
				}
			}
		}
	}
	else
		boundary.set_block(center,data);
	    boundary.draw_block(true);
	    return false;
}


bool obj::isInside(const Rect &rect)
{
	Rect a;
	a=rect;
	for(int i=0;i<4;i++){
		if(data[i].getx()+center.getx()>a.get_right()||data[i].getx()+center.getx()<a.get_left()||data[i].gety()+center.gety()>=a.get_bottom()||data[i].gety()+center.gety()<a.get_top())
			return false;
	}
	return true;
}


void obj::draw(bool show)
{
	if(show){
	    for(int i=0;i<4;i++){
		    gotoxy(center.getx()+data[i].getx(),center.gety()+data[i].gety());
		    cout << "*";
	    }
	}
	else{
		for(int i=0;i<4;i++){
		    gotoxy(center.getx()+data[i].getx(),center.gety()+data[i].gety());
		    cout << ' ';
		}
	}
}


int obj::get_datax(int i)
{
	return data[i].getx();
}


int obj::get_datay(int i)
{
	return data[i].gety();
}


bool obj::x_inside(const Rect &rect,point t)
{
	Rect a;
	a=rect;
	for(int i=0;i<4;i++){
		if(data[i].getx()+center.getx()+t.getx()>a.get_right()||data[i].getx()+center.getx()+t.getx()<a.get_left()){
			return true;
		}
	}
	return false;
}


void obj::rotate(Rect &rect)
{
	point p(0,0),u(0,-1),down(0,1),l(-1,0),r(1,0);
	point temp[4];
	int w=0,a=0,s=0,d=0;
	for(int i=0;i<4;i++){
		temp[i]=data[i];
	}
	for(int i=0;i<4;i++){
		data[i].rotate_xy();
	}
	if(is_right(rect)){
		while(is_right(rect)){
			center=center.operator+(point(-1,0));
			d++;
		}
	}
	if(is_left(rect)){
		while(is_left(rect)){
			center=center.operator+(point(1,0));
			a++;
		}
	}
	if(is_top(rect)){
		while(is_top(rect)){
			center=center.operator+(point(0,1));
			w++;
		}
	}
	if(is_bottom(rect)){
		while(is_bottom(rect)){
			center=center.operator+(point(0,-1));
			s++;
		}
	}
	if(!rect.is_block(data,center,p)){
		for(int i=0;i<4;i++){
			data[i]=temp[i];
		}
		if(w!=0){
			while(w!=0){
				center=center.operator+(point(0,-1));
				w--;
			}
		}
		if(a!=0){
			while(a!=0){
				center=center.operator+(point(-1,0));
				a--;
			}
		}
		if(s!=0){
			while(s!=0){
				center=center.operator+(point(0,1));
				s--;
			}
		}
		if(d!=0){
			while(d!=0){
				center=center.operator+(point(1,0));
				d--;
			}
		}
	}
}


bool obj::is_right(const Rect &rect)
{
	Rect a;
	a=rect;
	for(int i=0;i<4;i++){
		if(data[i].getx()+center.getx()>=a.get_right()){
			return true;
		}
	}
	return false;
}


bool obj::is_left(const Rect &rect)
{
	Rect a;
	a=rect;
	for(int i=0;i<4;i++){
		if(data[i].getx()+center.getx()<=a.get_left()){
			return true;
		}
	}
	return false;
}


bool obj::is_bottom(const Rect &rect)
{
	Rect a;
	a=rect;
	for(int i=0;i<4;i++){
		if(data[i].gety()+center.gety()>=a.get_bottom()){
			return true;
		}
	}
	return false;
}


bool obj::is_top(const Rect &rect)
{
	Rect a;
	a=rect;
	for(int i=0;i<4;i++){
		if(data[i].gety()+center.gety()<=a.get_top()+1){
			return true;
		}
	}
	return false;
}


bool obj::is_rotate(void)
{
	int temp=0;
	point shape[4] = { point(-1,0), point(0,0), point(0,-1), point(-1,-1)};
	for(int i=0;i<4;i++){
		if(data[i].getx()==shape[i].getx()&&data[i].gety()==shape[i].gety()){
			temp++;
		}
	}
	if(temp==4) return true;
	else return false;
}


bool obj::if_create(Rect rect)
{
	point p(0,0);
	if(!rect.is_block(data,center,p)) return false;
	else return true;
}


void obj::draw_obj(bool s)
{
	if(s){
		for(int i=0;i<4;i++){
		    gotoxy(4+data[i].getx(),7+data[i].gety());
		    cout << "*";
	    }
	}
	else{
		for(int i=0;i<4;i++){
		    gotoxy(4+data[i].getx(),7+data[i].gety());
		    cout << ' ';
	    }
	}
}
