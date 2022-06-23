#include "SoundManager.h"
#include "resource.h"
#include<Windows.h>
#include<mmsystem.h>
#include<Digitalv.h>
#pragma comment(lib, "winmm.lib")

MCI_OPEN_PARMS openBgm;
MCI_OPEN_PARMS openBgm1;
MCI_OPEN_PARMS openBgm2;
MCI_OPEN_PARMS openBgm3;
MCI_OPEN_PARMS openBgm4;
MCI_OPEN_PARMS openBgm5;
MCI_PLAY_PARMS playBgm;

MCI_OPEN_PARMS openEffect;
MCI_OPEN_PARMS openEffect1;
MCI_PLAY_PARMS playEffect;

UINT bgmDwID;
UINT bgmDwID1;
UINT bgmDwID2;
UINT bgmDwID3;
UINT bgmDwID4;
UINT bgmDwID5;

UINT effectDwID;
UINT effectDwID1;

void PlayingBgm(int type)
{
	mciSendCommand(bgmDwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&playBgm);
	mciSendCommand(bgmDwID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	mciSendCommand(bgmDwID1, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&playBgm);
	mciSendCommand(bgmDwID1, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	mciSendCommand(bgmDwID2, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&playBgm);
	mciSendCommand(bgmDwID2, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	mciSendCommand(bgmDwID3, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&playBgm);
	mciSendCommand(bgmDwID3, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	mciSendCommand(bgmDwID4, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&playBgm);
	mciSendCommand(bgmDwID4, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	mciSendCommand(bgmDwID5, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&playBgm);
	mciSendCommand(bgmDwID5, MCI_SEEK, MCI_SEEK_TO_START, NULL);

	switch (type)
	{
	case Opening:
		openBgm.lpstrElementName = L"Sound/Pokemon Platinum - Opening.mp3";
		openBgm.lpstrDeviceType = L"mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
		bgmDwID = openBgm.wDeviceID;
		mciSendCommand(bgmDwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	case WildPokemonBattle:
		openBgm1.lpstrElementName = L"Sound/Pokemon Platinum - Wild Pokemon Battle.mp3";
		openBgm1.lpstrDeviceType = L"mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm1);
		bgmDwID1 = openBgm1.wDeviceID;
		mciSendCommand(bgmDwID1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	case GiratinaBattle:
		openBgm2.lpstrElementName = L"Sound/Pokemon Platinum - Giratina Battle.mp3";
		openBgm2.lpstrDeviceType = L"mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm2);
		bgmDwID2 = openBgm2.wDeviceID;
		mciSendCommand(bgmDwID2, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	case TrainerBattle: // 이거 안거임
		openBgm3.lpstrElementName = L"Sound/Pokemon Platinum - Trainer Battle.mp3";
		openBgm3.lpstrDeviceType = L"mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm3);
		bgmDwID3 = openBgm3.wDeviceID;
		mciSendCommand(bgmDwID3, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	case Lake:
		openBgm4.lpstrElementName = L"Sound/Pokemon Platinum - Lake.mp3";
		openBgm4.lpstrDeviceType = L"mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm4);
		bgmDwID4 = openBgm4.wDeviceID;
		mciSendCommand(bgmDwID4, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	case Ending:
		openBgm5.lpstrElementName = L"Sound/Pokemon Platinum - Lake.mp3";
		openBgm5.lpstrDeviceType = L"mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm5);
		bgmDwID5 = openBgm4.wDeviceID;
		mciSendCommand(bgmDwID5, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	default:
		break;
	}
	

}

void PlayingEffect(int type)
{
	switch (type)
	{
	case ItemGet:
		mciSendCommand(effectDwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&playEffect);
		openEffect.lpstrElementName = L"Sound/Pokemon Platinum - Item Get.mp3";
		openEffect.lpstrDeviceType = L"mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openEffect);
		effectDwID = openEffect.wDeviceID;
		mciSendCommand(effectDwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&playEffect);
		break;
	case Recorvery:
		mciSendCommand(effectDwID1, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&playEffect);
		openEffect1.lpstrElementName = L"Sound/Pokemon Platinum - Recovery.mp3";
		openEffect1.lpstrDeviceType = L"mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openEffect1);
		effectDwID1 = openEffect.wDeviceID;
		mciSendCommand(effectDwID1, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&playEffect);
		break;
	default:
		break;
	}
}

