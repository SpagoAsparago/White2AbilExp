#include "abilexp.h"

extern "C" {

int GlobalItem;

int RecoverHP(int a1, int a2, unsigned int a3){
  char *v6; // r5
  int BattleMon; // [sp+0h] [bp-18h]

  BattleMon = GetBattleMon(a1, a2);
  if ( IsMonFullHP(BattleMon) )
  {
    v6 = BattleHandler_PushWork(a1, 4, a2);
    BattleHandler_StrSetup((unsigned __int16 *)v6 + 2, 2u, 210);
    BattleHandler_AddArg((int)(v6 + 4), a2);
    *(unsigned __int16 *)v6 |= 0x800000u;
  }
  else
  {
    v6 = BattleHandler_PushWork(a1, 5, a2);
    v6[6] = a2;
    *((unsigned __int16 *)v6 + 2) = DivideMaxHPZeroCheck(BattleMon, a3);
    *(unsigned int *)v6 |= 0x800000u;
    BattleHandler_StrSetup((unsigned __int16 *)v6 + 4, 2u, 387); 
    BattleHandler_AddArg((int)(v6 + 8), a2);
  }
  BattleHandler_PopWork(a1, (unsigned int*)v6);
  return BattleEventVar_RewriteValue(VAR_GENERALUSE, 1);
}

int CustomCommonAddStatusFailed(int a1, int a2, int a3, int *a4, __int16 a5) 
{
  int result; // r0
  char *v9; // r7

  result = BattleEventVar_GetValue(4);
  if ( (a3 == result) )
  {
    result = *a4;
    if ( *a4 == 1 )
    {
      BattleHandler_PushRun(a2, 2, a3);
      v9 = BattleHandler_PushWork(a2, 4, a3);
      BattleHandler_StrSetup((unsigned __int16*)v9 + 2, 2u, a5);
      BattleHandler_AddArg((int)(v9 + 4), a3);
      BattleHandler_PopWork(a2,(unsigned int*)v9);
      BattleHandler_PushRun(a2, 3, a3);
      result = 0;
      *a4 = 0;
    }
  } 
  else if ((IsAllyMonID(a3, result)) )
  {
    a3 = result;
    result = *a4;
    if ( *a4 == 1 )
    {
      
      BattleHandler_PushRun(a2, 2, a3);
      v9 = BattleHandler_PushWork(a2, 4, a3);
      BattleHandler_StrSetup((unsigned __int16*)v9 + 2, 2u, a5);
      BattleHandler_AddArg((int)(v9 + 4), a3);
      BattleHandler_PopWork(a2,(unsigned int*)v9);
      BattleHandler_PushRun(a2, 3, a3);
      result = 0;
      *a4 = 0;
    }
  }
  return result;
}

int CustomCommonStatDropGuardCheck(int a1, int a2, int *a3, int a4)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  int BattleMon;

  if ( a2 == result )
  {
    BattleMon = GetBattleMon(a1, result);
    if (DoesMonHaveType(BattleMon, TYPE_GRASS))
    {
      result = BattleEventVar_GetValue(VAR_ATTACKINGMON);
      if ( a2 != result )
      {
        if ( a4 == 8 || (result = BattleEventVar_GetValue(31), a4 == result) )
        {
          result = BattleEventVar_GetValue(32);
          if ( result < 0 )
          {
            result = BattleEventVar_RewriteValue(VAR_MOVEFAILFLAG, 1);
            *a3 = result;
          }
        }
      }
    }
 
  } 
  else if (IsAllyMonID(a2, result))
  {
    a2 = result;
    BattleMon = GetBattleMon(a1, result);
    if (DoesMonHaveType(BattleMon, TYPE_GRASS))
    {
      result = BattleEventVar_GetValue(VAR_ATTACKINGMON);
      if ( a2 != result )
      {
        if ( a4 == 8 || (result = BattleEventVar_GetValue(31), a4 == result) )
        {
          result = BattleEventVar_GetValue(32);
          if ( result < 0 )
          {
            result = BattleEventVar_RewriteValue(VAR_MOVEFAILFLAG, 1);
            *a3 = result;
          }
        }
     }
    }

  }

  return result;
}

int CustomCommonStatDropGuardFixed(int a1, int a2, int *a3, __int16 a4)
{
  int result; // r0
  int Value; // r7
  char *v10; // [sp+4h] [bp-1Ch]
  int BattleMon;

  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a2 == result )
  {
    BattleMon = GetBattleMon(a1, result);
    if (DoesMonHaveType(BattleMon, TYPE_GRASS))
    {
      result = *a3;
      if ( *a3 )
      {
        Value = BattleEventVar_GetValue(25);
        if ( !Value || a3[1] != Value )
        {
          BattleHandler_PushRun(a1, 2, a2);
          v10 = BattleHandler_PushWork(a1, 4, a2);
          BattleHandler_StrSetup((unsigned __int16 *)v10 + 2, 2u, a4);
          BattleHandler_AddArg((int)(v10 + 4), a2);
          BattleHandler_PopWork(a1, (unsigned int*)v10);
          BattleHandler_PushRun(a1, 3, a2);
          a3[1] = Value;
        }
        result = 0;
        *a3 = 0;
      }
    }
  } 
  else if (IsAllyMonID(a2, result))
  {
    a2 = result;
    BattleMon = GetBattleMon(a1, result);
    if (DoesMonHaveType(BattleMon, TYPE_GRASS))
    {
      result = *a3;
      if ( *a3 )
      {
        Value = BattleEventVar_GetValue(25);
        if ( !Value || a3[1] != Value )
        {
          BattleHandler_PushRun(a1, 2, a2);
          v10 = BattleHandler_PushWork(a1, 4, a2);
          BattleHandler_StrSetup((unsigned __int16 *)v10 + 2, 2u, a4);
          BattleHandler_AddArg((int)(v10 + 4), a2);
          BattleHandler_PopWork(a1, (unsigned int*)v10);
          BattleHandler_PushRun(a1, 3, a2);
          a3[1] = Value;
        }
        result = 0;
        *a3 = 0;
      }
    }
  }
  return result;
}

int GuardCondition(char* GuardList, int count)
{
    char effectUsed = BattleEventVar_GetValue(29);
    for(int i = 0; i < count; i++)
    {
        if( effectUsed == GuardList[i] )
        {
            return BattleEventVar_RewriteValue(65, 1);
        }
    }
    return 0;
}

#pragma region Handlers

