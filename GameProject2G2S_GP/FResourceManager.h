#pragma once
#pragma comment(lib, "fmod_vc")
#include "fmod.hpp"

enum class ESoundChannel {
	BackgroundMusic,
	SoundEffect,
	Last
};

struct FSoundInformation {
	FMOD::Sound* Sound;
	bool bIsLoop;
};

class FTexture;

class FResourceManager {
	SINGLETON(FResourceManager);

	map<wstring, FSoundInformation*> Sounds;
	map<wstring, FTexture*> Textures;
	FMOD::Channel* FmodChannel[(UINT)ESoundChannel::Last];
	FMOD::System* FmodSystem;

public:
	FTexture* FindTexture(const wstring& Key);

	FTexture* LoadTexture(const wstring& Key, const wstring& RelativePath);

	void Initialize();

	void LoadSound(const wstring& Key, const wstring& RelativePath, bool bDoLoop);

	void PauseChannel(ESoundChannel SoundChannel, bool bDoPause);

	void PlaySoundByKey(const wstring& Key);

	void Release();

	void SetChannelVolume(ESoundChannel SoundChannel, float Volume);

	void StopChannel(ESoundChannel SoundChannel);

private:
	FSoundInformation* FindSound(const wstring& Key);
};

