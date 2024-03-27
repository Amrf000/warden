#pragma once
#include "HeapManager.h"

class CHandleObject
{
public:
	virtual void Release()
	{

	}
	virtual int HeapRelease()
	{
		::HeapRelease(this);
	}
	virtual void SafeHeapRelease()
	{
		if (this)
			this->HeapRelease();
	}
	virtual int ObjectId()
	{
		return 0;
	}
};