void HandlerAromaVeil(int a1, int a2, int a3, int *a4)
{
  int result; // r0
  char BlockedEffects [] = { CND_INFATUATION, CND_ENCORE, CND_TAUNT, CND_TORMENT, CND_HEALBLOCK, CND_DISABLEMOVE };
  result = BattleEventVar_GetValue(VAR_DEFENDINGMON);
  
  if ( (a3 == result) || (IsAllyMonID(a3, result)) )
  {
    *a4 = GuardCondition(BlockedEffects, sizeof(BlockedEffects));
  }
}

int HandlerCustomAddStatusFailed(int a1, int a2, int a3, int *a4)
{
  return CustomCommonAddStatusFailed(a1, a2, a3, a4 , 210);
}

void HandlerFlowerVeil(int a1, int a2, int a3, int *a4) //Non-volatile Status Guard
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_DEFENDINGMON);
  if ( (a3 == result)  || (IsAllyMonID(a3, result)) ) 
  {
    int BattleMon = GetBattleMon(a2, result);
    if (DoesMonHaveType(BattleMon, TYPE_GRASS)) 
    {
      char BlockedEffects [] = { CND_PARALYSIS, CND_SLEEP, CND_FREEZE, CND_BURN, CND_POISON, CND_DROWSY };
      *a4 = GuardCondition(BlockedEffects, sizeof(BlockedEffects));
    }
  }
}

int HandlerFlowerVeilStatCheck(int a1, int a2, int a3, int *a4) //Stat Lowering Check
{ 
  return CustomCommonStatDropGuardCheck(a2, a3, a4, 8);
}

int HandlerFlowerVeilStatGuard(int a1, int a2, int a3, int *a4) //Stat Lowering Guard
{
  return CustomCommonStatDropGuardFixed(a2, a3, a4, 198);
}

int HandlerCheekPouch(int a1, int a2, int a3, unsigned int *a4)
{
  int result; // r0
  int BattleMon; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result )
  {
    BattleMon = GetBattleMon(a2, a3);
    result = BattleEventVar_GetValue(45);
    if ( !result && PML_ItemIsBerry(GetBattleMonHeldItem(BattleMon)) )
    {
      BattleMon = GetBattleMon(a2, a3);
      result = GetBattleMonHeldItem(BattleMon);
      if ( result )
      {
        result = 1;
        *a4 = 1;
      }
    }
  }
  return result;
}

int HandlerCheekPouchHeal(int a1, int a2, int a3, int *a4)
{
  int result; // r0
  int BattleMon; // r0
  char *v8;

  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result )
  {
    BattleMon = GetBattleMon(a2, a3);
    result = *a4;
    if ( *a4 == 1 && !CheckCondition(BattleMon, 15) )
    {
      return RecoverHP(a2, a3, 3u);
    }
  }
  return result;
}

unsigned int HandlerProtean(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    if (BattleEventVar_GetValue(VAR_MOVETYPE) != TYPE_NONE){
      //if (!BattleEventVar_GetValue(VAR_MOVEFAILFLAG))
      {
        unsigned int v7;
        char *v8;
        int BattleMon = GetBattleMon(a2, result);
        result = BattleEventVar_GetValue(VAR_MOVETYPE);
        v7 = result;
        if ( (result) != 18 ) //struggle -> change to 17 if fairy type is not implemented
        {
          result = DoesMonHaveType(BattleMon, v7);
          if ( !result )
          {
            BattleHandler_PushRun(a2, 2, a3);
            v8 = BattleHandler_PushWork(a2, 20, a3);
            *((unsigned __int16 *)v8 + 2) = sub_21CE570(v7);
            v8[6] = a3;
            BattleHandler_PopWork(a2,(unsigned int*)v8);
            return (unsigned int)BattleHandler_PushRun(a2, 3, a3);
          }
        } 
      }

    }
  }
  return result;
}

int HandlerFurCoat(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_DEFENDINGMON);
  if ( a3 == result ) {
    unsigned __int16 Value = BattleEventVar_GetValue(VAR_MOVEID);
    result = PML_MoveGetCategory(Value);
    if (result == 1)
    {
      return BattleEventVar_MulValue(VAR_RATIO, 2048);
    }
  }
  return result;
}

int HandlerMagicianStart(int a1, int a2, int a3, int *a4)
{
  int result; // r0
  int BattleMon; // r0

  result = BattleEventVar_GetValue(VAR_ATTACKINGMON);
  if ( a3 == result )
  {
    BattleMon = GetBattleMon(a2, a3);
    result = GetBattleMonHeldItem(BattleMon) != 0;
    *a4 = result;
  }
  return result;
}

unsigned int HandlerMagician(int a1, int a2, unsigned int a3, unsigned int *a4)
{
  unsigned int result; // r0
  int BattleMon; // r0
  int v9; // r6
  char *v10; // r7
  int BattleMonHeldItem; // r0
  char *v12; // r0
  int v13; // [sp+0h] [bp-18h]

  result = BattleEventVar_GetValue(VAR_ATTACKINGMON);
  if ( a3 == result )
  {
    BattleMon = GetBattleMon(a2, a3);
    result = GetBattleMonHeldItem(BattleMon);
    if ( !result )
    {
      result = *a4;
      if ( !*a4 )
      {
        result = BattleEventVar_GetValue(VAR_TARGETMONID);
        v9 = result;
        if ( result != 31 )
        {
          v13 = GetBattleMon(a2, v9);
          result = GetBattleMonHeldItem(v13);
          if ( result )
          {
            result = sub_21CDF68(a2, a3, v9); //check for giratina/arceus/genesect items
            if ( !result )
            {
              v10 = BattleHandler_PushWork(a2, 36, a3);
              v10[4] = v9;
              BattleHandler_StrSetup((unsigned __int16 *)v10 + 4, 2u, 1057);
              BattleHandler_AddArg((int)(v10 + 8), a3);
              BattleHandler_AddArg((int)(v10 + 8), v9);
              BattleMonHeldItem = GetBattleMonHeldItem(v13);
              BattleHandler_AddArg((int)(v10 + 8), BattleMonHeldItem);
              BattleHandler_PopWork(a2, (unsigned int*)v10);
              v12 = BattleHandler_PushWork(a2, 58, a3);
              *(unsigned int*)v12 |= 0x800000u;
              v12[4] = 1;
              return (unsigned int)BattleHandler_PopWork(a2, (unsigned int*)v12);
            }
          }
        }
      }
    }
  }
  return result;
}

