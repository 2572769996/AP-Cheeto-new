#include "pch-il2cpp.h"
#include "pipeline/gui/tabs/SettingsTAB.h"
#include "pipeline/settings.h"
#include "../../modules/UnityExplorerModule.h"



void SettingsTAB::Render()
{
    std::string settingstext = ICON_SETTINGS_3_LINE + std::string(" ") + TR("Settings");
    if (ImGui::BeginTabItem(settingstext.c_str())) {
        ImGui::Spacing();

        //ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.8f, 1.0f), "General Settings");
        //ImGui::Separator();
        //ImGui::Spacing();
        //
        //ImGui::Text("Application settings will be added here.");
        auto& translator = Translator::getInstance();
        const char* current_lang = (translator.getLanguage() == Language::en) ? "English" : "简体中文";
        if (ImGui::BeginCombo(TR("Language"), current_lang))
        {
            if (ImGui::Selectable("English")) {
                translator.setLanguage(Language::en);
            }
            if (ImGui::Selectable("简体中文")) {
                translator.setLanguage(Language::zh_cn);
            }
            ImGui::EndCombo();
        }
        ImGui::Spacing();

        // Theme Selection
        


        if (ImGui::BeginCombo(TR("Theme"), settings.current_theme_name))
        {
            if (ImGui::Selectable(TR("Default"))) {
                settings.current_theme_name = "Default";
				settings.currentTheme = GUITheme::Default;
            }
            if (ImGui::Selectable("Evangelion Unit 01")) {
                settings.current_theme_name = "Evangelion Unit 01";
				settings.currentTheme = GUITheme::EvangelionUnit01;
            }
            if (ImGui::Selectable(TR("Evangelion Unit 02"))) {
                settings.current_theme_name = "Evangelion Unit 02";
				settings.currentTheme = GUITheme::EvangelionUnit02;
            }
            ImGui::EndCombo();
        }
        ImGui::Spacing();

        if (ToggleSwitch(TR("Toggle Console"), &settings.show_console)) {
            ToggleConsole(settings.show_console);
            LOG_INFO("{} {}", "Console", settings.show_console ? TR("enabled") : TR("Disabled"));
        }

 

        UnityExplorerModule::GetInstance().RenderGUI();
        
        if (ImGui::Button("load json")) {
            std::string json_str;
            if (LoadRCDATAToString(LANG_JSON, json_str))
                printf("%s\n", json_str.c_str());
            else
                printf("no");
			
        }

        
        ImGui::EndTabItem();
    }
}

void SettingsTAB::ToggleConsole(BOOL show)
{
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL)
    {
        ShowWindow(hwnd, show ? SW_SHOW : SW_HIDE);
    }
}