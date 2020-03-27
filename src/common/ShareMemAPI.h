#pragma once

#include "Define.h"

#if defined(SYSTEM_LINUX)
typedef		INT		SMHandle;
#else
typedef		VOID*	SMHandle;
#endif

//typedef	ULONG	SM_KEY;
typedef unsigned long SM_KEY;

namespace ShareMemAPI
{
	/*����ShareMem �ڴ���
	*
	*	key   ����ShareMem �Ĺؼ�ֵ
	*
	*  Size  ������С
	*
	*	���� ��ӦShareMem����ֵ
	*/
	SMHandle		CreateShareMem(SM_KEY key, UINT Size);
	/*��ShareMem �ڴ���
	*
	* key   ��ShareMem �Ĺؼ�ֵ
	*
	* Size  �򿪴�С
	*
	* ����  ��ӦShareMem ����ֵ
	*/
	SMHandle		OpenShareMem(SM_KEY key, UINT Size);

	/*ӳ��ShareMem �ڴ���
	*
	*	handle ӳ��ShareMem �ı���ֵ
	*
	*  ���� ShareMem ������ָ��
	*/
	CHAR*			MapShareMem(SMHandle handle);

	/*�ر�ӳ�� ShareMem �ڴ���
	*
	*	MemoryPtr			ShareMem ������ָ��
	*
	*
	*/
	VOID			UnMapShareMem(CHAR* MemoryPtr);

	/*	�ر�ShareMem
	* 	handle  ��Ҫ�رյ�ShareMem ����ֵ
	*/
	VOID			CloseShareMem(SMHandle handle);
};

