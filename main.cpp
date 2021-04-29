#include "utilwin32.h" // clrscr()
#include <stdlib.h> // system()
#include <iostream>
#include <assert.h>
#include <time.h>
#include <conio.h>
#include "obj.h"
#include "point.h"
#include "Rect.h"
using namespace std;
const int orgX = 10, orgY = 5, width = 25, height = 16;
obj random_obj(void){
	srand(time(NULL));
	int ran = rand()%19;
	switch(ran)
	{
	case 0:
		{
		const point shape[4] = { point(-1,0), point(0,0), point(0,-1), point(-1,-1) };//**
		obj object('*', point(orgX+width/2,orgY+1), shape);                           //*+
		return object;
		break;
		}
	case 1:
		{
		const point shape[4] = { point(0,-1), point(0,0), point(0,1), point(0,2) };//*
		obj object('*', point(orgX+width/2,orgY+1), shape);                        //+
		return object;                                                             //*
		break;																	   //*
		}
	case 2:
		{
		const point shape[4] = { point(-1,0), point(0,0), point(0,1), point(0,2) };//*+
		obj object('*', point(orgX+width/2,orgY), shape);                          // * 
		return object;                                                             // *
		break;
		}
	case 3:
		{
		const point shape[4] = { point(1,0), point(0,0), point(0,1), point(0,2) };//+*
		obj object('*', point(orgX+width/2,orgY), shape);                         //*
		return object;                                                            //*
		break;
		}
	case 4:
		{
		const point shape[4] = { point(0,-1), point(0,0), point(1,0), point(1,1) };//*
		obj object('*', point(orgX+width/2,orgY+1), shape);						   //+*
		return object;															   // *
		break;
		}
	case 5:
		{
		const point shape[4] = { point(0,-1), point(0,0), point(-1,0), point(-1,1) };// *
		obj object('*', point(orgX+width/2,orgY+1), shape);							 //*+
		return object;																 //*
		break;
		}
	case 6:
		{
		const point shape[4] = { point(0,-1), point(0,0), point(-1,0), point(1,0) };// *
		obj object('*', point(orgX+width/2,orgY+1), shape);							//*+*
		return object;
		break;
		}
	case 7:
		{
		const point shape[4] = { point(-1,0), point(0,0), point(1,0), point(2,0) };//*+**
		obj object('*', point(orgX+width/2,orgY), shape);
		return object;
		break;
		}
	case 8:
		{
		const point shape[4] = { point(-1,0), point(0,0), point(1,0), point(-1,1) };//*+*
		obj object('*', point(orgX+width/2,orgY), shape);							//*
		return object;
		break;
		}
	case 9:
		{
		const point shape[4] = { point(1,0), point(0,0), point(0,-1), point(0,-2) };//*
		obj object('*', point(orgX+width/2,orgY+2), shape);							//*
		return object;																//+*
		break;
		}
	case 10:
		{
		const point shape[4] = { point(-1,0), point(0,0), point(-2,0), point(0,-1) };// *
		obj object('*', point(orgX+width/2,orgY+2), shape);							 // *
		return object;																 //*+
		break;
		}
	case 11:
		{
		const point shape[4] = { point(1,0), point(0,0), point(0,-1), point(2,0) };//*
		obj object('*', point(orgX+width/2,orgY+1), shape);						   //+**
		return object;
		break;
		}
	case 12:
		{
		const point shape[4] = { point(-1,0), point(0,0), point(0,-1), point(0,-2) };// *
		obj object('*', point(orgX+width/2,orgY+2), shape);							 // *
		return object;																 //*+
		break;
		}
	case 13:
		{
		const point shape[4] = { point(-2,0), point(0,0), point(0,1), point(-1,0) };//**+
		obj object('*', point(orgX+width/2,orgY), shape);							//  *
		return object;
		break;
		}
	case 14:
		{
		const point shape[4] = { point(-1,0), point(0,0), point(0,-1), point(1,-1) };// **
		obj object('*', point(orgX+width/2,orgY+1), shape);							 //*+
		return object;
		break;
		}
	case 15:
		{
		const point shape[4] = { point(1,0), point(0,0), point(0,-1), point(-1,-1) };//**
		obj object('*', point(orgX+width/2,orgY+1), shape);							 // +*
		return object;
		break;
		}
	case 16:
		{
		const point shape[4] = { point(-1,0), point(0,0), point(0,1), point(0,-1) };// *
		obj object('*', point(orgX+width/2,orgY+1), shape);							//*+
		return object;																// *
		break;
		}
	case 17:
		{
		const point shape[4] = { point(1,0), point(0,0), point(0,1), point(0,-1) };//*
		obj object('*', point(orgX+width/2,orgY+1), shape);						   //+*
		return object;															   //*
		break;
		}
	case 18:
		{
		const point shape[4] = { point(-1,0), point(0,0), point(0,1), point(1,0) };//*+*
		obj object('*', point(orgX+width/2,orgY), shape);						   // *
		return object;
		break;
		}
	}
}
int main()
{
    Rect canvas(orgX, orgY, orgX+width-1, orgY+height-1);
	int speed=500;
    clrscr();
    canvas.drawBoundary();
	obj object=random_obj();
	point t(0,1),r(1,0),l(-1,0);
	point temp=t;
	gotoxy(1,20);
	delay(500);
	while(object.if_create(canvas)){
		obj object2=random_obj();
		object2.draw_obj(true);
		while(object.move(&t, canvas)==true){
			t=temp;
			if(kbhit()){
				int c=getch();
				if(c==112){
					while(getch()!=112){
						delay(500);
					}
				}
				else if(c==27) return 0;
				else if(c=='a'){
					if(!object.x_inside(canvas,l)){
						t=l;
						gotoxy(1,20);
						delay(50);
					}
				}
				else if(c=='d'){
					if(!object.x_inside(canvas,r)){
						t=r;
						gotoxy(1,20);
						delay(50);
					}
				}
				else if(c=='s'){
					gotoxy(1,20);
					delay(50);
				}
				else if(c=='w'){
					gotoxy(1,20);
					object.draw(false);
					if(!object.is_rotate()){
						object.rotate(canvas);
					}
					object.draw(true);
					delay(speed);
				}
			}
			else{
				gotoxy(1,20);
				delay(speed);
			}
		}
		canvas.del_block();
		object=object2;
		object2.draw_obj(false);
	}
    gotoxy(1,23); system("pause");
}