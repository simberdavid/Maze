
#include "stdafx.h"
#include "Maze.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING];            

HBITMAP wall = NULL;
HBITMAP box = NULL;

int mx = 24;
int my = 24;

int mapdata[28][22]  
{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
  {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
  {1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1},
  {1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
  {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1},
  {1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1},
  {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 ,1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
  {1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1}, 
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT2));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECT2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
               0, 0, 3840, 2160, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void DrawSprite(RECT* prc, HBITMAP g_hbmBall, HDC hdc, int x, int y)
{
	HDC hdcBuffer = CreateCompatibleDC(hdc);
	HBITMAP hbmBuffer = CreateCompatibleBitmap(hdc, prc->right, prc->bottom);
	HBITMAP hbmOldBuffer = (HBITMAP)SelectObject(hdcBuffer, hbmBuffer);

	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, g_hbmBall);

	FillRect(hdcBuffer, prc, (HBRUSH)GetStockObject(WHITE_BRUSH));

	BitBlt(hdcBuffer, x, y, 24, 24, hdcMem, 0, 0, SRCAND);

	SelectObject(hdcMem, g_hbmBall);
	BitBlt(hdcBuffer, x, y, 24, 24, hdcMem, 0, 0, SRCPAINT);

	BitBlt(hdc, 0, 0, prc->right, prc->bottom, hdcBuffer, 0, 0, SRCCOPY);

	SelectObject(hdcMem, hbmOld);
	DeleteDC(hdcMem);

	SelectObject(hdcBuffer, hbmOldBuffer);
	DeleteDC(hdcBuffer);
	DeleteObject(hbmBuffer);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
	case WM_CREATE:
		{
			BITMAP bm;

			wall = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));
			if (wall == NULL)
				MessageBoxA(hWnd, "Could not load IDB_BITMAP1!", "Error", MB_ICONEXCLAMATION);

			GetObject(wall, sizeof(bm), &bm);

			box = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2));
			if (box == NULL)
				MessageBoxA(hWnd, "Could not load IDB_BITMAP1!", "Error", MB_ICONEXCLAMATION);

			GetObject(box, sizeof(bm), &bm);

		}
		break;
    case WM_PAINT:
        {
			RECT rcClient;
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
			GetClientRect(hWnd, &rcClient);
			DrawSprite(&rcClient, box, hdc, 24, 24);

			for (size_t y = 0; y < 28; y++)
			{
				for (size_t x = 0; x < 22; x++)
				{
					if (mapdata[y][x] == 1)
					{
						HDC hdcMem = CreateCompatibleDC(hdc);
						HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, wall);

						BitBlt(hdc, x * 24, y * 24, 24, 24, hdcMem, 0, 0, SRCCOPY);

						SelectObject(hdcMem, hbmOld);
						DeleteDC(hdcMem);
					}
				}
			}
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_KEYDOWN:
		{
			RECT rcClient;
			HDC hdc = GetDC(hWnd);

			switch (wParam)
			{
			case VK_RIGHT:
				{
					if (mapdata[(my / 24)][mx / 24 + 1] == 0)
					{
						GetClientRect(hWnd, &rcClient);

						mx += 24;
						DrawSprite(&rcClient, box, hdc, mx, my);
					}
				}
				break;
			case VK_LEFT:
				{
					if (mapdata[my / 24][mx / 24 - 1] == 0)
					{
						GetClientRect(hWnd, &rcClient);

						mx -= 24;
						DrawSprite(&rcClient, box, hdc, mx, my);
					}
				}
				break;
			case VK_DOWN:
				{
					if (mapdata[my / 24 + 1][mx / 24] == 0)
					{
						GetClientRect(hWnd, &rcClient);

						my += 24;
						DrawSprite(&rcClient, box, hdc, mx, my);
					}
				}
				break;
			case VK_UP:
				{
					if (mapdata[my / 24 - 1][mx / 24] == 0)
					{
						GetClientRect(hWnd, &rcClient);

						my -= 24;
						DrawSprite(&rcClient, box, hdc, mx, my);
					}
				}
				break;
			}

			for (size_t y = 0; y < 28; y++)
		    {
				for (size_t x = 0; x < 22; x++)
				{
					if (mapdata[y][x] == 1)
					{
						HDC hdcMem = CreateCompatibleDC(hdc);
						HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, wall);

						BitBlt(hdc, x * 24, y * 24, 24, 24, hdcMem, 0, 0, SRCCOPY);

						SelectObject(hdcMem, hbmOld);
						DeleteDC(hdcMem);
					}
				}
			}

			ReleaseDC(hWnd, hdc);
		}
		break;
    case WM_DESTROY:

		DeleteObject(wall);
		DeleteObject(box);

        	PostQuitMessage(0);

        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
