#pragma once
#include<Windows.h>
/***********************************
VTimer ΢�뼶��ʱ�� by iBelieve

������VTimer
������
	double get();    //��ȡʱ�����(��λms������0.001)
	void start();	 //��ʼ��ʱ
	void reset();	 //���ü�ʱ��
	void pause();    //��ͣ��ʱ
	void resume();   //�ָ���ʱ
************************************/

class VTimer{
private:
		LARGE_INTEGER liPerfFreq;
		LARGE_INTEGER liPerfStart;
		LARGE_INTEGER liPerfNow;
		double eTime;
		bool counting;
		bool paused;

		void setZero(LARGE_INTEGER &tmp){
				tmp.HighPart=0;
				tmp.LowPart=0;
				tmp.u.HighPart=0;
				tmp.u.LowPart=0;
				tmp.QuadPart=0;
		}

public:
		VTimer(){
				eTime=0;
				counting=false;
				paused=false;
				setZero(liPerfFreq);
				setZero(liPerfStart);
				setZero(liPerfNow);
				QueryPerformanceFrequency(&liPerfFreq); 
		} 

		~VTimer(){
		}

		double get(){
				if(counting){
						QueryPerformanceCounter(&liPerfNow);
						return paused?eTime:(eTime+((liPerfNow.QuadPart-liPerfStart.QuadPart)*1000.0)/liPerfFreq.QuadPart);
				}
				return 0;
		}

		void start(){
				QueryPerformanceCounter(&liPerfStart);
				counting=true;
		}

		void reset(){
				eTime=0;
				paused=false;
				counting=false;
				setZero(liPerfStart);
		}

		void pause(){
				if(counting){
						eTime=get();
						paused=true;
				}
		}

		void resume(){
				if(counting&&paused){
						setZero(liPerfStart);
						start();
						paused=false;
				}
		}
};
