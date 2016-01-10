/*!
 * \file Enum.h
 * \date 2015/12/06 3:28
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

#ifndef Enum_h__
#define Enum_h__

enum ObjState
{
	OBJ_STATE_NONE,

	OBJ_STATE_IDLE,
	OBJ_STATE_ALIVE,
	OBJ_STATE_DIE
};

enum UnitGameState
{
	UNIT_STATE_NONE,

	UNIT_STATE_IDLE,
	UNIT_STATE_PLAYING,
	UNIT_STATE_GOAL
};

enum UnitMotionState

{
	UNIT_MOTION_NONE,

	UNIT_MOTION_BASIC,

	UNIT_MOTION_RUN,
	UNIT_MOTION_BUSTER,

	UNIT_MOTION_FALL,
	UNIT_MOTION_AVOID
};

enum UnitDir
{

};


#endif // Enum_h__
