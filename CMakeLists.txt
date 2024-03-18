cmake_minimum_required(VERSION 3.27)
project(warden)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    add_compile_options(/wd4819)
endif ()

add_executable(warden main.cpp
        base/TSCD.h
        base/TRefCnt.cpp
        base/TRefCnt.h
        base/memory.cpp
        base/memory.h
        base/platform_win.cpp
        base/platform_win.h
        base/CEvent.cpp
        base/CEvent.h
        base/CEvent.h
        base/CPresenceRef.cpp
        base/CPresenceRef.h
        base/CPresenceRef.h
        base/CObserver.cpp
        base/CObserver.h
        base/CEventTimer.cpp
        base/CEventTimer.h
        base/CEventTimer.h
        base/RCString.cpp
        base/RCString.h
        base/RCString.h
        base/CAgentTimer.cpp
        base/CAgentTimer.h
        base/TInstanceAllocator.h
        base/TInstanceAllocator.h
        base/TSLink.h
        base/TSLink.h
        base/TSLinkedNode.h
        base/TSBaseArray.h
        base/TSBaseArray.h
        base/TSList.h
        base/TSList.h
        base/TSGetExplicitLink.h
        base/TSGetLink.h
        base/TSGetLink.h
        base/TSFixedArray.h
        base/TSFixedArray.h
        base/TSCArray.h
        base/TSCArray.h
        base/TSHashTable.h
        "base/ TSGrowableArray.h"
        base/TSStaticDynamicArray.h
        base/TSHashTableReuse.h
        base/TSHashTableReuse.h
        base/TSHashTable_P.h
        base/TSExplicitList.h
        base/TSExplicitList.h)
