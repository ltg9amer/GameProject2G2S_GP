#include "pch.h"
#include "UI.h"
#include "UIElement.h"

UI::UI()
{
}

UI::~UI()
{
	Release();
}

void UI::Update()
{
	for (UINT i = 0; i < (UINT)UIElementGroup::End; ++i) {
		for (size_t j = 0; j < elements[i].size(); ++j) {
			if (!elements[i][j]->GetIsDead()) {
				elements[i][j]->Update();
			}
		}
	}
}

void UI::Render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)UIElementGroup::End; ++i) {
		for (size_t j = 0; j < elements[i].size();) {
			if (!elements[i][j]->GetIsDead()) {
				elements[i][j]->Render(_dc);

				++j;
			}
			else {
				elements[i].erase(elements[i].begin() + j);
			}
		}
	}
}

void UI::Release()
{
	for (UINT i = 0; i < (UINT)UIElementGroup::End; ++i) {
		for (size_t j = 0; j < elements[i].size(); ++j) {
			delete elements[i][j];
		}

		elements[i].clear();
	}
}
