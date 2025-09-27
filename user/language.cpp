#include "pch-il2cpp.h"
#include "language.h"
#include "helpers.h"

Translator::Translator() {
    loadFromResource();
}

Translator& Translator::getInstance() {
    static Translator instance;
    return instance;
}

bool Translator::loadFromResource() {
    std::string json_str;
    if (LoadRCDATAToString(LANG_JSON, json_str)) {
        return loadFromString(json_str);
    }
    return false;
}

bool Translator::reload() {
    return loadFromResource();
}

bool Translator::loadFromString(const std::string& jsonStr) {
    try {
        translations = nlohmann::json::parse(jsonStr);
        return true;
    }
    catch (const nlohmann::json::exception& e) {
        return false;
    }
}

std::string Translator::translate(const std::string& key) const {
    try {
        const auto& translation = translations.at(key);
        const std::string langStr = getLanguageString(currentLanguage);
        
        if (translation.contains(langStr)) {
            return translation[langStr].get<std::string>();
        }
    }
    catch (const nlohmann::json::exception&) {
        // If any error occurs during translation lookup, return the original key
    }
    
    return key;
}

void Translator::setLanguage(Language lang) {
    currentLanguage = lang;
}

Language Translator::getLanguage() const {
    return currentLanguage;
}

std::string Translator::getLanguageString(Language lang) const {
    switch (lang) {
        case Language::en:
            return "en";
        case Language::zh_cn:
            return "zh_cn";
        default:
            return "en";
    }
}