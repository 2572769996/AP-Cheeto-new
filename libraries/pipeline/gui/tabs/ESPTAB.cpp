#include "pch-il2cpp.h"
#include "pipeline/gui/tabs/ESPTAB.h"
#include "../../modules/ESPModule.h"

void ESPTAB::Render() {
	std::string esptext = ICON_EYE_LINE + std::string(TR(" ESP"));
	if (ImGui::BeginTabItem(esptext.c_str())) {
		// Call ESP module to render its GUI
		ESPModule::GetInstance().RenderGUI();

		ImGui::EndTabItem();
	}
}