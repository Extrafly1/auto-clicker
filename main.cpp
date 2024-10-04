#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

void simulateMouseClick(int x, int y) {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
    input.mi.mouseData = 0;
    input.mi.dwExtraInfo = 0;
    input.mi.time = 0;
    input.mi.dwExtraInfo = 0;

    input.mi.dwFlags = MOUSEEVENTF_MOVE;
    SetCursorPos(x, y);

    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main()
{
    std::cout << "iteration click >>> ";
    int n;
    std::cin >> n;
    n = abs(n);

    std::cout << "time >>> ";
    int t;
    std::cin >> t;
    t = abs(t);

    for (int i = 0; i <= t; i++) {
        Sleep(1000);
        std::cout << t-i <<" ";
    }
    std::cout << std::endl;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN) / 2;
    int screenHeight = GetSystemMetrics(SM_CYSCREEN) / 2;

    srand(time(NULL));

    for (int i = 0; i < n; i++) { 
        int r1 = rand() % 50 - 25, 
            r2 = rand() % 50 - 25, 
            r3 = rand() % 10 - 10; 
        simulateMouseClick(screenWidth + r1, screenHeight + r2);
        Sleep(35 + r3); 
    }

    std::cout << "finish" << std::endl;

    system("PAUSE");
    return 0;
}
