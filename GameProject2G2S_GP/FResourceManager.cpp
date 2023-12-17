#include "pch.h"
#include "FPathManager.h"
#include "FResourceManager.h"
#include "FTexture.h"

FTexture* FResourceManager::FindTexture(const wstring& Key) {
	auto Iterator = Textures.find(Key);

	if (Iterator != Textures.end()) {
		return Iterator->second;
	}

	return nullptr;
}

FTexture* FResourceManager::LoadTexture(const wstring& Key, const wstring& RelativePath) {
	FTexture* Texture = FindTexture(Key);

	if (Texture != nullptr) {
		return Texture;
	}

	wstring TextureFilepath = FPathManager::GetInstance()->GetResourcesPath() + RelativePath;
	Texture = new FTexture;

	Texture->Load(TextureFilepath);
	Texture->SetKey(Key);
	Texture->SetRelativePath(RelativePath);
	Textures.insert({ Key, Texture });

	return Texture;
}

void FResourceManager::Initialize() {
	FMOD::System_Create(&FmodSystem);

	if (FmodSystem != nullptr) {
		FmodSystem->init((int)ESoundChannel::Last, FMOD_INIT_NORMAL, nullptr);
	}
}

void FResourceManager::LoadSound(const wstring& Key, const wstring& ReleativePath, bool bDoLoop) {
	if (FindSound(Key)) {
		return;
	}

	wstring SoundFilePath = FPathManager::GetInstance()->GetResourcesPath() + ReleativePath;

	std::string SoundFilePathString;

	SoundFilePathString.assign(SoundFilePath.begin(), SoundFilePath.end());

	FMOD_MODE FmodMode = FMOD_LOOP_NORMAL;

	if (!bDoLoop) {
		FmodMode = FMOD_DEFAULT;
	}

	FSoundInformation* SoundInformation = new FSoundInformation;
	SoundInformation->bIsLoop = bDoLoop;

	FmodSystem->createSound(SoundFilePathString.c_str(), FmodMode, nullptr, &SoundInformation->Sound);
	Sounds.insert({ Key, SoundInformation });
}

void FResourceManager::PauseChannel(ESoundChannel SoundChannel, bool bDoPause) {
	FmodChannel[(UINT)SoundChannel]->setPaused(bDoPause);
}

void FResourceManager::PlaySoundByKey(const wstring& Key) {
	FSoundInformation* SoundInformation = FindSound(Key);

	if (!SoundInformation) {
		return;
	}

	FmodSystem->update();

	ESoundChannel SoundChannel = ESoundChannel::BackgroundMusic;

	if (!SoundInformation->bIsLoop) {
		SoundChannel = ESoundChannel::SoundEffect;
	}

	FmodSystem->playSound(SoundInformation->Sound, nullptr, false, &FmodChannel[(UINT)SoundChannel]);
}

void FResourceManager::Release() {
	map<wstring, FTexture*>::iterator TextureIterator;

	for (TextureIterator = Textures.begin(); TextureIterator != Textures.end(); ++TextureIterator) {
		if (TextureIterator->second != nullptr) {
			delete TextureIterator->second;
		}
	}

	Textures.clear();

	map<wstring, FSoundInformation*>::iterator SoundIterator;

	for (SoundIterator = Sounds.begin(); SoundIterator != Sounds.end(); ++SoundIterator) {
		if (SoundIterator->second != nullptr) {
			delete SoundIterator->second;
		}
	}

	Sounds.clear();
	FmodSystem->close();
	FmodSystem->release();
}

void FResourceManager::SetChannelVolume(ESoundChannel SoundChannel, float Volume) {
	FmodChannel[(UINT)SoundChannel]->setVolume(Volume);
}

void FResourceManager::StopChannel(ESoundChannel SoundChannel) {
	FmodChannel[(UINT)SoundChannel]->stop();
}

FSoundInformation* FResourceManager::FindSound(const wstring& Key) {
	map<wstring, FSoundInformation*>::iterator Iterator = Sounds.find(Key);

	if (Iterator == Sounds.end()) {
		return nullptr;
	}

	return Iterator->second;
}
