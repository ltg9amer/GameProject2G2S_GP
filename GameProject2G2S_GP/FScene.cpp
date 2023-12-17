#include "pch.h"
#include "FObject.h"
#include "FScene.h"

FScene::FScene() {
}

FScene::~FScene() {
	Release();
}

void FScene::FinalUpdate() {
	for (UINT i = 0; i < (UINT)EObjectGroup::Last; ++i) {
		if (i == (UINT)EObjectGroup::UserInterface) {
			continue;
		}

		for (size_t j = 0; j < Objects[i].size(); ++j) {
			Objects[i][j]->FinalUpdate();
		}
	}
}

void FScene::Release() {
	for (UINT i = 0; i < (UINT)EObjectGroup::Last; ++i) {
		for (size_t j = 0; j < Objects[i].size(); ++j) {
			delete Objects[i][j];
		}

		Objects[i].clear();
	}
}

void FScene::Render(HDC _dc) {
	for (UINT i = 0; i < (UINT)EObjectGroup::Last; ++i) {
		if (i == (UINT)EObjectGroup::UserInterface) {
			continue;
		}

		for (size_t j = 0; j < Objects[i].size();) {
			if (!Objects[i][j]->IsDead()) {
				Objects[i][j]->Render(_dc);

				++j;
			}
			else {
				Objects[i].erase(Objects[i].begin() + j);
			}
		}
	}
}

void FScene::Update() {
	for (UINT i = 0; i < (UINT)EObjectGroup::Last; ++i) {
		if (i == (UINT)EObjectGroup::UserInterface) {
			continue;
		}

		for (size_t j = 0; j < Objects[i].size(); ++j) {
			if (!Objects[i][j]->IsDead()) {
				Objects[i][j]->Update();
			}
		}
	}
}
