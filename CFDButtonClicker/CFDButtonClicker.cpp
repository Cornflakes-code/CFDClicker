// CFDButtonClicker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// https://sites.google.com/site/wodeap/cheng-shi-qing-dan/apptips/use-api-to-programmatically-click-button-of-another-app?pli=1


#include <windows.h>
void clickButton(const LPCWSTR window, const LPCWSTR subWindowClass, const LPCWSTR subWindow)
{
	HWND WindowHandle = FindWindow(window, NULL);
	// the Button's Caption is "Open" and it is a "Button". 
	// SPYXX.exe that comes with Microsoft Visual Studio will reveal this information to you
	HWND ButtonHandle = FindWindowEx(WindowHandle, 0, subWindowClass, subWindow);
	// send a message to the button that you are "clicking" it. 
	// Surprisingly C++ understands what BM_CLICK is without having to set it.
	SendMessage(ButtonHandle, BM_CLICK, 0, 0);
}

void downUpButton(const LPCWSTR windowClass, const LPCWSTR window, 
				  const LPCWSTR subWindowClass, const LPCWSTR subWindow,
				  WPARAM w, LPARAM l)
{
	HWND WindowHandle = FindWindow(windowClass, window);
	// the Button's Caption is "Open" and it is a "Button". 
	// SPYXX.exe that comes with Microsoft Visual Studio will reveal this information to you
	HWND ButtonHandle = FindWindowEx(WindowHandle, 0, subWindowClass, subWindow);
	// send a message to the button that you are "clicking" it. 
	// Surprisingly C++ understands what BM_CLICK is without having to set it.
	LRESULT res = 0;
	res = SendMessage(ButtonHandle, WM_MOUSEACTIVATE, MA_ACTIVATE, 0);
	//res = SendMessage(ButtonHandle, WM_MOUSEACTIVATE, WM_LBUTTONDOWN, 0);
	res = SendMessage(ButtonHandle, WM_LBUTTONDOWN, MK_LBUTTON, l);
	::SleepEx(1000, false);
	res = SendMessage(ButtonHandle, WM_LBUTTONUP, MK_LBUTTON, l);
	if (res)
		res = 0;
}

//Here is something similar, but it will click the 'Start' button.
void OpenStart(bool Open)
{
	if (Open == true)
	{
		HWND TaskBar, Start;
		TaskBar = FindWindow(L"Shell_Traywnd", NULL);
		Start = FindWindowEx(TaskBar, 0, L"Start", NULL);
		LRESULT res = SendMessage(Start, WM_LBUTTONDOWN, MK_LBUTTON, 0);
		::SleepEx(1000, false);
		res = SendMessage(Start, WM_LBUTTONUP, MK_LBUTTON, 0);
		if (res)
			res = 0;
	}
}

int main()
{
	int x = 10; // X coordinate of the click
	int y = 11; // Y coordinate of the click

	WPARAM wParam = 0;
	LPARAM lParam = (y << 16) | x;
	//downUpButton(L"Notepad", L"Untitled - Notepad", L"Edit", 0, 0, 0);
	downUpButton(L"Shell_Traywnd", 0, L"Start", 0, wParam, lParam);
	//downUpButton(L"WinMergeWindowClassW", 0, L"ReBarWindow32", 0, wParam, lParam);

	// OpenStart(true);
	return 0;
}


