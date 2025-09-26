#include "pch-il2cpp.h"

#include "pipeline/gui/GUITheme.h"
#include "pipeline/settings.h"
#include <imgui/imgui.h>
#include <cmath>
#include <cstring> // 需要 strlen
#include <cstdio> // 需要 sscanf
ImVec4 HexToImVec4(unsigned int hex) {
    float r = ((hex >> 24) & 0xFF) / 255.0f;
    float g = ((hex >> 16) & 0xFF) / 255.0f;
    float b = ((hex >> 8) & 0xFF) / 255.0f;
    float a = (hex & 0xFF) / 255.0f;
    return ImVec4(r, g, b, a);
}

// 辅助函数：将 "RRGGBBAA" 字符串转换为 ImVec4
// 保留您的辅助函数
ImVec4 StringHexToImVec4(const char* hexString) {
    if (strlen(hexString) != 8) return ImVec4(0, 0, 0, 1); // 错误处理

    unsigned int value;
    // 使用 std::sscanf 安全地读取十六进制值
    if (sscanf_s(hexString, "%x", &value) != 1) return ImVec4(0, 0, 0, 1);

    float r = ((value >> 24) & 0xFF) / 255.0f;
    float g = ((value >> 16) & 0xFF) / 255.0f;
    float b = ((value >> 8) & 0xFF) / 255.0f;
    float a = (value & 0xFF) / 255.0f;
    return ImVec4(r, g, b, a);
}

