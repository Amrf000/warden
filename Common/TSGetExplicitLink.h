// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#ifndef WARDEN_TSGETEXPLICITLINK_H
#define WARDEN_TSGETEXPLICITLINK_H

template<typename T>
class TSGetExplicitLink {
private:
    T *m_prevLink;
    T *m_nextLink;

public:
    TSGetExplicitLink() : m_prevLink(nullptr), m_nextLink(nullptr) {}

    T *GetPrevLink() const {
        return m_prevLink;
    }

    T *GetNextLink() const {
        return m_nextLink;
    }

    void SetPrevLink(T *prev) {
        m_prevLink = prev;
    }

    void SetNextLink(T *next) {
        m_nextLink = next;
    }
};

#endif //WARDEN_TSGETEXPLICITLINK_H
