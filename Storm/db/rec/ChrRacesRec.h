#pragma once

#include <cstdint>

class SFile;

class ChrRacesRec {
public:
    int32_t m_ID;
    int32_t m_flags;
    int32_t m_factionID;
    int32_t m_explorationSoundID;
    int32_t m_maleDisplayID;
    int32_t m_femaleDisplayID;
    const char *m_clientPrefix;
    int32_t m_baseLanguage;
    int32_t m_creatureType;
    int32_t m_resSicknessSpellID;
    int32_t m_splashSoundID;
    const char *m_clientFileString;
    int32_t m_cinematicSequenceID;
    int32_t m_alliance;
    const char *m_name;
    const char *m_nameFemale;
    const char *m_nameMale;
    const char *m_facialHairCustomization[2];
    const char *m_hairCustomization;
    int32_t m_requiredExpansion;

    static const char *GetFilename();

    static uint32_t GetNumColumns();

    static uint32_t GetRowSize();

    static bool NeedIDAssigned();

    int32_t GetID();

    void SetID(int32_t id);

    bool Read(SFile *f, const char *stringBuffer);
};


