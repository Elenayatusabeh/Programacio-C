#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main() {
	const int maxOffset = 7;
	POINT place;

	FreeConsole();
	srand(GetTickCount());
    char n;
    n=0;
    while(TRUE){
            fflush(stdin);
            getch();
            n=getch();

	if(n!=0) {

            GetCursorPos(&place);

            int direction = (rand() % 4);
            switch(direction) {
                case 0:
                    SetCursorPos(place.x + (rand() % maxOffset), place.y + (rand() % maxOffset));
                    break;
                case 1:
                    SetCursorPos(place.x + (rand() % maxOffset), place.y - (rand() % maxOffset));
                    break;
                case 2:
                    SetCursorPos(place.x - (rand() % maxOffset), place.y - (rand() % maxOffset));
                    break;
                case 3:
                default: // ??
                    SetCursorPos(place.x - (rand() % maxOffset), place.y + (rand() % maxOffset));
                    break;
            }
            Sleep(5);
    n=0;
	}


    }
    }



