#pragma once

class BeatMapRes
{
public:
		BeatMapRes(wchar_t *path);
		~BeatMapRes(void);

		wchar_t path[64];
		string name;
		string music;
		string describe;
		string BK1,BK2;
		int n;
		int level;
		int band;
		struct{
				int G;
				int V;
		}phy[3];
		struct{
				int begin,end;
		}range;
		struct scene{
				int n;
				int l,r;
				string file;
				HIMAGE *image;
		}*anime;
		bool readed;
		bool *loaded;
		bool loading;

		int load_Rate;
		
		bool ReadCfg();	//���������ļ�
		bool Load(int id);  //��������
		bool Release(int id);  //��������

		void clear();

private:

		HANDLE LoadProcess; 
		int load_index;
		static DWORD WINAPI Load_Data(LPVOID pParam); //��̨��������
};

