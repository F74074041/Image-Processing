
// HW1_1.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CHW1_1App: 
// �аѾ\��@�����O�� HW1_1.cpp
//

class CHW1_1App : public CWinApp
{
public:
	CHW1_1App();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CHW1_1App theApp;