#pragma once
class Welcome
				:public CXEventMsg
{
public:
		BOOL Initialize();
		Welcome(void);
		~Welcome(void);

private:
		GAME_WINDOWS *BiliBeat;
		
		Launcher launcher;

		HWINDOW mWelcome;

		HIMAGE Anime[22];
		int alpha,dec,count,index;

		BOOL AnimeTimer(HWINDOW hWindow, UINT_PTR nIDEvent, UINT uElapse);
};

