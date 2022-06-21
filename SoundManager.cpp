#include "SoundManager.h"
//#include"resource.h"

MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
UINT bgmDwID;

void PlayingBgm(int type)
{
	if (bgmDwID != 0) {
		mciSendCommand(bgmDwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&openBgm);
		mciSendCommand(bgmDwID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	}
	switch (type)
	{
	case Opening:
		openBgm.lpstrElementName = L"Sound/Pokemon Platinum - Opening.mp3";
		break;
	case WildPokemonBattle:
		openBgm.lpstrElementName = L"Sound/Pokemon Platinum - Wild Pokemon Battle.mp3";
		break;
	case GiratinaBattle:
		openBgm.lpstrElementName = L"Sound/Pokemon Platinum - Giratina Battle.mp3";
		break;
	case TrainerBattle:
		openBgm.lpstrElementName = L"Sound/Pokemon Platinum - Trainer Battle.mp3";
		break;
	case Lake:
		openBgm.lpstrElementName = L"Sound/Pokemon Platinum - Lake.mp3";
		break;
	default:
		break;
	}
	openBgm.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	bgmDwID = openBgm.wDeviceID;
	mciSendCommand(bgmDwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
}