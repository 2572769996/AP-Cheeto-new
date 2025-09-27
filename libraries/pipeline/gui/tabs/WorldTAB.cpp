#include "pch-il2cpp.h"
#include "WorldTAB.h"
#include <imgui/imgui.h>
#include "../../modules/WorldSpeedModule.h"


void WorldTAB::Render() {
    std::string worldtext = ICON_EARTH_LINE + std::string(TR(" World"));
    if (ImGui::BeginTabItem(worldtext.c_str())) {
        // Call WorldSpeed module to render its GUI
        WorldSpeedModule::GetInstance().RenderGUI();
        
        ImGui::EndTabItem();
    }
}

