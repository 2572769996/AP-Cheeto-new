#include "pch-il2cpp.h"
#include "VisualTAB.h"
#include <imgui/imgui.h>
#include "../../modules/FPSModule.h"
#include "../../modules/FreeCam.h"
#include "../../modules/NoFog.h"
#include "../../modules/FpsUnlocker.h"
#include "../../modules/PlayerProfile.h"

void VisualTAB::Render() {
    std::string visualtext = ICON_LAYOUT_2_LINE + std::string(" Visual");
    if (ImGui::BeginTabItem(visualtext.c_str())) {
        // Call FPS module to render its GUI
        FPSModule::GetInstance().RenderGUI();
        FreeCam::GetInstance().RenderGUI();
        NoFog::GetInstance().RenderGUI();
		FpsUnlocker::GetInstance().RenderGUI();
        PlayerProfile::GetInstance().RenderGUI();
        ImGui::EndTabItem();
    }
}

