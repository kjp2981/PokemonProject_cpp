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
	Lake,
	Ending
};

enum EffectType {
	ItemGet,
	Recorvery,
	GiratinaCries,
	Victory
};

extern MCI_OPEN_PARMS openBgm;
extern MCI_OPEN_PARMS openBgm1;
extern MCI_OPEN_PARMS openBgm2;
extern MCI_OPEN_PARMS openBgm3;
extern MCI_OPEN_PARMS openBgm4;
extern MCI_OPEN_PARMS openBgm5;

extern MCI_PLAY_PARMS playBgm;

extern MCI_OPEN_PARMS openEffect;
extern MCI_OPEN_PARMS openEffect1;
extern MCI_OPEN_PARMS openEffect2;
extern MCI_OPEN_PARMS openEffect3;
extern MCI_PLAY_PARMS playEffect;

extern UINT bgmDwID;
extern UINT bgmDwID1;
extern UINT bgmDwID2;
extern UINT bgmDwID3;
extern UINT bgmDwID4;
extern UINT bgmDwID5;

extern UINT effectDwID;
extern UINT effectDwID1;
extern UINT effectDwID2;
extern UINT effectDwID3;

void PlayingBgm(int type);

void PlayingEffect(int type);
