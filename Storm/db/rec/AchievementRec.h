#pragma once

#include <cstdint>

class SFile;

class AchievementRec {
public:
    int32_t m_ID;
    int32_t m_faction;
    int32_t m_instanceID;
    int32_t m_supercedes;
    const char *m_title;
    const char *m_description;
    int32_t m_category;
    int32_t m_points;
    int32_t m_uiOrder;
    int32_t m_flags;
    int32_t m_iconID;
    const char *m_reward;
    int32_t m_minimumCriteria;
    int32_t m_sharesCriteria;

    static const char *GetFilename();

    static uint32_t GetNumColumns();

    static uint32_t GetRowSize();

    int32_t GetID();

    bool Read(SFile *f, const char *stringBuffer);
};


