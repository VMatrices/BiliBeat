// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN  //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <ctime>
#include<iostream>
#include<fstream>
#include<string>
 #include<io.h>
#include<vector>
using namespace std;



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include"w2s.h"

/*************����XCGUI��*************/
#include "xcgui.h"				   
#ifdef _DEBUG
#pragma comment(lib, "XCGUId.lib")
#else
#pragma comment(lib, "XCGUI.lib")
#endif

/*************�����ý���*************/
#include <mmsystem.h>		  
#pragma comment(lib, "winmm.lib")

/*************�����ʱ��*************/
#include "VTimer.h"

/*************����������Ϣ*************/
#include "BeatMapRes.h"

/*************������Ϸ����*************/
#include "GAME_WINDOWS.h"
#include "Launcher.h"
#include "Welcome.h"	   


