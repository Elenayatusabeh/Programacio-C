#include <windows.h>
int main(){
while (!GetAsyncKeyState(VK_F8)){
system("start cmd.exe");
}
return 0;
}
