#include "StdAfx.h"
#include "Welcome.h"


Welcome::Welcome(void) :alpha(1),index(0),dec(2),count(0)
{
		
}


Welcome::~Welcome(void)
{
		//delete BiliBeat;
		//delete Bmap;
}

BOOL Welcome::Initialize(){
		mWelcome=XWnd_CreateWindow(0,0,480,270,L"BiliBeat!");
		if(mWelcome){
				XWnd_SetIcon2(mWelcome,L"Resouce\\Icon\\BiliBeat.ico",true);
				XWnd_SetIcon2(mWelcome,L"Resouce\\Icon\\BiliBeat.ico",false);
				XWnd_SetTransparentFlag(mWelcome,XC_WIND_TRANSPARENT_SHAPED);
				XWnd_EnableMaxButton(mWelcome,false,true);
				XWnd_EnableCloseButton(mWelcome,false,true);
				XWnd_EnableMinButton(mWelcome,false,true);
				XWnd_SetBorderSize(mWelcome,0,0,0,0);
				XWnd_SetCaptionHeight(mWelcome,0);

				wchar_t buff[64];
				for(int i=0;i<22;i++){
						wsprintf(buff,L"%d.png",i+1);
						Anime[i]=XImage_LoadZip(L"Resouce\\Anime\\BiliBeat.dat",buff,NULL,false);
						XImage_EnableAutoDestroy(Anime[i],false);
				
				}
				XCGUI_RegWndMessage(mWelcome, WM_TIMER, & Welcome::AnimeTimer); 
				XWnd_SetTimer(mWelcome, 1, 10); 

				mciSendString(L"open Resouce\\Audio\\Welcome.mp3 alias wc", NULL, 0, NULL);
				mciSendString(L"play wc", NULL, 0, NULL);

				XWnd_ShowWindow(mWelcome,SW_SHOW);  
				SetWindowPos(XWnd_GetHWnd(mWelcome),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
				return true;
		}
		return false;
		
}

BOOL Welcome::AnimeTimer(HWINDOW hWindow, UINT_PTR nIDEvent, UINT uElapse){
		XWnd_SetImageNC(mWelcome,Anime[index]); 
		if(alpha<256)XWnd_SetTransparentAlpha(mWelcome,alpha); 
		XWnd_RedrawWnd(mWelcome,true);
		index=(index+1)%22;
		alpha+=dec;
		count++;
		if(count>360) dec=-3;
		if(alpha<=0){
				XWnd_KillTimer(mWelcome,1);
				mciSendString(L"close wc", NULL, 0, NULL);
				XWnd_KillTimer(mWelcome,1);
				XWnd_CloseWindow(mWelcome);
				launcher.Initialize();
		}
		if(GetForegroundWindow()==XWnd_GetHWnd(mWelcome)&&(GetKeyState(VK_RETURN)&0x80||GetKeyState(VK_LBUTTON)&0x80)){
				dec=-5;
		}
		return false;
}