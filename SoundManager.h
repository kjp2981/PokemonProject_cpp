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
extern MCI_PLAY_PARMS playBgm;
extern UINT bgmDwID;

void PlayingBgm(int type);
