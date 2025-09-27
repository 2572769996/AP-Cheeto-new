#include "pch-il2cpp.h"
#include "pipeline/gui/tabs/PlayTAB.h"
#include "../../modules/damagehack.h"

void PlayTAB::Render() {
    std::string playertext = ICON_SWORD_LINE + std::string(TR(" Player"));
    if (ImGui::BeginTabItem(playertext.c_str())) {
        ImGui::Spacing();
        
        //ImGui::TextColored(ImVec4(1.0f, 0.8f, 0.0f, 1.0f), "Player Features");
        //ImGui::Separator();
        //ImGui::Spacing();
        
		Damagehack::GetInstance().RenderGUI();

        ImGui::EndTabItem();
    }
}

