#include "StdAfx.h"
#include "GAME_WINDOWS.h"

GAME_WINDOWS::GAME_WINDOWS(BeatMapRes *bmap,bool *GameEnd):Bmap(bmap),GameEnd(GameEnd),FPS_Speed(1000.0/DEFAULT_FPS),BK_Speed(1000.0/BK_ANIME_FPS),SE_Speed(1000.0/SE_ANIME_FPS),Ball_Speed(1000.0/BALL_ANIME_FPS)
{
		LoadData_Process=Game_Process=WatchKey_Process=DanmuTip_Process=Music_Process=NULL;
		ExitCode=false;
		p1=p2=p3=p4=false;

}

GAME_WINDOWS::~GAME_WINDOWS(void)
{
		ExitCode=true;
		Sleep(100);
		int n=Bmap->n;
		while(n--){
				Bmap->Release(n);
		}
}

bool GAME_WINDOWS::Initialize(){
		mWindow = XWnd_CreateWindow(0, 0, 600,100, L"Loading...");
		if(mWindow){

				/********************MAIN_WINDWOS_BEGIN**********************/
				XWnd_EnableRound(mWindow,true,true);
				XWnd_SetIcon2(mWindow,L"Resouce\\Icon\\BiliBeat.ico",true);
				XWnd_EnableMaxButton(mWindow,false,true);
				XWnd_EnableCloseButton(mWindow,false,true);
				XWnd_EnableMinButton(mWindow,false,true);
				XWnd_SetBorderSize(mWindow,0,0,0,0);
				XWnd_ShowWindow(mWindow, SW_MINIMIZE);
				XWnd_SetCaptionHeight(mWindow,0);

				mload=XProgBar_Create(0,0,600,100,true,mWindow);
				XProgBar_SetImage (mload,XImage_LoadFile(L"Resouce\\Image\\UI\\unload.png",false));
				XProgBar_SetImage2(mload,XImage_LoadFile(L"Resouce\\Image\\UI\\loaded.png",false));
				XProgBar_SetPos(mload,0);
				XWnd_ShowWindow(mWindow,true);
				SetWindowPos(XWnd_GetHWnd(mWindow),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
				LoadData_Process=CreateThread(NULL,0,GAME_WINDOWS::Load_Data,this,0,NULL);
				CloseHandle(LoadData_Process);
				/********************MAIN_WINDWOS_END************************/

				gWindow = XWnd_CreateWindow(0, 0, 960, 540, L"BiliBeat!");
				//XCGUI_RegWndMessage(gWindow, WM_CLOSE, &GAME_WINDOWS::Quit);

				return true;
		}
		return false;
}

bool GAME_WINDOWS::Quit(HWINDOW hWindow){
		//TODO
		return false;
}

DWORD WINAPI GAME_WINDOWS::Game_Draw(LPVOID pParam){
		GAME_WINDOWS *GW= (GAME_WINDOWS*)pParam;
		double _time;
		wchar_t buff[128];
		RECT rc1,rc2,rc,_rc;
		double ps=72.0/4,Ball_v=20,G=10;
		double half_H=GW->Bmap->phy[2].V*GW->Bmap->phy[2].V/(3.0*GW->Bmap->phy[2].G);
		bool reJump=false,setNew=false;
		const int Pillar_H[5]={418,338,258,178,98};	 //地图高度常量
		bool jump_two=false,jump_dec=false;
		bool over=false;
		bool stop=false;
		bool light=true;
		bool NowLoading=false;
		while(!GW->ExitCode){
				if(!GW->GamePause){
						if(!GW->BK_Pause){
								/********************开始画面*******************/
								if(!GW->Begin_showed&&GW->Begin_tm.get()>20){
										GW->Begin_alpha-=2;
										if(GW->Begin_alpha<=0){
												GW->Begin_alpha=0;
												GW->Begin_showed=true;
												GW->Music_play=1;
												GW->Music_play_send=true;
												GW->Music_tm.reset();
												GW->Music_tm.start();
										}
										GW->Begin_tm.reset();
										GW->Begin_tm.start();
								}

								/********************计算动画背景*******************/
								if(GW->BK_Anime_tm.get()>GW->BK_Speed){
										GW->BK_Anime_index++;
										GW->BK_Anime_index=GW->BK_Anime_index%GW->Bmap->anime[0].n;
										GW->BK_Anime_tm.reset();
										GW->BK_Anime_tm.start();
								}

								/******************计算滚滚动背景1****************/
								if(GW->BK_Loop1_tm.get()>100){
										rc1=GW->BK_Loop1_1_pos;
										rc2=GW->BK_Loop1_2_pos;
										const int step=2;
										rc1.left-=step;rc1.right-=step;
										rc2.left-=step;rc2.right-=step;
										if(rc1.left<=0&&rc2.right<0){
												rc2.left=rc1.right,rc2.right=rc2.left+960;
										} else 
												if(rc2.left<=0&&rc1.right<0){
														rc1.left=rc2.right,rc1.right=rc1.left+960;
												}
												GW->BK_Loop1_1_pos=rc1;
												GW->BK_Loop1_2_pos=rc2;
												GW->BK_Loop1_Alpha=GW->BK_Loop1_Alpha+GW->BK_Loop1_Alpha_Dec;
												if(GW->BK_Loop1_Alpha<20||GW->BK_Loop1_Alpha>230)GW->BK_Loop1_Alpha_Dec*=-1;

												GW->BK_Loop1_tm.reset();
												GW->BK_Loop1_tm.start();
								}

								/******************计算滚滚动背景2****************/
								if(GW->BK_Loop2_tm.get()>50){
										rc1=GW->BK_Loop2_1_pos;
										rc2=GW->BK_Loop2_2_pos;
										const int step=3;
										rc1.left-=step;rc1.right-=step;
										rc2.left-=step;rc2.right-=step;
										if(rc1.left<=0&&rc2.right<0){
												rc2.left=rc1.right,rc2.right=rc2.left+960;
										} else 
												if(rc2.left<=0&&rc1.right<0){
														rc1.left=rc2.right,rc1.right=rc1.left+960;
												}
												GW->BK_Loop2_1_pos=rc1;
												GW->BK_Loop2_2_pos=rc2;
												GW->BK_Loop2_Alpha=GW->BK_Loop2_Alpha+GW->BK_Loop2_Alpha_Dec;
												if(GW->BK_Loop2_Alpha<20||GW->BK_Loop2_Alpha>230)GW->BK_Loop2_Alpha_Dec*=-1;
												GW->BK_Loop2_tm.reset();
												GW->BK_Loop2_tm.start();
								}
						}

						/********************计算球动画*******************/
						if(GW->Ball_Anime_tm.get()>GW->Ball_Speed){//
								GW->Ball_Anime_index++;
								GW->Ball_Anime_index=GW->Ball_Anime_index%BALL_ANIME_NUM;
								GW->Ball_Anime_tm.reset();						
								GW->Ball_Anime_tm.start();
						}

						/*****************绘制球体圆柱运动****************/
						_time=GW->Ball_Move_tm.get()/100.0;
						rc=GW->Pillar_pos[GW->Pillar_index];	 

						rc.left=(-ps*_time+(jump_dec?72:0));		//负责根据球的落地时间移动地图
						rc.right=rc.left+72;
						GW->Pillar_pos[GW->Pillar_index]=rc;

						for(int i=1;i<15;i++){
								_rc=GW->Pillar_pos[(GW->Pillar_index+i)%15];
								_rc.left=rc.left+i*72,_rc.right=rc.right+i*72;
								GW->Pillar_pos[(GW->Pillar_index+i)%15]=_rc;	
						}

						int Fall_index=(GW->Pillar_index+4)%15;		  //负责小球的重力效果
						double Dtime,v=Ball_v-G*_time;
						rc=GW->Ball_pos;
						double h=Ball_v*_time-0.5*G*_time*_time;
						GW->Ball_Fall=v>0?false:true;

						if((!GW->Ball_Fall&&h>half_H)||(GW->Ball_Fall)){   //判断当前时段是否允许跳跃
								GW->Ball_AllowHit=true;
						} else {
								GW->Ball_AllowHit=false;
						}

						if(!GW->Tip_Tap_show&&((((!GW->Ball_Fall&&h>20)||(GW->Ball_Fall))&&GW->Pillar_State[Fall_index].type<GW->Pillar_State[(Fall_index+1)%15].type)||GW->Pillar_State[(Fall_index+1)%15].color==6)){ //Tap提示
								GW->Tip_Add_img=GW->Tip_Tap;
								GW->Tip_Add_dec=12;
								GW->Tip_Add_y=(rc.top-300)<0?0:(rc.top-300);
								GW->Tip_Add=true;
								GW->Tip_Tap_show=true;
						}

						if(!GW->Tip_Miss_show&&over&&GW->Ball_Fall){		  //Miss提示
								if(!GW->End_end)GW->Score-=50;
								GW->Tip_Add_img=GW->Tip_Miss;
								GW->Tip_Add_dec=10;
								GW->Tip_Add_y=rc.top>220?220:(rc.top-100);
								GW->Tip_Add=true;
								GW->Tip_Miss_show=true;
								GW->Hited_num=0;
						}

						rc.top=Pillar_H[GW->Pillar_State[GW->Pillar_Hit_index].type]-h;
						rc.bottom=Pillar_H[GW->Pillar_State[GW->Pillar_Hit_index].type]+72-h;

						if(rc.top>540){		//从天而降的球球酱
								over=false;
								rc.top-=540;
								rc.bottom-=540;
								GW->Tip_Miss_show=false;
						}

						if(!over&&GW->Ball_Fall&&rc.top>Pillar_H[GW->Pillar_State[Fall_index].type]){
								GW->Tip_Tap_show=false;
								if(GW->AutoRun&&rand()%8){	 //自动演示模式																																
										if((GW->Pillar_State[Fall_index].type<GW->Pillar_State[(Fall_index+1)%15].type||GW->Pillar_State[(Fall_index+1)%15].color==6))	GW->Ball_Jump=true;	   //自动跳跃1倍速
										if(GW->AutoRun==2&&GW->Pillar_State[Fall_index].type>=GW->Pillar_State[(Fall_index+1)%15].type&&GW->Pillar_State[(Fall_index+2)%15].color!=6)	GW->Ball_Jump=true;	   //自动跳跃2倍速
								}

								if(GW->Ball_Jump&&(GW->Pillar_State[Fall_index].type<GW->Pillar_State[(Fall_index+1)%15].type||GW->Pillar_State[(Fall_index+1)%15].color==6)){
										GW->Hited_num++;
										if(GW->Hited_num>1&&!GW->End_end){				//唤起连击提示
												swprintf(buff,L"%d",GW->Hited_num>99?99:GW->Hited_num);
												XStatic_SetText(GW->Hit_show_count,buff);
												GW->Hit_board_alpha=255;
												XEle_ShowEle(GW->Hit_board,true);
										}
										if(GW->Hited_num>11){
												if(!GW->End_end)GW->Score+=100;
												GW->Tip_Add_img=GW->Tip_Perfect;	  //perfect 提示
												GW->Tip_Add_dec=1;
										} else if(GW->Hited_num>7){
												if(!GW->End_end)GW->Score+=75;
												GW->Tip_Add_img=GW->Tip_Nice;	   //nice提示
												GW->Tip_Add_dec=2;
										} else {
												if(!GW->End_end)GW->Score+=50;
												GW->Tip_Add_img=GW->Tip_Good;	 	//Good提示
												GW->Tip_Add_dec=3;
										}
										GW->Tip_Add_dec=3;
										GW->Tip_Add_y=(rc.top-200)<0?0:(rc.top-200);
										GW->Tip_Add=true;
								}
								GW->Pillar_Hit_index=Fall_index;

								/*********************跳跃计算部分***********************/
								if(GW->Ball_Jump&&GW->Pillar_State[Fall_index].color!=6){
										if(!GW->End_end)GW->Score+=2;
										if(GW->Pillar_State[Fall_index].type>=GW->Pillar_State[(Fall_index+2)%15].type&&GW->Pillar_State[Fall_index].type>=GW->Pillar_State[(Fall_index+1)%15].type){
												if(!GW->End_end)GW->Score+=11;
												Ball_v=GW->Bmap->phy[0].V;	   //100 50
												G=GW->Bmap->phy[0].G;
												Dtime=(Ball_v+sqrt(Ball_v*Ball_v+2.0*G*(Pillar_H[GW->Pillar_State[(Fall_index+2)%15].type]-Pillar_H[GW->Pillar_State[Fall_index].type])))/G;  //计算从当前点到下一次落地点的时间
												ps=72.0/Dtime*2;
												jump_two=true;
										} else {
												Ball_v=GW->Bmap->phy[1].V;		 //100 40
												G=GW->Bmap->phy[1].G;
												Dtime=(Ball_v+sqrt(Ball_v*Ball_v+2.0*G*(Pillar_H[GW->Pillar_State[(Fall_index+1)%15].type]-Pillar_H[GW->Pillar_State[Fall_index].type])))/G;  //计算从当前点到下一次落地点的时间
												ps=72.0/Dtime;
										}
								} else {
										Ball_v=GW->Bmap->phy[2].V;	  //60 30
										G=GW->Bmap->phy[2].G;
										Dtime=(Ball_v+sqrt(Ball_v*Ball_v+2.0*G*(Pillar_H[GW->Pillar_State[(Fall_index+1)%15].type]-Pillar_H[GW->Pillar_State[Fall_index].type])))/G;  //计算从当前点到下一次落地点的时间
										ps=72.0/Dtime;
										jump_two=false;
										if (GW->Pillar_State[Fall_index].color==6){ 								
												over=true;
												Ball_v=v;	   //100 50
												Dtime=(Ball_v+sqrt(Ball_v*Ball_v+2.0*G*(540-Pillar_H[GW->Pillar_State[Fall_index].type]+Pillar_H[GW->Pillar_State[(Fall_index+1)%15].type])))/G;
												ps=72.0/Dtime;
										} else if(GW->Pillar_State[Fall_index].type<GW->Pillar_State[(Fall_index+1)%15].type){
												over=true; 
												Dtime=(Ball_v+sqrt(Ball_v*Ball_v+2.0*G*(540-Pillar_H[GW->Pillar_State[Fall_index].type]+Pillar_H[GW->Pillar_State[(Fall_index+1)%15].type])))/G;
												ps=72.0/Dtime*2.0;
												jump_two=true;
										}
								}
								/***********************结束********************/

								GW->Ball_Jump=false;
								jump_dec=false;
								rc.top=Pillar_H[GW->Pillar_State[GW->Pillar_Hit_index].type];	   //修正落地偏差
								rc.bottom=rc.top+72;
								setNew=true;
								light=rand()%3;
								GW->Pillar_hited=true;
								GW->Pillar_hited_up=false;
								GW->Pillar_Hit_tm.reset();
								GW->Pillar_Hit_tm.start();
								GW->Ball_Move_tm.reset();
								GW->Ball_Move_tm.start();
						}
						GW->Ball_pos=rc;

						/*****************放置新生成的地图****************/
						rc=GW->Pillar_pos[GW->Pillar_index];
						if((jump_two&&rc.right<=0)||(setNew)){	
								GW->Pillar_index++;
								GW->Pillar_index%=15;
								int _index=(GW->Pillar_index+14)%15;  
								GW->Pillar_State[_index].type=0;
								/************************随机生成一定有解的地图***********************/
								if((GW->Music_tm.get()>(GW->Bmap->range.begin-60)*100.0)&&GW->Begin_showed){
										if(GW->Music_tm.get()>(GW->Bmap->range.end-50)*100.0) GW->AutoRun=3;
										if(GW->AutoRun!=3){
												if(GW->Pillar_State[(_index+14)%15].color==6){
														GW->Pillar_State[_index].type=rand()%(GW->Pillar_State[(_index+15)%15].type+1);
												} else {
														GW->Pillar_State[_index].type=rand()%(GW->Pillar_State[(_index+14)%15].type+2);
														if(GW->Pillar_State[_index].type>4) GW->Pillar_State[_index].type--;
												}
										}
										if(GW->Pillar_State[_index].type<=GW->Pillar_State[(_index+14)%15].type&&GW->Pillar_State[(_index+14)%15].color!=6){
												GW->Pillar_State[_index].color=rand()%7;
										} else {
												GW->Pillar_State[_index].color=rand()%6;
										}
								} else {
												GW->Pillar_State[_index].color=rand()%6;
								}
								rc=GW->Pillar_pos[_index];
								rc.top=Pillar_H[GW->Pillar_State[_index].type]+32;
								rc.bottom=rc.top+50;
								GW->Pillar_img[_index]=GW->Pillar_N_image[GW->Pillar_State[_index].color];
								GW->Pillar_img_change[_index]=true;
								GW->Pillar_pos[_index]=rc;
								if(!setNew&&jump_two){
										jump_two=false;
										jump_dec=true;
								}
								setNew=false;
						}

						/*****************绘制圆柱回弹运动****************/
						if(GW->Pillar_hited&&GW->Pillar_Hit_tm.get()>10&&GW->Pillar_State[GW->Pillar_Hit_index].color!=6){
								_rc=GW->Pillar_pos[GW->Pillar_Hit_index];
								const int step=2;
								if(GW->Pillar_hited_up){
										_rc.top-=step,_rc.bottom-=step;
										if(light){
												GW->BK_Loop2_Alpha-=12;
												if(GW->BK_Loop2_Alpha<20)GW->BK_Loop2_Alpha=20;
										} else {
												GW->BK_Loop1_Alpha-=6;
												if(GW->BK_Loop1_Alpha<20)GW->BK_Loop1_Alpha=20;
										}
								} else {
										_rc.top+=step,_rc.bottom+=step;
										if(light){
												GW->BK_Loop2_Alpha+=12;
												if(GW->BK_Loop2_Alpha>230)GW->BK_Loop2_Alpha=230;
										} else {
												GW->BK_Loop1_Alpha+=6;
												if(GW->BK_Loop1_Alpha>230)GW->BK_Loop1_Alpha=230;
										}
								}
								if(_rc.top>(Pillar_H[GW->Pillar_State[GW->Pillar_Hit_index].type]+32+12)) {
										GW->Pillar_hited_up=true;
										GW->Pillar_img[GW->Pillar_Hit_index]=GW->Pillar_L_image[GW->Pillar_State[GW->Pillar_Hit_index].color];
										GW->Pillar_img_change[GW->Pillar_Hit_index]=true;
								}
								GW->Pillar_Hit_tm.reset();
								if(_rc.top>(Pillar_H[GW->Pillar_State[GW->Pillar_Hit_index].type]+32)){
										GW->Pillar_Hit_tm.start();
								} else {
										GW->Pillar_hited=false;
								}
								GW->Pillar_pos[GW->Pillar_Hit_index]=_rc;
						}

						/*******************连击提示计算******************/
						if(GW->Hit_board_alpha>0&&GW->Hit_board_tm.get()>6){
								GW->Hit_board_alpha-=2;
								if(GW->Hit_board_alpha<=0){
										XEle_ShowEle(GW->Hit_board,false);
								}
								GW->Hit_board_tm.reset();
								GW->Hit_board_tm.start();
						}


						/*****************场景动画切换******************/
						if(GW->Scene_index<GW->Bmap->n){
								if(!GW->Bmap->loaded[GW->Scene_index]&&GW->Music_tm.get()>(GW->Bmap->anime[GW->Scene_index].l-30)*100.0){
										XStatic_SetText(GW->Time_show,L"数据载入中");
										NowLoading=true;
										GW->PauseGame(true,GW);
								}
								if(!GW->Scene_start&&GW->Music_tm.get()>(GW->Bmap->anime[GW->Scene_index].l)*100.0){						
										GW->Scene_start=true;
										GW->Scene_over=false;
										GW->SE_Anime_play=true;
										GW->SE_Alpha=0;
										GW->SE_Anime_index=0;
										XEle_ShowEle(GW->SE_Anime,true);
										GW->SE_Anime_tm.reset();
										GW->SE_Anime_tm.start();
										GW->SE_Switch_tm.reset();
										GW->SE_Switch_tm.start();
								}
								if(GW->Scene_start&&(!GW->BK_Pause)&&GW->SE_Switch_tm.get()>20){
										GW->SE_Alpha+=5;
										if(GW->SE_Alpha>=255){
												GW->SE_Alpha=255;
												GW->BK_Pause=true;						
										}
										GW->SE_Switch_tm.reset();
										GW->SE_Switch_tm.start();
								}
								if(!GW->Scene_over&&GW->Music_tm.get()>(GW->Bmap->anime[GW->Scene_index].r)*100.0){
										GW->Scene_over=true;
										GW->BK_Pause=false;
								}
								if(GW->Scene_over&&GW->SE_Switch_tm.get()>20){
										GW->SE_Alpha-=5;
										if(GW->SE_Alpha<=0){
												GW->SE_Alpha=0;
												GW->Scene_over=false;	
												GW->Scene_start=false;
												GW->BK_Pause=false;
												GW->SE_Anime_play=false;
												GW->Scene_index++;
												XEle_ShowEle(GW->SE_Anime,false);
										}
										GW->SE_Switch_tm.reset();
										GW->SE_Switch_tm.start();
								}
						}

						/*******************场景动画计算*****************/
						if(GW->SE_Anime_play&&GW->SE_Anime_tm.get()>GW->SE_Speed){
								GW->SE_Anime_index++;
								GW->SE_Anime_index=GW->SE_Anime_index%GW->Bmap->anime[GW->Scene_index].n;
								GW->SE_Anime_tm.reset();
								GW->SE_Anime_tm.start();
						}

						/*******************游戏结束处理部分****************/
						if(!GW->End_end&&((GW->Music_tm.get()>(GW->Bmap->range.end+30)*100.0)||GW->Score<=0)){
								if(GW->Score<=0){
										GW->Score=0;
										XStatic_SetText(GW->End_score,L"GAME OVER");
								}
								GW->AutoRun=2;
								GW->End_end=true;
								GW->End_score_show=false;
								GW->Music_tm.pause();
								GW->End_Alpha=0;
								XEle_ShowEle(GW->End_board,true);
						}
						if(!GW->End_score_show&&GW->End_end&&GW->End_tm.get()>15){
								GW->End_Alpha+=1;
								if(GW->End_Alpha>=255){
										GW->End_Alpha=255;
										GW->End_score_show=true;
										int level=GW->Score/GW->Bmap->band;
										for(int i=0;i<5;i++){
												if(i<level){
														XPic_SetImage(GW->End_star[i],GW->End_img_star1);
												} else {
														XPic_SetImage(GW->End_star[i],GW->End_img_star2);
												}
												XEle_ShowEle(GW->End_star[i],true);
										}
										
								}
								if(GW->Score>0){
										swprintf(buff,L"%d",int(GW->End_Alpha*GW->Score/255));
										XStatic_SetText(GW->End_score,buff);
								}
								GW->End_tm.reset();
								GW->End_tm.start();		
						}
						if(!GW->End_star_show&&GW->End_score_show){
								double _time=GW->End_tm.get()/10;
								rc.top=300,rc.bottom=362;
								for(int i=0;i<5;i++){
										rc.left=325+i*_time;
										rc.right=rc.left+62;
										GW->End_star_pos[i]=rc;
								}
								if(rc.left>573){
										GW->End_star_show=true;
								}
						}

						/*******************控制刷新率******************/
						double _time=GW->FPS_tm.get();
						int FPS_Counter=_time/GW->FPS_Speed+0.5;
						if(FPS_Counter!=GW->FPS_Counter_pre){
								swprintf(buff,L"%dFPS",int(1000.0/(_time-GW->FPS_Time_pre)+0.5));
								XStatic_SetText(GW->FPS_Show,buff);

								double TM=GW->Music_tm.get();

								swprintf(buff,L"%0.2d:%0.2d:%0.2d",int(TM/1000)/60,int(TM/1000)%60,int(TM)%1000/10);
								XStatic_SetText(GW->Time_show,buff);

								swprintf(buff,L"Score %d",GW->Score);
								XStatic_SetText(GW->Score_show,buff);

								GW->FPS_Counter_pre=FPS_Counter;
								GW->FPS_Time_pre=_time;

								/*****************************/
								if(GW->End_end&&!GW->End_score_show){
										XEle_SetAlpha(GW->End_Pic,GW->End_Alpha);
										XEle_SetAlpha(GW->End_score,GW->End_Alpha);
								
								}
								if(GW->End_score_show&&!GW->End_star_show){
										for(int i=0;i<5;i++){
												XEle_SetRect(GW->End_star[i],&GW->End_star_pos[i]);
										}
								}

								/*****************绘制部分****************/
								XPic_SetImage(GW->Ball_Anime,GW->Ball_Anime_image[GW->Ball_Anime_index] );	   	   //绘制球动画
								XEle_SetRect(GW->Ball_Anime,&GW->Ball_pos);

								if(GW->SE_Anime_play){
										XEle_SetAlpha(GW->SE_Anime,GW->SE_Alpha);
										XPic_SetImage(GW->SE_Anime,GW->Bmap->anime[GW->Scene_index].image[GW->SE_Anime_index] );  	//绘制场景动画
								}
								if(!GW->BK_Pause){
										XPic_SetImage(GW->BK_Anime,GW->Bmap->anime[0].image[GW->BK_Anime_index] );  	//绘制背景动画

										XEle_SetRect(GW->BK_Loop1_1,&GW->BK_Loop1_1_pos);  //绘制滚动背景1
										XEle_SetRect(GW->BK_Loop1_2,&GW->BK_Loop1_2_pos);
										XEle_SetAlpha(GW->BK_Loop1_1,GW->BK_Loop1_Alpha);
										XEle_SetAlpha(GW->BK_Loop1_2,GW->BK_Loop1_Alpha);

										XEle_SetRect(GW->BK_Loop2_1,&GW->BK_Loop2_1_pos); //绘制滚动背景2
										XEle_SetRect(GW->BK_Loop2_2,&GW->BK_Loop2_2_pos);
										XEle_SetAlpha(GW->BK_Loop2_1,GW->BK_Loop2_Alpha);
										XEle_SetAlpha(GW->BK_Loop2_2,GW->BK_Loop2_Alpha);
								}

								for(int i=0;i<15;i++){
										XEle_SetRect(GW->Pillar[i],&GW->Pillar_pos[i]);			 //地图移动
										if(GW->Pillar_img_change[i]){
												XPic_SetImage(GW->Pillar[i],GW->Pillar_img[i]);
												GW->Pillar_img_change[i]=false;
										}
								}

								for(int i=0;i<10;i++){							 //弹幕提示
										if(GW->Tip_Alpha_state[i]>0){
												XEle_SetAlpha(GW->Tip[i],GW->Tip_Alpha_state[i]);
										}
								}

								if(GW->Hit_board_alpha>0){ //连击提示
										XEle_SetAlpha(GW->Hit_show_text,GW->Hit_board_alpha);
										XEle_SetAlpha(GW->Hit_show_count,GW->Hit_board_alpha);
								}

								if(!GW->Begin_showed){
										if(GW->Begin_alpha<256){
												XEle_SetAlpha(GW->Begin_Pic,GW->Begin_alpha);
										}
								}
								/******************************************/

								XWnd_RedrawWnd(GW->gWindow,true);
						}
				} else if(NowLoading&&GW->Bmap->loaded[GW->Scene_index]){
						NowLoading=false;
						GW->PauseGame(false,GW);
				}
				Sleep(5);
		}
		GW->p1=true;
		return 0;
}

void GAME_WINDOWS::PauseGame(bool pause,GAME_WINDOWS *GW){
		if(pause){
				XStatic_SetText(GW->Time_show,L"暂停");
				GW->Music_play=false;
				GW->Music_play_send=true;
				GW->Music_tm.pause();
				GW->BK_Anime_tm.pause();
				GW->FPS_tm.pause();
				GW->BK_Loop1_tm.pause();
				GW->BK_Loop2_tm.pause();
				GW->Ball_Move_tm.pause();
				GW->Pillar_Hit_tm.pause();
				GW->GamePause=true;
		} else {
				GW->BK_Anime_tm.resume();
				GW->BK_Loop1_tm.resume();
				GW->BK_Loop2_tm.resume();
				GW->FPS_tm.resume();
				GW->Pillar_Hit_tm.resume();
				GW->Ball_Move_tm.resume();
				GW->Music_tm.resume();
				GW->GamePause=false;
				GW->Music_play=true;	
				GW->Music_play_send=true;
		}
}

DWORD WINAPI GAME_WINDOWS::MusicWatch(LPVOID pParam){
		GAME_WINDOWS *GW= (GAME_WINDOWS*)pParam;
		wchar_t buff[128];
		wsprintf(buff,L"open BeatMap\\%s\\%S alias bgm",GW->Bmap->path,GW->Bmap->music.c_str());
		mciSendString(buff, NULL, 0, NULL);
		while(!GW->ExitCode){
				if(GW->Music_play_send){
						if(GW->Music_play==1){
								mciSendString(L"play bgm", NULL, 0, NULL);
						} else if(GW->Music_play==2){
								mciSendString(L"seek bgm to start", NULL, 0, NULL);
						} else {
								mciSendString(L"pause bgm", NULL, 0, NULL);
						}
						GW->Music_play_send=false;
				}
				Sleep(5);
		}
		mciSendString(L"close bgm", NULL, 0, NULL);
		GW->p4=true;
		return false;
}

DWORD WINAPI GAME_WINDOWS::DanmuTip(LPVOID pParam){
		GAME_WINDOWS *GW= (GAME_WINDOWS*)pParam;
		VTimer Tip_tm;
		RECT rc;
		int dec[10]={0};
		int index=0;
		Tip_tm.start();
		while(!GW->ExitCode){
				if(!GW->GamePause){
						if(GW->Tip_Add&&!GW->End_end){
										rc.top=GW->Tip_Add_y;
										rc.bottom=rc.top+360;
										rc.left=rand()%500+10;
										rc.right=rc.left+360;
										XEle_SetRect(GW->Tip[index],&rc);
										dec[index]=GW->Tip_Add_dec;
										GW->Tip_Alpha_state[index]=255;
										XPic_SetImage(GW->Tip[index],GW->Tip_Add_img);				
										XEle_ShowEle(GW->Tip[index],true);
										GW->Tip_Add=false;
										index=(index+1)%10;
										Tip_tm.reset();
								Tip_tm.start();
						}
						if(Tip_tm.get()>15){
								for(int i=0;i<10;i++){
										if(GW->Tip_Alpha_state[i]>0){
												GW->Tip_Alpha_state[i]-=dec[i];
												if(GW->Tip_Alpha_state[i]<=0){
														XEle_ShowEle(GW->Tip[i],false);
												}
										}
								}
								Tip_tm.reset();
								Tip_tm.start();
						}
				}
				Sleep(5);
		}
		GW->p2=true;
		return 0;
}


DWORD WINAPI GAME_WINDOWS::WatchKeyDown(LPVOID pParam){			//监视键盘
		GAME_WINDOWS *GW= (GAME_WINDOWS*)pParam;
		Sleep(5);
		int index=0;
		while(!GW->ExitCode){
				if(index+1<GW->Bmap->n&&GW->Bmap->loaded[index]){
						//cprintf("%d\n",index);
						index++;
						//cprintf("%d==%d\n",index,GW->Bmap->n);
						if(!GW->Bmap->Load(index)){
								MessageBox(NULL,TEXT("BeatMap数据载入失败！\n请检查数据包是否受损。"),TEXT("BiliBeat!"),MB_OK);
								exit(0);
						}
				}
				if(!GW->End_end){
						if(GW->Begin_showed){
								if(GW->Ball_AllowHit){
										if(GetKeyState(VK_RETURN)&0x80||GetKeyState(VK_LBUTTON)&0x80){
												GW->Ball_Jump=true;
												Sleep(100);
										}
										if(GetKeyState(VK_SPACE)&0x80){
												if(GW->GamePause)
														GW->PauseGame(false,GW);
												else
														GW->PauseGame(true,GW);
												Sleep(500);
										} 
										if(GetKeyState(VK_TAB)&0x80){
												if(GetKeyState(VK_NUMPAD0)&0x80){
														GW->AutoRun=0;
												}
												if(GetKeyState(VK_NUMPAD1)&0x80){
														GW->AutoRun=1;	
												}
												if(GetKeyState(VK_NUMPAD2)&0x80){
														GW->AutoRun=2;	
												}
												if(GetKeyState(VK_NUMPAD3)&0x80){
														GW->AutoRun=3;	
												}
												if(GetKeyState(VK_NUMPAD9)&0x80){
														GW->ResetGame(GW);
												}

										}
										GW->Tip_Wrong_show=false;
								} else {
										if(!GW->Tip_Wrong_show&&((GetKeyState(VK_RETURN)&0x80||GetKeyState(VK_LBUTTON)&0x80))){
												GW->Score-=50;
												GW->Hited_num=0;
												GW->Tip_Add_img=GW->Tip_Wrong;
												GW->Tip_Add_dec=13;
												GW->Tip_Add_y=GW->Ball_pos.top>220?220:(GW->Ball_pos.top-100);
												GW->Tip_Add=true;
												GW->Tip_Wrong_show=true;
									} 
								}
						}
				} else {
						if(GetKeyState(VK_RETURN)&0x80){
								GW->ResetGame(GW);
								Sleep(500);
						}
				}
				if(GetKeyState(VK_ESCAPE)&0x80){
						GW->ExitCode=true;
						while(!(GW->p1&&GW->p2&&GW->p4)) Sleep(100);
						XWnd_CloseWindow(GW->gWindow);
						*(GW->GameEnd)=true;
				}
				Sleep(5);																						    
		}
		GW->p3=true;
		return 0;
}


void GAME_WINDOWS::ResetGame(GAME_WINDOWS *GW){
		RECT rc;
		//其他
		GW->AutoRun=0;
		GW->ExitCode=false;
		 //开始画面重置
		GW->Begin_alpha=400;
		XEle_SetAlpha(GW->Begin_Pic,255);
		XEle_ShowEle(GW->Begin_Pic,true);
		GW->Begin_showed=false;
		GW->Begin_tm.start();
		GW->GamePause=true;
		Sleep(100);
		for(int i=0;i<15;i++){
				rc.top=450;
				rc.bottom=500;
				rc.left=i*72;
				rc.right=(i+1)*72;
				GW->Pillar_pos[i]=rc;
				GW->Pillar_State[i].type=0;
				GW->Pillar_State[i].color=rand()%4;
				XPic_SetImage(GW->Pillar[i],GW->Pillar_N_image[GW->Pillar_State[i].color]);
		}
		for(int i=0;i<10;i++){
				GW->Tip_Alpha_state[i]=0;
				XEle_SetAlpha(GW->Tip[i],GW->Tip_Alpha_state[i]);
		}
		//球动画重置
		GW->Ball_Anime_tm.start();
		GW->Ball_Anime_index=0;
		//球动作重置
		GW->Ball_Jump=false;
		GW->Ball_Fall=false;
		GW->Ball_AllowHit=false;
		GW->Ball_Move_tm.start();
		rc.top=400;rc.bottom=472;
		rc.left=216;rc.right=288;
		XEle_SetRect(GW->Ball_Anime,&rc);
		//分数重置
		GW->Score=100;
		//连击提示重置
		GW->Hit_board_alpha=0;
		GW->Hit_board_tm.start();
		GW->Hit_board_alpha=0;
		GW->Hited_num=0;
		GW->Hit_board_tm.start();
		//弹幕提示重置
		GW->Tip_Tap_show=false;
		GW->Tip_Miss_show=false;
		GW->Tip_Wrong_show=false;
		GW->Tip_Add=false;
		//FPS计数器重置
		GW->FPS_Counter_pre=-1;
		GW->FPS_tm.start();
		//地图移动重置
		GW->Pillar_index=0;
		GW->Pillar_Hit_index=4;
		//背景动画重置
		GW->BK_Anime_tm.start();
		GW->BK_Anime_index=0;
		//循环背景1重置
		GW->BK_Loop1_Alpha=200;
		GW->BK_Loop1_Alpha_Dec=-1;
		GW->BK_Loop1_tm.start();
		rc.top=125;rc.bottom=540;
		rc.left=0;rc.right=960;
		GW->BK_Loop1_1_pos=rc;
		XEle_SetRect(GW->BK_Loop1_1,&rc);
		rc.left=960;rc.right=1920;
		GW->BK_Loop1_2_pos=rc;
		XEle_SetRect(GW->BK_Loop1_2,&rc);
		//循环背景2重置
		GW->BK_Loop2_Alpha=200;
		GW->BK_Loop2_Alpha_Dec=+2;
		GW->BK_Loop2_tm.start();
		rc.top=330;rc.bottom=540;
		rc.left=0;rc.right=960;					   
		GW->BK_Loop2_1_pos=rc;
		XEle_SetRect(GW->BK_Loop2_1,&rc);
		rc.left=960;rc.right=1920;
		GW->BK_Loop2_2_pos=rc;
		XEle_SetRect(GW->BK_Loop2_2,&rc);
		//场景动画重置
		GW->Scene_index=1;
		GW->Scene_start=false;
		GW->SE_Anime_index=0;
		GW->SE_Switch_tm.start();
		GW->BK_Pause=false;
		GW->Scene_over=false;
		GW->SE_Anime_play=false;
		XEle_ShowEle(GW->SE_Anime,false);
		//重置游戏结束板块
		rc.top=300,rc.bottom=362;
		rc.left=325,rc.right=387;
		for(int i=4;i>=0;i--){																																															
				XEle_ShowEle(GW->End_star[i],false);
				XEle_SetRect(GW->End_star[i],&rc);
		}
		XEle_SetAlpha(GW->End_Pic,0);
		XEle_SetAlpha(GW->End_score,0);
		XEle_ShowEle(GW->End_board,false);
		GW->End_Alpha=0;
		GW->End_end=false;
		GW->End_score_show=false;
		GW->End_star_show=false;
		GW->End_tm.reset();
		GW->End_tm.start();
		//音乐计时器重置
		GW->Music_tm.reset();
		//停止播放音乐
		GW->Music_play=2;
		GW->Music_play_send=true;	
		GW->GamePause=false;
}


DWORD WINAPI GAME_WINDOWS::Load_Data(LPVOID pParam){	 //载入游戏数据、初始化游戏窗口
		GAME_WINDOWS *GW= (GAME_WINDOWS*)pParam;
		wchar_t buff[128]={0};

		
		GW->Bmap->Load(0);
		while(GW->Bmap->load_Rate<99&&!GW->ExitCode){
				XProgBar_SetPos(GW->mload,GW->Bmap->load_Rate);  //载入进度
				XEle_RedrawEle(GW->mload);
				Sleep(10);
		}

		for(int i=0;i<BALL_ANIME_NUM&&!GW->ExitCode;i++){ //载入球动画
				wsprintf(buff,L"%d.png",i+1);
				GW->Ball_Anime_image[i]=XImage_LoadZip(L"Resouce\\Anime\\Ball.dat",buff,NULL,false);
				XImage_EnableAutoDestroy(GW->Ball_Anime_image[i],false);
		}


		/********************GAME_WINDWOS_BEGIN**********************/
		//初始化游戏窗口
		XWnd_SetCaptionHeight(GW->gWindow,0);
		XWnd_SetIcon2(GW->gWindow,L"Resouce\\Icon\\BiliBeat.ico",true);
		XWnd_EnableMaxButton(GW->gWindow,false,true);
		XWnd_EnableCloseButton(GW->gWindow,false,true);
		XWnd_EnableMinButton(GW->gWindow,false,true);
		XWnd_SetBorderSize(GW->gWindow,0,0,0,0);
		XWnd_EnableRound(GW->gWindow,false,true);

		//背景动画
		GW->BK_Anime=XPic_Create(0,0,960,540,GW->gWindow);
		XEle_SetBkTransparent(GW->BK_Anime,true);
		GW->BK_Anime_tm.start();
		GW->BK_Anime_index=0;

		//循环背景1
		GW->BK_Loop1_1=XPic_Create(0,125,960,415,GW->gWindow);
		GW->BK_Loop1_2=XPic_Create(960,125,960,415,GW->gWindow);
		XEle_GetRect(GW->BK_Loop1_1,&GW->BK_Loop1_1_pos);
		XEle_GetRect(GW->BK_Loop1_2,&GW->BK_Loop1_2_pos);
		XEle_SetBkTransparent(GW->BK_Loop1_1,true);
		XEle_SetBkTransparent(GW->BK_Loop1_2,true);
		wsprintf(buff,L"BeatMap\\%s\\%S",GW->Bmap->path,GW->Bmap->BK1.c_str());
		XPic_SetImage (GW->BK_Loop1_1,XImage_LoadFile(buff,false));
		XPic_SetImage (GW->BK_Loop1_2,XImage_LoadFile(buff,false));
		GW->BK_Loop1_Alpha=200;
		GW->BK_Loop1_Alpha_Dec=-1;
		GW->BK_Loop1_tm.start();

		//循环背景2
		GW->BK_Loop2_1=XPic_Create(0,330,960,210,GW->gWindow);
		GW->BK_Loop2_2=XPic_Create(960,330,960,210,GW->gWindow);
		XEle_GetRect(GW->BK_Loop2_1,&GW->BK_Loop2_1_pos);
		XEle_GetRect(GW->BK_Loop2_2,&GW->BK_Loop2_2_pos);
		XEle_SetBkTransparent(GW->BK_Loop2_1,true);
		XEle_SetBkTransparent(GW->BK_Loop2_2,true);
		wsprintf(buff,L"BeatMap\\%s\\%S",GW->Bmap->path,GW->Bmap->BK2.c_str());
		XPic_SetImage (GW->BK_Loop2_1,XImage_LoadFile(buff,false));
		XPic_SetImage (GW->BK_Loop2_2,XImage_LoadFile(buff,false));
		GW->BK_Loop2_Alpha=200;
		GW->BK_Loop2_Alpha_Dec=+2;
		GW->BK_Loop2_tm.start();
																  
		//场景动画
		GW->SE_Anime=XPic_Create(0,0,960,540,GW->gWindow);
		XEle_SetBkTransparent(GW->SE_Anime,true);
		GW->SE_Anime_index=0;
		GW->Scene_index=1;
		GW->SE_Switch_tm.start();
		//GW->Music_tm.start();
		GW->Scene_start=false;
		GW->BK_Pause=false;
		GW->Scene_over=false;
		GW->SE_Anime_play=false;

		//实时FPS
		GW->FPS_Show=XStatic_Create(5,2,200,30,L"FPS",GW->gWindow);
		XEle_SetTextColor(GW->FPS_Show,RGB(230,230,230));
		XEle_SetFont(GW->FPS_Show,XFont_Create2(L"微软雅黑",30,1,0,0,0));
		XEle_SetBkTransparent(GW->FPS_Show,true);
		GW->FPS_Counter_pre=-1;
		GW->FPS_tm.start();

		//分数显示
		GW->Score_show=XStatic_Create(655,2,300,30,L"Score",GW->gWindow);
		XEle_SetTextColor(GW->Score_show,RGB(230,230,230));
		XEle_SetFont(GW->Score_show,XFont_Create2(L"微软雅黑",30,1,0,0,0));
		XStatic_SetTextAlign(GW->Score_show,2);
		XEle_SetBkTransparent(GW->Score_show,true);

		//时间显示
		GW->Time_show=XStatic_Create(330,2,300,40,L"Time",GW->gWindow);
		XEle_SetTextColor(GW->Time_show,RGB(0,220,250));
		XEle_SetFont(GW->Time_show,XFont_Create2(L"微软雅黑",40,1,0,0,0));
		XStatic_SetTextAlign(GW->Time_show,1);
		XEle_SetBkTransparent(GW->Time_show,true);

		/*********************载入提示图片**********************/ 
		for(int i=9;i>=0;i--){
				GW->Tip[i]=XPic_Create(0,0,360,360,GW->gWindow);
				GW->Tip_Alpha_state[i]=0;
				XEle_SetBkTransparent(GW->Tip[i],true);
		}
		GW->Tip_Tap=XImage_LoadFile(L"Resouce\\Image\\Tips\\Tap.png",false);
		XImage_EnableAutoDestroy(GW->Tip_Tap,false);
		GW->Tip_Good=XImage_LoadFile(L"Resouce\\Image\\Tips\\Good.png",false);
		XImage_EnableAutoDestroy(GW->Tip_Good,false);
		GW->Tip_Miss=XImage_LoadFile(L"Resouce\\Image\\Tips\\Miss.png",false);
		XImage_EnableAutoDestroy(GW->Tip_Miss,false);
		GW->Tip_Nice=XImage_LoadFile(L"Resouce\\Image\\Tips\\Nice.png",false);
		XImage_EnableAutoDestroy(GW->Tip_Nice,false);
		GW->Tip_Wrong=XImage_LoadFile(L"Resouce\\Image\\Tips\\Wrong.png",false);
		XImage_EnableAutoDestroy(GW->Tip_Wrong,false);
		GW->Tip_Perfect=XImage_LoadFile(L"Resouce\\Image\\Tips\\Perfect.png",false);
		XImage_EnableAutoDestroy(GW->Tip_Perfect,false);
		GW->Tip_Tap_show=false;
		GW->Tip_Miss_show=false;
		GW->Tip_Wrong_show=false;
		GW->Tip_Add=false;			

		/*********************载入地图贴图**********************/ 
		GW->Pillar_N_image[0]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_Red_N.png",false);
		GW->Pillar_N_image[1]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_GREEN_N.png",false);
		GW->Pillar_N_image[2]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_BLUE_N.png",false);
		GW->Pillar_N_image[3]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_PINK_N.png",false);
		GW->Pillar_N_image[4]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_ORANGE_N.png",false);
		GW->Pillar_N_image[5]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_BLACK_N.png",false);
		GW->Pillar_N_image[6]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_BAD_N.png",false);
		GW->Pillar_L_image[0]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_Red_L.png",false);
		GW->Pillar_L_image[1]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_GREEN_L.png",false);
		GW->Pillar_L_image[2]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_BLUE_L.png",false);
		GW->Pillar_L_image[3]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_PINK_L.png",false);
		GW->Pillar_L_image[4]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_ORANGE_L.png",false);
		GW->Pillar_L_image[5]=XImage_LoadFile(L"Resouce\\Image\\Pillar\\Piller_BLACK_L.png",false);

		for(int i=0;i<7;i++){
						XImage_EnableAutoDestroy(GW->Pillar_N_image[i],false);
						if(i<6)XImage_EnableAutoDestroy(GW->Pillar_L_image[i],false);
		}

		for(int i=0;i<15;i++){
				GW->Pillar[i]=XPic_Create(i*72,450,72,50,GW->gWindow);
				XEle_SetBkTransparent(GW->Pillar[i],true);
				GW->Pillar_State[i].type=0;
				GW->Pillar_State[i].color=rand()%4;
				GW->Pillar_img[i]=GW->Pillar_N_image[GW->Pillar_State[i].color];
				GW->Pillar_img_change[i]=true;
				XEle_GetRect(GW->Pillar[i],&GW->Pillar_pos[i]);
		}
		GW->Pillar_index=0;
		GW->Pillar_Hit_index=4;

		//连击提示
		GW->Hit_board=XEle_Create(310,120,340,200,GW->gWindow);
		XEle_EnableBorder(GW->Hit_board,false);
		XEle_SetBkTransparent(GW->Hit_board,true);
		XEle_ShowEle(GW->Hit_board,false);
		GW->Hit_show_text=XStatic_Create(0,50,160,100,L"Hit×",GW->Hit_board);
		XEle_SetBkTransparent(GW->Hit_show_text,true);
		XEle_SetFont(GW->Hit_show_text,XFont_Create2(L"微软雅黑",100,0,0,0,0));
		XEle_SetTextColor(GW->Hit_show_text,RGB(220,220,220));
		GW->Hit_show_count=XStatic_Create(160,0,180,200,NULL,GW->Hit_board);
		XStatic_SetTextAlign(GW->Hit_show_count,1);
		XEle_SetBkTransparent(GW->Hit_show_count,true);
		XEle_SetFont(GW->Hit_show_count,XFont_Create2(L"微软雅黑",200,0,0,0,0));
		XEle_SetTextColor(GW->Hit_show_count,RGB(255,255,255));
		GW->Hit_board_alpha=0;
		GW->Hited_num=0;
		GW->Hit_board_tm.start();

		//初始化球
		GW->Ball_Anime=XPic_Create(216,400,72,72,GW->gWindow);
		XEle_GetRect(GW->Ball_Anime,&GW->Ball_pos);
		XEle_SetBkTransparent(GW->Ball_Anime,true);
		GW->Ball_Anime_tm.start();
		GW->Ball_Anime_index=0;
		GW->Ball_Jump=false;
		GW->Ball_Fall=false;
		GW->Ball_AllowHit=false;
		GW->Ball_Move_tm.start();

		GW->AutoRun=0;
		GW->ExitCode=false;
		GW->GamePause=false;
		GW->Score=100;


		//开始界面
		GW->Begin_Pic=XPic_Create(0,0,960,540,GW->gWindow);
		XPic_SetImage(GW->Begin_Pic,XImage_LoadFile(L"Resouce\\Image\\UI\\start.png",false));
		XEle_SetBkTransparent(GW->Begin_Pic,true);
		GW->Begin_alpha=400;
		GW->Begin_showed=false;
		GW->Begin_tm.start();


		//结束游戏
		GW->End_board=XEle_Create(0,0,960,540,GW->gWindow);
		XEle_SetBkTransparent(GW->End_board,true);
		GW->End_Pic=XPic_Create(0,0,960,540,GW->End_board);
		XPic_SetImage(GW->End_Pic,XImage_LoadFile(L"Resouce\\Image\\UI\\board.png",false));
		XEle_SetBkTransparent(GW->End_Pic,true);
		XEle_SetAlpha(GW->End_Pic,0);
		GW->End_score=XStatic_Create(0,100,960,200,NULL,GW->End_board);
		XEle_SetBkTransparent(GW->End_score,true);
		XEle_SetAlpha(GW->End_score,0);
		XEle_SetFont(GW->End_score,XFont_Create2(L"微软雅黑",200,0,0,0,0));
		XEle_SetTextColor(GW->End_score,RGB(150,150,255));
		XStatic_SetTextAlign(GW->End_score,1);
		XEle_ShowEle(GW->End_board,false);
		for(int i=4;i>=0;i--){
				GW->End_star[i]=XPic_Create(325,300,62,62,GW->End_board);
				XEle_SetBkTransparent(GW->End_star[i],true);
				XEle_ShowEle(GW->End_star[i],false);
		}
		GW->End_img_star1=XImage_LoadFile(L"Resouce\\Image\\UI\\star1.png",false);
		GW->End_img_star2=XImage_LoadFile(L"Resouce\\Image\\UI\\star2.png",false);
		XImage_EnableAutoDestroy(GW->End_img_star1,false);
		XImage_EnableAutoDestroy(GW->End_img_star2,false);
		GW->End_Alpha=0;
		GW->End_end=false;
		GW->End_score_show=false;
		GW->End_star_show=false;
		GW->End_tm.start();

		GW->Music_play=false;
		GW->Music_play_send=true;

		/********************GAME_WINDWOS_END************************/

		SetWindowPos(XWnd_GetHWnd(GW->gWindow),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);//窗口置顶
		XWnd_CloseWindow(GW->mWindow);
		XWnd_ShowWindow(GW->gWindow, SW_SHOW);
		Sleep(10);

		GW->Game_Process=CreateThread(NULL,0,GAME_WINDOWS::Game_Draw,pParam,0,NULL);
		GW->WatchKey_Process=CreateThread(NULL,0,GAME_WINDOWS::WatchKeyDown,pParam,0,NULL);
		GW->DanmuTip_Process=CreateThread(NULL,0,GAME_WINDOWS::DanmuTip,pParam,0,NULL);
		GW->Music_Process=CreateThread(NULL,0,GAME_WINDOWS::MusicWatch,pParam,0,NULL);

		Sleep(10);
		CloseHandle(GW->Game_Process);
		CloseHandle(GW->WatchKey_Process);
		CloseHandle(GW->DanmuTip_Process);
		CloseHandle(GW->Music_Process);

		return false;
}

