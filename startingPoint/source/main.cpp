/*===========================================
GRRLIB (GX Version)
- Template Code -
Minimum Code To Use GRRLIB
============================================*/
#include <grrlib.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <vector>
#include <math.h>
#include <thread>
#include "font_ttf.h"
#include "coin_png.h"
#define WSP_POINTER_CORRECTION_X 200
#define WSP_POINTER_CORRECTION_Y 250
int touchX;
int touchY;
char player = 'X';
char winner;
bool garbage = 0;
const char* anotherSomething(char places[], int num) {
	if (places[num] == 'X') {
		return "X";
	}
	else if (places[num] == 'O') {
		return "O";
	}
	else {
		return " ";
	}
}
bool ptInRect(int rect[4], int wpadx, int wpady) {
	return(((wpadx >= rect[0]) && (wpadx <= (rect[2]))) && ((wpady >= rect[1]) && (wpady <= (rect[3]))));
}
void switchSomething(char &stuff) {
	if (stuff == 'X') {
		stuff = 'O';
	} 
	else {
		stuff = 'X';
	}
}

int main(int argc, char **argv) {
	GRRLIB_Init();
	bool asdflkjsadlkjfasd = true;
	GRRLIB_texImg* coin = GRRLIB_LoadTexture(coin_png);
	GRRLIB_ttfFont* font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
	int rectangles[9][4] = {
		{0, 0, 213, 160},
		{213, 0, 416, 160},
		{416, 0, 640, 160},
		{0, 160, 213, 320},
		{213, 160, 416, 320},
		{416, 160, 640, 320},
		{0, 320, 213, 480},
		{213, 320, 416, 480},
		{416, 320, 640, 480}
		
		
	};
	char filler[9] = {
		'_',
		'_',
		'_',
		'_',
		'_',
		'_',
		'_',
		'_',
		'_'
	};
	// Initialise the Graphics & Video subsystem
	
	// Initialise the Wiimotes
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
	// Loop forever
	
	
	while(asdflkjsadlkjfasd) {
		
		WPAD_ScanPads(); // Scan the Wiimotes
		ir_t ir;
		WPAD_IR(WPAD_CHAN_0, &ir);
		if (!(WPAD_ButtonsDown(WPAD_CHAN_0) & WPAD_BUTTON_A)) {
			garbage = false;
		}
		touchX = (ir.sx - WSP_POINTER_CORRECTION_X);
		touchY = (ir.sy - WSP_POINTER_CORRECTION_Y);
		// If [HOME] was pressed on the first Wiimote, break out of the loop
		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break;
		// ---------------------------------------------------------------------
		if ((WPAD_ButtonsDown(WPAD_CHAN_0) & WPAD_BUTTON_A) && garbage == false) {
			for (int i = 0; i < 9; i++) {
				if (ptInRect(rectangles[i], touchX, touchY)) {
					if (filler[i] != 'X' && filler[i] != 'O') {
						filler[i] = player;
						switchSomething(player);
						break;
					}
					
				}
			}

			
			garbage = true;
		}
		
		//if (asdflkjsadlkjfasd) {
		//	switchSomething(player);
		//	asdflkjsadlkjfasd = false;
		//}
		GRRLIB_FillScreen(0x000000FF);
		if (filler[0] == filler[4] && filler[0] == filler[8] && filler[0] != '_') {
			asdflkjsadlkjfasd = false;
			winner = filler[8];
			GRRLIB_Line(0, 0, 640, 480, 0xFFFFFFFF);
		}
		else if (filler[2] == filler[4] && filler[2] == filler[6] && filler[2] != '_') {
			asdflkjsadlkjfasd = false;
			winner = filler[6];
			GRRLIB_Line(640, 0, 0, 480, 0xFFFFFFFF);
		}
		else if (filler[0] == filler[3] && filler[0] == filler[6] && filler[0] != '_') {
			asdflkjsadlkjfasd = false;
			winner = filler[6];
			GRRLIB_Line(106, 0, 106, 480, 0xFFFFFFFF);
		}
		else if (filler[1] == filler[4] && filler[1] == filler[7] && filler[1] != '_') {
			asdflkjsadlkjfasd = false;
			winner = filler[7];
			GRRLIB_Line(320, 0, 320, 480, 0xFFFFFFFF);
		}
		else if (filler[2] == filler[5] && filler[2] == filler[8] && filler[2] != '_') {
			asdflkjsadlkjfasd = false;
			winner = filler[2];
			GRRLIB_Line(520, 0, 520, 480, 0xFFFFFFFF);
		}
		else if (filler[0] == filler[1] && filler[0] == filler[2] && filler[2] != '_') {
			asdflkjsadlkjfasd = false;
			winner = filler[1];
			GRRLIB_Line(0, 80, 640, 80, 0xFFFFFFFF);
		}
		else if (filler[3] == filler[4] && filler[3] == filler[5] && filler[3] != '_') {
			asdflkjsadlkjfasd = false;
			winner = filler[3];
			GRRLIB_Line(0, 240, 640, 240, 0xFFFFFFFF);
		}
		else if (filler[6] == filler[7] && filler[6] == filler[8] && filler[6] != '_') {
			asdflkjsadlkjfasd = false;
			winner = filler[6];
			GRRLIB_Line(400, 0, 400, 640, 0xFFFFFFFF);
		}
		else if (filler[0] != '_' && filler[1] != '_' && filler[2] != '_' && filler[3] != '_' && filler[4] != '_' && filler[5] != '_' && filler[6] != '_' && filler[7] != '_' && filler[8] != '_') {
			asdflkjsadlkjfasd = false;
			winner = '_';
		}
		
		GRRLIB_Line(213, 0, 213, 480, 0xFFFFFFFF);
		GRRLIB_Line(416, 0, 416, 480, 0xFFFFFFFF);
		GRRLIB_Line(0, 160, 640, 160, 0xFFFFFFFF);
		GRRLIB_Line(0, 320, 640, 320, 0xFFFFFFFF);
		//(const char*) was causing problems
		GRRLIB_PrintfTTF(92, 36, font, anotherSomething(filler, 0), 64, 0xFFFFFFFF);
		GRRLIB_PrintfTTF(305, 37, font, anotherSomething(filler, 1), 64, 0xFFFFFFFF);
		GRRLIB_PrintfTTF(508, 40, font, anotherSomething(filler, 2), 64, 0xFFFFFFFF);
		GRRLIB_PrintfTTF(508, 40, font, anotherSomething(filler, 2), 64, 0xFFFFFFFF);
		GRRLIB_PrintfTTF(92, 160, font, anotherSomething(filler, 3), 64, 0xFFFFFFFF);
		GRRLIB_PrintfTTF(320, 160, font, anotherSomething(filler, 4), 64, 0xFFFFFFFF);
		GRRLIB_PrintfTTF(508, 160, font, anotherSomething(filler, 5), 64, 0xFFFFFFFF);
		GRRLIB_PrintfTTF(92, 320, font, anotherSomething(filler, 6), 64, 0xFFFFFFFF);
		GRRLIB_PrintfTTF(305, 320, font, anotherSomething(filler, 7), 64, 0xFFFFFFFF);
		GRRLIB_PrintfTTF(508, 320, font, anotherSomething(filler, 8), 64, 0xFFFFFFFF);
		GRRLIB_DrawImg(touchX, touchY, coin, 0, 1, 1, 0xFFFFFFFF);

		// ---------------------------------------------------------------------
		GRRLIB_Render(); // Render the frame buffer to the TV
		
		
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	GRRLIB_FillScreen(0x000000FF);
	if (winner == '_') {
		GRRLIB_PrintfTTF(0, 208, font, "Cat Game!", 64, 0xFFFFFFFF);
	}
	else if (winner == 'X') {
		GRRLIB_PrintfTTF(0, 208, font, "X Wins!", 64, 0xFFFFFFFF);
	}
	else if (winner == 'O') {
		GRRLIB_PrintfTTF(0, 208, font, "O Wins!", 64, 0xFFFFFFFF);
	}
	GRRLIB_Render();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	GRRLIB_FreeTTF(font);
	GRRLIB_FreeTexture(coin);
	GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

	exit(0); // Use exit() to exit a program, do not use ’return’ from main()
}