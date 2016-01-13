#include <iostream>
#include "MemoryPool.h"
#include "SingleTon.h"
using namespace std;

class CDataMP : public CMemoryPool < CDataMP > {
private:
	char a[1024];
	char b[1024];

};
void main(){
	//CDataMP 
	for (int i = 0; i < 1000000; i++){
		CDataMP *pData = new CDataMP();

		delete pData;
	}
}