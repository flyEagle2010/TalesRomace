//
//  RoleCreate.cpp
//  TalesRomance
//
//  Created by qll on 14/12/18.
//
//

#include "RoleCreate.h"
RoleCreate* RoleCreate::create()
{
    RoleCreate* pRet=new RoleCreate();
    
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool RoleCreate::init()
{
    if(!BaseUI::init("RoleCreate.csb",""))
    {
        return false;
    }

    return true;
}