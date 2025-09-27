#pragma once
#include "pch-il2cpp.h"

namespace SettingsTAB {
	inline static int selectedLanguageIndex = 0; // New static variable to store selected language index
	void Render();
	// FPSRander function moved to FPSModule
	void ToggleConsole(BOOL show);
}