#include <sapi.h> //包含TTS语音引擎头文件和库文件
#include <sphelper.h>
#include <string>
#include "speech.h"
#pragma comment(lib, "sapi.lib")

void speech(std::wstring input)
{
	ISpVoice* pVoice = NULL;
	::CoInitialize(NULL);
	HRESULT hr;
	auto a = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
	hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	if (SUCCEEDED(hr))
	{
		//pVoice->SetVolume(80);//0~100
		pVoice->SetRate(-2);//-10~10
		hr = pVoice->Speak(input.c_str(), 0, NULL);
		pVoice->Release();
		pVoice = NULL;
		::CoUninitialize();
	}
}