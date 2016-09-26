/*
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "MouseMovement.hpp"


/*
#define X 123
#define Y 123
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 800
*/

/*void MouseSetup(INPUT *buffer);*/
void MouseMoveAbsolute( int x, int y);
void MouseClick(INPUT *buffer);
int mouseMove();
void SetMousePosition(long x, long y);


/*void MouseSetup(INPUT *buffer)
{
    buffer->type = INPUT_MOUSE;
    buffer->mi.dx = (0 * (0xFFFF / SCREEN_WIDTH));
    buffer->mi.dy = (0 * (0xFFFF / SCREEN_HEIGHT));
    buffer->mi.mouseData = 0;
    buffer->mi.dwFlags = MOUSEEVENTF_ABSOLUTE;
    buffer->mi.time = 0;
    buffer->mi.dwExtraInfo = 0;
}*/


void MouseMoveAbsolute( int x, int y)
{
	/*INPUT buffer[1];

    buffer->mi.dx = (x * (0xFFFF / SCREEN_WIDTH));
    buffer->mi.dy = (y * (0xFFFF / SCREEN_HEIGHT));
    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);

    SendInput(1, buffer, sizeof(INPUT));*/
}


/*
void MouseClick(INPUT *buffer)
{
    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
    SendInput(1, buffer, sizeof(INPUT));

    Sleep(10);

    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
    SendInput(1, buffer, sizeof(INPUT));
}
*/


int mouseMove()
{


    /*MouseSetup(&buffer);*/

	/*for(int i=0; i < 10 ; i ++) {
		MouseMoveAbsolute(X + i*10, Y + + i*10);
	}
*/
   // MouseClick(&buffer);

    return 0;
}

void SetMousePosition(long x, long y)
{
	POINT  mp;
	mp.x = x;
	mp.y = y;
	long fScreenWidth	    = GetSystemMetrics( SM_CXSCREEN ) - 1;
	long fScreenHeight	    = GetSystemMetrics( SM_CYSCREEN ) - 1;

	// http://msdn.microsoft.com/en-us/library/ms646260(VS.85).aspx
	// If MOUSEEVENTF_ABSOLUTE value is specified, dx and dy contain normalized absolute coordinates between 0 and 65,535.
	// The event procedure maps these coordinates onto the display surface.
	// Coordinate (0,0) maps onto the upper-left corner of the display surface, (65535,65535) maps onto the lower-right corner.
	float fx		        = mp.x * ( 65535.0f / fScreenWidth  );
	float fy		        = mp.y * ( 65535.0f / fScreenHeight );

	INPUT Input             = { 0 };
	Input.type		        = INPUT_MOUSE;

	Input.mi.dwFlags	    = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;

	Input.mi.dx		        = (long)fx;
	Input.mi.dy		        = (long)fy;

	SendInput(1,&Input,sizeof(INPUT));
}

void LeftClick()
{
	INPUT    Input={0};													// Create our input.

	Input.type        = INPUT_MOUSE;									// Let input know we are using the mouse.
	Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;							// We are setting left mouse button down.
	SendInput( 1, &Input, sizeof(INPUT) );								// Send the input.

	ZeroMemory(&Input,sizeof(INPUT));									// Fills a block of memory with zeros.
	Input.type        = INPUT_MOUSE;									// Let input know we are using the mouse.
	Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;								// We are setting left mouse button up.
	SendInput( 1, &Input, sizeof(INPUT) );								// Send the input.
}
