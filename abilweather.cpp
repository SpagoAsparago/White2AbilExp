#include "abilexp.h"

extern "C" {

unsigned int * THUMB_BRANCH_CommonWeatherChangeAbility (int a1, unsigned int *a2, char Weather)
{
  int WeatherDuration = 5;
  unsigned int *result; // r0
  char *v7; // r0

  result = (unsigned int *)BattleEventVar_GetValue(VAR_MONID);
  if ( a2 == result )
  {
    int itemId = GetBattleMonHeldItem(GetBattleMon(a1, (unsigned int)result));

    if ( ( (Weather == WEATHER_RAIN) && (itemId == 285) ) //Damp Rock
    || ( (Weather == WEATHER_SUN) && (itemId == 284) ) //Heat Rock
    || ( (Weather == WEATHER_SAND) && (itemId == 283) ) //Smooth Rock
    || ( (Weather == WEATHER_HAIL) && (itemId == 282) ) ) //Icy Rock
    {
      WeatherDuration = 8;
    }
    
    v7 = BattleHandler_PushWork(a1, 29, (int)a2);
    *(unsigned int*)v7 |= 0x800000u;
    v7[4] = Weather;
    v7[5] = WeatherDuration;
    return BattleHandler_PopWork(a1, (unsigned int*)v7);
  }
  return result;
}


}