unsigned int * HandlerBulletproof(int a1, int a2,unsigned int *a3)
{
  unsigned int *result; // r0
  unsigned __int16 Value; // r0
  char *v7; // r6

  result = (unsigned int *)BattleEventVar_GetValue(VAR_DEFENDINGMON);
  if ( a3 == result )
  {
    /*Acid Spray, Aura Sphere, Bullet Seed, Egg Bomb, Electro Ball, Energy Ball, Focus Blast, Gyro Ball, Ice Ball, Magnet Bomb, 
    Mist Ball, Mud Bomb, Octazooka, Rock Blast, Rock Wrecker, Seed Bomb, Shadow Ball, Sludge Bomb, Weather Ball, Zap Cannon*/
    Value = BattleEventVar_GetValue(VAR_MOVEID);
    if ( Value == 121 || Value ==  140 || Value ==  188 || Value == 190 || Value == 192 || Value == 247 || Value == 296 
     || Value == 301 || Value == 311 || Value == 331 || Value == 350 || Value == 360 || Value == 396 || Value == 402 
     || Value == 411 || Value == 412 || Value == 426 || Value == 439 || Value == 443 || Value == 486 || Value == 491)
    { 
      result = (unsigned int *)BattleEventVar_RewriteValue(VAR_NOEFFECTFLAG, 1);
      if ( result )
      {
        BattleHandler_PushRun(a2, 2, (int)a3);
        v7 = BattleHandler_PushWork(a2, 4, (int)a3);
        BattleHandler_StrSetup((unsigned __int16 *)v7 + 2, 2u, 210);
        BattleHandler_AddArg((int)(v7 + 4), (int)a3);
        BattleHandler_PopWork(a2, (unsigned int*)v7);
        return BattleHandler_PushRun(a2, 3, (int)a3);
      }
    }
  }
  return result;
}

unsigned int * HandlerCompetitive(int a1, int a2, int a3)
{
  unsigned int *result; // r0
  unsigned __int8 Value; // r0
  char *v7; // r0

  result = (unsigned int *)BattleEventVar_GetValue(2);
  if ( (unsigned int *)a3 == result )
  {
    Value = BattleEventVar_GetValue(3);
    result = (unsigned int *)IsAllyMonID(a3, Value);
    if ( !result )
    {
      result = (unsigned int *)BattleEventVar_GetValue(32);
      if ( (int)result < 0 )
      {
        v7 = BattleHandler_PushWork(a2, 14, a3);
        *(unsigned int *)v7 |= 0x800000u;
        *((unsigned int *)v7 + 1) = 3;
        v7[12] = 2;
        v7[14] = 1;
        v7[15] = 1;
        v7[16] = a3;
        return BattleHandler_PopWork(a2, (unsigned int*)v7);
      }
    }
  }
  return result;
}

int HandlerStrongJaw(int a1, int a2, int a3)
{
  int result; // r0

  result = BattleEventVar_GetValue(VAR_ATTACKINGMON);
  if ( a3 == result )
  {
    result = BattleEventVar_GetValue(VAR_MOVEID);
    /*Bite, Crunch, Fire Fang, Thunder Fang, Ice Fang, Hyper Fang, Poison Fang*/
    if ( result == 44 || result == 158 || result == 242 || result == 305 
    || result == 422 || result == 423 || result == 424  )
    {
      return BattleEventVar_MulValue(VAR_MOVEPOWERRATIO, 6144);
    }
  }
  return result;
}

int  HandlerRefrigerate(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    if (BattleEventVar_GetValue(VAR_MOVETYPE) == TYPE_NORMAL){
      
      return BattleEventVar_RewriteValue(VAR_MOVETYPE, TYPE_ICE); 
    }
  }
  return result;
}

int HandlerRefrigerateBoost(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    if (BattleEventVar_GetValue(VAR_MOVETYPE) == TYPE_ICE){
      
      return BattleEventVar_MulValue(VAR_RATIO, 4915); //20% boost
    }
  }
  return result;
}

void HandlerSweetVeil(int a1, int a2, int a3, int *a4)
{
  int result; // r0
  char BlockedEffects [] = { CND_SLEEP, CND_DROWSY };
  result = BattleEventVar_GetValue(VAR_DEFENDINGMON);
  
  if ( (a3 == result) || (IsAllyMonID(a3, result)) )
  {
    *a4 = GuardCondition(BlockedEffects, sizeof(BlockedEffects));
  }
}

int HandlerStanceChange(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    return result;
  }
  return result;
}

int HandlerStanceChangeGuardCondition(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    return result;
  }
  return result;
}

int HandlerGaleWings(int a1, int a2, int a3)
{
  int result; // r0
  unsigned __int16 Value; // r0
  unsigned __int8 v6; // r0

  result = BattleEventVar_GetValue(3);
  if ( a3 == result )
  {
    if ( BattleEventVar_GetValue(VAR_MOVETYPE) == 2 )
    {
      v6 = BattleEventVar_GetValue(24);
      return BattleEventVar_RewriteValue(24, v6 + 1);
    }
  }
  return result;
}

int HandlerMegaLauncher(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_ATTACKINGMON);
  if ( a3 == result )
  {
    result = BattleEventVar_GetValue(VAR_MOVEID);
    /*Aura Sphere, Dark Pulse, Dragon pulse, Heal Pulse, Water Pulse*/
    if ( result == 396 || result == 352 || result == 399 || result == 406)
    {
      return BattleEventVar_MulValue(VAR_MOVEPOWERRATIO, 6144);
    }
    else if (result == 505 )
    {
      return BattleEventVar_MulValue(VAR_MOVEPOWERRATIO, 6144);
    }
  }
  return result;
}

int HandlerGrassPelt(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_DEFENDINGMON);
  if ( a3 == result ) {
    if (sub_21D5AB4(0xFF)) //Change to Grassy Terrain FieldEvent ID
    {
      BattleEventVar_GetValue(VAR_MOVEID);
      if (BattleEventVar_GetValue(VAR_MOVECATEGORY) == 1)
      { 
        return BattleEventVar_MulValue(VAR_RATIO, 6144);
      }
    }
  }
  return result;
}

int HandlerSymbiosis(int a1, int a2, int a3, unsigned int *a4)
{
  int result; // r0
  int BattleMon; // r0
  result = BattleEventVar_GetValue(VAR_DEFENDINGMON);
  if ( a3 == result )
  {
    BattleMon = GetBattleMon(a2, a3);
    result = BattleEventVar_GetValue(45);
    if ( !result )
    {
      BattleMon = GetBattleMon(a2, a3);
      result = GetBattleMonHeldItem(BattleMon);
      if ( result )
      {
        GlobalItem = result;
        result = 1;
        *a4 = 1;
      }
    }
  }
  return result;
}

