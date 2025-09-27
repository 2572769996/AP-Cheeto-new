#pragma once
#include <string>
#include <unordered_map>


#define TR(key) Translator::getInstance().translate(key).c_str()


enum class Language {
    en,
    zh_cn
};

class Translator {
public:
    static Translator& getInstance();
    bool loadFromString(const std::string& jsonStr);
    std::string translate(const std::string& key ) const;
    void setLanguage(Language lang);
    Language getLanguage() const;
    bool reload();

private:
    Translator();  // 修改构造函数为非default
    Translator(const Translator&) = delete;
    Translator& operator=(const Translator&) = delete;

    bool loadFromResource();
    Language currentLanguage = Language::en;
    nlohmann::json translations;

    std::string getLanguageString(Language lang) const;
};