#include "pch-il2cpp.h"
#include "PlayerProfile.h"
#include <iostream>

PlayerProfile::PlayerProfile() : BaseModule("PlayerProfile") {
	uidtext = "";
	nametext = "";
}

void PlayerProfile::Initialize() {
	// std::cout << "[INFO] FPS Module initialized" << std::endl;
	LoadConfig();
}

void PlayerProfile::Shutdown() {
	SaveConfig();

}

void PlayerProfile::OnUpdate() {
	// Synchronization is now automatic
}



void PlayerProfile::RenderGUI() {
	if (ImGui::CollapsingHeader("PlayerProfile")) {
		ImGui::Indent();
		if (ToggleSwitch("Profile changer", &enabled)) {
			if (enabled)
			{
				app::GameObject* uid = app::GameObject_Find(string_to_il2cppi_app("/[UI Root]/[VisiableWaterMark]/testingWaterMark/markIdText"), nullptr);				
				app::GameObject* Carduid = app::GameObject_Find(string_to_il2cppi_app("/[UI Root]/pagePlayerCard/board/Bottom/Left/uid/bg/txt_uid"), nullptr);
				if (uid != nullptr) {
					app::Component* LText_comp = app::GameObject_GetComponentByName(uid, string_to_il2cppi_app("TextMeshProUGUI"), nullptr);
					if (LText_comp != nullptr) {
						app::LTextMeshProUGUI_set_text(RCAST(app::LTextMeshProUGUI*, LText_comp), string_to_il2cppi_app(uidtext), nullptr);
					}
				}
				if (Carduid != nullptr) {
					app::Component* LText_comp_ = app::GameObject_GetComponentByName(Carduid, string_to_il2cppi_app("TextMeshProUGUI"), nullptr);
					if (LText_comp_ != nullptr) {
						app::LTextMeshProUGUI_set_text(RCAST(app::LTextMeshProUGUI*, LText_comp_), string_to_il2cppi_app(uidtext), nullptr);
					}
				}
			}
		}
		if (enabled) {
			InputText("UID text", &uidtext);
			InputText("Name text", &nametext);
			if (ToggleSwitch("Name changer", &enabled)) {
				app::GameObject* name = app::GameObject_Find(string_to_il2cppi_app("/[UI Root]/pagePlayerCard/board/Right/info/title/name/txt_name"), nullptr);
				if (name != nullptr) {
					app::Component* LText_comp = app::GameObject_GetComponentByName(name, string_to_il2cppi_app("TextMeshProUGUI"), nullptr);
					if (LText_comp != nullptr) {
						app::LTextMeshProUGUI_set_text(RCAST(app::LTextMeshProUGUI*, LText_comp), string_to_il2cppi_app(nametext), nullptr);
					}
				}
			}
			
		}


		ImGui::Unindent();
	}
}


void PlayerProfile::RenderOverlay() {

}

void PlayerProfile::ProcessHotkeys() {

}