unsigned int HandlerSymbiosisPassItem(int a1, int a2, int a3, int *a4)
{
  int result; // r0
  __int16 v7; // r0
  unsigned int i; // r4
  int v9; // r1
  int BattleMon; // r0
  char *v11; // r0
  unsigned int v12; // [sp+0h] [bp-20h]
  char v13[4];

  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result )
  {
    if ( *a4 == 1 )
    {
      v7 = sub_21ABB90(a2, a3);
      result = HandlerGetAlivePartyCount(a2, v7 | 0x400, (int)v13);
      v12 = result;
      for (i = 0; i < v12; result = v12);
      {
        v9 = (unsigned __int8)v13[i];
        if (v9 != a3)
        {
          BattleMon = GetBattleMon(a2, v9);
          if (GetBattleMonHeldItem(BattleMon) == 0)
          { 
                char *v10 = BattleHandler_PushWork(a2, 32, a3);
                v10[6] = a3;
                *((unsigned __int16 *)v10 + 2) = 0;
                BattleHandler_PopWork(a2, (unsigned int*)v10);
                v11 = BattleHandler_PushWork(a2, 32, a3);
                v11[6] = v9;
                char *v14 = v11;
                *((unsigned __int16 *)v11 + 2) = GlobalItem;
                BattleHandler_StrSetup((unsigned __int16 *)v11 + 6, 2u, 1111);
                BattleHandler_AddArg((int)(v14 + 12), v9);
                BattleHandler_AddArg((int)(v14 + 12), a3);
                BattleHandler_AddArg((int)(v14 + 12), GlobalItem);
                return (unsigned int)BattleHandler_PopWork(a2, (unsigned int*)v14);
          }
        }
      }
     
    }
  }
  return result;
}

int HandlerToughClaws(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_ATTACKINGMON);
  if ( a3 == result ) {
    int MoveID = BattleEventVar_GetValue(VAR_MOVEID);
    if(getMoveFlag(MoveID, 0))
    {
      return BattleEventVar_MulValue(VAR_MOVEPOWERRATIO, 5324);
    }
  }
  return result;
}

int  HandlerPixilate(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    if (BattleEventVar_GetValue(VAR_MOVETYPE) == TYPE_NORMAL){
      
      return BattleEventVar_RewriteValue(VAR_MOVETYPE, TYPE_FAIRY); 
    }
  }
  return result;
}

int HandlerPixilateBoost(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    if (BattleEventVar_GetValue(VAR_MOVETYPE) == TYPE_FAIRY){
      
      return BattleEventVar_MulValue(VAR_RATIO, 4915); //20% boost
    }
  }
  return result;
}

unsigned int* HandlerGooey(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_DEFENDINGMON);
  if ( a3 == result ) {
    if (!BattleEventVar_GetValue(VAR_SUBSTITUTE)) {
      if (getMoveFlag(BattleEventVar_GetValue(VAR_MOVEID), 0))
      {
        int Opponent = BattleEventVar_GetValue(VAR_ATTACKINGMON);
        int BattleMon = GetBattleMon(a2, Opponent);
        if (!IsFainted(BattleMon))
        {
          //lower the speed
          
          BattleHandler_PushRun(a2, 2, a3);
          char *v8 = BattleHandler_PushWork(a2, 14, a3);
          v8[15] = 1;
          v8[16] = Opponent;
          v8[14] = 1;
          *((unsigned int*)v8 + 1) = 5;
          v8[12] = -1;
          BattleHandler_PopWork(a2, (unsigned int*)v8);
          return BattleHandler_PushRun(a2, 3, a3);
        }
      }
    }
  }
  return (unsigned int*)result;
}

int  HandlerAerilate(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    if (BattleEventVar_GetValue(VAR_MOVETYPE) == TYPE_NORMAL){
      
      return BattleEventVar_RewriteValue(VAR_MOVETYPE, TYPE_FLYING); 
    }
  }
  return result;
}

int HandlerAerilateBoost(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    if (BattleEventVar_GetValue(VAR_MOVETYPE) == TYPE_FLYING){
      
      return BattleEventVar_MulValue(VAR_RATIO, 4915); //20% boost
    }
  }
  return result;
}

int HandlerParentalBond(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_ATTACKINGMON);
  if ( a3 == result ) 
  {
    return result;
  }
  return result;
}

int HandlerDarkAura(int a1, int a2, int a3)
{
  int result; // r0
  if ( BattleEventVar_GetValue(VAR_MOVETYPE) == TYPE_DARK ) 
  {
    return BattleEventVar_MulValue(VAR_MOVEPOWERRATIO, 5448);
  }
  return result;
}

int HandlerFairyAura(int a1, int a2, int a3)
{
  int result; // r0
  if ( BattleEventVar_GetValue(VAR_MOVETYPE) == TYPE_FAIRY ) 
  {
    return BattleEventVar_MulValue(VAR_MOVEPOWERRATIO, 5448);
  }
  return result;
}

int HandlerAuraBreak(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    return result;
  }
  return result;
}

int HandlerPrimordialSea(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    return result;
  }
  return result;
}
int HandlerDesolateLand(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    return result;
  }
  return result;
}
int HandlerDeltaStream(int a1, int a2, int a3)
{
  int result; // r0
  result = BattleEventVar_GetValue(VAR_MONID);
  if ( a3 == result ) {
    return result;
  }
  return result;
}
#pragma endregion Handlers

typedef struct {
	int triggerValue;
	ABILITY_HANDLER_FUNC function;
} ABILITY_TRIGGERTABLE;

