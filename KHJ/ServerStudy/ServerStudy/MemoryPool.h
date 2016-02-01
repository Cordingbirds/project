
#pragma once
#include <Windows.h>
#include <cassert>
template <class T, int ALLOC_BLOCK_SIZE = 50>

class CMemoryPool{
public:
	static void* operator new(std::size_t allocLength){
		assert(sizeof(T) == allocLength);				//assert : ()���� ������ �����ؾ� ���)
		assert(sizeof(T) >= sizeof(UCHAR*));			//���� ���� �� ����		-> �������̹Ƿ� ������� ��밡���� ����ó���� �ٲܰ� ���

		if (!mFreePointer)
			allocBlock();

		UCHAR *ReturnPointer = mFreePointer;
		mFreePointer = *reinterpret_cast<UCHAR**>(ReturnPointer);

		return ReturnPointer;
	}
	static void operator delete(void* deletePointer){
		*reinterpret_cast<UCHAR**>(deletePointer) = mFreePointer;
		mFreePointer = static_cast<UCHAR*>(deletePointer);
	}
private:
	static void allocBlock(){
		mFreePointer = new UCHAR[sizeof(T)* ALLOC_BLOCK_SIZE];
		UCHAR **Current = reinterpret_cast<UCHAR**>(mFreePointer);
		UCHAR * Next = mFreePointer;

		for (int i = 0; i < ALLOC_BLOCK_SIZE - 1; i++){
			Next += sizeof(T);
			*Current = Next;
			Current = reinterpret_cast<UCHAR**>(Next);
		}
		*Current = 0;
	}
	static UCHAR *mFreePointer;

protected:
	~CMemoryPool(){

	}
};

template < class T, int ALLOC_BLOCK_SIZE >
UCHAR* CMemoryPool<T, ALLOC_BLOCK_SIZE>::mFreePointer;