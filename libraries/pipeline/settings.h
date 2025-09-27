#pragma once

#include "keybinds.h"
#include "./gui/GUITheme.h"

class Settings {
public:
#pragma region MenuStatus
	KeyBinds::Config KeyBinds = {
		VK_F12 // toggle menu
	};
	const char* current_theme_name = "Evangelion Unit 01";
	bool ImGuiInitialized = false;
	bool bShowMenu = true;
	bool show_console = true;
	GUITheme currentTheme = GUITheme::EvangelionUnit01; // 全局变量来存储当前主题
private:
	
	 
};

extern Settings settings;