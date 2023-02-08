using System.Reflection;
using static System.Net.Mime.MediaTypeNames;

/*
 * procedure ClickButton(WindowName, WindowCaption, ControlName, ControlCaption: String); 
Var hParent, hControl : HWND; 
Begin 
    hParent := 0; 
    hControl:= 0; 
    hParent:= FindWindow(pChar(WindowName), pChar(WindowCaption)); 
    Try 
        BringWindowToTop(hParent); 
        Application.ProcessMessages; 
        hControl:= FindWindowEx(hParent, 0, pChar(ControlName), pChar(ControlCaption)); 
        Try 
            SendMessage(hControl, BM_CLICK, 0,0); 
        Finally 
            hControl := 0; 
        End; 
    Finally hParent := 0; 
End;
// WindowName: The name of the form (eg: TForm1) 
// WindowCaption: The caption of the form (eg: Form1) 
// ControlName: The name of the control (eg: TButton) 
// ControlCaption: The text/caption of the control (eg: Ok)
Procedure Button2Click(Sender: TObject);
Begin
    ClickButton('TForm1', 'Form1', 'TSpeedbutton', '');
End;
*/
[DllImport("user32.dll")]

static extern IntPtr SendMessage(IntPtr hWnd, int msg, IntPtr wParam, IntPtr lParam);

...

Button myButton = ...;

const int BM_CLICK = 0x00F5;

SendMessage(myButton.Handle, BM_CLICK, IntPtr.Zero, IntPtr.Zero);

This code will click a command button in another program using standard Windows API calls.

This example clicks the "Open" button that appears in Internet Explorer when you try to open and executable, script, batch file, etc.

#include <windows.h>

int main()

{

//create two structures to hold our Main Window handle

//and the Button's handle

HWND WindowHandle;

HWND ButtonHandle;

//this window's caption is "File Download", so we search for it's handle using the FindWindow API

WindowHandle = FindWindow(NULL, "File Download");

//the Button's Caption is "Open" and it is a "Button". SPYXX.exe that comes with Microsoft Visual Studio will reveal this information to you

ButtonHandle = FindWindowEx(WindowHandle, 0, "Button", "&Open");

//send a message to the button that you are "clicking" it. Surprisingly C++ understands what BM_CLICK is without having to set it. Different than VB

SendMessage (ButtonHandle, BM_CLICK, 0 , 0);

return 0;

}

Here is something similar, but it will click the 'Start' button.

#include <windows.h>

void OpenStart(bool Open);

int main()

{

OpenStart (true);

return 0;

}

void OpenStart(bool Open)

{

if (Open == true)

{

HWND TaskBar, Start;

TaskBar = FindWindow("Shell_Traywnd",NULL);

Start = FindWindowEx(TaskBar,0,"Button",NULL);

PostMessage(Start,BM_CLICK,0,0);

}


}