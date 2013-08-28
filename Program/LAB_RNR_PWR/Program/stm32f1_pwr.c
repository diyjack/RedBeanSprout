/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f1_system.h"
#include "stm32f1_pwr.h"
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : PWR_StandbyMode
**功能 : 進入待機模式
**輸入 : None
**輸出 : None
**使用 : PWR_StandbyMode();   // Use KEY_WU to WakeUp
**=====================================================================================================*/
/*=====================================================================================================*/
void PWR_StandbyMode( void )
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

  PWR_WakeUpPinCmd(ENABLE);
  PWR_BackupAccessCmd(ENABLE);
  PWR_ClearFlag(PWR_FLAG_SB);
  PWR_EnterSTANDBYMode();
}
/*=====================================================================================================*/
/*=====================================================================================================*/
