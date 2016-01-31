/*!
 * \file FbxBuffer.h
 * \date 2016/01/31 12:58
 *
 * \author ±è¸íÁö
 * Contact: bluevill04@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/

#pragma once

#ifndef FbxBuffer_h__
#define FbxBuffer_h__

#include "Buffer.h"

class CFbxBuffer abstract : public CBuffer
{
//private :
//	FbxManager*		mFBXManager;
//	FbxScene*		mFBXScene;

public :
	virtual void	Render()			PURE;
public :
	virtual HRESULT LoadFbx(wstring _wstrPath)	PURE;


protected :
	CFbxBuffer(CDevice*);
public :
	~CFbxBuffer();
};

#endif // FbxBuffer_h__
