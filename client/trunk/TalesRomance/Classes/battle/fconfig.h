//
//  fconfig.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14-8-14.
//
//

#ifndef fancyHeart_fconfig_h
#define fancyHeart_fconfig_h

#define RANDOM_0_1() ((float)rand()/RAND_MAX)
#define GRID_SIZE (40.0*BattleMgr::getInstance()->heroScale)


#define ani_idle "idle"
#define ani_walk "walk"
#define ani_jumpIn "jumpIn"
#define ani_jumpOut "jumpOut"
#define ani_buildup "buildup"
#define ani_attack1 "attack1" //物理
#define ani_attack2 "attack2" //魔法
#define ani_attack3 "attack3" //治疗
#define ani_attacked "attacked"
#define ani_die "die"
#define ani_win "win"
#define ani_yuJia "yuJia"
#define ani_wuShu "wuShu"
#define ani_liYi "liYi"
#define ani_lianJin "lianJin"
#define ani_moFa "moFa"
#define ani_shenXue "shenXue"
#define ani_jiXie "jiXie"
#define ani_huaZhuang "huaZhuang"
#define ani_tiNeng "tiNeng"
#define ani_nuShow "nuShou"
#define ani_caiShi "caiShi"
#define ani_xiaoYuanxunLuo "xiaoYuanxunLuo"
#define ani_zhuJiaoDaGong "zhuJiaoDaGong"
#define ani_xiaoSheJianZao "xiaoShejianZao"
#define ani_heGuanDaGong "heGuanDaGong"
#define ani_kanBanNiang "kanBanNiang"
#define ani_hongPeiDaGong "hongPeiDaGong"
#define ani_daTie "daTie"
#define ani_moOuBaoYang "moOuBaoYang"
#define ani_shenMiaoShouHu "shenMiaoShouHu"
#define ani_commonOver "commonOver"
#define ani_commonLevelUp "commonLevelUp"


enum TrackIndex{
    ANI_COMMON,
    ANI_BUILDUP,
    ANI_JUMPIN,
    ANI_JUMPOUT,
    ANI_ATTACK,
    ANI_ATTACKED,
    ANI_DIE,
    ANI_WIN
};


enum Efstate{
    idle,
    run,
    spell,
    shoot,
    onAir,
    die,
    win
};

enum SkillState{
    SKILL_PAUSE,
    SKILL_RESUME,
    SKILL_STOP
};
#endif
