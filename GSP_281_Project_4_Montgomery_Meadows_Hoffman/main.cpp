/*
  Names: Matthew Montgomery
  Date: 5/30/12
  File: fov.cpp
  Week #4 Assignment

  Purpose:
  
*/

#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <map>
#include "Vector2.h"
#include "resource.h"
#include "Sprite.h"
#include "Line.h"
#include "CollisionManager.h"
#include "MouseInput.h"
// your path for this include may vary
#include "GraphicsFramework.h"
#include "Particle.h"
#include <sstream>
//#define  _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <MMSystem.h>
#include "ObjectManager.h"
#include "GameLogic.h"
#include "Timer.h"
#include "Interface.h"
#include "GlobalData.h"
#include "Random.h"
#include <CommCtrl.h>
#include <fstream>
// Global variable to store the graphics framwork object
extern GraphicsFramework* PGraphics;
HWND HOutput = 0;  // handle to the output control
HWND HDialog = 0;
//If the Program needs to quit.
bool quit = false;

GlobalData runSimulation() {
	//
}

#define FRAND (rand()/((float)RAND_MAX))
#include <map>
class SA { // simulated annealing
public:
	class neighborident {
	public:
		int flags[3];
		
		neighborident(int p0,int p1,int p2) {
			flags[0] = p0;
			flags[1] = p1;
			flags[2] = p2;
		}
		
		int& operator[](int l) {
			flags[l];
		}
		bool operator<(neighborident &l) {
			return (*this)[0] < l[0] && (*this)[1] < l[1] && (*this)[2] < l[2];
		}
	};

	class neighbor {
	public:
		GlobalData data;
		
		neighborident getIdent() {
			return neighborident(data.cook_num,data.waiter_num,data.table_num);
		}
	};
	
	typedef std::map<neighborident,neighbor> DATACONT;
	DATACONT data;

	SA() {
		//
	}

	~SA() {
		//
	}

	void simulate(float maxtemp,int numiterations) {
		//
	}
};

//Converts a number to a string
std::string NumberToString(float x)
{
	std::stringstream out;
	out << x;
	return out.str();
}
void BeginSimulation(void)
{
	char str[32];
	int brokenTime,
		FixedTime,
		TechCount,
		RunTime;
	float DiscardDataTime;
	HWND progressbar = GetDlgItem(HDialog,IDC_PROGRESS1);
	//Accept User Input
	GetDlgItemText(HDialog, IDC_EDIT1, str, 32);
	brokenTime = atoi(str);
	if(brokenTime == NULL)
		brokenTime = 8;
	
	GetDlgItemText(HDialog, IDC_EDIT2, str, 32);
	FixedTime = atoi(str);
	if(FixedTime == NULL)
		FixedTime = 30;
	
	GetDlgItemText(HDialog, IDC_EDIT4, str, 32);
	TechCount = atoi(str);
	if(TechCount == NULL)
		TechCount = 10;
	
	GetDlgItemText(HDialog, IDC_EDIT5, str, 32);
	RunTime = atoi(str);
	if(RunTime == NULL || RunTime <= 2)
	{
		RunTime = 2;
		SetDlgItemText(HDialog, IDC_EDIT5,(LPCSTR)"2");
	}
	DiscardDataTime = 1;
	DiscardDataTime *= 120000;
	bool exit = false;
	RECT rect;
	GameLogic GL;
	RECT rect2;
	int wdRect;
	GetClientRect(HOutput, &rect);
	wdRect = rect.right - rect.left;
	rect2.left = -wdRect / 2;
	rect2.right =  wdRect / 2;
	wdRect = rect.bottom - rect.top;
	rect2.bottom = -(wdRect/2);
	rect2.top = -rect2.bottom;
	RAND->Set((float)time(NULL));
	GL.Init(5,10,4,2,3,1,2);
	float temp = 0;
	SendMessage(progressbar,PBM_SETRANGE,0,MAKELPARAM(0,100));
	SendMessage(progressbar,PBM_SETSTEP,(WPARAM) 1, 0);
	SendMessage(progressbar,PBM_SETBARCOLOR,(WPARAM) 0,MAKELPARAM(0,RGB(255,0,0)));
	//SendDlgItemMessage(progressbar,IDC_PROGRESS1,PBM_SETRANGE,0,100);
	//SendDlgItemMessage(progressbar,IDC_PROGRESS1,PBM_SETBARCOLOR,0,RGB(0,255,0));
	SendDlgItemMessage(progressbar,IDC_PROGRESS1,PBM_SETSTATE,PBST_NORMAL,0);
	SendDlgItemMessage(progressbar,IDC_PROGRESS1,PBM_SETMARQUEE,1,0);
	//SendDlgItemMessage(progressbar,IDC_PROGRESS1,PBM_SETSTEP,10,0);
	//SendMessage(progressbar,PBM_STEPIT,0,0);
	MS->ResetClock();
	int temp1;
	//11 hours a day 7 days a week for 30 days in minutes
	int MaxRunTime = 138600;
	float HasDiscarded = false;
	while(MS->GetClock() < 138600)
	{
		if(!HasDiscarded && MS->GetClock() >= DiscardDataTime)
		{
			//GD->Reset();
			HasDiscarded = true;
		}
		if((int)temp < (int)((MS->GetClock() / 138600)*100.0f))
		{
			SendMessage(progressbar,PBM_STEPIT,0,0);
			temp = (float)MS->GetClock() / 138600 * 100.0f;
		}
		GL.Update(.016f);
		GL.Draw();
		temp1 = (int)MS->GetClock();
	}
	//AM->Complete();
	OM->Clear();
	AM->Clear();
}
void CalculateSimulation(void)
{
	fstream outfile;
	outfile.open("myfile.txt");
	//outfile << *GD;
	outfile.close( );
}
/*
DialogProc
this is the window event handler for the main dialog
*/
BOOL CALLBACK DialogProc (HWND hwnd, 
    UINT message, 
    WPARAM wParam, 
    LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
        // dialog is initializing - store the picture box handle in a global variable for later
        HOutput = GetDlgItem(hwnd, IDC_PICTURE_OUTPUT);        

        // instantiate and initialize our graphics framework object
        PGraphics = new GraphicsFramework(HOutput);

        break;

    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
            case IDC_BTN_DRAW:
				//GetDlgItems which sets up the variables


                BeginSimulation();
				CalculateSimulation();
				Beep(500, 200);
				system("myfile.txt");
                break;
            case IDC_BTN_CLEAR:
                // clear button was pressed so clear the scene and draw the empty scene
                PGraphics->ClearScene(RGB(0, 0, 0));
                PGraphics->Draw();
                break;
            case IDCANCEL:
                // user is quitting so release the GraphicsFramework object and quit
                delete PGraphics;
				quit = true;
                PostQuitMessage(0);
                break;
        }
                  
    }
    return FALSE;
}

