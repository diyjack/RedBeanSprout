/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f1_system.h"
#include "stm32f1_flash.h"
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_WritePage
**功能 : 
**輸入 : 
**輸出 : None
**使用 : 
**=====================================================================================================*/
/*=====================================================================================================*/
void Flash_WritePage( u32 WritePage, uc16 *WriteData, u16 DataLen )
{
  u16 Count = 0;
  FLASH_Status FLASHStatus;

  FLASH_UnlockBank1();

  FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
  FLASHStatus = FLASH_ErasePage(WritePage);
  while((Count < DataLen) && (FLASHStatus == FLASH_COMPLETE)) {
    FLASHStatus = FLASH_ProgramHalfWord(WritePage+(Count<<1), WriteData[Count]);
    Count++;
  }
  FLASH_LockBank1();
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ReadPage
**功能 : 
**輸入 : 
**輸出 : None
**使用 : 
**=====================================================================================================*/
/*=====================================================================================================*/
void Flash_ReadPage( u32 ReadPage, u16 *ReadData, u16 DataLen )
{
  u16 Count = 0;

  while(Count<DataLen) {
    ReadData[Count] = (*(vu32*)(ReadPage+(Count<<1)));
    Count++;
  }
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ErasePage
**功能 : 
**輸入 : 
**輸出 : None
**使用 : 
**=====================================================================================================*/
/*=====================================================================================================*/
void Flash_ErasePage( u32 ErasePage )
{
  FLASH_Status FLASHStatus;

  FLASH_UnlockBank1();
  FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
  FLASHStatus = FLASH_ErasePage(ErasePage);
  while(FLASHStatus != FLASH_COMPLETE);
  FLASH_LockBank1();
}
/*=====================================================================================================*/
/*=====================================================================================================*/
