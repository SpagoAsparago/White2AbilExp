#include "swan-master/swantypes.h"
#include "swan-master/math/fixed.h"
#include "swan-master/pml/poke_party.h"
#include "swan-master/gfl/core/gfl_heap.h"
#include "swan-master/system/game_data.h"
#include "swan-master/save/savedata_eventwork.h"

typedef void* (*ABILITY_SETUP_FUNC)(int*);
typedef void* (*ABILITY_HANDLER_FUNC)();

C_DECL_BEGIN

    int const DEFAULT_ABIL_NUMBER = 158;
    int const NEW_ABIL_NUMBER = 27;
    extern int calcAbilHandlerSubPriority(int a1, int a2, int a3, int a4);
    extern int GetBattleMonStat(int a1, int a2);
    extern int GetMonID(int a1);
    extern int* BattleEvent_AddItem(int a1, __int16 a2, int a3, int a4, char a5, int a6, unsigned __int16 a7);

    extern int GetBattleMon(int a1, int a2);
    extern int GetWeather(int a1);
    extern int devideNumHandersAndPri(int *a1);
    extern bool getMoveFlag(int a1, int a2);

    extern int BattleEventVar_GetValue(int a1);
    extern int BattleEventVar_MulValue(int a1, int a2);
    extern int BattleEventVar_RewriteValue(int a1, int a2);
    extern int BattleHandler_AddArg(int result, int a2);
    extern unsigned __int16* BattleHandler_StrSetup(unsigned __int16 *result, unsigned __int8 a2, __int16 a3);
    extern char* BattleHandler_PushWork(int a1, int a2, int a3);
    extern unsigned int* BattleHandler_PopWork(int a1, unsigned int *a2);
    extern unsigned int* BattleHandler_PushRun(int a1, int a2, int a3);
   
    extern int BattleEventItem_GetSubID(int a1);
    extern int PML_MoveGetCategory(int wazaId);
    extern int PML_ItemIsBerry(u16 itemId);
    extern int sub_21BBF80(int a1); //harvest handler
    extern int CommonGetItemParam(int a1, int itemField);
    extern int GetBattleMonHeldItem(int a1);
    extern int DivideMaxHPZeroCheck(int a1, unsigned int a2);
    extern int CommonTypeRecoverHP(int a1, int a2, unsigned int a3);
    extern bool IsMonFullHP(int a1);
    extern bool IsFainted(int a1);
    extern bool CheckCondition(int a1, int conditionID);
    extern bool IsAllyMonID(unsigned int a1, unsigned int a2);
    extern bool DoesMonHaveType(int a1, int a2);

    extern int HandlerAddStatusFailedCommon(int a1, int a2, int a3, int *a4);
    extern int HandlerCommonGuardStatus(int a1, int a2, int a3);
    extern unsigned int* HandlerObliviousCureStatus(int a1, int a2, unsigned int *a3);
    extern int HandlerObliviousNoEffectCheck(int a1, int a2, int a3);
    extern unsigned int* HandlerObliviousActionEnd(int a1, int a2, int a3);
    extern int CommonStatDropGuardCheck(int a1, int a2, int *a3, int a4);
    extern int CommonStatDropGuardFixed(int a1, int a2, int *a3, __int16 a4);

    //color change handler
    extern int sub_21CDE78(int a1);
    extern bool sub_21ABF54(int a1);
    extern int sub_21CE570(__int16 a1);

    //thief handler
    extern bool sub_21CDF68(int a1, unsigned int a2, int a3);

    //check field effect
    extern int sub_21D5AB4(int a1);

    //healer handler
    extern int sub_21ABB90(int a1, unsigned int a2);
    int HandlerGetAlivePartyCount(int a1, __int16 a2, int a3);

C_DECL_END

enum BattleEventVar
#ifdef __cplusplus
: u32
#endif
{
VAR_MONID         = 2,
VAR_ATTACKINGMON   = 3,
VAR_DEFENDINGMON   = 4,
VAR_TARGETMONID   = 6,
VAR_PRIORITY      = 0x11,
VAR_MOVEID        = 0x12,
VAR_MOVETYPE      = 0x16,
VAR_MOVECATEGORY   = 0x1A,
VAR_CONDITIONID   = 0x1D,
VAR_CONDITIONADDRESS   = 0x1E,
VAR_STATBOOSTAMOUNT   = 0x20,
VAR_FLOATING      = 0x21,
VAR_FAILCAUSE     = 0x22,
VAR_EFFECTTURNCOUNT   = 0x24,
VAR_ADDEDEFFECT   = 0x26,
VAR_CRITSTAGE     = 0x2C,
VAR_SPEED         = 0x2F,
VAR_MOVEPOWER     = 0x30,
VAR_MOVEPOWERRATIO   = 0x31,
VAR_RATIO         = 0x35,
VAR_DAMAGE        = 0x37,
VAR_TYPEEFFECTIVENESS   = 0x38,
VAR_ENDURE        = 0x3A,
VAR_NOEFFECTFLAG   = 0x40,
VAR_MOVEFAILFLAG   = 0x41,
VAR_SEMIINVULNERABLE   = 0x42,
VAR_CRITICALFLAG   = 0x45,
VAR_SUBSTITUTE    = 0x46,
VAR_EFFECTBLOCKED   = 0x47,
VAR_TRICKROOMFLAG   = 0x4A,
VAR_GENERALUSE    = 0x51,
VAR_SIDEEFFECT    = 0x53,
};

enum statValues
#ifdef __cplusplus
: u32
#endif
{
ATTACK = 1,
DEFENSE = 2,
SPECIAL_ATTACK = 3,
SPECIAL_DEFENSE = 4,
SPEED = 5,
ACCURACY = 6,
EVASIVENESS = 7,
};

