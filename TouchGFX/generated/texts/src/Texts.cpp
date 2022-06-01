/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

//Default typed text database
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x3e, 0x20, 0x30, 0x2e, 0x33, 0x20, 0x75, 0x6d, 0x20, 0x20, 0x2, 0x0, // @0 "> 0.3 um  <>"
    0x3e, 0x20, 0x30, 0x2e, 0x35, 0x20, 0x75, 0x6d, 0x20, 0x20, 0x2, 0x0, // @12 "> 0.5 um  <>"
    0x3e, 0x20, 0x31, 0x2e, 0x30, 0x20, 0x75, 0x6d, 0x20, 0x20, 0x2, 0x0, // @24 "> 1.0 um  <>"
    0x3e, 0x20, 0x32, 0x2e, 0x35, 0x20, 0x75, 0x6d, 0x20, 0x20, 0x2, 0x0, // @36 "> 2.5 um  <>"
    0x3e, 0x20, 0x35, 0x2e, 0x30, 0x20, 0x75, 0x6d, 0x20, 0x20, 0x2, 0x0, // @48 "> 5.0 um  <>"
    0x50, 0x4d, 0x20, 0x31, 0x2e, 0x30, 0x20, 0x65, 0x6e, 0x20, 0x2, 0x0, // @60 "PM 1.0 en <>"
    0x50, 0x4d, 0x20, 0x31, 0x2e, 0x30, 0x20, 0x73, 0x74, 0x20, 0x2, 0x0, // @72 "PM 1.0 st <>"
    0x50, 0x4d, 0x20, 0x32, 0x2e, 0x35, 0x20, 0x65, 0x6e, 0x20, 0x2, 0x0, // @84 "PM 2.5 en <>"
    0x50, 0x4d, 0x20, 0x32, 0x2e, 0x35, 0x20, 0x73, 0x74, 0x20, 0x2, 0x0, // @96 "PM 2.5 st <>"
    0x3e, 0x20, 0x31, 0x30, 0x20, 0x75, 0x6d, 0x20, 0x20, 0x2, 0x0, // @108 "> 10 um  <>"
    0x50, 0x4d, 0x20, 0x31, 0x30, 0x20, 0x65, 0x6e, 0x20, 0x2, 0x0, // @119 "PM 10 en <>"
    0x50, 0x4d, 0x20, 0x31, 0x30, 0x20, 0x73, 0x74, 0x20, 0x2, 0x0, // @130 "PM 10 st <>"
    0x20, 0x74, 0x65, 0x6d, 0x70, 0x2, 0x20, 0xb0, 0x43, 0x0, // @141 " temp<> ?C"
    0x43, 0x6c, 0x69, 0x63, 0x6b, 0x20, 0x4d, 0x65, 0x0, // @151 "Click Me"
    0x4e, 0x65, 0x77, 0x20, 0x54, 0x65, 0x78, 0x74, 0x0, // @160 "New Text"
    0x68, 0x75, 0x6d, 0x0 // @169 "hum"
};
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

//array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

//Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
