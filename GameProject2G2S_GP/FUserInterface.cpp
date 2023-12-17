#include "pch.h"
#include "FUserInterface.h"
#include "FUserInterfaceElement.h"

FUserInterface::FUserInterface() : OwnerScene(nullptr) {

}

FUserInterface::~FUserInterface() {
	Release();
}

void FUserInterface::Update() {
	for (UINT i = 0; i < (UINT)EUserInterfaceElementGroup::Last; ++i) {
		for (size_t j = 0; j < Elements[i].size(); ++j) {
			if (!Elements[i][j]->IsDead()) {
				Elements[i][j]->Update();
			}
		}
	}
}

void FUserInterface::Render(HDC _dc) {
	for (UINT i = 0; i < (UINT)EUserInterfaceElementGroup::Last; ++i) {
		for (size_t j = 0; j < Elements[i].size();) {
			if (!Elements[i][j]->IsDead()) {
				Elements[i][j]->Render(_dc);

				++j;
			}
			else {
				Elements[i].erase(Elements[i].begin() + j);
			}
		}
	}
}

void FUserInterface::Release() {
	for (UINT i = 0; i < (UINT)EUserInterfaceElementGroup::Last; ++i) {
		for (size_t j = 0; j < Elements[i].size(); ++j) {
			delete Elements[i][j];
		}

		Elements[i].clear();
	}
}
