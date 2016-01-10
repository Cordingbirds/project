/*!
 * \file Function.h
 * \date 2015/12/06 2:44
 *
 * \author �����
 * Contact: bluevill04@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/

#pragma once

#ifndef Function_h__
#define Function_h__

template<typename T>
static void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = NULL;
	}
}

template <typename T>
void Safe_Delete_Array(T& pointer)
{
	if (NULL != pointer)
	{
		delete[] pointer;
		pointer = NULL;
	}
}

template <typename T>
void Safe_Release(T& pointer)
{
	if (NULL != pointer)
	{
		pointer->Release();
		pointer = NULL;
	}
}

#endif // Function_h__