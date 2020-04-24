#pragma once

#if defined(SYSTEM_LINUX)
typedef		int		SMHandle;
#else
typedef		void*	SMHandle;
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
	SMHandle		CreateShareMem(SM_KEY key, int Size);
	/*��ShareMem �ڴ���
	*
	* key   ��ShareMem �Ĺؼ�ֵ
	*
	* Size  �򿪴�С
	*
	* ����  ��ӦShareMem ����ֵ
	*/
	SMHandle		OpenShareMem(SM_KEY key, int Size);

	/*ӳ��ShareMem �ڴ���
	*
	*	handle ӳ��ShareMem �ı���ֵ
	*
	*  ���� ShareMem ������ָ��
	*/
	char*			MapShareMem(SMHandle handle);

	/*�ر�ӳ�� ShareMem �ڴ���
	*
	*	MemoryPtr			ShareMem ������ָ��
	*
	*
	*/
	void			UnMapShareMem(char* MemoryPtr);

	/*	�ر�ShareMem
	* 	handle  ��Ҫ�رյ�ShareMem ����ֵ
	*/
	void			CloseShareMem(SMHandle handle);
};

