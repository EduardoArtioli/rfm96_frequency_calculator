/*****************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define FXOSC 32000000
// #define FSTEPdiv 524288

uint32_t rfm_freq(uint8_t reg0, uint8_t reg1, uint8_t reg2)
{
    uint8_t FSTEP;

    uint32_t FSTEPdiv, RegsBigEndian, frequency;

    FSTEPdiv = pow(2,19);
    FSTEP = FXOSC / FSTEPdiv;

    RegsBigEndian = (reg0 << 16) | (reg1 << 8) | reg2;

    frequency = FSTEP * RegsBigEndian;

    return frequency;
}

void main(void)
{
    uint8_t reg0, reg1, reg2;

    // 433.92 MHz
    reg0 = 0x6C;
    reg1 = 0x5C;
    reg2 = 0xA0;

    printf("%d\n", rfm_freq(reg0, reg1, reg2));
}
/*****************************************************************/