ABILITY_TRIGGERTABLE AbilityTriggerTable[] =
{
{ 0x65,		(ABILITY_HANDLER_FUNC) HandlerAromaVeil },	
{ 0x67,		(ABILITY_HANDLER_FUNC) HandlerCustomAddStatusFailed },
{ 0x8A,		(ABILITY_HANDLER_FUNC) HandlerObliviousCureStatus },		
{ 0x2D,		(ABILITY_HANDLER_FUNC) HandlerObliviousNoEffectCheck },	
{ 2,		(ABILITY_HANDLER_FUNC) HandlerObliviousActionEnd },	

{ 0x65,	(ABILITY_HANDLER_FUNC) HandlerFlowerVeil },
{ 0x67,	(ABILITY_HANDLER_FUNC) HandlerCustomAddStatusFailed },
{ 0x5B,	(ABILITY_HANDLER_FUNC) HandlerFlowerVeilStatCheck },
{ 0x5C,	(ABILITY_HANDLER_FUNC) HandlerFlowerVeilStatGuard },

{ 0x9C,	(ABILITY_HANDLER_FUNC) HandlerCheekPouch },
{ 0x9D,	(ABILITY_HANDLER_FUNC) HandlerCheekPouchHeal },

{ 0x28,	(ABILITY_HANDLER_FUNC) HandlerProtean },

{ 0x3B,	(ABILITY_HANDLER_FUNC) HandlerFurCoat},

{ 0x81,	(ABILITY_HANDLER_FUNC) HandlerMagicianStart},
{ 0x83,	(ABILITY_HANDLER_FUNC) HandlerMagician},

{ 0x2D,	(ABILITY_HANDLER_FUNC) HandlerBulletproof},

{ 0x5D,	(ABILITY_HANDLER_FUNC) HandlerCompetitive},

{ 0x38,	(ABILITY_HANDLER_FUNC) HandlerStrongJaw},

{ 40,	(ABILITY_HANDLER_FUNC) HandlerRefrigerate},
{ 59,	(ABILITY_HANDLER_FUNC) HandlerRefrigerateBoost},

{ 0x65,	(ABILITY_HANDLER_FUNC) HandlerSweetVeil},
{ 0x67,	(ABILITY_HANDLER_FUNC) HandlerCustomAddStatusFailed },

{ 75,		(ABILITY_HANDLER_FUNC) HandlerStanceChange},
{ 0x65,	(ABILITY_HANDLER_FUNC) HandlerStanceChangeGuardCondition},
{ 0x67,	(ABILITY_HANDLER_FUNC) HandlerCustomAddStatusFailed },

{ 0x11,	(ABILITY_HANDLER_FUNC) HandlerGaleWings},

{ 0x38,	(ABILITY_HANDLER_FUNC) HandlerMegaLauncher},

{ 0x47,		(ABILITY_HANDLER_FUNC) HandlerGrassPelt}, 

{ 0x9C,		(ABILITY_HANDLER_FUNC) HandlerSymbiosis},
{ 0x9D,		(ABILITY_HANDLER_FUNC) HandlerSymbiosisPassItem},

{ 0x38,		(ABILITY_HANDLER_FUNC) HandlerToughClaws},

{ 40,		(ABILITY_HANDLER_FUNC) HandlerPixilate},
{ 59,		(ABILITY_HANDLER_FUNC) HandlerPixilateBoost},

{ 0x4B,		(ABILITY_HANDLER_FUNC) HandlerGooey},

{ 40,		(ABILITY_HANDLER_FUNC) HandlerAerilate},
{ 59,		(ABILITY_HANDLER_FUNC) HandlerAerilateBoost},

{ 0x35,		(ABILITY_HANDLER_FUNC) HandlerParentalBond},

{ 0x38,		(ABILITY_HANDLER_FUNC) HandlerDarkAura},
{ 0x38,		(ABILITY_HANDLER_FUNC) HandlerFairyAura},

{ 0x38,		(ABILITY_HANDLER_FUNC) HandlerAuraBreak},

{ 75,		(ABILITY_HANDLER_FUNC) HandlerDesolateLand},
{ 75,		(ABILITY_HANDLER_FUNC) HandlerPrimordialSea},
{ 75,		(ABILITY_HANDLER_FUNC) HandlerDeltaStream},

};

#pragma region EventAddAbility
int * EventAddAromaVeil(unsigned __int16 *a1)
{
  *a1 = 5;
  return (int*)&AbilityTriggerTable[0].triggerValue;
}

int * EventAddFlowerVeil(unsigned __int16 *a1)
{
  *a1 = 4;
  return (int*)&AbilityTriggerTable[5].triggerValue;
}

int * EventAddCheekPouch(unsigned __int16 *a1)
{
  *a1 = 2;
  return (int*)&AbilityTriggerTable[9].triggerValue;
}

int * EventAddProtean(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[11].triggerValue;
}

int * EventAddFurCoat(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[12].triggerValue;
}

int * EventAddMagician(unsigned __int16 *a1)
{
  *a1 = 2;
  
  return (int*)&AbilityTriggerTable[13].triggerValue;
}

int * EventAddBulletproof(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[15].triggerValue;
}

int * EventAddCompetitive(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[16].triggerValue;
}

int * EventAddStrongJaw(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[17].triggerValue;
}

int * EventAddRefrigerate(unsigned __int16 *a1)
{
  *a1 = 2;
  
  return (int*)&AbilityTriggerTable[18].triggerValue;
}

int * EventAddSweetVeil(unsigned __int16 *a1)
{
  *a1 = 2;
  
  return (int*)&AbilityTriggerTable[20].triggerValue;
}

int * EventAddStanceChange(unsigned __int16 *a1)
{
  *a1 = 3;
  
  return (int*)&AbilityTriggerTable[22].triggerValue;
}

int * EventAddGaleWings(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[25].triggerValue;
}

int * EventAddMegaLauncher(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[26].triggerValue;
}

int * EventAddGrassPelt(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[27].triggerValue;
}

int * EventAddSymbiosis(unsigned __int16 *a1)
{
  *a1 = 2;
  
  return (int*)&AbilityTriggerTable[28].triggerValue;
}

int * EventAddToughClaws(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[30].triggerValue;
}

int * EventAddPixilate(unsigned __int16 *a1)
{
  *a1 = 2;
  
  return (int*)&AbilityTriggerTable[31].triggerValue;
}

int * EventAddGooey(unsigned __int16 *a1)
{
  *a1 = 1;
 
  return (int*)&AbilityTriggerTable[33].triggerValue;
}
int * EventAddAerilate(unsigned __int16 *a1)
{
  *a1 = 2;
  
  return (int*)&AbilityTriggerTable[34].triggerValue;
}

int * EventAddParentalBond(unsigned __int16 *a1)
{
  *a1 = 1;
 
  return (int*)&AbilityTriggerTable[36].triggerValue;
}

int * EventAddDarkAura(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[37].triggerValue;
}

int * EventAddFairyAura(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[38].triggerValue;
}

int * EventAddAuraBreak(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[39].triggerValue;
}

int * EventAddPrimordialSea(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[40].triggerValue;
}

int * EventAddDesolateLand(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[40].triggerValue;
}

int * EventAddDeltaStream(unsigned __int16 *a1)
{
  *a1 = 1;
  
  return (int*)&AbilityTriggerTable[40].triggerValue;
}
#pragma endregion EventAddAbility


