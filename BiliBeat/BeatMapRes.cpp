#include "StdAfx.h"
#include "BeatMapRes.h"


BeatMapRes::BeatMapRes(wchar_t *path):loading(false),load_Rate(0),readed(false),n(0)
{
		wcscpy(this->path,path);
}

BeatMapRes::~BeatMapRes(void)
{
		if(readed){
				delete [] loaded;
				delete [] anime;
				CloseHandle(LoadProcess);
		}
}

bool BeatMapRes::Load(int id){		
		if(loaded[id]||loading) return false;
		load_index=id;
		load_Rate=0;				
		LoadProcess=CreateThread(NULL,0,BeatMapRes::Load_Data,this,0,NULL);
		return true;
}

bool BeatMapRes::Release(int id){
		if(!loaded[id]||loading) return false;
		for(int i=0;i<anime[id].n;i++){
				XImage_Destroy(anime[id].image[i]);
		}
		delete [] anime[id].image;
		return true;
}

void BeatMapRes::clear(){
		for(int i=0;i<n;i++) loaded[i]=false;
}
																												
DWORD WINAPI BeatMapRes::Load_Data(LPVOID pParam){
		BeatMapRes *BM=(BeatMapRes*)pParam;
		//AllocConsole();
		//_cprintf("%d %d\n",BM->load_index,BM->anime[BM->load_index].n);
		BM->anime[BM->load_index].image=new HIMAGE[BM->anime[BM->load_index].n];
		wchar_t buff1[32],buff2[64];
		BM->loading=true;
		//AllocConsole();
		for(int i=0;i<BM->anime[BM->load_index].n;i++){ //ÔØÈë¶¯»­
				wsprintf(buff1,L"%d.jpg",i+1);
				wsprintf(buff2,L"BeatMap\\%s\\%S",BM->path,BM->anime[BM->load_index].file.c_str());
				BM->anime[BM->load_index].image[i]=XImage_LoadZip(buff2,buff1,NULL,true);
				XImage_EnableAutoDestroy(BM->anime[BM->load_index].image[i],false);
				BM->load_Rate=(i+1)*100/BM->anime[BM->load_index].n;
		}
		BM->loaded[BM->load_index]=true;
		BM->loading=false;
		//cprintf("%d %d %d\n",BM->load_index,BM->loaded[BM->load_index],BM->loading);
		return false;
}

bool BeatMapRes::ReadCfg(){
		string file="BeatMap\\"+w2s(path)+"\\Config.ini";
		ifstream cfg(file);
		if (!cfg) {
				return false;
		}
		const string str[]={"[Config]","[Scene]","Name","Music","Range","Background1","Background2","Phyinfo1","Phyinfo2","Phyinfo3","SceneN","Band","Level","Describe"};
		string line;
		int index=0;
		bool mode;
		while (getline(cfg,line)){
				if(line.empty()||line[0]=='#') continue;
				if(line.find(str[0])!=string::npos){
						mode=true;
						continue;
				}
				if(line.find(str[1])!=string::npos){
						mode=false;
						continue;
				}
				if(mode){
						int pos=line.find('=');
						if(pos==string::npos) return false;
						string key=line.substr(0,pos);
						string value=line.substr(pos+1,line.size()-pos);
						if(key==str[2]){
								name=value;
						} else 
						if(key==str[3]){
								music=value;
						} else
						if(key==str[4]){
								int _pos=value.find(',');
								if(_pos==string::npos) return false;
								range.begin=atoi(value.substr(0,_pos).c_str());
								range.end=atoi(value.substr(_pos+1,value.size()-_pos).c_str());
						} else 
						if(key==str[5]){
								BK1=value;
						} else 
						if(key==str[6]){
								BK2=value;
						} else 
						if(key==str[7]){
								int _pos=value.find(',');
								if(_pos==string::npos) return false;
								phy[0].G=atoi(value.substr(0,_pos).c_str());
								phy[0].V=atoi(value.substr(_pos+1,value.size()-_pos).c_str());
						} else
						if(key==str[8]){
								int _pos=value.find(',');
								if(_pos==string::npos) return false;
								phy[1].G=atoi(value.substr(0,_pos).c_str());
								phy[1].V=atoi(value.substr(_pos+1,value.size()-_pos).c_str());
						} else
						if(key==str[9]){
								int _pos=value.find(',');
								if(_pos==string::npos) return false;
								phy[2].G=atoi(value.substr(0,_pos).c_str());
								phy[2].V=atoi(value.substr(_pos+1,value.size()-_pos).c_str());
						}else 
						if(key==str[10]){
								n=atoi(value.c_str());
								loaded=new bool[n];
								anime=new BeatMapRes::scene[n];
								for(int i=0;i<n;i++) loaded[i]=false;
						}else 
						if(key==str[11]){
								band=atoi(value.c_str());
						}else 
						if(key==str[12]){
								level=atoi(value.c_str());
						} else if(key==str[13]){
								describe=value;
						}
				} else if(index<n){
						int pos1=line.find('|');
						if(pos1==string::npos) continue;
						int pos2=line.rfind('|');
						string range=line.substr(pos1+1,pos2-pos1-1);
						int pos3=line.find(',');
						if(pos3==string::npos) continue;
						anime[index].n=atoi(line.substr(0,pos1).c_str());
						anime[index].file=line.substr(pos2+1,line.size()-pos2);
						anime[index].l=atoi(line.substr(pos1+1,pos3-pos1-1).c_str());
						anime[index].r=atoi(line.substr(pos3+1,pos2-pos3-1).c_str());
						index++;
				}
		}
		if(index<n) return false;
		cfg.close();	
		readed=true;
		return true;
}
