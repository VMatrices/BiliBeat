#include "StdAfx.h"
#include "Launcher.h"


Launcher::Launcher(void)
{
		GameEnd=false;
		Running=false;
}


Launcher::~Launcher(void)
{
}

bool Launcher::Initialize(){
		mLauncher=XWnd_CreateWindow(0,0,730,540,L"BiliBeat!");
		if(mLauncher){
				XWnd_SetIcon2(mLauncher,L"Resouce\\Icon\\BiliBeat.ico",true);
				XWnd_SetIcon2(mLauncher,L"Resouce\\Icon\\BiliBeat.ico",false);
				XWnd_SetBkColor(mLauncher,RGB(0,0,0));
				XWnd_SetImageNC(mLauncher,XImage_LoadFile(L"Resouce\\Image\\UI\\bk_launcher.png",true));
				XWnd_SetTransparentFlag(mLauncher,XC_WIND_TRANSPARENT_SHAPED);
				XWnd_EnableRound(mLauncher,false);
				XWnd_EnableMaxButton(mLauncher,false,true);
				XWnd_EnableCloseButton(mLauncher,false,true);
				XWnd_EnableMinButton(mLauncher,false,true);
				XWnd_SetBorderSize(mLauncher,0,0,0,0);
				XWnd_SetCaptionHeight(mLauncher,0);
				XWnd_EnableDragWindow(mLauncher,true);

				HELE topTitle=XStatic_Create(5,3,80,24,L"BiliBeat!",mLauncher);
				XEle_SetTextColor(topTitle,RGB(255,255,255));
				XEle_SetFont(topTitle,XFont_Create2(L"微软雅黑",24,0,1,0,0));
				XEle_SetBkTransparent(topTitle,true);

				btnClose=XBtn_Create(690,0,40,30,NULL,mLauncher);
				XEle_SetBkTransparent(btnClose,true);
				XBtn_SetImageLeave(btnClose,XImage_LoadFile(L"Resouce\\Image\\UI\\btn_close_unpress.png",true)); 
				XBtn_SetImageStay(btnClose,XImage_LoadFile(L"Resouce\\Image\\UI\\btn_close_press.png",true)); 
				XBtn_SetImageDown(btnClose,XImage_LoadFile(L"Resouce\\Image\\UI\\btn_close_press.png",true)); 
				XCGUI_RegEleEvent(btnClose, XE_BNCLICK, &Launcher::Launcher_Close); 

				for(int i=0;i<5;i++){
						wsprintf(buff,L"Resouce\\Image\\Intro\\%d.jpg",i+1);
						IntroImg[i]=XImage_LoadFile(buff,true);
						XImage_EnableAutoDestroy(IntroImg[i],false);
				}

				Intro=XEle_Create(20,45,340,340,mLauncher);
				XEle_EnableBorder(Intro,false);
				IntroPicA=XPic_Create(0,0,340,340,Intro);
				IntroPicB=XPic_Create(0,0,340,340,Intro);
				XPic_SetImage(IntroPicB,IntroImg[0]);

				AnimePic=XGif_Create(5,395,360,140,mLauncher);
				XGif_SetImage(AnimePic,L"Resouce\\Image\\UI\\bilibeat.gif");
				XEle_EnableBorder(AnimePic,false);

				MusicList=XSView_Create(370,70,355,465,mLauncher);
				XSView_SetScrollSize(MusicList,0,10);
				XEle_EnableBorder(MusicList,false);
				XEle_SetBkTransparent(MusicList,true);
				XEle_SetBkTransparent(XSView_GetView(MusicList),true);
																												
				HELE MusicTitle=XStatic_Create(372,40,350,25,L"BeatMap List",mLauncher);
				XEle_SetTextColor(MusicTitle,RGB(100,150,100));
				XEle_SetBkColor(MusicTitle,RGB(50,50,50));
				XEle_SetFont(MusicTitle,XFont_Create2(L"微软雅黑",22,1,0,0,0));
				XStatic_SetTextAlign(MusicTitle,1);
				//XEle_SetBkTransparent(MusicTitle,true);
				
				XSBar_EnableScrollButton2(XSView_GetVScrollBar(MusicList),false); 
				XSBar_SetImage(XSView_GetVScrollBar(MusicList),XImage_LoadFile(L"Resouce\\Image\\UI\\SlideBar1.png",true));
				XSBar_SetImageLeaveSlider(XSView_GetVScrollBar(MusicList),XImage_LoadFile(L"Resouce\\Image\\UI\\SlideBar2.png",true)); 
				XSBar_SetImageStaySlider(XSView_GetVScrollBar(MusicList),XImage_LoadFile(L"Resouce\\Image\\UI\\SlideBar2.png",true)); 
				XSBar_SetImageDownSlider(XSView_GetVScrollBar(MusicList),XImage_LoadFile(L"Resouce\\Image\\UI\\SlideBar2.png",true)); 
				XEle_EnableBorder(XSView_GetVScrollBar(MusicList),false);
			
				GetDir(); 
				XSView_SetSize(MusicList,335,100*(Bmap.size()>5?Bmap.size():5));

				for(int i=0;i<Bmap.size();i++){
						MusicItem[i]=XEle_Create(0,i*100,330,100,MusicList);
						XEle_EnableBorder(MusicItem[i],false);
						XEle_SetBkTransparent(MusicItem[i],true);

						wsprintf(buff,L"BeatMap\\%s\\cover.jpg",Bmap[i]->path);
						HELE cover=XPic_Create(10,10,80,80,MusicItem[i]);
						XPic_SetImage(cover,XImage_LoadFile(buff,true));

						wsprintf(buff,L"%S",Bmap[i]->name.c_str());
						HELE title=XStatic_Create(102,2,220,32,buff,MusicItem[i]);
						XEle_SetTextColor(title,RGB(255,255,255));
						XEle_SetFont(title,XFont_Create2(L"微软雅黑",30,0,0,0,0));
						XEle_SetBkTransparent(title,true);

						wsprintf(buff,L"%S",Bmap[i]->describe.c_str());
						HELE describe=XStatic_Create(102,32,220,22,buff,MusicItem[i]);
						XEle_SetTextColor(describe,RGB(150,150,150));
						XEle_SetFont(describe,XFont_Create2(L"微软雅黑",20,0,0,0,0));
						XEle_SetBkTransparent(describe,true);

						string levelStar="";
						int x=Bmap[i]->level;
						while(x--)levelStar+="★ ";
						wsprintf(buff,L"Level %S",levelStar.c_str());
						//wsprintf(buff,L"Level %C",char('A'-1+Bmap[i]->level));
						HELE level=XStatic_Create(102,52,220,22,buff,MusicItem[i]);
						XEle_SetTextColor(level,RGB(200,200,200));
						XEle_SetFont(level,XFont_Create2(L"微软雅黑",20,0,0,0,0));
						XEle_SetBkTransparent(level,true);

						swprintf(buff,L"Time %0.1f min",double(Bmap[i]->range.end/600.0));
						HELE time=XStatic_Create(102,74,220,20,buff,MusicItem[i]);
						XEle_SetTextColor(time,RGB(150,150,150));
						XEle_SetFont(time,XFont_Create2(L"微软雅黑",18,0,0,0,0));
						XEle_SetBkTransparent(time,true);

						MusicItemBtn[i]=XRadio_Create(-1,-1,332,102,NULL,MusicItem[i]);	 //大一圈，隐藏选中后的虚线框
						XEle_SetBkTransparent(MusicItemBtn[i],true);
						XRadio_SetImageLeave_UnCheck(MusicItemBtn[i],XImage_LoadFile(L"Resouce\\Image\\UI\\Item0.png",true));
						XRadio_SetImageStay_UnCheck(MusicItemBtn[i],XImage_LoadFile(L"Resouce\\Image\\UI\\Item1.png",true));
						XRadio_SetImageStay_Check(MusicItemBtn[i],XImage_LoadFile(L"Resouce\\Image\\UI\\Item1.png",true));
						XRadio_SetImageDown_Check(MusicItemBtn[i],XImage_LoadFile(L"Resouce\\Image\\UI\\Item2.png",true));
						XRadio_SetImageDown_UnCheck(MusicItemBtn[i],XImage_LoadFile(L"Resouce\\Image\\UI\\Item2.png",true));
						XRadio_SetImageLeave_Check(MusicItemBtn[i],XImage_LoadFile(L"Resouce\\Image\\UI\\Item0.png",true));
					
						XRadio_SetGroupID(MusicItemBtn[i],i);		 //通过单选按钮、滚动图示、基础元素实现富内容列表，组ID用来标记列表元素ID
						XCGUI_RegEleEvent(MusicItemBtn[i],XE_BNCLICK,&Launcher::Music_Select);
				}
				XWnd_ShowWindow(mLauncher,true);
				XCGUI_RegWndMessage(mLauncher, WM_TIMER, &Launcher::LauncherTimer); 

				XWnd_SetTimer(mLauncher, 1,15); 
				return true;
		}
		return false;
}

