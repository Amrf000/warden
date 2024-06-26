#include "GLObject.h"
#include "Storm/Debug.h"


void GLObject::AddRefTwin() {
}

uint32_t GLObject::Release() {
    BLIZZARD_ASSERT(this->m_RefCount > 0);

    this->m_RefCount--;

    if (this->m_RefCount == 0) {
        this->ReleaseObject();
    }

    this->ReleaseTwin();

    return this->m_RefCount;
}

void GLObject::ReleaseTwin() {
}
