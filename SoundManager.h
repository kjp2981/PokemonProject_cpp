#include"Console.h"
#include<mmsystem.h>
#include<Digitalv.h>
#pragma comment(lib, "winmm.lib")

enum BgmType
{
	Opening,
	WildPokemonBattle,
	GiratinaBattle,
	TrainerBattle,
	Lake
};

extern MCI_OPEN_PARMS openBgm;
extern MCI_OPEN_PARMS openBgm1;
extern MCI_OPEN_PARMS openBgm2;
extern MCI_OPEN_PARMS openBgm3;
extern MCI_OPEN_PARMS openBgm4;

extern MCI_PLAY_PARMS playBgm;

extern UINT bgmDwID;
extern UINT bgmDwID1;
extern UINT bgmDwID2;
extern UINT bgmDwID3;
extern UINT bgmDwID4;

void PlayingBgm(int type);
