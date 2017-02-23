#pragma once

//由于时间原因，游戏目前仅为Demo试玩版，后期会逐渐完善各种功能

#define DEFAULT_FPS 30//默认刷新帧率

#define BK_ANIME_FPS 30  //定义背景动画播放帧率
#define SE_ANIME_FPS 30  //定义背景动画播放帧率

#define BALL_ANIME_NUM 40  //定义球体动画总帧数
#define BALL_ANIME_FPS 30  //定义球体动画播放帧率

//#define 

class GAME_WINDOWS :
		public CXEventMsg
{
private:
		HANDLE Game_Process;  //游戏界面绘制线程
		HANDLE WatchKey_Process;  //按键监视线程
		HANDLE DanmuTip_Process;  //弹幕提示处理线程
		HANDLE LoadData_Process;  //数据载入线程
		HANDLE Music_Process;	 //音乐播放

		HWINDOW mWindow;  //载入窗口
		HWINDOW gWindow;   //游戏窗口

		bool p1,p2,p3,p4;   //测试用，确保线程已经完全退出

		/*********************分数板******************/
		HELE End_board;
		HELE End_score;
		HELE End_Pic;
		HELE End_star[5];
		RECT End_star_pos[5];
		int End_Alpha;
		VTimer End_tm;
		bool End_end;
		bool End_score_show;
		bool End_star_show;
		HIMAGE End_img_star1;
		HIMAGE End_img_star2;

		/*******************开始界面****************/
		HELE Begin_Pic;
		int Begin_alpha;
		bool Begin_showed;
		VTimer Begin_tm;

		/******************游戏场景***************/
		BeatMapRes *Bmap;
		int Scene_index;
		bool BK_Pause;

		/***********************************/
		VTimer Music_tm;
		bool Music_play_send;
		int Music_play;

		/******************背景动画******************/
		const double BK_Speed;   //背景动画帧速
		HELE BK_Anime;  //动画背景
		int BK_Anime_index;  //背景动画当前播放帧
		VTimer BK_Anime_tm;  //背景动画计时器

		/******************场景动画******************/
		const double SE_Speed;   //背景动画帧速
		HELE SE_Anime;  //动画背景
		int SE_Anime_index;  //背景动画当前播放帧
		int SE_Anime_play;
		int SE_Alpha;
		bool Scene_start;
		bool Scene_over;
		VTimer SE_Anime_tm;  //背景动画计时器
		VTimer SE_Switch_tm;   //场景切换计时器

		/*******************滚动背景*****************/
		HELE BK_Loop1_1,BK_Loop1_2; //滚动背景1
		HELE BK_Loop2_1,BK_Loop2_2; //滚动背景2
		int BK_Loop1_Alpha,BK_Loop1_Alpha_Dec;  //滚动背景1透明度、步进数
		int BK_Loop2_Alpha,BK_Loop2_Alpha_Dec;  //滚动背景2透明度、步进数
		VTimer BK_Loop1_tm;	//滚动背景1计时器
		VTimer BK_Loop2_tm;	//滚动背景2计时器
		RECT BK_Loop1_1_pos; //保存滚动背景位置
		RECT BK_Loop1_2_pos;
		RECT BK_Loop2_1_pos;
		RECT BK_Loop2_2_pos;

		/********************球动画****************/
		const double Ball_Speed;  //球动画帧速
		HELE Ball_Anime;  //球
		VTimer Ball_Anime_tm;  //球动画计时器
		int Ball_Anime_index;  //球动画当前播放帧
		HIMAGE Ball_Anime_image[BALL_ANIME_NUM];  //存储球动画每一帧

		/****************球位置计算********************/
		bool Ball_Jump; //标记球是否跳起
		bool Ball_Fall;  //标记球是否在下落
		int Ball_v;	 //球的起始速度
		bool Ball_AllowHit;
		VTimer Ball_Move_tm;   //球上抛运动计时器
		RECT Ball_pos;		//保存球位置

		/******************地图块******************/
		HIMAGE Pillar_N_image[7],Pillar_L_image[6];	 //存储地图块贴图 //黑色 红色 绿色 蓝色 粉色 橙色 虚块
		struct{int color,type;} Pillar_State[15]; //标记每个柱子的状态
		HELE Pillar[15];
		RECT Pillar_pos[15]; //保存地图位置
		int Pillar_index; // 地区块循环下标
		bool Pillar_hited;	  //标记是否有块被撞击
		bool Pillar_hited_up;  //标记撞击块是否上升
		int Pillar_Hit_index;  //撞击块位置
		VTimer Pillar_Hit_tm;  //撞击块运动计时器
		HIMAGE Pillar_img[15];	//记录每一块的贴图状态
		bool Pillar_img_change[15];	 //记录地图块 是否改变

		/*****************弹幕提示*******************/
		HIMAGE Tip_Add_img,Tip_Tap,Tip_Good,Tip_Miss,Tip_Nice,Tip_Wrong,Tip_Perfect;  //存储屏幕提示贴图
		HELE Tip[10]; //屏幕提示
		VTimer Tip_tm;	//屏幕提示计时器
		bool Tip_Tap_show,Tip_Miss_show,Tip_Wrong_show;  //标记Tip是否显示过
		int Tip_Alpha_state[10];	 //每个提示的透明度
		int Tip_Add_Alpha;	//新增提示的透明度
		int Tip_Add_dec;   //新增元素透明度递减值
		int Tip_Add_y;	  //新增元素的垂直位置
		bool Tip_Add;	 //标记是否有新提示加入

		/**************游戏分数************/
		HELE Score_show;  //游戏分数显示
		int Score;	  //分数

		/**************时间显示************/
		HELE Time_show;  //游戏分数显示

		/**************连击显示************/
		HELE Hit_board,Hit_show_count,Hit_show_text;
		int Hit_board_alpha;
		int Hited_num;
		VTimer Hit_board_tm;
		
		/******************帧率控制******************/
		const double FPS_Speed;  //系统总帧速
		VTimer FPS_tm;  //FPS计时器
		HELE FPS_Show; //实时FPS显示
		double FPS_Time_pre;  //储存上一帧的时间
		int FPS_Counter_pre;   //记录上一次刷新位置

		/******************其他******************/
		bool ExitCode;	//线程退出标记
		bool GamePause;	//游戏暂停标记
		int AutoRun; //自动演示模式
		HELE mload;	 //载入进度条
		wchar_t buff[64]; //共用缓冲区

		/******************函数******************/
		bool Quit(HWINDOW hWindow);	 //关闭程序
		bool WndKeyDown(HWINDOW hWindow,WPARAM wParam,LPARAM lParam);  //按键响应
		void ResetGame(GAME_WINDOWS *GW);
		void PauseGame(bool pause,GAME_WINDOWS *GW); //暂停游戏

		static DWORD WINAPI Load_Data(LPVOID pParam);  //游戏资源载入
		static DWORD WINAPI Game_Draw(LPVOID pParam);  //游戏界面绘制
		static DWORD WINAPI WatchKeyDown(LPVOID pParam); //按键监视(应对XCGUI在高速重绘窗口时不能及时响应按键事件)
		static DWORD WINAPI DanmuTip(LPVOID pParam);
		static DWORD WINAPI MusicWatch(LPVOID pParam);

public:
		bool Initialize(); //主窗口初始化
		bool *GameEnd;
		GAME_WINDOWS(BeatMapRes *Bmap,bool *GameEnd);
		~GAME_WINDOWS(void);
};

