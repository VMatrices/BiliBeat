#pragma once
class Launcher
		:public CXEventMsg
{
public:
		Launcher(void);
		~Launcher(void);
		HWINDOW mLauncher;
		HELE Intro,IntroPicA,IntroPicB,AnimePic,MusicList;
	
		vector<BeatMapRes*> Bmap;
		GAME_WINDOWS *GW;

		int RunID;
		HELE MusicItem[100],MusicItemBtn[100];
		HELE btnClose;

		HIMAGE IntroImg[5];

		
		wchar_t buff[64];

		bool GameEnd;
		bool Running;
		void GetDir();

		bool Music_Select(HELE hEle,HELE hEventEle);
		bool LauncherTimer(HWINDOW hWindow, UINT_PTR nIDEvent, UINT uElapse);
		bool Launcher_Close(HELE hEle,HELE hEventEle);

		bool Initialize();
};


