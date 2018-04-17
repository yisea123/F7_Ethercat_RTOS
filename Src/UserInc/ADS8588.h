#ifndef __ADS8588_H
#define	__ADS8588_H

#include "stm32f7xx_hal.h"




typedef struct AD_DEVICE_STRUCT{
	uint16_t uChannel[8];
	float fChannel[8];
	float fMinVoltage;
	float fMaxVoltage;
	float fRange;
	float fMid;
	uint16_t uChannelNum;
	SPI_HandleTypeDef *AD_spi;
	uint8_t ucDataFlag;
	void (*getVoltage)(struct AD_DEVICE_STRUCT *ptADDev);
	void (*Reset)(struct AD_DEVICE_STRUCT *ptADDev);
}AD_DEVICE;

void Init_AD(AD_DEVICE * ptADDev,uint16_t numChannel,float vMin,float vMax,SPI_HandleTypeDef *AD_spi);
void AD_BUSYCallback(AD_DEVICE *ptADDev);
void AD_SPICallback(AD_DEVICE *ptADDev);
#endif /* __BSP_ADC_H */



