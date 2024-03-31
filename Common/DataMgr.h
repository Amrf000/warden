#pragma once

#include "datamgr/CDataMgr.h"
#include "Storm/Handle.h"
#include <NTempest/C3Vector.h>

typedef HOBJECT HDATAMGR;
using namespace NTempest;

void DataMgrGetCoord(HDATAMGR mgr, uint32_t fieldId, C3Vector *coord);

void DataMgrSetCoord(HDATAMGR mgr, uint32_t fieldId, const C3Vector &coord, uint32_t coordFlags);

void DataMgrSetFloat(HDATAMGR mgr, uint32_t fieldId, float val);