void Launcher::GetDir() 
{  
		long   hFile= 0;  
		struct _finddata_t fileinfo; 
		if((hFile=_findfirst("BeatMap\\*",&fileinfo)) != -1){  
				do{   
						if((fileinfo.attrib &  _A_SUBDIR)){  
								if(strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0){
										wsprintf(buff,L"%S",fileinfo.name);
										BeatMapRes *tmp=new BeatMapRes(buff);
										if(!tmp->ReadCfg()){
												MessageBox(NULL,TEXT("BeatMap配置文件解析失败！\n请检查文件是否受损。"),TEXT("BiliBeat!"),MB_OK);
												delete tmp;
												exit(1);
										} else {
												Bmap.push_back(tmp);
										}
								}
						}  
				}while(_findnext(hFile, &fileinfo)  == 0); 
				_findclose(hFile); 
		} 
}

bool Launcher::Music_Select(HELE hEle,HELE hEventEle){
		RunID=XRadio_GetGroupID(hEventEle);
		GW=new GAME_WINDOWS(Bmap[RunID],&GameEnd);
		GameEnd=false;
		XWnd_ShowWindow(mLauncher,SW_HIDE);
		if(GW->Initialize()){
				Running=true;
				return true;
		}
		return false;
}

bool Launcher::LauncherTimer(HWINDOW hWindow, UINT_PTR nIDEvent, UINT uElapse){
		static int index=4;
		static int tm=0;
		const int dx[4]={-10,0,10,0};
		const int dy[4]={-0,-10,0,10};	 
		const RECT drc[4]={{0,340,340,680},{-340,0,0,340},{0,-340,340,0},{340,0,680,340}};
		if(!Running){
				RECT rc,_rc;
				XEle_GetRect(IntroPicB,&rc);
				if(rc.left!=0||rc.right!=340||rc.top!=0||rc.right!=340){
						rc.left+=dx[index%4];
						rc.right+=dx[index%4];
						rc.top+=dy[index%4];
						rc.bottom+=dy[index%4];
						XEle_SetRect(IntroPicB,&rc);
				} else {
						tm++;
						if(tm>80){
								_rc=drc[index%4];
								XPic_SetImage(IntroPicA,IntroImg[(index+1)%5]);
								XPic_SetImage(IntroPicB,IntroImg[(index+2)%5]);
								XEle_SetRect(IntroPicB,&_rc);
								index++;
								tm=0;
						}
				}
				XEle_RedrawEle(Intro,true);
		}
		if(GameEnd){							  
				delete GW;
				Bmap[RunID]->clear();
				XWnd_ShowWindow(mLauncher,SW_SHOW);
				GameEnd=false;
				Running=false;
		}
		
		return true;
}

bool Launcher::Launcher_Close(HELE hEle,HELE hEventEle)
{
		XWnd_CloseWindow(mLauncher);
		return false;
}
