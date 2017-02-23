#pragma once

//����ʱ��ԭ����ϷĿǰ��ΪDemo����棬���ڻ������Ƹ��ֹ���

#define DEFAULT_FPS 30//Ĭ��ˢ��֡��

#define BK_ANIME_FPS 30  //���屳����������֡��
#define SE_ANIME_FPS 30  //���屳����������֡��

#define BALL_ANIME_NUM 40  //�������嶯����֡��
#define BALL_ANIME_FPS 30  //�������嶯������֡��

//#define 

class GAME_WINDOWS :
		public CXEventMsg
{
private:
		HANDLE Game_Process;  //��Ϸ��������߳�
		HANDLE WatchKey_Process;  //���������߳�
		HANDLE DanmuTip_Process;  //��Ļ��ʾ�����߳�
		HANDLE LoadData_Process;  //���������߳�
		HANDLE Music_Process;	 //���ֲ���

		HWINDOW mWindow;  //���봰��
		HWINDOW gWindow;   //��Ϸ����

		bool p1,p2,p3,p4;   //�����ã�ȷ���߳��Ѿ���ȫ�˳�

		/*********************������******************/
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

		/*******************��ʼ����****************/
		HELE Begin_Pic;
		int Begin_alpha;
		bool Begin_showed;
		VTimer Begin_tm;

		/******************��Ϸ����***************/
		BeatMapRes *Bmap;
		int Scene_index;
		bool BK_Pause;

		/***********************************/
		VTimer Music_tm;
		bool Music_play_send;
		int Music_play;

		/******************��������******************/
		const double BK_Speed;   //��������֡��
		HELE BK_Anime;  //��������
		int BK_Anime_index;  //����������ǰ����֡
		VTimer BK_Anime_tm;  //����������ʱ��

		/******************��������******************/
		const double SE_Speed;   //��������֡��
		HELE SE_Anime;  //��������
		int SE_Anime_index;  //����������ǰ����֡
		int SE_Anime_play;
		int SE_Alpha;
		bool Scene_start;
		bool Scene_over;
		VTimer SE_Anime_tm;  //����������ʱ��
		VTimer SE_Switch_tm;   //�����л���ʱ��

		/*******************��������*****************/
		HELE BK_Loop1_1,BK_Loop1_2; //��������1
		HELE BK_Loop2_1,BK_Loop2_2; //��������2
		int BK_Loop1_Alpha,BK_Loop1_Alpha_Dec;  //��������1͸���ȡ�������
		int BK_Loop2_Alpha,BK_Loop2_Alpha_Dec;  //��������2͸���ȡ�������
		VTimer BK_Loop1_tm;	//��������1��ʱ��
		VTimer BK_Loop2_tm;	//��������2��ʱ��
		RECT BK_Loop1_1_pos; //�����������λ��
		RECT BK_Loop1_2_pos;
		RECT BK_Loop2_1_pos;
		RECT BK_Loop2_2_pos;

		/********************�򶯻�****************/
		const double Ball_Speed;  //�򶯻�֡��
		HELE Ball_Anime;  //��
		VTimer Ball_Anime_tm;  //�򶯻���ʱ��
		int Ball_Anime_index;  //�򶯻���ǰ����֡
		HIMAGE Ball_Anime_image[BALL_ANIME_NUM];  //�洢�򶯻�ÿһ֡

		/****************��λ�ü���********************/
		bool Ball_Jump; //������Ƿ�����
		bool Ball_Fall;  //������Ƿ�������
		int Ball_v;	 //�����ʼ�ٶ�
		bool Ball_AllowHit;
		VTimer Ball_Move_tm;   //�������˶���ʱ��
		RECT Ball_pos;		//������λ��

		/******************��ͼ��******************/
		HIMAGE Pillar_N_image[7],Pillar_L_image[6];	 //�洢��ͼ����ͼ //��ɫ ��ɫ ��ɫ ��ɫ ��ɫ ��ɫ ���
		struct{int color,type;} Pillar_State[15]; //���ÿ�����ӵ�״̬
		HELE Pillar[15];
		RECT Pillar_pos[15]; //�����ͼλ��
		int Pillar_index; // ������ѭ���±�
		bool Pillar_hited;	  //����Ƿ��п鱻ײ��
		bool Pillar_hited_up;  //���ײ�����Ƿ�����
		int Pillar_Hit_index;  //ײ����λ��
		VTimer Pillar_Hit_tm;  //ײ�����˶���ʱ��
		HIMAGE Pillar_img[15];	//��¼ÿһ�����ͼ״̬
		bool Pillar_img_change[15];	 //��¼��ͼ�� �Ƿ�ı�

		/*****************��Ļ��ʾ*******************/
		HIMAGE Tip_Add_img,Tip_Tap,Tip_Good,Tip_Miss,Tip_Nice,Tip_Wrong,Tip_Perfect;  //�洢��Ļ��ʾ��ͼ
		HELE Tip[10]; //��Ļ��ʾ
		VTimer Tip_tm;	//��Ļ��ʾ��ʱ��
		bool Tip_Tap_show,Tip_Miss_show,Tip_Wrong_show;  //���Tip�Ƿ���ʾ��
		int Tip_Alpha_state[10];	 //ÿ����ʾ��͸����
		int Tip_Add_Alpha;	//������ʾ��͸����
		int Tip_Add_dec;   //����Ԫ��͸���ȵݼ�ֵ
		int Tip_Add_y;	  //����Ԫ�صĴ�ֱλ��
		bool Tip_Add;	 //����Ƿ�������ʾ����

		/**************��Ϸ����************/
		HELE Score_show;  //��Ϸ������ʾ
		int Score;	  //����

		/**************ʱ����ʾ************/
		HELE Time_show;  //��Ϸ������ʾ

		/**************������ʾ************/
		HELE Hit_board,Hit_show_count,Hit_show_text;
		int Hit_board_alpha;
		int Hited_num;
		VTimer Hit_board_tm;
		
		/******************֡�ʿ���******************/
		const double FPS_Speed;  //ϵͳ��֡��
		VTimer FPS_tm;  //FPS��ʱ��
		HELE FPS_Show; //ʵʱFPS��ʾ
		double FPS_Time_pre;  //������һ֡��ʱ��
		int FPS_Counter_pre;   //��¼��һ��ˢ��λ��

		/******************����******************/
		bool ExitCode;	//�߳��˳����
		bool GamePause;	//��Ϸ��ͣ���
		int AutoRun; //�Զ���ʾģʽ
		HELE mload;	 //���������
		wchar_t buff[64]; //���û�����

		/******************����******************/
		bool Quit(HWINDOW hWindow);	 //�رճ���
		bool WndKeyDown(HWINDOW hWindow,WPARAM wParam,LPARAM lParam);  //������Ӧ
		void ResetGame(GAME_WINDOWS *GW);
		void PauseGame(bool pause,GAME_WINDOWS *GW); //��ͣ��Ϸ

		static DWORD WINAPI Load_Data(LPVOID pParam);  //��Ϸ��Դ����
		static DWORD WINAPI Game_Draw(LPVOID pParam);  //��Ϸ�������
		static DWORD WINAPI WatchKeyDown(LPVOID pParam); //��������(Ӧ��XCGUI�ڸ����ػ洰��ʱ���ܼ�ʱ��Ӧ�����¼�)
		static DWORD WINAPI DanmuTip(LPVOID pParam);
		static DWORD WINAPI MusicWatch(LPVOID pParam);

public:
		bool Initialize(); //�����ڳ�ʼ��
		bool *GameEnd;
		GAME_WINDOWS(BeatMapRes *Bmap,bool *GameEnd);
		~GAME_WINDOWS(void);
};

