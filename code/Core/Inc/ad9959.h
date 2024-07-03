
#ifndef AD9959_AD9959_H
#define AD9959_AD9959_H

#define CSR             0x00    //通道选择寄存器
#define FR1             0x01    //功能寄存器1
#define FR2             0x02    //功能寄存器2
#define CFR             0x03    //通道功能寄存器
#define CFTWO           0x04    //通道频率转换字寄存器
#define CPOWO           0x05    //通道相位转换字寄存器
#define ACR             0x06    //幅度控制寄存器
#define LSRR            0x07    //通道线性扫描寄存器
#define RDW             0x08    //通道线性向上扫描寄存器
#define FDW             0x09    //通道线性向下扫描寄存器

extern uint8_t chanel_num;

extern uint32_t fre[4];
extern uint32_t amp[4];
extern uint32_t pha[4];

extern uint8_t ch0[1];
extern uint8_t ch1[1];
extern uint8_t ch2[1];
extern uint8_t ch3[1];

extern uint8_t CSR_data[1];
extern uint8_t FR1_data[3];
extern uint8_t FR2_data[2];
extern uint8_t CFR_data[3];
extern uint8_t CFTWO_data[4];
extern uint8_t CPOWO_data[2];
extern uint8_t ACR_data[3];


void delay1 (uint32_t length);
void update();
void IO_Init(void);  //IO口初始化
void Reset(void); //复位
void ad9959_init();


//功能函数
void Write_Amplitude(uint8_t channel,uint16_t Amplitude);
void Write_Phase(uint8_t channel,uint16_t Phase);
void Write_frequence(uint8_t channel,uint32_t freq);


#endif //AD9959_AD9959_H
