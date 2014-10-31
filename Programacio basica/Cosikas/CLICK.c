#include <windows.h>

int main() {
	const int maxOffset = 7;
	POINT place;

	FreeConsole();
	srand(GetTickCount());

	while(1==1) {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
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
        }
        else{
           continue;

        }

    }


}
