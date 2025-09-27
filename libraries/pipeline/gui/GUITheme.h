#pragma once

enum class GUITheme {
    Default,
    EvangelionUnit01,
    EvangelionUnit02
};

void ApplySelectedTheme(GUITheme theme);
ImVec4 HexToImVec4(unsigned int hex);
ImVec4 StringHexToImVec4(const char* hexString);
void ApplyEvangelionUnit01Style();
void ApplyEvangelionUnit02Style();