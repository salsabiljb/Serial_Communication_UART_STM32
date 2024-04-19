#ifndef ADC_H
#define ADC_H
#include <stdint.h>
void ADC_Init(void);
void ADC_Enable(void);
void ADC_Start(int channel);
void ADC_WaitForConv(void);
uint16_t ADC_GetVal(void);
void ADC_Disable(void);

#endif /* ADC_H */
