//
//  RoleCreate.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/25.
//
//

#ifndef __TalesRomance__RoleCreate__
#define __TalesRomance__RoleCreate__

#include <stdio.h>
#include "BaseUI.h"

class RoleCreate : public BaseUI
{
public:
    static RoleCreate* create();
    bool init();
private:
    
};
#endif /* defined(__TalesRomance__RoleCreate__) */
