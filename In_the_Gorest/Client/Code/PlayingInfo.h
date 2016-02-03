/*!
* \file PlayingInfo.h
* \date 2016/01/21 4:56
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

#ifndef PlayingInfo_h__
#define PlayingInfo_h__

#include "Component.h"
#include "Enum.h"

class CPlayingInfo : public CComponent
{
public :
	const static WORD	MAX_HP		= 100;

	static enum InMapState
	{
		INMAP_STATE_NONE,

		INMAP_STATE_READY,
		INMAP_STATE_PLAYING,
		INMAP_STATE_GOAL
	};

	static enum AniState
	{
		ANI_STATE_NONE,

		ANI_STATE_STOP,

		ANI_STATE_RUN,
		ANI_STATE_BUSTER,

		ANI_STATE_FALL,
		ANI_STATE_AVOID
	};


public:
	InMapState		m_eInMapState;
	AniState		m_eAniState;

	WORD			m_wGradeNum;
	WORD			m_wRabNum;
	float			m_fProgressRate;

	WORD			m_wHP;


public:
	static CComponent*		Create();
public :
	virtual void			Update();
private:
	virtual void			Release();

public:
	explicit CPlayingInfo();
	virtual ~CPlayingInfo();
};


#endif // PlayingInfo_h__
