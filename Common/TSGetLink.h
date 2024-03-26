// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#ifndef WARDEN_TSGETLINK_H
#define WARDEN_TSGETLINK_H

template<typename T>
class TSGetLink {
private:
    T *m_link;

public:
    TSGetLink() : m_link(nullptr) {}

    T *GetLink() const {
        return m_link;
    }

    void SetLink(T *link) {
        m_link = link;
    }
};

#endif //WARDEN_TSGETLINK_H