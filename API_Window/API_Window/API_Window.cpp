#include "windows.h"

#define Xpos1  0
#define Ypos1  0
#define WindowWidth1 640
#define WindowHeigth1 480

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
//initial
	HWND hwnd;
	MSG Msg;
	WNDCLASS wndclass;
	TCHAR lpszClassName[] = L"Àý2-1";
	TCHAR lpszTitle[] = L"µÚÈýÕÂÁ·Ï°";
//define
	wndclass.style = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = lpszClassName;
//register
	if (!RegisterClass(&wndclass)) {
		MessageBeep(0);
		return false;
	}
//create
	hwnd = CreateWindow(
		lpszClassName,
		lpszTitle,
		WS_OVERLAPPEDWINDOW|WS_HSCROLL|WS_VSCROLL,
		Xpos1,
		Ypos1,
		WindowWidth1,
		WindowHeigth1,
		NULL,
		NULL,
		hInstance,
		NULL
		);
//show
	ShowWindow(hwnd, nCmdShow);
//update
	UpdateWindow(hwnd);
//message loop
	while (GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

LRESULT CALLBACK WndProc(
	HWND hwnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam) {

	switch (message) {
	case WM_DESTROY:	
		PostQuitMessage(0); break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}
	return 0;
}