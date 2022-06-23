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
MCI_PLAY_PARMS playBgm;
//MCI_PLAY_PARMS playBgm1;
//MCI_PLAY_PARMS playBgm2;
//MCI_PLAY_PARMS playBgm3;
//MCI_PLAY_PARMS playBgm4;

UINT bgmDwID;
UINT bgmDwID1;
UINT bgmDwID2;
UINT bgmDwID3;
UINT bgmDwID4;


void PlayingBgm(int type)
{
	switch (type)
	{
	case Opening:
		openBgm.lpstrElementName = L"Sound/Pokemon Platinum - Opening.wav";
		//openBgm.lpstrElementName = L"Pokemon_Platinum_Opening.mp3";
		openBgm.lpstrDeviceType = L"waveaudio";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
		bgmDwID = openBgm.wDeviceID;
		mciSendCommand(bgmDwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	case WildPokemonBattle:
		openBgm1.lpstrElementName = L"Sound/Pokemon Platinum - Wild Pokemon Battle.mp3";
		openBgm1.lpstrDeviceType = L"waveaudio";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm1);
		bgmDwID1 = openBgm1.wDeviceID;
		mciSendCommand(bgmDwID1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	case GiratinaBattle:
		openBgm2.lpstrElementName = L"Sound/Pokemon Platinum - Giratina Battle.mp3";
		openBgm2.lpstrDeviceType = L"waveaudio";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm2);
		bgmDwID2 = openBgm2.wDeviceID;
		mciSendCommand(bgmDwID2, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	case TrainerBattle:
		openBgm3.lpstrElementName = L"Sound/Pokemon Platinum - Trainer Battle.mp3";
		openBgm3.lpstrDeviceType = L"waveaudio";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm3);
		bgmDwID3 = openBgm3.wDeviceID;
		mciSendCommand(bgmDwID3, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	case Lake:
		openBgm4.lpstrElementName = L"Sound/Pokemon Platinum - Lake.mp3";
		openBgm4.lpstrDeviceType = L"waveaudio";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm4);
		bgmDwID4 = openBgm4.wDeviceID;
		mciSendCommand(bgmDwID4, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBgm);
		break;
	default:
		break;
	}
	

}