enum Conditions
#ifdef __cplusplus
: char
#endif
{
  CND_PARALYSIS = 1,
  CND_SLEEP = 2,
  CND_FREEZE = 3,
  CND_BURN = 4,
  CND_POISON = 5,
  CND_CONFUSION = 6,
  CND_INFATUATION = 7,
  CND_TAUNT = 11,
  CND_TORMENT = 12,
  CND_DISABLEMOVE = 13,
  CND_DROWSY = 14,
  CND_HEALBLOCK = 15,
  CND_ENCORE = 23,
  CND_EMBARGO = 35,
};

enum Types 
#ifdef __cplusplus
: u32
#endif
{
  TYPE_NORMAL = 0,
  TYPE_FIGHTING = 1, 
  TYPE_FLYING = 2,
  TYPE_POISON = 3,
  TYPE_GROUND = 4,
  TYPE_ROCK = 5,
  TYPE_BUG = 6,
  TYPE_GHOST = 7,
  TYPE_STEEL = 8,
  TYPE_FIRE = 9,
  TYPE_WATER = 10,
  TYPE_GRASS = 11,
  TYPE_ELECTRIC = 12,
  TYPE_PSYCHIC = 13,
  TYPE_ICE = 14,
  TYPE_DRAGON = 15,
  TYPE_DARK = 16,
  TYPE_FAIRY = 17,
  TYPE_NONE = 18,
};

enum ItemField
#ifdef __cplusplus
: u32
#endif
{
  ITSTAT_PRICE = 0x0,
  ITSTAT_USE_EFFECT = 0x1,
  ITSTAT_USE_PARAM = 0x2,
  ITSTAT_FLAG1 = 0x3,
  ITSTAT_FLAG2 = 0x4,
  ITSTAT_POCKET_FIELD = 0x5,
  ITSTAT_EFFECT_FIELD = 0x6,
  ITSTAT_EFFECT_BATTLE = 0x7,
  ITSTAT_NATURAL_GIFT_EFFECT = 0x8,
  ITSTAT_FLING_EFFECT = 0x9,
  ITSTAT_FLING_POWER = 0xA,
  ITSTAT_NATURAL_GIFT_POWER = 0xB,
  ITSTAT_NATURAL_GIFT_TYPE = 0xC,
  ITSTAT_POCKET_BATTLE = 0xD,
  ITSTAT_HAS_BATTLE_STATS = 0xE,
  ITSTAT_CLASS = 0xF,
  ITSTAT_CONSUMABLE = 0x10,
  ITSTAT_SORT_IDX = 0x11,
  ITSTAT_AILMENT_SLP = 0x12,
  ITSTAT_AILMENT_PSN = 0x13,
  ITSTAT_AILMENT_BRN = 0x14,
  ITSTAT_AILMENT_FRZ = 0x15,
  ITSTAT_AILMENT_PAR = 0x16,
  ITSTAT_AILMENT_CFZ = 0x17,
  ITSTAT_AILMENT_INF = 0x18,
  ITSTAT_AILMENT_GSP = 0x19,
  ITSTAT_BOOST_REVIVE = 0x1A,
  ITSTAT_BOOST_SACRED_ASH = 0x1B,
  ITSTAT_BOOST_RARECANDY = 0x1C,
  ITSTAT_BOOST_EVOSTONE = 0x1D,
  ITSTAT_BOOST_ATK = 0x1E,
  ITSTAT_BOOST_DEF = 0x1F,
  ITSTAT_BOOST_SPA = 0x20,
  ITSTAT_BOOST_SPD = 0x21,
  ITSTAT_BOOST_SPE = 0x22,
  ITSTAT_BOOST_ACC = 0x23,
  ITSTAT_BOOST_CRIT = 0x24,
  ITSTAT_BOOST_PP1 = 0x25,
  ITSTAT_BOOST_PPMAX = 0x26,
  ITSTAT_FLAG_PPREPLENISH = 0x27,
  ITSTAT_FLAG_PPREPLENISH_FULL = 0x28,
  ITSTAT_FLAG_HPREPLENISH = 0x29,
  ITSTAT_FLAG_EVADD_HP = 0x2A,
  ITSTAT_FLAG_EVADD_ATK = 0x2B,
  ITSTAT_FLAG_EVADD_DEF = 0x2C,
  ITSTAT_FLAG_EVADD_SPE = 0x2D,
  ITSTAT_FLAG_EVADD_SPA = 0x2E,
  ITSTAT_FLAG_EVADD_SPD = 0x2F,
  ITSTAT_FLAG_EVADD_ABOVE100 = 0x30,
  ITSTAT_FLAG_FRIENDSHIP_ADD1 = 0x31,
  ITSTAT_FLAG_FRIENDSHIP_ADD2 = 0x32,
  ITSTAT_FLAG_FRIENDSHIP_ADD3 = 0x33,
  ITSTAT_EV_HP = 0x34,
  ITSTAT_EV_ATK = 0x35,
  ITSTAT_EV_DEF = 0x36,
  ITSTAT_EV_SPE = 0x37,
  ITSTAT_EV_SPA = 0x38,
  ITSTAT_EV_SPD = 0x39,
  ITSTAT_HEAL_AMOUNT = 0x3A,
  ITSTAT_PP_GAIN = 0x3B,
  ITSTAT_FRIENDSHIP1 = 0x3C,
  ITSTAT_FRIENDSHIP2 = 0x3D,
  ITSTAT_FRIENDSHIP3 = 0x3E,
};