// this is the main function that starts the application
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, char * cmdParam, int cmdShow)
{
	// create the main window
    // store its handle in a global if needed
    HDialog = CreateDialog (GetModuleHandle(NULL), 
        MAKEINTRESOURCE(IDD_DIALOG1), 
        0, 
        DialogProc);

    // make the dialog visible
    ShowWindow(HDialog, SW_SHOW);
	SetDlgItemText(HDialog,IDC_STATIC1,(LPCSTR)"Broken Time(Hours)");
	SetDlgItemText(HDialog,IDC_STATIC2,(LPCSTR)"Fix Time(Mins)");
	SetDlgItemText(HDialog,IDC_STATIC3,(LPCSTR)"How Many Techs");
	SetDlgItemText(HDialog,IDC_STATIC4,(LPCSTR)"How Long In Years");
	SetDlgItemText(HDialog,IDC_EDIT1,(LPCSTR)"8");
	SetDlgItemText(HDialog,IDC_EDIT2,(LPCSTR)"30");
	SetDlgItemText(HDialog,IDC_EDIT4,(LPCSTR)"10");
	SetDlgItemText(HDialog,IDC_EDIT5,(LPCSTR)"2");
    // standard windows message loop
    MSG  msg;
    int status;
	//Loading the Textures
	OM->Init();

	//Setting up the Mouse
	Minput = new MouseInput();
	//The Window Rect
	RECT rect;
	Timer timer;
	//Run Thourgh the message to set up the window
	for(int i = 0; i < 10; ++i)
	{
		status = PeekMessage (&msg, 0, 0, 0,PM_REMOVE);
		if(status == -1)
			return -1;
		//If there is no message then the button has yet to be pressed.
		if(status == 0)
			Minput->ButtonClick = 0x0000;
		//Getting the Client Rect
		GetClientRect(HOutput,&rect);

		//Flip the Y coordnates of the mouse then position it at the center of the screen. 
		Minput->coord.y = (float)-msg.pt.y + rect.bottom/2 + 40;
		//Reposition the X coordnites of the mouse.
		Minput->coord.x = (float)msg.pt.x - rect.right/2;
		// avoid processing messages for the dialog
        if (!IsDialogMessage (HDialog, & msg))
        {
            TranslateMessage ( & msg );
            DispatchMessage ( & msg );
        }
	}
	//The Game will continue to loop as long as the right mouse click hasnt been pressed
    while (!quit)
    {
		//Draw Everything
		//Peek at the Message GetMessage waits for a message while peek doesnt.
		//If there is no message it returns 0;
		status = GetMessage (&msg, 0, 0, 0);
		if(status == -1)
			return -1;
		//Getting the Client Rect
		GetClientRect(HOutput,&rect);

		// avoid processing messages for the dialog
        if (!IsDialogMessage (HDialog, & msg))
        {
            TranslateMessage ( & msg );
            DispatchMessage ( & msg );
        }
    }
	//delete Minput;
	//delete OM;
	//delete PGraphics;

    return 1;
}