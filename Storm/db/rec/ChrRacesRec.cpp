#include "ChrRacesRec.h"
#include "Storm/SFile.h"

const char *ChrRacesRec::GetFilename() {
    return "DBFilesClient\\ChrRaces.dbc";
}

uint32_t ChrRacesRec::GetNumColumns() {
    return 69;
}

uint32_t ChrRacesRec::GetRowSize() {
    return 276;
}

bool ChrRacesRec::NeedIDAssigned() {
    return false;
}

int32_t ChrRacesRec::GetID() {
    return this->m_ID;
}

void ChrRacesRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool ChrRacesRec::Read(SFile *f, const char *stringBuffer) {
    uint32_t clientPrefixOfs;
    uint32_t clientFileStringOfs;
    uint32_t nameOfs[16];
    uint32_t nameMask;
    uint32_t nameFemaleOfs[16];
    uint32_t nameFemaleMask;
    uint32_t nameMaleOfs[16];
    uint32_t nameMaleMask;
    uint32_t facialHairCustomizationOfs[2];
    uint32_t hairCustomizationOfs;

    if (
            !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &this->m_flags, sizeof(this->m_flags), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &this->m_factionID, sizeof(this->m_factionID), nullptr, nullptr, nullptr)
            ||
            !SFile::Read(f, &this->m_explorationSoundID, sizeof(this->m_explorationSoundID), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &this->m_maleDisplayID, sizeof(this->m_maleDisplayID), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &this->m_femaleDisplayID, sizeof(this->m_femaleDisplayID), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &clientPrefixOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &this->m_baseLanguage, sizeof(this->m_baseLanguage), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &this->m_creatureType, sizeof(this->m_creatureType), nullptr, nullptr, nullptr)
            ||
            !SFile::Read(f, &this->m_resSicknessSpellID, sizeof(this->m_resSicknessSpellID), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &this->m_splashSoundID, sizeof(this->m_splashSoundID), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &clientFileStringOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &this->m_cinematicSequenceID, sizeof(this->m_cinematicSequenceID), nullptr, nullptr,
                            nullptr)
            || !SFile::Read(f, &this->m_alliance, sizeof(this->m_alliance), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameFemaleMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &nameMaleMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &facialHairCustomizationOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &facialHairCustomizationOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &hairCustomizationOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
            || !SFile::Read(f, &this->m_requiredExpansion, sizeof(this->m_requiredExpansion), nullptr, nullptr, nullptr)
            ) {
        return false;
    }

    if (stringBuffer) {
        this->m_clientPrefix = &stringBuffer[clientPrefixOfs];
        this->m_clientFileString = &stringBuffer[clientFileStringOfs];
        this->m_name = &stringBuffer[nameOfs[0]];
        this->m_nameFemale = &stringBuffer[nameFemaleOfs[0]];
        this->m_nameMale = &stringBuffer[nameMaleOfs[0]];
        this->m_facialHairCustomization[0] = &stringBuffer[facialHairCustomizationOfs[0]];
        this->m_facialHairCustomization[1] = &stringBuffer[facialHairCustomizationOfs[1]];
        this->m_hairCustomization = &stringBuffer[hairCustomizationOfs];
    } else {
        this->m_clientPrefix = "";
        this->m_clientFileString = "";
        this->m_name = "";
        this->m_nameFemale = "";
        this->m_nameMale = "";
        this->m_facialHairCustomization[0] = "";
        this->m_facialHairCustomization[1] = "";
        this->m_hairCustomization = "";
    }

    return true;
}