void ApplyTheme()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(0.85f, 0.85f, 0.85f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.05f, 0.07f, 0.90f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.05f, 0.05f, 0.07f, 0.90f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.10f, 0.10f, 0.12f, 0.95f);

    colors[ImGuiCol_Border] = ImVec4(0.20f, 0.20f, 0.25f, 0.50f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.00f);

    colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.10f, 0.12f, 0.85f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.15f, 0.15f, 0.18f, 0.85f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.20f, 0.24f, 0.85f);

    colors[ImGuiCol_TitleBg] = ImVec4(0.07f, 0.07f, 0.09f, 0.85f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.10f, 0.10f, 0.12f, 0.95f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.05f, 0.05f, 0.07f, 0.80f);

    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.60f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.30f, 0.30f, 0.35f, 0.80f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.35f, 0.35f, 0.40f, 0.90f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.40f, 0.40f, 0.45f, 1.00f);

    colors[ImGuiCol_CheckMark] = ImVec4(0.70f, 0.70f, 0.75f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.30f, 0.30f, 0.35f, 0.80f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.35f, 0.35f, 0.40f, 1.00f);

    colors[ImGuiCol_Button] = ImVec4(0.10f, 0.10f, 0.12f, 0.80f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0.15f, 0.18f, 0.85f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.20f, 0.24f, 0.90f);

    colors[ImGuiCol_Header] = ImVec4(0.12f, 0.12f, 0.15f, 0.80f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.17f, 0.17f, 0.20f, 0.85f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.22f, 0.22f, 0.26f, 0.90f);

    colors[ImGuiCol_Separator] = ImVec4(0.15f, 0.15f, 0.18f, 0.50f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.20f, 0.20f, 0.24f, 0.75f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.25f, 0.25f, 0.30f, 1.00f);

    colors[ImGuiCol_ResizeGrip] = ImVec4(0.30f, 0.30f, 0.35f, 0.25f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.35f, 0.35f, 0.40f, 0.50f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.40f, 0.45f, 0.70f);

    colors[ImGuiCol_Tab] = ImVec4(0.10f, 0.10f, 0.12f, 0.80f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.15f, 0.15f, 0.18f, 0.85f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.24f, 0.90f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.07f, 0.09f, 0.70f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.12f, 0.12f, 0.15f, 0.80f);

    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.05f, 0.05f, 0.07f, 0.73f);

    style.WindowRounding = 8.0f;
    style.ChildRounding = 4.0f;
    style.FrameRounding = 4.0f;
    style.PopupRounding = 4.0f;
    style.ScrollbarRounding = 4.0f;
    style.GrabRounding = 4.0f;
    style.TabRounding = 4.0f;

    style.WindowPadding = ImVec2(10, 10);
    style.FramePadding = ImVec2(8, 6);
    style.ItemSpacing = ImVec2(8, 8);
    style.ItemInnerSpacing = ImVec2(6, 6);
    style.IndentSpacing = 21.0f;

    style.ScrollbarSize = 15.0f;
    style.GrabMinSize = 10.0f;
}
void ApplyEvangelionUnit01Style() {
    ImGuiStyle& style = ImGui::GetStyle();

    // ----------------------------------------------------
    // 1. 样式设置 (Style) - 沿用您的基本设置，保持简洁
    // ----------------------------------------------------
    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.60f;
    style.WindowPadding = ImVec2(10.0f, 10.0f); // 略大一点
    style.WindowRounding = 4.0f; // 略微方正
    style.WindowBorderSize = 0.0f;
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f); // 标题居中
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 4.0f;
    style.ChildBorderSize = 0.0f;
    style.PopupRounding = 4.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(6.0f, 4.0f); // 略大一点
    style.FrameRounding = 4.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 6.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.TabRounding = 4.0f; // 标签圆角
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabRounding = 4.0f; // 抓手圆角
    style.AntiAliasedLines = true;
    style.AntiAliasedFill = true;

    // ----------------------------------------------------
    // 2. 颜色设置 (Colors) - 初号机主题配色
    // ----------------------------------------------------
    // 主题色板:
    // - 深背景: 19171C (近黑色)
    // - 次背景: 2A282E (深灰)
    // - 主色 (紫): 7857A7 (深紫) / A38CCF (亮紫)
    // - 辅色 (绿): 4DE6A5 (青色/青柠绿)
    // - 强调色 (黄/橙): FFD700 (金色) / FFA500 (橙色)

    ImVec4* colors = style.Colors;

    colors[ImGuiCol_Text] = StringHexToImVec4("FFFFFFFF");      // 纯白色文字
    colors[ImGuiCol_TextDisabled] = StringHexToImVec4("7857A7FF"); // 禁用文字 (深紫)

    // 背景
    colors[ImGuiCol_WindowBg] = StringHexToImVec4("19171CFF");   // 窗口背景 (近黑色)
    colors[ImGuiCol_ChildBg] = StringHexToImVec4("2A282EFF");    // 子窗口背景 (深灰)
    colors[ImGuiCol_PopupBg] = StringHexToImVec4("2A282EE6");    // 弹窗背景 (略透明深灰)
    colors[ImGuiCol_Border] = StringHexToImVec4("4DE6A5FF");     // 边框 (青柠绿)
    colors[ImGuiCol_BorderShadow] = StringHexToImVec4("00000000"); // 无阴影

    // 帧背景 (Frame) - 按钮/输入框/滑块的背景
    colors[ImGuiCol_FrameBg] = StringHexToImVec4("4A455240");    // 半透明深色背景
    colors[ImGuiCol_FrameBgHovered] = StringHexToImVec4("A38CCF80"); // 悬停时的亮紫色 (半透明)
    colors[ImGuiCol_FrameBgActive] = StringHexToImVec4("7857A780");  // 激活时的深紫色 (半透明)

    // 标题栏 (Title)
    colors[ImGuiCol_TitleBg] = StringHexToImVec4("2A282EFF");    // 标题栏背景
    colors[ImGuiCol_TitleBgActive] = StringHexToImVec4("7857A7FF"); // 活动窗口标题栏 (深紫)
    colors[ImGuiCol_TitleBgCollapsed] = StringHexToImVec4("4A4552FF"); // 折叠窗口标题栏

    colors[ImGuiCol_MenuBarBg] = StringHexToImVec4("2A282EFF");  // 菜单栏背景

    // 头部 (Header) - 树节点/可折叠部分
    colors[ImGuiCol_Header] = StringHexToImVec4("7857A7FF");     // 深紫
    colors[ImGuiCol_HeaderHovered] = StringHexToImVec4("A38CCFFF"); // 悬停时亮紫
    colors[ImGuiCol_HeaderActive] = StringHexToImVec4("4DE6A5FF");  // 激活时青柠绿 (初号机高光)

    // 按钮 (Button) - 强调色
    colors[ImGuiCol_Button] = StringHexToImVec4("4DE6A5FF");     // 青柠绿按钮
    colors[ImGuiCol_ButtonHovered] = StringHexToImVec4("98FF98FF"); // 悬停时更亮的绿
    colors[ImGuiCol_ButtonActive] = StringHexToImVec4("FFD700FF");  // 激活时的金色 (点缀)

    // 滑块 (Slider) & 抓手 (Grab)
    colors[ImGuiCol_SliderGrab] = StringHexToImVec4("7857A7FF");   // 深紫滑块
    colors[ImGuiCol_SliderGrabActive] = StringHexToImVec4("FFD700FF"); // 激活时的金色
    colors[ImGuiCol_CheckMark] = StringHexToImVec4("FFD700FF");    // 勾选标记 (金色)
    colors[ImGuiCol_ResizeGrip] = StringHexToImVec4("A38CCF80");    // 亮紫调整手柄 (半透明)
    colors[ImGuiCol_ResizeGripHovered] = StringHexToImVec4("4DE6A5FF");
    colors[ImGuiCol_ResizeGripActive] = StringHexToImVec4("FFD700FF");

    // 滚动条 (Scrollbar)
    colors[ImGuiCol_ScrollbarBg] = StringHexToImVec4("19171C00"); // 滚动条背景（透明）
    colors[ImGuiCol_ScrollbarGrab] = StringHexToImVec4("4A4552FF"); // 抓取部分 (深灰)
    colors[ImGuiCol_ScrollbarGrabHovered] = StringHexToImVec4("7857A7FF");
    colors[ImGuiCol_ScrollbarGrabActive] = StringHexToImVec4("A38CCFFF");

    // 分隔符 (Separator)
    colors[ImGuiCol_Separator] = StringHexToImVec4("4DE6A5FF"); // 青柠绿分隔符
    colors[ImGuiCol_SeparatorHovered] = StringHexToImVec4("98FF98FF");
    colors[ImGuiCol_SeparatorActive] = StringHexToImVec4("FFD700FF");

    // Tab 栏
    colors[ImGuiCol_Tab] = StringHexToImVec4("7857A7FF"); // 未选中 Tab (深紫)
    colors[ImGuiCol_TabHovered] = StringHexToImVec4("4DE6A5FF"); // 悬停 Tab (青柠绿
    colors[ImGuiCol_TabActive] = StringHexToImVec4("FFD700FF"); // 选中 Tab (金)
    colors[ImGuiCol_TabUnfocused] = StringHexToImVec4("4A4552E0");
    colors[ImGuiCol_TabUnfocusedActive] = StringHexToImVec4("7857A7E0");

    // 绘制 (Plot) - 使用青柠绿和金色
    colors[ImGuiCol_PlotLines] = StringHexToImVec4("4DE6A5FF");
    colors[ImGuiCol_PlotLinesHovered] = StringHexToImVec4("FFD700FF");
    colors[ImGuiCol_PlotHistogram] = StringHexToImVec4("4DE6A5FF");
    colors[ImGuiCol_PlotHistogramHovered] = StringHexToImVec4("FFD700FF");

    // 表格 (Table)
    colors[ImGuiCol_TableHeaderBg] = StringHexToImVec4("7857A7FF"); // 表格头背景 (深紫)
    colors[ImGuiCol_TableRowBg] = StringHexToImVec4("2A282EF8"); // 表格行背景
    colors[ImGuiCol_TableRowBgAlt] = StringHexToImVec4("252329EC"); // 表格交替行背景
    colors[ImGuiCol_TableBorderStrong] = StringHexToImVec4("4DE6A5FF");
    colors[ImGuiCol_TableBorderLight] = StringHexToImVec4("4A45526E");

    // 选中/高亮
    colors[ImGuiCol_TextSelectedBg] = StringHexToImVec4("4DE6A533"); // 选中文本背景 (青柠绿透明)
    colors[ImGuiCol_DragDropTarget] = StringHexToImVec4("FFD700E6"); // 金色
    colors[ImGuiCol_NavHighlight] = StringHexToImVec4("A38CCFB3"); // 导航高亮 (亮紫)
    colors[ImGuiCol_NavWindowingHighlight] = StringHexToImVec4("FFFFFFB3");
    colors[ImGuiCol_NavWindowingDimBg] = StringHexToImVec4("2A282EAA");
    //colors[ImGuiCol_DockingPreview] = StringHexToImVec4("4DE6A5B3"); // Docking 预览 (青柠绿透明)
    //colors[ImGuiCol_DockingEmptyBg] = StringHexToImVec4("19171CFF");
    colors[ImGuiCol_ModalWindowDimBg] = StringHexToImVec4("0000007A"); // 模态窗口变暗背景
}
void ApplyEvangelionUnit02Style() {
    ImGuiStyle& style = ImGui::GetStyle();

    // ----------------------------------------------------
    // 1. 样式设置 (Style) - 沿用 Unit-01 的设置，保持 UI 结构一致
    // ----------------------------------------------------
    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.60f;
    style.WindowPadding = ImVec2(10.0f, 10.0f);
    style.WindowRounding = 4.0f;
    style.WindowBorderSize = 0.0f;
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 4.0f;
    style.ChildBorderSize = 0.0f;
    style.PopupRounding = 4.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(6.0f, 4.0f);
    style.FrameRounding = 4.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 6.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.TabRounding = 4.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabRounding = 4.0f;
    style.AntiAliasedLines = true;
    style.AntiAliasedFill = true;

    // ----------------------------------------------------
    // 2. 颜色设置 (Colors) - 二号机主题配色
    // ----------------------------------------------------
    // 主题色板:
    // - 深背景: 1E1E1E (深黑灰)
    // - 次背景: 3A3A3A (深灰)
    // - 主色 (红): D9293B (深红) / F74658 (亮红)
    // - 辅色 (橙黄): F7B302 (橙黄) / FFE664 (浅黄)

    ImVec4* colors = style.Colors;

    colors[ImGuiCol_Text] = StringHexToImVec4("FFFFFFFF");      // 纯白色文字
    colors[ImGuiCol_TextDisabled] = StringHexToImVec4("D9293BFF"); // 禁用文字 (深红)

    // 背景
    colors[ImGuiCol_WindowBg] = StringHexToImVec4("1E1E1EFF");   // 窗口背景 (深黑灰)
    colors[ImGuiCol_ChildBg] = StringHexToImVec4("3A3A3AFF");    // 子窗口背景 (深灰)
    colors[ImGuiCol_PopupBg] = StringHexToImVec4("3A3A3AE6");    // 弹窗背景 (略透明深灰)
    colors[ImGuiCol_Border] = StringHexToImVec4("F7B302FF");     // 边框 (橙黄)
    colors[ImGuiCol_BorderShadow] = StringHexToImVec4("00000000"); // 无阴影

    // 帧背景 (Frame) - 按钮/输入框/滑块的背景
    colors[ImGuiCol_FrameBg] = StringHexToImVec4("4A455240");    // 半透明深色背景
    colors[ImGuiCol_FrameBgHovered] = StringHexToImVec4("F7465880"); // 悬停时的亮红 (半透明)
    colors[ImGuiCol_FrameBgActive] = StringHexToImVec4("D9293B80");  // 激活时的深红 (半透明)

    // 标题栏 (Title)
    colors[ImGuiCol_TitleBg] = StringHexToImVec4("3A3A3AFF");    // 标题栏背景
    colors[ImGuiCol_TitleBgActive] = StringHexToImVec4("D9293BFF"); // 活动窗口标题栏 (深红)
    colors[ImGuiCol_TitleBgCollapsed] = StringHexToImVec4("4A4552FF"); // 折叠窗口标题栏

    colors[ImGuiCol_MenuBarBg] = StringHexToImVec4("3A3A3AFF");  // 菜单栏背景

    // 头部 (Header) - 树节点/可折叠部分
    colors[ImGuiCol_Header] = StringHexToImVec4("D9293BFF");     // 深红
    colors[ImGuiCol_HeaderHovered] = StringHexToImVec4("F74658FF"); // 悬停时亮红
    colors[ImGuiCol_HeaderActive] = StringHexToImVec4("F7B302FF");  // 激活时橙黄 (二号机高光)

    // 按钮 (Button) - 强调色
    colors[ImGuiCol_Button] = StringHexToImVec4("F7B302FF");     // 橙黄按钮
    colors[ImGuiCol_ButtonHovered] = StringHexToImVec4("FFE664FF"); // 悬停时更亮的黄
    colors[ImGuiCol_ButtonActive] = StringHexToImVec4("F74658FF");  // 激活时的亮红 (点缀)

    // 滑块 (Slider) & 抓手 (Grab)
    colors[ImGuiCol_SliderGrab] = StringHexToImVec4("D9293BFF");   // 深红滑块
    colors[ImGuiCol_SliderGrabActive] = StringHexToImVec4("F7B302FF"); // 激活时的橙黄
    colors[ImGuiCol_CheckMark] = StringHexToImVec4("F7B302FF");    // 勾选标记 (橙黄)
    colors[ImGuiCol_ResizeGrip] = StringHexToImVec4("F7465880");    // 亮红调整手柄 (半透明)
    colors[ImGuiCol_ResizeGripHovered] = StringHexToImVec4("F7B302FF");
    colors[ImGuiCol_ResizeGripActive] = StringHexToImVec4("D9293BFF");

    // 滚动条 (Scrollbar)
    colors[ImGuiCol_ScrollbarBg] = StringHexToImVec4("1E1E1E00"); // 滚动条背景（透明）
    colors[ImGuiCol_ScrollbarGrab] = StringHexToImVec4("4A4552FF"); // 抓取部分 (深灰)
    colors[ImGuiCol_ScrollbarGrabHovered] = StringHexToImVec4("D9293BFF");
    colors[ImGuiCol_ScrollbarGrabActive] = StringHexToImVec4("F74658FF");

    // 分隔符 (Separator)
    colors[ImGuiCol_Separator] = StringHexToImVec4("F7B302FF"); // 橙黄分隔符
    colors[ImGuiCol_SeparatorHovered] = StringHexToImVec4("FFE664FF");
    colors[ImGuiCol_SeparatorActive] = StringHexToImVec4("D9293BFF");

    // Tab 栏
    colors[ImGuiCol_Tab] = StringHexToImVec4("3A3A3AFF"); // 未选中 Tab (深灰)
    colors[ImGuiCol_TabHovered] = StringHexToImVec4("D9293BFF"); // 悬停 Tab (深红)
    colors[ImGuiCol_TabActive] = StringHexToImVec4("F74658FF"); // 选中 Tab (亮红)
    colors[ImGuiCol_TabUnfocused] = StringHexToImVec4("3A3A3AE0");
    colors[ImGuiCol_TabUnfocusedActive] = StringHexToImVec4("D9293BE0");

    // 绘制 (Plot) - 使用亮红和橙黄
    colors[ImGuiCol_PlotLines] = StringHexToImVec4("F74658FF");
    colors[ImGuiCol_PlotLinesHovered] = StringHexToImVec4("F7B302FF");
    colors[ImGuiCol_PlotHistogram] = StringHexToImVec4("F74658FF");
    colors[ImGuiCol_PlotHistogramHovered] = StringHexToImVec4("F7B302FF");

    // 表格 (Table)
    colors[ImGuiCol_TableHeaderBg] = StringHexToImVec4("D9293BFF"); // 表格头背景 (深红)
    colors[ImGuiCol_TableRowBg] = StringHexToImVec4("3A3A3AF8"); // 表格行背景
    colors[ImGuiCol_TableRowBgAlt] = StringHexToImVec4("353535EC"); // 表格交替行背景
    colors[ImGuiCol_TableBorderStrong] = StringHexToImVec4("F7B302FF");
    colors[ImGuiCol_TableBorderLight] = StringHexToImVec4("4A45526E");

    // 选中/高亮
    colors[ImGuiCol_TextSelectedBg] = StringHexToImVec4("F7465833"); // 选中文本背景 (亮红透明)
    colors[ImGuiCol_DragDropTarget] = StringHexToImVec4("F7B302E6"); // 橙黄
    colors[ImGuiCol_NavHighlight] = StringHexToImVec4("F74658B3"); // 导航高亮 (亮红)
    colors[ImGuiCol_NavWindowingHighlight] = StringHexToImVec4("FFFFFFB3");
    colors[ImGuiCol_NavWindowingDimBg] = StringHexToImVec4("3A3A3AAA");
    //colors[ImGuiCol_DockingPreview] = StringHexToImVec4("F7B302B3"); // Docking 预览 (橙黄透明)
   // colors[ImGuiCol_DockingEmptyBg] = StringHexToImVec4("1E1E1EFF");
    colors[ImGuiCol_ModalWindowDimBg] = StringHexToImVec4("0000007A"); // 模态窗口变暗背景
}