int * THUMB_BRANCH_AbilityEvent_AddItem(int a1) 
{
  int v2; // r3
  int BattleMonStat; // r4
  unsigned int i; // r2
  int v5; // r5
  int v6; // r7
  char MonID; // r6
  int v8; // r5
  int v9; // r0
  int v11[7]; // [sp+Ch] [bp-1Ch] BYREF

  int *AbilArray = (int*)GFL_HeapAllocate(0x12, 1264 + NEW_ABIL_NUMBER*8 + 32, 1, __FILE__, __LINE__);

  #pragma region OriginalAbilities
  AbilArray[0] = 0x00000016;
  AbilArray[1] = 0x021BDE51;
  AbilArray[2] = 0x0000001D;
  AbilArray[3] = 0x021BEAC9;
  AbilArray[4] = 0x00000049;
  AbilArray[5] = 0x021BEAC9;
  AbilArray[6] = 0x00000027;
  AbilArray[7] = 0x021BDEE1;
  AbilArray[8] = 0x00000050;
  AbilArray[9] = 0x021BDF05;
  AbilArray[10] = 0x0000002F;
  AbilArray[11] = 0x021BDF59;
  AbilArray[12] = 0x00000034;
  AbilArray[13] = 0x021BEA71;
  AbilArray[14] = 0x00000025;
  AbilArray[15] = 0x021BDF91;
  AbilArray[16] = 0x0000004A;
  AbilArray[17] = 0x021BDF91;
  AbilArray[18] = 0x0000006E;
  AbilArray[19] = 0x021BE3AD;
  AbilArray[20] = 0x00000003;
  AbilArray[21] = 0x021BE469;
  AbilArray[22] = 0x00000042;
  AbilArray[23] = 0x021BE4B5;
  AbilArray[24] = 0x00000043;
  AbilArray[25] = 0x021BE4D1;
  AbilArray[26] = 0x00000041;
  AbilArray[27] = 0x021BE4ED;
  AbilArray[28] = 0x00000044;
  AbilArray[29] = 0x021BE509;
  AbilArray[30] = 0x0000003E;
  AbilArray[31] = 0x021BE59D;
  AbilArray[32] = 0x0000005C;
  AbilArray[33] = 0x021BEA65;
  AbilArray[34] = 0x00000033;
  AbilArray[35] = 0x021BEA9D;
  AbilArray[36] = 0x00000056;
  AbilArray[37] = 0x021BEBC9;
  AbilArray[38] = 0x00000074;
  AbilArray[39] = 0x021BE3E1;
  AbilArray[40] = 0x0000006F;
  AbilArray[41] = 0x021BE3E1;
  AbilArray[42] = 0x0000003F;
  AbilArray[43] = 0x021BEA41;
  AbilArray[44] = 0x0000004F;
  AbilArray[45] = 0x021BE945;
  AbilArray[46] = 0x00000066;
  AbilArray[47] = 0x021BEC35;
  AbilArray[48] = 0x00000002;
  AbilArray[49] = 0x021BEFBD;
  AbilArray[50] = 0x00000046;
  AbilArray[51] = 0x021BEFD9;
  AbilArray[52] = 0x0000002D;
  AbilArray[53] = 0x021BEFF5;
  AbilArray[54] = 0x00000075;
  AbilArray[55] = 0x021BF011;
  AbilArray[56] = 0x0000004C;
  AbilArray[57] = 0x021BF0A5;
  AbilArray[58] = 0x0000000D;
  AbilArray[59] = 0x021BF0A5;
  AbilArray[60] = 0x00000065;
  AbilArray[61] = 0x021BE975;
  AbilArray[62] = 0x0000000C;
  AbilArray[63] = 0x021BEEA5;
  AbilArray[64] = 0x0000005D;
  AbilArray[65] = 0x021BF339;
  AbilArray[66] = 0x0000005A;
  AbilArray[67] = 0x021BF401;
  AbilArray[68] = 0x00000073;
  AbilArray[69] = 0x021BF0C1;
  AbilArray[70] = 0x0000002C;
  AbilArray[71] = 0x021BF0DD;
  AbilArray[72] = 0x00000013;
  AbilArray[73] = 0x021BF281;
  AbilArray[74] = 0x0000005B;
  AbilArray[75] = 0x021BE499;
  AbilArray[76] = 0x00000020;
  AbilArray[77] = 0x021BF2C5;
  AbilArray[78] = 0x0000005E;
  AbilArray[79] = 0x021BF1D5;
  AbilArray[80] = 0x00000021;
  AbilArray[81] = 0x021BDFF1;
  AbilArray[82] = 0x00000022;
  AbilArray[83] = 0x021BE025;
  AbilArray[84] = 0x0000003D;
  AbilArray[85] = 0x021BF39D;
  AbilArray[86] = 0x0000004D;
  AbilArray[87] = 0x021BE0A1;
  AbilArray[88] = 0x0000005F;
  AbilArray[89] = 0x021BE065;
  AbilArray[90] = 0x00000037;
  AbilArray[91] = 0x021BE115;
  AbilArray[92] = 0x00000004;
  AbilArray[93] = 0x021BF425;
  AbilArray[94] = 0x0000004B;
  AbilArray[95] = 0x021BF425;
  AbilArray[96] = 0x00000069;
  AbilArray[97] = 0x021BF455;
  AbilArray[98] = 0x00000053;
  AbilArray[99] = 0x021BF4E9;
  AbilArray[100] = 0x00000061;
  AbilArray[101] = 0x021BE411;
  AbilArray[102] = 0x00000059;
  AbilArray[103] = 0x021BE9B1;
  AbilArray[104] = 0x0000000E;
  AbilArray[105] = 0x021BE2C1;
  AbilArray[106] = 0x00000045;
  AbilArray[107] = 0x021BF97D;
  AbilArray[108] = 0x00000078;
  AbilArray[109] = 0x021BE9F9;
  AbilArray[110] = 0x00000009;
  AbilArray[111] = 0x021BF549;
  AbilArray[112] = 0x00000026;
  AbilArray[113] = 0x021BF519;
  AbilArray[114] = 0x00000031;
  AbilArray[115] = 0x021BF579;
  AbilArray[116] = 0x0000001B;
  AbilArray[117] = 0x021BF665;
  AbilArray[118] = 0x00000039;
  AbilArray[119] = 0x021BE5F9;
  AbilArray[120] = 0x0000003A;
  AbilArray[121] = 0x021BE5F9;
  AbilArray[122] = 0x00000038;
  AbilArray[123] = 0x021BF60D;
  AbilArray[124] = 0x00000008;
  AbilArray[125] = 0x021BE305;
  AbilArray[126] = 0x00000051;
  AbilArray[127] = 0x021BE349;
  AbilArray[128] = 0x00000024;
  AbilArray[129] = 0x021BF9AD;
  AbilArray[130] = 0x00000060;
  AbilArray[131] = 0x021BF9A1;
  AbilArray[132] = 0x00000018;
  AbilArray[133] = 0x021BF779;
  AbilArray[134] = 0x0000001E;
  AbilArray[135] = 0x021BFB89;
  AbilArray[136] = 0x0000001C;
  AbilArray[137] = 0x021BF959;
  AbilArray[138] = 0x00000058;
  AbilArray[139] = 0x021BFC35;
  AbilArray[140] = 0x00000005;
  AbilArray[141] = 0x021BFF49;
  AbilArray[142] = 0x00000055;
  AbilArray[143] = 0x021C0105;
  AbilArray[144] = 0x0000006D;
  AbilArray[145] = 0x021C00A1;
  AbilArray[146] = 0x00000057;
  AbilArray[147] = 0x021C031D;
  AbilArray[148] = 0x0000000A;
  AbilArray[149] = 0x021C0375;
  AbilArray[150] = 0x0000000B;
  AbilArray[151] = 0x021C0349;
  AbilArray[152] = 0x0000004E;
  AbilArray[153] = 0x021C0381;
  AbilArray[154] = 0x00000007;
  AbilArray[155] = 0x021BEC75;
  AbilArray[156] = 0x0000000F;
  AbilArray[157] = 0x021BECE1;
  AbilArray[158] = 0x00000048;
  AbilArray[159] = 0x021BECE1;
  AbilArray[160] = 0x00000014;
  AbilArray[161] = 0x021BEDF5;
  AbilArray[162] = 0x00000028;
  AbilArray[163] = 0x021BED21;
  AbilArray[164] = 0x00000029;
  AbilArray[165] = 0x021BEDA1;
  AbilArray[166] = 0x00000011;
  AbilArray[167] = 0x021BED61;
  AbilArray[168] = 0x00000071;
  AbilArray[169] = 0x021C03D5;
  AbilArray[170] = 0x0000002B;
  AbilArray[171] = 0x021C0451;
  AbilArray[172] = 0x0000001A;
  AbilArray[173] = 0x021C04ED;
  AbilArray[174] = 0x0000007A;
  AbilArray[175] = 0x021BE8CD;
  AbilArray[176] = 0x00000012;
  AbilArray[177] = 0x021C0869;
  AbilArray[178] = 0x0000006C;
  AbilArray[179] = 0x021BFD85;
  AbilArray[180] = 0x0000006B;
  AbilArray[181] = 0x021BFE81;
  AbilArray[182] = 0x00000077;
  AbilArray[183] = 0x021BFF3D;
  AbilArray[184] = 0x0000006A;
  AbilArray[185] = 0x021BF821;
  AbilArray[186] = 0x00000032;
  AbilArray[187] = 0x021C0991;
  AbilArray[188] = 0x00000010;
  AbilArray[189] = 0x021BF8A9;
  AbilArray[190] = 0x00000068;
  AbilArray[191] = 0x021C0AB1;
  AbilArray[192] = 0x00000036;
  AbilArray[193] = 0x021C0661;
  AbilArray[194] = 0x0000001F;
  AbilArray[195] = 0x021C0CBD;
  AbilArray[196] = 0x00000072;
  AbilArray[197] = 0x021C0C79;
  AbilArray[198] = 0x00000070;
  AbilArray[199] = 0x021BE299;
  AbilArray[200] = 0x00000006;
  AbilArray[201] = 0x021C0741;
  AbilArray[202] = 0x00000019;
  AbilArray[203] = 0x021C0589;
  AbilArray[204] = 0x00000064;
  AbilArray[205] = 0x021BE139;
  AbilArray[206] = 0x0000003B;
  AbilArray[207] = 0x021C0C6D;
  AbilArray[208] = 0x00000015;
  AbilArray[209] = 0x021C0E1D;
  AbilArray[210] = 0x00000040;
  AbilArray[211] = 0x021C0EAD;
  AbilArray[212] = 0x00000067;
  AbilArray[213] = 0x021C1045;
  AbilArray[214] = 0x0000003C;
  AbilArray[215] = 0x021C1139;
  AbilArray[216] = 0x0000002E;
  AbilArray[217] = 0x021C1145;
  AbilArray[218] = 0x00000062;
  AbilArray[219] = 0x021C1215;
  AbilArray[220] = 0x0000007B;
  AbilArray[221] = 0x021C0939;
  AbilArray[222] = 0x00000035;
  AbilArray[223] = 0x021C1435;
  AbilArray[224] = 0x00000054;
  AbilArray[225] = 0x021C13C1;
  AbilArray[226] = 0x00000001;
  AbilArray[227] = 0x021C1239;
  AbilArray[228] = 0x00000017;
  AbilArray[229] = 0x021C1269;
  AbilArray[230] = 0x00000047;
  AbilArray[231] = 0x021C12DD;
  AbilArray[232] = 0x0000002A;
  AbilArray[233] = 0x021C134D;
  AbilArray[234] = 0x0000007C;
  AbilArray[235] = 0x021C1549;
  AbilArray[236] = 0x0000007D;
  AbilArray[237] = 0x021C1831;
  AbilArray[238] = 0x00000080;
  AbilArray[239] = 0x021C1919;
  AbilArray[240] = 0x00000081;
  AbilArray[241] = 0x021C1961;
  AbilArray[242] = 0x00000088;
  AbilArray[243] = 0x021C1999;
  AbilArray[244] = 0x00000086;
  AbilArray[245] = 0x021C2445;
  AbilArray[246] = 0x00000087;
  AbilArray[247] = 0x021C246D;
  AbilArray[248] = 0x0000007E;
  AbilArray[249] = 0x021C24B9;
  AbilArray[250] = 0x0000007F;
  AbilArray[251] = 0x021C257D;
  AbilArray[252] = 0x00000082;
  AbilArray[253] = 0x021C16C9;
  AbilArray[254] = 0x00000083;
  AbilArray[255] = 0x021C1A75;
  AbilArray[256] = 0x00000084;
  AbilArray[257] = 0x021C19CD;
  AbilArray[258] = 0x00000085;
  AbilArray[259] = 0x021C1785;
  AbilArray[260] = 0x00000089;
  AbilArray[261] = 0x021C1AB9;
  AbilArray[262] = 0x0000008A;
  AbilArray[263] = 0x021C1AFD;
  AbilArray[264] = 0x0000008B;
  AbilArray[265] = 0x021C2439;
  AbilArray[266] = 0x0000008C;
  AbilArray[267] = 0x021C1B89;
  AbilArray[268] = 0x0000008D;
  AbilArray[269] = 0x021C1D01;
  AbilArray[270] = 0x0000008E;
  AbilArray[271] = 0x021C1D31;
  AbilArray[272] = 0x0000008F;
  AbilArray[273] = 0x021C1DCD;
  AbilArray[274] = 0x00000090;
  AbilArray[275] = 0x021C1E55;
  AbilArray[276] = 0x00000091;
  AbilArray[277] = 0x021C1E61;
  AbilArray[278] = 0x00000092;
  AbilArray[279] = 0x021C1E8D;
  AbilArray[280] = 0x00000093;
  AbilArray[281] = 0x021C1EC1;
  AbilArray[282] = 0x00000094;
  AbilArray[283] = 0x021C1EFD;
  AbilArray[284] = 0x00000095;
  AbilArray[285] = 0x021C262D;
  AbilArray[286] = 0x00000096;
  AbilArray[287] = 0x021C2621;
  AbilArray[288] = 0x00000097;
  AbilArray[289] = 0x021C20E5;
  AbilArray[290] = 0x00000098;
  AbilArray[291] = 0x021C2225;
  AbilArray[292] = 0x00000099;
  AbilArray[293] = 0x021C20F1;
  AbilArray[294] = 0x0000009A;
  AbilArray[295] = 0x021C2165;
  AbilArray[296] = 0x0000009B;
  AbilArray[297] = 0x021C21BD;
  AbilArray[298] = 0x0000009C;
  AbilArray[299] = 0x021C2395;
  AbilArray[300] = 0x0000009D;
  AbilArray[301] = 0x021C22F5;
  AbilArray[302] = 0x0000009E;
  AbilArray[303] = 0x021C2335;
  AbilArray[304] = 0x0000009F;
  AbilArray[305] = 0x021C1F55;
  AbilArray[306] = 0x000000A0;
  AbilArray[307] = 0x021BF779;
  AbilArray[308] = 0x000000A1;
  AbilArray[309] = 0x021C207D;
  AbilArray[310] = 0x000000A2;
  AbilArray[311] = 0x021C26F9;
  AbilArray[312] = 0x000000A3;
  AbilArray[313] = 0x021C0AB1;
  AbilArray[314] = 0x000000A4;
  AbilArray[315] = 0x021C0AB1;

#pragma endregion OriginalAbilities

  //New slots
  #pragma region NewAbilities
  AbilArray[316] = 0x000000A5 ;
  AbilArray[317] = (int) ((*EventAddAromaVeil));
  AbilArray[318] = 0x000000A6 ;
  AbilArray[319] = (int) ((*EventAddFlowerVeil));
  AbilArray[320] = 0x000000A7 ;
  AbilArray[321] = (int) ((*EventAddCheekPouch));
  AbilArray[322] = 0x000000A8 ;
  AbilArray[323] = (int) ((*EventAddProtean));
  AbilArray[324] = 0x000000A9 ;
  AbilArray[325] = (int) ((*EventAddFurCoat));
  AbilArray[326] = 0x000000AA ;
  AbilArray[327] = (int) ((*EventAddMagician));
  AbilArray[328] = 0x000000AB ;
  AbilArray[329] = (int) ((*EventAddBulletproof));
  AbilArray[330] = 0x000000AC ;
  AbilArray[331] = (int) ((*EventAddCompetitive));
  AbilArray[332] = 0x000000AD ;
  AbilArray[333] = (int) ((*EventAddStrongJaw));
  AbilArray[334] = 0x000000AE ;
  AbilArray[335] = (int) ((*EventAddRefrigerate));
  AbilArray[336] = 0x000000AF ;
  AbilArray[337] = (int) ((*EventAddSweetVeil));
  AbilArray[338] = 0x000000B0 ;
  AbilArray[339] = (int) ((*EventAddStanceChange));
  AbilArray[340] = 0x000000B1 ;
  AbilArray[341] = (int) ((*EventAddGaleWings));
  AbilArray[342] = 0x000000B2 ;
  AbilArray[343] = (int) ((*EventAddMegaLauncher));
  AbilArray[344] = 0x000000B3 ;
  AbilArray[345] = (int) ((*EventAddGrassPelt));
  AbilArray[346] = 0x000000B4 ;
  AbilArray[347] = (int) ((*EventAddSymbiosis));
  AbilArray[348] = 0x000000B5 ;
  AbilArray[349] = (int) ((*EventAddToughClaws));
  AbilArray[350] = 0x000000B6 ;
  AbilArray[351] = (int) ((*EventAddPixilate));
  AbilArray[352] = 0x000000B7 ;
  AbilArray[353] = (int) ((*EventAddGooey));
  AbilArray[354] = 0x000000B8 ;
  AbilArray[355] = (int) ((*EventAddAerilate));
  AbilArray[356] = 0x000000B9 ;
  AbilArray[357] = (int) ((*EventAddParentalBond));
  AbilArray[358] = 0x000000BA ;
  AbilArray[359] = (int) ((*EventAddDarkAura));
  AbilArray[360] = 0x000000BB ;
  AbilArray[361] = (int) ((*EventAddFairyAura));
  AbilArray[362] = 0x000000BC ;
  AbilArray[363] = (int) ((*EventAddAuraBreak));
  AbilArray[364] = 0x000000BD ;
  AbilArray[365] = (int) ((*EventAddPrimordialSea));
  AbilArray[366] = 0x000000BE ;
  AbilArray[367] = (int) ((*EventAddDesolateLand));
  AbilArray[368] = 0x000000BF ;
  AbilArray[369] = (int) ((*EventAddDeltaStream));
  #pragma endregion NewAbilities
  
  //Filler? Present in the original table
  AbilArray[372] = 0x04030201;
  AbilArray[373] = 0x00000005;
  
  BattleMonStat = (unsigned __int16)GetBattleMonStat(a1, 16);
  //BattleMonStat = 183; For testing purposes, give everyone this ability effect
  for ( i = 0; i < DEFAULT_ABIL_NUMBER + NEW_ABIL_NUMBER; ++i )
  {
    v5 = 8 * i;
    if ( BattleMonStat == AbilArray[2*i] )
    {
      v6 = calcAbilHandlerSubPriority(a1, (int)AbilArray[i], i, v2);
      MonID = GetMonID(a1);
      v8 = (*(int (**)(int *))((char *)&AbilArray[0] + v5 + 4))(v11);
      v9 = devideNumHandersAndPri(v11);
      GFL_HeapFree((void*)AbilArray);
      return BattleEvent_AddItem(4, BattleMonStat, v9, v6, MonID, v8, v11[0]);
      
    }
  }
  
  GFL_HeapFree((void*)AbilArray);
  return 0;
}

} 

