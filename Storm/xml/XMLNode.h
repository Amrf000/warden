#pragma once


#include <cstdint>
#include "Common/RCString.h"
#include "XMLAttribute.h"
#include "Common/TSGrowableArray.h"


class XMLNode {
public:
    // Member variables
    void *m_userData;
    XMLNode *m_parent;
    XMLNode *m_child;
    RCString m_name;
    char *m_body;
    uint32_t m_bodyLen;
    TSGrowableArray <XMLAttribute> m_attributes;
    uint32_t m_offset;
    XMLNode *m_next;

    // Member functions
    XMLNode();

    ~XMLNode();

    const char *GetAttributeByName(const char *name);

    const char *GetBody() const;

    XMLNode *GetChildByName(const char *name);

    const char *GetName();

    void Init(XMLNode *parent, const char *name);

    void SetAttribute(const char *name, const char *value);
};


