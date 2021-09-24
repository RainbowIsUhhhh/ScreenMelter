#include <windows.h>
#include <thread>

void meltScreen() {
    while (true) {
        HWND hWnd = GetDesktopWindow();
        HDC hDC = GetWindowDC(hWnd);
        RECT rct;

        GetWindowRect(hWnd, &rct);

        int X = rand() % rct.right;

        int Y = rand() % 10 + 0;

        BitBlt(hDC, X, Y, rct.right, rct.bottom, hDC, X, 0, SRCCOPY);

        Sleep(50);
    }
}

int main()
{
    MessageBox(NULL, L"Press 'ESC' to stop melting", L"Screen Melter", MB_OK);

    meltScreen();
}