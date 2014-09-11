#line 1 "..\\main.c"










 
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"
 
 
 





 






 













#line 38 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"


  
  typedef unsigned int size_t;    








 
 

 
  typedef struct __va_list __va_list;





   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 129 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 
extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 948 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"



 

#line 13 "..\\main.c"
#line 1 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
     
 
 
 
 




              




 
 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn         = -14,     
  HardFault_IRQn              = -13,     
  SVCall_IRQn                 = -5,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  BOD_IRQn                  = 0,          
  WDT_IRQn                  = 1,         
  EINT0_IRQn                = 2,         
  EINT1_IRQn                = 3,         
  GPAB_IRQn                 = 4,         
  GPCDEF_IRQn               = 5,         
  PWMA_IRQn                 = 6,         
  PWMB_IRQn                 = 7,         
  TMR0_IRQn                 = 8,         
  TMR1_IRQn                 = 9,         
  TMR2_IRQn                 = 10,        
  TMR3_IRQn                 = 11,        
  UART02_IRQn               = 12,       
  UART1_IRQn                = 13,        
  SPI0_IRQn                 = 14,        
  SPI1_IRQn                 = 15,        
  SPI2_IRQn                 = 16,        
  SPI3_IRQn                 = 17,        
  I2C0_IRQn                 = 18,        
  I2C1_IRQn                 = 19,        
  CAN0_IRQn                 = 20,        
  CAN1_IRQn                 = 21,        
  SC012_IRQn                = 22,        
  USBD_IRQn                 = 23,        
  PS2_IRQn                  = 24,        
  ACMP_IRQn                 = 25,        
  PDMA_IRQn                 = 26,        
  I2S_IRQn                  = 27,        
  PWRWU_IRQn                = 28,        
  ADC_IRQn                  = 29,        
  IRC_IRQn                  = 30,        
  RTC_IRQn                  = 31         
} IRQn_Type;






 

 





#line 1 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\CoreSupport\\core_cm0.h"
 




















 










 











#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"
 
 





 










#line 26 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"







 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     
typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;

     
typedef   signed       __int64 intmax_t;
typedef unsigned       __int64 uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 197 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"

     







     










     











#line 261 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"



 



#line 46 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\CoreSupport\\core_cm0.h"

















 

#line 72 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\CoreSupport\\core_cm0.h"





 


 





 
typedef struct
{
  volatile uint32_t ISER[1];                       
       uint32_t RESERVED0[31];
  volatile uint32_t ICER[1];                       
       uint32_t RSERVED1[31];
  volatile uint32_t ISPR[1];                       
       uint32_t RESERVED2[31];
  volatile uint32_t ICPR[1];                       
       uint32_t RESERVED3[31];
       uint32_t RESERVED4[64];
  volatile uint32_t IPR[8];                        
}  NVIC_Type;
   





 
typedef struct
{
  volatile const  uint32_t CPUID;                         
  volatile uint32_t ICSR;                          
       uint32_t RESERVED0;                                      
  volatile uint32_t AIRCR;                         
  volatile uint32_t SCR;                           
  volatile uint32_t CCR;                           
       uint32_t RESERVED1;                                      
  volatile uint32_t SHP[2];                        
  volatile uint32_t SHCSR;                         
       uint32_t RESERVED2[2];                                   
  volatile uint32_t DFSR;                          
} SCB_Type;                                                

 















 



























 















 









 






 



 














   





 
typedef struct
{
  volatile uint32_t CTRL;                          
  volatile uint32_t LOAD;                          
  volatile uint32_t VAL;                           
  volatile const  uint32_t CALIB;                         
} SysTick_Type;

 












 



 



 








   





 
typedef struct
{
  volatile uint32_t DHCSR;                         
  volatile  uint32_t DCRSR;                         
  volatile uint32_t DCRDR;                         
  volatile uint32_t DEMCR;                         
} CoreDebug_Type;

 

































 






 








   


 











   




 





#line 367 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\CoreSupport\\core_cm0.h"


 


 




#line 385 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\CoreSupport\\core_cm0.h"


 
 








 
extern uint32_t __get_PSP(void);








 
extern void __set_PSP(uint32_t topOfProcStack);








 
extern uint32_t __get_MSP(void);








 
extern void __set_MSP(uint32_t topOfMainStack);








 
extern uint32_t __REV16(uint16_t value);








 
extern int32_t __REVSH(int16_t value);


#line 490 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\CoreSupport\\core_cm0.h"








 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}







 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}







 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}







 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}





#line 760 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\CoreSupport\\core_cm0.h"







 
 

 

 
 












 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISER[0] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICER[0] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[0] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}








 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[0] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICPR[0] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}












 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[( ((((uint32_t)(IRQn) & 0x0F)-8) >> 2) )] = (((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[( ((((uint32_t)(IRQn) & 0x0F)-8) >> 2) )] & ~(0xFF << ( (((uint32_t)(IRQn) ) & 0x03) * 8 ))) | 
        (((priority << (8 - 2)) & 0xFF) << ( (((uint32_t)(IRQn) ) & 0x03) * 8 )); }
  else {
    ((NVIC_Type *) ((0xE000E000) + 0x0100))->IPR[( ((uint32_t)(IRQn) >> 2) )] = (((NVIC_Type *) ((0xE000E000) + 0x0100))->IPR[( ((uint32_t)(IRQn) >> 2) )] & ~(0xFF << ( (((uint32_t)(IRQn) ) & 0x03) * 8 ))) |
        (((priority << (8 - 2)) & 0xFF) << ( (((uint32_t)(IRQn) ) & 0x03) * 8 )); }
}















 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)((((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[( ((((uint32_t)(IRQn) & 0x0F)-8) >> 2) )] >> ( (((uint32_t)(IRQn) ) & 0x03) * 8 ) ) >> (8 - 2)));  }  
  else {
    return((uint32_t)((((NVIC_Type *) ((0xE000E000) + 0x0100))->IPR[( ((uint32_t)(IRQn) >> 2) )] >> ( (((uint32_t)(IRQn) ) & 0x03) * 8 ) ) >> (8 - 2)));  }  
}



 












 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > (0xFFFFFFul << 0))  return (1);             
                                                               
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD  = (ticks & (0xFFFFFFul << 0)) - 1;       
  NVIC_SetPriority (SysTick_IRQn, (1<<2) - 1);   
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL   = 0;                                           
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL  = (1ul << 2) | 
                   (1ul << 1)   | 
                   (1ul << 0);                     
  return (0);                                                   
}






 





 
static __inline void NVIC_SystemReset(void)
{
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR  = ((0x5FA << 16)      | 
                 (1ul << 2));
  __dsb(0);                                                                                            
  while(1);                                                                             
}

   





   



 
#line 75 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\system_NUC200Series.h"
 
 
 
 
 






 
 
 



   









 



 






extern uint32_t SystemCoreClock;                    
extern uint32_t CyclesPerUs;                        
extern uint32_t PllClock;                           









 
extern void SystemInit(void);










 
extern void SystemCoreClockUpdate (void);





#line 76 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"


#pragma anon_unions



 



 


 



 
typedef struct
{
    




     
    volatile uint32_t  PMD;                         

    




     
    volatile uint32_t  OFFD;                        

    




     
    volatile uint32_t  DOUT;                        

    




     
    volatile uint32_t  DMASK;                       

    




     
    volatile const  uint32_t  PIN;                         

    




     
    volatile uint32_t  DBEN;                        

    




     
    volatile uint32_t  IMD;                         

    




     
    volatile uint32_t  IEN;                         

    




     
    volatile uint32_t  ISRC;                        
} GPIO_T;                                  
                                                
typedef struct                                  
{                                               
    




     
    volatile uint32_t  DBNCECON;                    
} GPIO_DBNCECON_T;

 
















































 



                                            



 



 



 



 



 






 



 








   



 




 
typedef struct
{
                                
    union {                             
    volatile uint32_t DATA;                 

    










     
    volatile uint32_t THR;                  

    








     
    volatile uint32_t RBR;                  
    };

    









































     
    volatile uint32_t IER;                  

    



































     
    volatile uint32_t FCR;                  

    





























     
    volatile uint32_t LCR;                  

    

















     
    volatile uint32_t MCR;                  

    
















     
    volatile uint32_t MSR;                  

    





























































     
    volatile uint32_t FSR;                  

    















































     
    volatile uint32_t ISR;                  

    














     
    volatile uint32_t TOR;                  

    





















     
    volatile uint32_t BAUD;                 

    


















     
    volatile uint32_t IRCR;                 

    


























     
    volatile uint32_t ALT_CSR;               

    











     
    volatile uint32_t FUN_SEL;               
    volatile uint32_t LIN_CTL; 
    volatile uint32_t LIN_SR; 
} UART_T;




 



 



 







































 















 


















 









 










 







































 











    









































           



















 






 












 









 
























 



 










































 












   


 



 
typedef struct
{
    




     
    volatile uint32_t  TCSR;                

    




     
    volatile uint32_t  TCMPR;		        

    




     
    volatile uint32_t  TISR;		        

    




     
    volatile const  uint32_t  TDR;			        

    




     
    volatile const  uint32_t  TCAP;		        

    




     
    volatile uint32_t  TEXCON;	            

    




     
    volatile uint32_t  TEXISR;	            
} TIMER_T;

 








                                                                                 





















 



 






 



 



 





















 


   


 



 
typedef struct
{
    




     
    volatile uint32_t  WTCR;                 

    




     
    volatile uint32_t  WTCRALT;              
} WDT_T;

 






























 


   


 



 
typedef struct
{
    




     
    volatile uint32_t  WWDTRLD;

    




     
    volatile uint32_t  WWDTCR;

    




     
    volatile uint32_t  WWDTSR;

    




     
    volatile const  uint32_t  WWDTCVR;
} WWDT_T;

 



 















 






 


   


 



 
typedef struct
{
    volatile uint32_t CNTRL;       
    volatile uint32_t DIVIDER;     
    volatile uint32_t SSR;         
    volatile const  uint32_t RESERVE0;
    volatile const  uint32_t RX[2];       
    volatile const  uint32_t RESERVE1;
    volatile const  uint32_t RESERVE2;
    volatile  uint32_t TX[2];       
    volatile const  uint32_t RESERVE3;
    volatile const  uint32_t RESERVE4;
    volatile const  uint32_t RESERVE5;
    volatile uint32_t VARCLK;      
    volatile uint32_t DMA;         
    volatile uint32_t CNTRL2;      
    volatile uint32_t FIFO_CTL;    
    volatile uint32_t STATUS;      
} SPI_T;


 






















































 






 















 









 
























 
























 




































   



 



 
typedef struct
{
    
































     
    volatile uint32_t I2CON;	
    
     













    
    volatile uint32_t I2CADDR0;    

    








     
    volatile uint32_t I2CDAT;    
    
    

















     
    volatile const  uint32_t I2CSTATUS;        
    
    








     
    volatile uint32_t I2CLK;    
    
    


















     
    volatile uint32_t I2CTOC;    
    
    













     
    volatile uint32_t I2CADDR1;    
    
    













     
    volatile uint32_t I2CADDR2;    
    
    













     
    volatile uint32_t I2CADDR3; 
    
    














     
    volatile uint32_t I2CADM0;    
    
    














     
    volatile uint32_t I2CADM1;    
    
    














     
    volatile uint32_t I2CADM2;    
    
    














     
    volatile uint32_t I2CADM3;    
    
    




     
    uint32_t RESERVED0[2];
      
    









     
    volatile uint32_t I2CWKUPCON;
    
    









     
    volatile uint32_t I2CWKUPSTS;            
} I2C_T;

 


















 






 



 



 



 









 



 



 



   


 



 
typedef struct
{
    




     
    volatile uint32_t INIR;

    




     
    volatile uint32_t AER;

    




     
    volatile uint32_t FCR;

    




     
    volatile uint32_t TLR;

    




     
    volatile uint32_t CLR;

    




     
    volatile uint32_t TSSR;

    




     
    volatile uint32_t DWR;

    




     
    volatile uint32_t TAR;

    




     
    volatile uint32_t CAR;

    




     
    volatile const  uint32_t LIR;

    




     
    volatile uint32_t RIER;

    




     
    volatile uint32_t RIIR;

    




     
    volatile uint32_t TTR;
} RTC_T;

                                             






 






 






 


















 


















                                             



 



 


















 


















 



 






 






 


   



 



 
typedef struct
{
    volatile const  uint32_t ADDR[8];                
    volatile uint32_t ADCR;                   
    volatile uint32_t ADCHER;                 
    volatile uint32_t ADCMPR[2];              
    volatile uint32_t ADSR;                   
    volatile const  uint32_t RESERVE0[3];
    volatile const  uint32_t ADPDMA;                 
} ADC_T;


 









 






























 






 


















 





















 



   


 



 
typedef struct
{
        volatile uint32_t CMPCR[2];         
        volatile uint32_t CMPSR;            

} ACMP_T;


 












 












   



 



 
typedef struct
{
    volatile uint32_t PWRCON;           
    volatile uint32_t AHBCLK;           
    volatile uint32_t APBCLK;           
    volatile uint32_t CLKSTATUS;        
    volatile uint32_t CLKSEL0;          
    volatile uint32_t CLKSEL1;          
    volatile uint32_t CLKDIV;           
    volatile uint32_t CLKSEL2;           
    volatile uint32_t PLLCON;           
    volatile uint32_t FRQDIV;           
    volatile uint32_t RESERVE[2];           
    volatile uint32_t APBCLK1;             
    volatile uint32_t CLKSEL3;          
    volatile uint32_t CLKDIV1;                        
} SYSCLK_T;

 



























 







 







































































                                                









 









 


















 






 







































 



























 









 












 









 





















 






   

 



 

typedef struct
{
    volatile const uint32_t PDID;
    volatile uint32_t RSTSRC;
    volatile uint32_t IPRSTC1;
    volatile uint32_t IPRSTC2;
    volatile uint32_t IPRSTC3;   
    uint32_t RESERVE0;
    volatile uint32_t BODCR;
    volatile uint32_t TEMPCR;
    uint32_t RESERVE1;
    volatile uint32_t PORCR;
    uint32_t RESERVE2[2];
    volatile uint32_t GPA_MFP;
    volatile uint32_t GPB_MFP;
    volatile uint32_t GPC_MFP;
    volatile uint32_t GPD_MFP;
    volatile uint32_t GPE_MFP;
    volatile uint32_t GPF_MFP;
    uint32_t RESERVE3[2];
    volatile uint32_t ALT_MFP;
    uint32_t RESERVE4;
    volatile uint32_t ALT_MFP1;
    uint32_t RESERVE5[9];
    volatile uint32_t IRCTRIMCTL;
    volatile uint32_t IRCTRIMIEN;  
    volatile uint32_t IRCTRIMINT; 
    uint32_t RESERVE6[29];       
    volatile uint32_t REGWRPROT;
} GCR_T;

 





















 









 





































































 









 





















 



 



 







 






 






 






 












 















 






















































 













































 












 






 









 




typedef struct
{
    volatile const uint32_t IRQSRC[32];
    volatile uint32_t NMISEL;
    volatile uint32_t MCUIRQ;
} GCR_INT_T;

 



 





   

 



 
typedef struct
{
    





















































     
    volatile uint32_t ISPCON;

    









     
    volatile uint32_t ISPADR;

    









     
    volatile uint32_t ISPDAT;

    












     
    volatile uint32_t ISPCMD;

    











     
    volatile uint32_t ISPTRG;

    













     
    volatile const  uint32_t DFBADR;

    

























     
    volatile uint32_t FATCON;
    
    volatile const  uint32_t  RESERVED[9];

    volatile uint32_t ISPSTA;

} FMC_T;

 




















                                                                                        



 



 



 









 



 



 


























   


 



 
typedef struct
{
    















































   	
		volatile uint32_t PS2CON;
		
    









  						
		volatile uint32_t PS2TXDATA0;
		
    









  		
		volatile uint32_t PS2TXDATA1;
		
    









  			
		volatile uint32_t PS2TXDATA2;
		
    









  		
		volatile uint32_t PS2TXDATA3;
		
    











   		
		volatile uint32_t PS2RXDATA;
		
     






















































    		
		volatile uint32_t PS2STATUS;
		
     

















    		
		volatile uint32_t PS2INTID;
}PS2_T;


 



























 



 



























 


                     


   

 



 

typedef struct
{
    volatile uint32_t CREQ;
    volatile uint32_t CMASK;
    volatile uint32_t MASK1;
    volatile uint32_t MASK2;
    volatile uint32_t ARB1;
    volatile uint32_t ARB2;	
    volatile uint32_t MCON;			
    volatile uint32_t DAT_A1;			
    volatile uint32_t DAT_A2;		
    volatile uint32_t DAT_B1;
    volatile uint32_t DAT_B2;		
    volatile const uint32_t RESERVE0[13];        
                                    
} CAN_IF_T;

typedef struct
{
    volatile uint32_t   CON;		 	
    volatile uint32_t   STATUS;	
    volatile uint32_t   ERR;     		
    volatile uint32_t   BTIME;
    volatile uint32_t   IIDR;
    volatile uint32_t   TEST;
    volatile uint32_t   BRPE;
    volatile const uint32_t   	RESERVE0[1];     
    CAN_IF_T        IF[2];             
 	volatile const uint32_t   	RESERVE1[8];
    volatile uint32_t   TXREQ1;
    volatile uint32_t   TXREQ2;
    volatile const uint32_t   	RESERVE2[6];        
    volatile uint32_t   NDAT1;
    volatile uint32_t   NDAT2;
    volatile const uint32_t   	RESERVE3[6];
    volatile uint32_t   IPND1;
    volatile uint32_t   IPND2;
    volatile const uint32_t   	RESERVE4[6];
    volatile uint32_t   MVLD1;
    volatile uint32_t   MVLD2;
    volatile uint32_t   WU_EN;            
    volatile uint32_t   WU_STATUS;
} CAN_T;


 





















 


















 









    












 



 








             






 



 






 














  









 



 









 



         












 






























 






  






 






 






 



 



 



 



 



 



 



 



 



 


                                     

 



 

typedef struct
{
        volatile uint32_t BUFSEG;    
        
        volatile uint32_t MXPLD;     
        
        volatile uint32_t CFG;       
        
        volatile uint32_t CFGP;      
    
} USBD_EP_T;

typedef struct
{
        volatile uint32_t INTEN;       
        
        volatile uint32_t INTSTS;      
        
        volatile uint32_t FADDR;       
        
        volatile const  uint32_t EPSTS;       
        
        volatile uint32_t ATTR;        
        
        volatile const  uint32_t FLDET;       
        
        volatile uint32_t STBUFSEG;    
    
        volatile const  uint32_t RESERVE0;
    
        USBD_EP_T EP[6];           
    
        volatile const  uint32_t RESERVE1[4];
    
        volatile uint32_t DRVSE0;      
        
} USBD_T;

 


















 


















 



 





















 



























 



 



 



 



 















 






 



   


 



 
typedef struct
{
    volatile uint32_t CSR;
    volatile uint32_t SAR;
    volatile uint32_t DAR;
    volatile uint32_t BCR;
    volatile const  uint32_t POINT;
    volatile const  uint32_t CSAR;
    volatile const  uint32_t CDAR;
    volatile const  uint32_t CBCR;
    volatile uint32_t IER;
    volatile uint32_t ISR;
    volatile const  uint32_t RESERVE[22];
    volatile const  uint32_t SBUF;
} PDMA_T;

typedef struct
{
    volatile uint32_t GCRCSR;
    volatile uint32_t PDSSR0;
    volatile uint32_t PDSSR1;
    volatile uint32_t GCRISR;
    volatile uint32_t PDSSR2;
} PDMA_GCR_T;


 





















 



 



 




 






 






 






























 
























 















 

































 





   


 



 
typedef struct
{
    




     
    volatile uint32_t  CTL;

    




     
    volatile uint32_t  DMASAR;

    volatile const  uint32_t  RESERVED0;

    




     
    volatile uint32_t  DMABCR ;

    volatile const  uint32_t  RESERVED1;

    




     
    volatile const  uint32_t  DMACSAR;

    volatile const  uint32_t  RESERVED2;

    




     
    volatile const  uint32_t  DMACBCR;

    




     
    volatile uint32_t  DMAIER ;

    




     
    volatile uint32_t  DMAISR;

    volatile const  uint32_t  RESERVED3[22];

    




     
    volatile uint32_t  WDATA;

    




     
    volatile uint32_t  SEED;

    




     
    volatile const  uint32_t  CHECKSUM;
} CRC_T;

 




















    






 



 



 



 



 






 






 



 



 


   

 




 
typedef struct
{
    
























     
    volatile uint32_t PPR;

    























     
    volatile uint32_t CSR;

    








































































     
    volatile uint32_t PCR;

    























     
    volatile uint32_t CNR0;

    























     
    volatile uint32_t CMR0;

    









     
    volatile const  uint32_t PDR0;

    























     
    volatile uint32_t CNR1;

    























     
    volatile uint32_t CMR1;

    









     
    volatile const  uint32_t PDR1;

    























     
    volatile uint32_t CNR2;

    























     
    volatile uint32_t CMR2;

    









     
    volatile const  uint32_t PDR2;

    























     
    volatile uint32_t CNR3;

    























     
    volatile uint32_t CMR3;

    









     
    volatile const  uint32_t PDR3;

    




     
    volatile uint32_t PBCR;

    


















     
    volatile uint32_t PIER;

    


















     
    volatile uint32_t PIIR;

    




     
    volatile const uint32_t    RESERVE1[2];

    




























































































     
    volatile uint32_t CCR0;

    




























































































     
    volatile uint32_t CCR2;

    








     
    volatile uint32_t CRLR0;

    








     
    volatile uint32_t CFLR0;

    








     
    volatile uint32_t CRLR1;

    








     
    volatile uint32_t CFLR1;

    








     
    volatile uint32_t CRLR2;

    








     
    volatile uint32_t CFLR2;

    








     
    volatile uint32_t CRLR3;

    








     
    volatile uint32_t CFLR3;

    






















     
    volatile uint32_t CAPENR;

    






















     
    volatile uint32_t POE;

    




     
    volatile uint32_t TCON;

    




     
    volatile uint32_t TSTATUS;

    




      
    volatile uint32_t  SYNCBUSY0;

    




      
    volatile uint32_t  SYNCBUSY1;
    
    




      
    volatile uint32_t  SYNCBUSY2;
    
    




      
    volatile uint32_t  SYNCBUSY3;
                    
} PWM_T;

 












 












 




























































 



 



 



 



 































 
























 










































 










































 



 



 












 












 













 













 



 



 



 


   


 



 
typedef struct
{
    volatile uint32_t CON;                 
    volatile uint32_t CLKDIV;              
    volatile uint32_t IE;                  
    volatile const  uint32_t STATUS;              
    volatile  uint32_t TXFIFO;              
    volatile const  uint32_t RXFIFO;              
} I2S_T;


 






















































 






 








                                     








                                     







 

























































   



 




 
typedef struct
{  
    union {
        volatile const  uint32_t  RBR;      
        volatile  uint32_t  THR;      
    };
  
    volatile uint32_t  CTL;          
    volatile uint32_t  ALTCTL;       
    volatile uint32_t  EGTR;                 
    volatile uint32_t  RFTMR;        
    volatile uint32_t  ETUCR;        
    volatile uint32_t  IER;          
    volatile uint32_t  ISR;          
    volatile uint32_t  TRSR;         
    volatile uint32_t  PINCSR;       
    volatile uint32_t  TMR0;         
    volatile uint32_t  TMR1;         
    volatile uint32_t  TMR2;         
    uint32_t       RESERVE0[1];  
    volatile const  uint32_t  TDRA;         
    volatile const  uint32_t  TDRB;         
} SC_T;

 



 



 










































 







































 



 



 






 

































 


































 



















































 







































 






 






 






 



 







   
   


 
 
 



 
 






 
#line 6051 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"














































#line 6106 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"














   

 
 
 




 
#line 6137 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"














































#line 6192 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"












   








typedef volatile unsigned char  vu8;
typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;




#line 6226 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"

#line 6233 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"













 
#line 6279 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"

 











 
 
  
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"
 









 



#line 1 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
     
 
 
 
 

#line 6312 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
                                                                                                 
#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"



 



 


 
 
 





 




#line 49 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"








 
 
 













 
 
 
#line 91 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"

#line 119 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"

#line 140 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"


 
 
 
#line 153 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"

#line 174 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"

#line 185 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"

#line 196 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"

#line 207 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"

#line 218 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"




 
 
 
#line 237 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SYS.h"

 
 
 





 
 
 




 
 
 














 





  















    







 


































































































































 

































    







 







    







 







    







 







    











 


















































    











 
























































    
























    





























































































 





































































 







    







 

































































































































































































































































































































































 
 
 






 
 
 






































































































































































































































 
 
 









 
static __inline uint32_t DrvSYS_GetPLLClockFreq(void)
{
    uint32_t u32PllFreq;
    uint32_t u32FIN, u32NF, u32NR, u32NO;
    uint8_t au8NoTbl[4] = {1, 2, 2, 4};  
    uint32_t u32Reg;

    u32PllFreq = 0;
    u32Reg = ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->PLLCON;
    if((u32Reg & ((1ul << 16) | (1ul << 18))) == 0)
    {    
         

        u32FIN = (u32Reg & (1ul << 19))?(22118400UL):(12000000UL);
        if(u32Reg & (1ul << 17))
        {
             
            u32PllFreq = u32FIN;
        }
        else 
        {
             
            u32NO = au8NoTbl[((u32Reg & (3ul << 14)) >> 14)];
            u32NF  = ((u32Reg & (0x1FFul << 0)) >> 0) + 2;
            u32NR  = ((u32Reg & (0x1Ful << 9)) >> 9) + 2;
             
            u32PllFreq = (((u32FIN >> 2) * u32NF) / (u32NR * u32NO) << 2); 
        }
    }

    return u32PllFreq;
}















 
static __inline void SYS_WaitingForClockReady(uint32_t u32Mask)
{
    int32_t i32TimeOutCnt;

    i32TimeOutCnt = (50000000UL) / 200;  
    
    while((((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSTATUS & u32Mask) != u32Mask)
    {
        if(i32TimeOutCnt-- <= 0)
            break;    
    }
}











 
static __inline void SYS_SysTickDelay(uint32_t us)
{
    ((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD = us * CyclesPerUs;
    ((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL  =  (0x00);
    ((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL = (1ul << 2) | (1ul << 0);

     
    while((((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL & (1ul << 16)) == 0);
}
















 
static __inline void SYS_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv)
{
     
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->FRQDIV = (1ul << 4) | u32ClkDiv;

     
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->APBCLK |= (1ul << 6);

     
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL2 = (((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL2 & (~(3ul << 2))) | u32ClkSrc;
}









 
static __inline void SYS_DisableCKO(void)
{
     
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->APBCLK &= (~(1ul << 6));
}








 
static __inline void SYS_PowerDownInit(void)
{   
    ((SCB_Type *) ((0xE000E000) + 0x0D00))->SCR = (1ul << 2);
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->PWRCON |= ((1ul << 8) | (1ul << 7) | (1ul << 6));
}







 
static __inline void SYS_UnlockReg(void)
{   
    do
    {
        ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT = 0x59;
        ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT = 0x16;
        ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT = 0x88;
    }while(((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT == 0);
}






 
static __inline void SYS_LockReg(void)
{   
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->REGWRPROT = 0;
}




  



  




#line 6296 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\ADC.h"
 









 




 
 
 
#line 20 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\ADC.h"




 



 


 
 
 
























 
 
 




 
 
 







 
 
 




 
 
 





 
 
 



 
 
 





 
 
 



 




 




 




 




 




 




 




 












 












 









 









 













 










 











 











 




 




 




 




 




 




 




 




 




 













 


















 






















 















 










 










 












 




 




 




 




 




 




 




 




 




 




 




 




 




 





 
__inline void ADC_ResetIP()
{
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 |= (1<<28) ;
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 &= ~(1<<(28)) ;
}











 
static __inline uint32_t ADC_GetConversionRate()
{
    uint32_t u32AdcClkSrcSel;
    uint32_t u32ClkTbl[4] = {(12000000UL), 0, 0, (22118400UL)};    
    
    u32ClkTbl[1] = PllClock;
    u32ClkTbl[2] = SystemCoreClock;
    u32AdcClkSrcSel = ((((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (3ul << 2)) >> 2);
    return   ((u32ClkTbl[u32AdcClkSrcSel]) / (((((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKDIV & (0xFFul << 16))>>16)+ 1) / 21);
}




  



  


#line 6297 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\FMC.h"
 









 



#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\FMC.h"




 



 


 
 
 










 
 
 



 
 
 





 
 
 
#line 67 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\FMC.h"




 
 
 













 
static __inline void FMC_Write(uint32_t u32addr, uint32_t u32data)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x21;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = u32addr;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT = u32data;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;  
    __isb(0);
    while (((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);
}














 
static __inline uint32_t FMC_Read(uint32_t u32addr)
{ 
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x00;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = u32addr;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT = 0;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;
    __isb(0);
    while (((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);
    
    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}














 
static __inline void FMC_Erase(uint32_t u32addr)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x22;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = u32addr;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;
    __isb(0);
    while (((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);
}














 
static __inline uint32_t FMC_ReadUID(uint8_t u8index)
{ 
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x04;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADR = (u8index << 2);
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT = 0;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;
    __isb(0);
    while (((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);
    
    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}




  



  




#line 6298 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\GPIO.h"
 









 



#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\GPIO.h"




 



 















 
#line 126 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\GPIO.h"
        

 
 
 






#line 201 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\GPIO.h"
                                            

 
 
 



                                                        
#line 242 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\GPIO.h"

                                    
 
 
 



#line 266 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\GPIO.h"
                                    
#line 283 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\GPIO.h"


 
 
 
#line 304 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\GPIO.h"


 
 
 






#line 331 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\GPIO.h"


 
 
 



 
 
 



 
 
 



 
 
 







 
 
 










 












 












 












 












 




















 













 












 



 
 
 











 
static __inline void GPIO_EnableInt(GPIO_T *PORT, uint32_t u32Pin, uint32_t u32IntAttribs)
{
    PORT->IMD |= (((u32IntAttribs & (0xFF000000)) >> 24) << u32Pin);
    PORT->IEN |= ((u32IntAttribs & 0xFFFFFFUL) << u32Pin);
}











 
static __inline void GPIO_DisableInt(GPIO_T *PORT, uint32_t u32Pin)
{
    PORT->IMD &= ~((0x00000001) << u32Pin);
    PORT->IEN &= ~((0x00010001UL) << u32Pin);
}





  



  

#line 6299 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\I2C.h"
 









 



#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\I2C.h"




 



 

 
 
 
#line 39 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\I2C.h"


 
 
 



 
 
 









 










 










 











 










 










 


























 










 











 











 











 











 












 











 











 











 
















 
static __inline uint8_t I2C_ReadAck(I2C_T *port)
{
    (port)->I2CDAT= 0xFF;
    (port)->I2CON = (1ul << 6) | (1ul << 3) | (1ul << 2);
    while(((port)->I2CON & (1ul << 3)) == 0);
    return (port)->I2CDAT;
}









 
static __inline uint8_t I2C_ReadNak(I2C_T *port)
{
    (port)->I2CDAT= 0xFF;
    (port)->I2CON = (1ul << 6) | (1ul << 3);
    while(((port)->I2CON & (1ul << 3)) == 0);
    return (port)->I2CDAT;
}















 
static __inline void I2C_SetBusClockFreq(I2C_T * tI2C, uint32_t u32BusClock)
{
    uint32_t u32divider;     
 
    u32divider = (uint32_t) (((SystemCoreClock * 10)/(u32BusClock * 4) + 5) / 10 - 1);
                        
    tI2C->I2CLK = (u32divider & ~0xFF)? 0xFF:((u32divider & ~0x03)? u32divider: 4);
}




  



  



#line 6300 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"
 










 



 
 
 

#line 21 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"




 



 


 
 
 

 
 
 





 
 
 











 
 
 
#line 83 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"

 
 
 
#line 99 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"

 
 
 




















 
 
 





 
 
 





 
 
 






 
 
 




























 


























 

























 



























 



























 


























 




















 




















 




















 



















 



















 



















 























 




























 





















 




















 




















 





















 

























 






















 






















 






















 





















 




















 



















 




















 



















 





















 






















 





















 




















 





















 


















 






















 
#line 935 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"





















 
#line 963 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"





















 
#line 991 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"





















 
#line 1019 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"





















 
#line 1047 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"





















 
#line 1075 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"




















 
#line 1102 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"






















 
#line 1131 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"





















 






















 
#line 1182 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"


















 

























 
#line 1233 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"
        



















 

























 
#line 1286 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PWM.h"




















 





















 





















 




















 





















 





















 






















 






















 




















 




















 




        











  
__inline void PWM_ResetPwmController(PWM_T* PWM)
{
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 |= ((1ul << 20)<<(((PWM)==((PWM_T *) ((( uint32_t)0x40000000) + 0x40000)))?0:1));
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 &= ~(((1ul << 20)<<(((PWM)==((PWM_T *) ((( uint32_t)0x40000000) + 0x40000)))?0:1)));
}  




















 
__inline uint32_t PWM_GetTimerClockSource(PWM_T* PWM, uint32_t u32Ch)
{
    uint8_t     u8EngineClk;
    uint32_t u32ClkTbl[4] = {(12000000UL), 0, 0, (22118400UL)};
    
    u32ClkTbl[2] = SystemCoreClock;        
    u8EngineClk = ((PWM)==((PWM_T *) ((( uint32_t)0x40000000) + 0x40000)))?((((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1&((3ul << 28)<<(((u32Ch)/2)*2)))
                               >>(28+((u32Ch)/2)*2)):
                              ((((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL2&((3ul << 4)<<(((u32Ch)/2)*2)))
                               >>(4+((u32Ch)/2)*2));                                             
    return u32ClkTbl[u8EngineClk];    
}




  



  






#line 6301 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SPI.h"
 









 



 
 
 
#line 19 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SPI.h"



 



 

 
 
 
#line 50 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SPI.h"


 
 
 




 
 
 
#line 70 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SPI.h"


 
 
 




 
 
 
#line 90 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SPI.h"

 
 
 
#line 102 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SPI.h"

 
 
 






 
 
 



 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 












 
static __inline uint32_t SPI_GetSpi0Clock1Freq()
{
    if(((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->CNTRL2 & (1ul << 31))
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 4))
            return (SystemCoreClock/((((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->DIVIDER & 0xFF)+1));  
        else
            return (PllClock/((((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->DIVIDER & 0xFF)+1));  
    }
    else
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 4))
            return ((SystemCoreClock>>1)/((((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->DIVIDER & 0xFF)+1));  
        else
            return ((PllClock>>1)/((((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->DIVIDER & 0xFF)+1));  
    }
}










 
static __inline uint32_t SPI_GetSpi1Clock1Freq()
{
    if(((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->CNTRL2 & (1ul << 31))
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 5))
            return (SystemCoreClock/((((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->DIVIDER & 0xFF)+1));  
        else
            return (PllClock/((((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->DIVIDER & 0xFF)+1));  
    }
    else
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 5))
            return ((SystemCoreClock>>1)/((((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->DIVIDER & 0xFF)+1));  
        else
            return ((PllClock>>1)/((((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->DIVIDER & 0xFF)+1));  
    }
}










 
static __inline uint32_t SPI_GetSpi2Clock1Freq()
{
    if(((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->CNTRL2 & (1ul << 31))
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 6))
            return (SystemCoreClock/((((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->DIVIDER & 0xFF)+1));  
        else
            return (PllClock/((((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->DIVIDER & 0xFF)+1));  
    }
    else
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 6))
            return ((SystemCoreClock>>1)/((((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->DIVIDER & 0xFF)+1));  
        else
            return ((PllClock>>1)/((((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->DIVIDER & 0xFF)+1));  
    }
}










 
static __inline uint32_t SPI_GetSpi3Clock1Freq()
{
    if(((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->CNTRL2 & (1ul << 31))
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 7))
            return (SystemCoreClock/((((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->DIVIDER & 0xFF)+1));  
        else
            return (PllClock/((((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->DIVIDER & 0xFF)+1));  
    }
    else
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 7))
            return ((SystemCoreClock>>1)/((((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->DIVIDER & 0xFF)+1));  
        else
            return ((PllClock>>1)/((((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->DIVIDER & 0xFF)+1));  
    }
}










 
static __inline uint32_t SPI_GetSpi0Clock2Freq()
{
    uint32_t u32EngineClockRate;
    
    if(((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->CNTRL2 & (1ul << 31))
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 4))
            u32EngineClockRate = (SystemCoreClock/((((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->DIVIDER & 0xFF)+1));  
        else
            u32EngineClockRate = (PllClock/((((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->DIVIDER & 0xFF)+1));  
    }
    else
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 4))
            u32EngineClockRate = ((SystemCoreClock>>1)/((((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->DIVIDER & 0xFF)+1));  
        else
            u32EngineClockRate = ((PllClock>>1)/((((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->DIVIDER & 0xFF)+1));  
    }
    return (u32EngineClockRate>>1)/(((((SPI_T *) ((( uint32_t)0x40000000) + 0x30000))->DIVIDER & 0x00FF0000)>>16)+1);
}










 
static __inline uint32_t SPI_GetSpi1Clock2Freq()
{
    uint32_t u32EngineClockRate;
    
    if(((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->CNTRL2 & (1ul << 31))
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 5))
            u32EngineClockRate = (SystemCoreClock/((((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->DIVIDER & 0xFF)+1));  
        else
            u32EngineClockRate = (PllClock/((((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->DIVIDER & 0xFF)+1));  
    }
    else
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 5))
            u32EngineClockRate = ((SystemCoreClock>>1)/((((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->DIVIDER & 0xFF)+1));  
        else
            u32EngineClockRate = ((PllClock>>1)/((((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->DIVIDER & 0xFF)+1));  
    }
    return (u32EngineClockRate>>1)/(((((SPI_T *) ((( uint32_t)0x40000000) + 0x34000))->DIVIDER & 0x00FF0000)>>16)+1);
}










 
static __inline uint32_t SPI_GetSpi2Clock2Freq()
{
    uint32_t u32EngineClockRate;
    
    if(((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->CNTRL2 & (1ul << 31))
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 6))
            u32EngineClockRate = (SystemCoreClock/((((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->DIVIDER & 0xFF)+1));  
        else
            u32EngineClockRate = (PllClock/((((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->DIVIDER & 0xFF)+1));  
    }
    else
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 6))
            u32EngineClockRate = ((SystemCoreClock>>1)/((((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->DIVIDER & 0xFF)+1));  
        else
            u32EngineClockRate = ((PllClock>>1)/((((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->DIVIDER & 0xFF)+1));  
    }
    return (u32EngineClockRate>>1)/(((((SPI_T *) ((( uint32_t)0x40100000) + 0x30000))->DIVIDER & 0x00FF0000)>>16)+1);
}










 
static __inline uint32_t SPI_GetSpi3Clock2Freq()
{
    uint32_t u32EngineClockRate;
    
    if(((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->CNTRL2 & (1ul << 31))
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 7))
            u32EngineClockRate = (SystemCoreClock/((((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->DIVIDER & 0xFF)+1));  
        else
            u32EngineClockRate = (PllClock/((((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->DIVIDER & 0xFF)+1));  
    }
    else
    {
         
        if(((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (1ul << 7))
            u32EngineClockRate = ((SystemCoreClock>>1)/((((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->DIVIDER & 0xFF)+1));  
        else
            u32EngineClockRate = ((PllClock>>1)/((((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->DIVIDER & 0xFF)+1));  
    }
    return (u32EngineClockRate>>1)/(((((SPI_T *) ((( uint32_t)0x40100000) + 0x34000))->DIVIDER & 0x00FF0000)>>16)+1);
}





  



  




#line 6302 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\TIMER.h"
 









 



#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\TIMER.h"



 



 

 
                                                                             
 
#line 44 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\TIMER.h"


 
                                                                             
 
#line 64 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\TIMER.h"


 
                                                                             
 


 





 













 












 





 





 





 





 

                                               



 





 

                                               



 





 





 





 



 
 
 








 
static __inline uint32_t TIMER_GetClockFreq(uint32_t eTimerCH)
{
    uint8_t u8TMRClkSrcSel;
    uint32_t u32ClkSrcTbl[] = {(12000000UL), (32768UL), 0, 0, 0, (10000UL), 0, (22118400UL)};
        
    u32ClkSrcTbl[2] = SystemCoreClock;

    u8TMRClkSrcSel = (((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 >> (8+(eTimerCH*4))) & 0x7;

    return u32ClkSrcTbl[u8TMRClkSrcSel]; 
}














 
static __inline uint32_t TIMER_CalInitValue(uint32_t u32ClockFreq, uint32_t u32TicksPerSec)
{
    uint32_t u32Prescale;
    uint32_t u32FinalTCMPR;

    for (u32Prescale=1; u32Prescale<256; u32Prescale++)
    {
        u32FinalTCMPR = u32ClockFreq / (u32TicksPerSec*u32Prescale);

         
        if ((u32FinalTCMPR > 1) && (u32FinalTCMPR < 0x1000000))
            return (((u32Prescale-1) << 24) | u32FinalTCMPR);
    }
    
    return (uint32_t)-1;
}




  



  


#line 6303 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\WDT.h"
 









 



#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\WDT.h"



 



 

 
                                                                             
 


#line 38 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\WDT.h"

#line 47 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\WDT.h"

#line 56 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\WDT.h"


 
                                                                             
 






 
                                                                             
 


 





 





 





 





 





 





 





 





 





 



 
                                                                             
 


#line 151 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\WDT.h"


 
                                                                             
 













 
















 





 





 

   



 





 





 





 






  



  


#line 6304 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\RTC.h"
 









 



#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\RTC.h"



 



 

 
                                                                             
 



 
                                                                             
 



 
                                                                             
 


                                                            

 
                                                                             
 
#line 53 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\RTC.h"


 
                                                                             
 
#line 64 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\RTC.h"


 
                                                                             
 




 
                                                                             
 
#line 83 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\RTC.h"


 
                                                                             
 






 
                                                                             
 
#line 105 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\RTC.h"


 
                                                                             
 


 





 





 





 












 





 





 





 





 





 





 





 





 





 





 





 





 














 





 





 





 





 





 





 





 

                                               



 





 

                                               











 



 
 
 










 
static __inline void RTC_SetCurrentTime(uint32_t u32Hour, uint32_t u32Min, uint32_t u32Sec)
{
    ((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->TSSR = 0x1UL;

    ((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->TLR = ((u32Hour/10) << 20) | ((u32Hour%10) << 16) |
               ((u32Min/10) << 12) | ((u32Min%10) << 8) |
               ((u32Sec/10) << 4) | ((u32Sec%10) << 0);
}












 
static __inline void RTC_SetCurrentCalendar(uint32_t u32Year, uint32_t u32Mon, uint32_t u32Day)
{
    ((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->CLR = ((u32Year/10) << 20) | ((u32Year%10) << 16) |
               ((u32Mon/10) << 12)   | ((u32Mon%10) << 8)   |
               ((u32Day/10) << 4)   | ((u32Day%10) << 0);
}












 
static __inline void RTC_SetAlarmTime(uint32_t u32Hour, uint32_t u32Min, uint32_t u32Sec)
{
    ((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->TSSR = 0x1UL;

    ((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->TAR = ((u32Hour/10) << 20) | ((u32Hour%10) << 16) |
               ((u32Min/10) << 12) | ((u32Min%10) << 8) |
               ((u32Sec/10) << 4) | ((u32Sec%10) << 0);
}












 
static __inline void RTC_SetAlarmCalendar(uint32_t u32Year, uint32_t u32Mon, uint32_t u32Day)
{
    ((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->CAR = ((u32Year/10) << 20) | ((u32Year%10) << 16) |
               ((u32Mon/10) << 12)   | ((u32Mon%10) << 8)   |
               ((u32Day/10) << 4)   | ((u32Day%10) << 0);
}










 
static __inline void RTC_WaitAccessEnable(void)
{
     
    while ((((((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->AER & (1ul << 16)) == (1ul << 16))? 1:0) == 1);
    (((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->AER = 0x0000A965UL);

     
    while ((((((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->AER & (1ul << 16)) == (1ul << 16))? 1:0) == 0);
}




  



  


#line 6305 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\UART.h"
 









 



#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\UART.h"



 



 


 
 
 











 
 
 

















 
 
 



 
 
 





 
 
 
#line 93 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\UART.h"


 
 
 

















 















 




 
 
 












 













 


 
 
 









 

static __inline uint32_t UART_GetClockFreq()
{
    uint8_t u8UartClkSrcSel;
    uint32_t u32ClkTbl[4] = {(12000000UL), 0, 0, (22118400UL)};    
    u32ClkTbl[1] = PllClock;
    u8UartClkSrcSel = (((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 & (3ul << 24)) >> 24;
    return u32ClkTbl[u8UartClkSrcSel];
}










 

static __inline uint32_t UART_GetClockDivider()
{
    return ((((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKDIV & (0xFul << 8)) >> 8) + 1;
}











 
static __inline uint32_t UART_GetDivisor_ByMode0(uint32_t u32BaudRate)
{
    return ((((UART_GetClockFreq()/UART_GetClockDivider()) / u32BaudRate + 1) >> 4) -2) ;
}












                       
static __inline uint32_t UART_GetDivisor_ByMode1(uint32_t u32BaudRate,uint8_t u8Divider_X)
{
    return ((((UART_GetClockFreq()/UART_GetClockDivider()) / u32BaudRate + 1) / u8Divider_X) -2) ;
}                                        










 
static __inline uint32_t UART_GetDivisor_ByMode2(uint32_t u32BaudRate)
{
    return (((UART_GetClockFreq()/UART_GetClockDivider() * 2) / u32BaudRate + 1) >> 1);
}













 
static __inline void UART_SetBaudRate(UART_T *UART, uint32_t u32BaudRate)
{
    UART->BAUD = ((1ul << 29) | (1ul << 28)) | UART_GetDivisor_ByMode2(u32BaudRate); 
}



 
 
 














 
















 





















 
                               
static __inline void UART_SetTimeOutCounter(UART_T* UART,uint32_t u32Count)
{
    (UART)->TOR = ((UART)->TOR & ~(0xFFul << 0))| (u32Count);
    (UART)->IER |= (1ul << 11);
}

 
 
 











 
















 



                                              













 
















 















 
















 















 



















 





















 





 
 
 

























 






















 
























                                                                                       















   



 










   


 










  


 










 



 
 
 























   
                         
__inline void UART_SetRTS_TrgLev(UART_T* UART,uint32_t eActLevel,uint32_t eTRG_Level)
{
    (UART)->MCR = ((UART)->MCR & ~(1ul << 9)     | (eActLevel ));
    (UART)->FCR = ((UART)->FCR & ~(0xFul << 16) | (eTRG_Level));
}















   

















     
















 














 















 



 
 
 















   



 
 
 

















   



















   















                                                                                       














                                                                                       

















                                                                                       


















                                                                                       




   


 
 
 















                                                                                       















                                                                                       




 
 
                                                                                      












  

  











  














  
__inline void UART_ResetIP(UART_T* UART)
{
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 |= 1<< (16+ ((UART)==((UART_T *) ((( uint32_t)0x40000000) + 0x50000)))?0:1) ;
    ((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 &= ~(1<< (16+ ((UART)==((UART_T *) ((( uint32_t)0x40000000) + 0x50000)))?0:1)) ;
}     

 
 
  











  













  





__inline int32_t UART_Write(UART_T *UART,uint8_t *pu8TxBuf,uint32_t u32WriteBytes)
{
    uint32_t  u32Count, u32delayno;

    for (u32Count=0; u32Count != u32WriteBytes; u32Count++)
    {
       u32delayno = 0;
       while (((UART)->FSR & (1ul << 28)) == 0)   
       {
            u32delayno++;
            if ( u32delayno >= 0x40000000 )             
               return 0;               
       }
       (((UART))->THR = (pu8TxBuf[u32Count]));         
    }
    return 1;
}

__inline int32_t UART_Read(UART_T *UART,uint8_t *pu8RxBuf, uint32_t u32ReadBytes)
{
    uint32_t u32Count, u32delayno;

    for (u32Count=0; u32Count != u32ReadBytes; u32Count++)
    {
         u32delayno = 0;
         while ((UART)->FSR & (1ul << 14))
         {
            u32delayno++;        
            if ( u32delayno >= 0x40000000 )        
                return 0;               
         }
         ((pu8RxBuf[u32Count]) = ((UART))->RBR);           
    }
    return 1;
}




  



  














#line 6306 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\I2S.h"
 









 



 
 
 
#line 19 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\I2S.h"




 



 


 
 
 
#line 53 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\I2S.h"

 
 
 





 
 
 

#line 91 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\I2S.h"



  



  



#line 6307 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"
 









 



#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"



 



 


















 
#line 76 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"

#line 83 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"

#line 95 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"

#line 106 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"

#line 114 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"




#line 125 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"





#line 140 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"

 

    
 


 


 

        
 


 


 






 

    
 


 


 


     


 


   


 


 














 

 
 


 


 







 
 
 
 




 





#line 244 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"


 
 
 
#line 256 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"
 



 
 
 




 


 




 
 
 



#line 287 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"

#line 294 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\USB.h"
    
 
 
 
typedef enum
{
    eUSBD_DETACHED    = 0,
    eUSBD_ATTACHED    = 0x00000001,
    eUSBD_POWERED     = eUSBD_ATTACHED + 0x00000002,
    eUSBD_DEFAULT     = eUSBD_POWERED  + 0x00000004,
    eUSBD_ADDRESS     = eUSBD_DEFAULT  + 0x00000008,
    eUSBD_CONFIGURED  = eUSBD_ADDRESS  + 0x00000010,
    eUSBD_SUSPENDED   = 0x00000020

} E_USBD_STATE;


 
 
 
typedef struct
{
    uint8_t byLength;
    uint8_t byDescType;
    uint16_t au16UnicodeString[100];
    
} S_USBD_STRING_DESC;

typedef S_USBD_STRING_DESC    S_STRING_DESC;

typedef struct
{
    uint16_t u16VendorId;
    uint16_t u16ProductId;
    const S_USBD_STRING_DESC *psVendorStringDesc;
    const S_USBD_STRING_DESC *psProductStringDesc;

} S_USBD_VENDOR_INFO;

typedef S_USBD_VENDOR_INFO    S_VENDOR_INFO;


 
 
 
typedef void (*PFN_USBD_ATTACH_CALLBACK)(void *);
typedef void (*PFN_USBD_DETACH_CALLBACK)(void *);

typedef void (*PFN_USBD_BUS_RESET_CALLBACK)(void *);
typedef void (*PFN_USBD_BUS_SUSPEND_CALLBACK)(void *);
typedef void (*PFN_USBD_BUS_RESUME_CALLBACK)(void *);

typedef void (*PFN_USBD_SETUP_CALLBACK)(void *);
typedef void (*PFN_USBD_EP_IN_CALLBACK)(void *);
typedef void (*PFN_USBD_EP_OUT_CALLBACK)(void *);

typedef void (*PFN_USBD_CTRL_SETUP_CALLBACK)(void *);
typedef void (*PFN_USBD_CTRL_DATA_IN_CALLBACK)(void *);
typedef void (*PFN_USBD_CTRL_DATA_OUT_CALLBACK)(void *);


 
 
 
typedef void (*PFN_USBD_ISR_ATTACH_CALLBACK)(void *);
typedef void (*PFN_USBD_ISR_DETACH_CALLBACK)(void *);

typedef void (*PFN_USBD_ISR_BUS_RESET_CALLBACK)(void *);
typedef void (*PFN_USBD_ISR_BUS_SUSPEND_CALLBACK)(void *);
typedef void (*PFN_USBD_ISR_BUS_RESUME_CALLBACK)(void *);

typedef void (*PFN_USBD_ISR_SETUP_CALLBACK)(void *);
typedef void (*PFN_USBD_ISR_EP_IN_CALLBACK)(void *);
typedef void (*PFN_USBD_ISR_EP_OUT_CALLBACK)(void *);

typedef void (*PFN_USBD_CALLBACK)(void *);
typedef void (*PFN_USBD_INTCALLBACK)(void *);
typedef int32_t (*PFN_USBD_COMPARE)(uint8_t);


 
 
 
typedef struct
{
    uint8_t u8RequestType;
    uint8_t u8Request;
    PFN_USBD_CTRL_SETUP_CALLBACK      pfnCtrlSetupCallback;
    PFN_USBD_CTRL_DATA_IN_CALLBACK    pfnCtrlDataInCallback;
    PFN_USBD_CTRL_DATA_OUT_CALLBACK   pfnCtrlDataOutCallback;
    void *                              pVoid;
} S_USBD_CTRL_CALLBACK_ENTRY;

typedef struct
{
    int32_t                             bReg;
    S_USBD_CTRL_CALLBACK_ENTRY        sCtrlCallbackEntry;
} S_USBD_CTRL_CALLBACK_ENTRY_REG;


 
 
 
typedef struct
{
    uint32_t u32EpNum;
    uint32_t u32MaxPacketSize; 
    uint8_t *u8SramBuffer;
}S_USBD_EP_CTRL;


 
 
 
typedef struct
{
    PFN_USBD_CALLBACK apfnCallback;
    void *              apCallbackArgu;
}S_USBD_EVENT_PROCESS;


 
 
 
 
typedef struct
{
    void * device;
    PFN_USBD_CALLBACK pfnStart;        
    PFN_USBD_COMPARE  pfnCompare;
    void * pVoid;
}S_USBD_CLASS;


 
 
 
typedef struct
{
    uint32_t u32ATTR;
    uint32_t u32EPSTS;
    uint32_t u32FLDET;
    uint32_t u32INTSTS;

    int32_t  abData0[6];   
    S_USBD_EP_CTRL sEpCrl[6+1];
    int32_t  eUsbState;            

    uint16_t u16MiscEventFlags;

    uint16_t u16EPEventFlags;

    S_USBD_CTRL_CALLBACK_ENTRY    *pCtrlCallback;
    uint32_t CtrlCallbackSize;
    uint8_t  au8Setup[8];
    uint8_t  u8UsbAddress;
    uint8_t  u8UsbConfiguration;
        
    int32_t  bSelfPowered;   
    int32_t  bRemoteWakeup;  
    uint8_t  u8MaxPower;         
        
    S_USBD_CLASS *psUsbClass;
} S_USBD_DEVICE;


 
extern S_USBD_EP_CTRL sEpDescription[];
 
extern S_USBD_EVENT_PROCESS g_sBusOps[];
 
extern S_USBD_EVENT_PROCESS g_sUsbOps[];
extern uint32_t CFG_EP_SETTING[6];   
extern PFN_USBD_INTCALLBACK g_FnIntCallBack;   
extern S_USBD_DEVICE gsUsbDevice;


 
 
 
 
int32_t USBD_IsData0Out(uint32_t u32EpId);

 
E_USBD_STATE USBD_GetUsbState(void);

 
void USBD_SetUsbState(E_USBD_STATE eUsbState);


 
 
 







 
 
 
uint32_t USBD_GetVersion(void);
int32_t  USBD_Open(void * pVoid);
void     USBD_PreDispatchEvent(void);
void     USBD_DispatchEvent(void);
void     USBD_Close(void);
void     USBD_BusResetCallback(void * pVoid);
uint32_t USBD_GetSetupBuffer(void);
void *   USBD_InstallClassDevice(S_USBD_CLASS *sUsbClass);
int32_t  USBD_InstallCtrlHandler(void * *device, S_USBD_CTRL_CALLBACK_ENTRY *psCtrlCallbackEntry, uint32_t u32RegCnt);
int32_t  USBD_DataOutTrigger(uint32_t u32EpNum, uint32_t u32Size);
uint8_t* USBD_GetOutData(uint32_t u32EpNum, uint32_t *u32Size);
int32_t  USBD_DataIn(uint32_t u32EpNum, const uint8_t * u8Buffer, uint32_t u32Size);
void     USBD_CtrlSetupAck(void * pArgu);
void     USBD_CtrlDataInAck(void * pArgu);
void     USBD_CtrlDataOutAck(void * pArgu);
void     USBD_ClrCtrlReady(void);
void     USBD_ClrCtrlReadyAndTrigStall(void);
void     USBD_CtrlDataInDefault(void * pVoid);
void     USBD_CtrlDataOutDefault(void * pVoid);
void     USBD_Reset(uint32_t u32EpNum);
int32_t USBD_GetEpId(uint32_t u32EpNum);
int32_t USBD_GetEpIdentity(uint32_t u32EpNum, uint32_t u32EPAttr);
void     USBD_EnableRemoteWakeup(void);
void     USBD_DisableRemoteWakeup(void);
void     USBD_EnableSelfPower (void);
void     USBD_DisableSelfPower (void);
int32_t  USBD_IsSelfPowerEnabled (void);           
void     USBD_EnableRemoteWakeup(void);
void     USBD_DisableRemoteWakeup(void);
int32_t  USBD_IsRemoteWakeupEnabled (void);        
int32_t  USBD_SetMaxPower(uint32_t u32MaxPower);   
int32_t  USBD_GetMaxPower(void);                   

void USBD_CtrlSetupSetAddress(void * pVoid);
void USBD_CtrlSetupClearSetFeature(void * pVoid);
void USBD_CtrlSetupGetConfiguration(void * pVoid);
void USBD_CtrlSetupGetStatus(void * pVoid);
void USBD_CtrlSetupGetInterface(void * pVoid);
void USBD_CtrlSetupSetInterface(void * pVoid);
void USBD_CtrlSetupSetConfiguration(void * pVoid);
void USBD_CtrlDataInSetAddress(void * pVoid);

int32_t USBD_IsData0(uint32_t u32EpId);

void USBD_EnableUsb(S_USBD_DEVICE *psDevice);
void USBD_DisableUsb(S_USBD_DEVICE *psDevice);
void USBD_PreDispatchWakeupEvent(S_USBD_DEVICE *psDevice);
void USBD_PreDispatchFDTEvent(S_USBD_DEVICE *psDevice);
void USBD_PreDispatchEPEvent(S_USBD_DEVICE *psDevice);
void USBD_PreDispatchBusEvent(S_USBD_DEVICE *psDevice);
void USBD_DispatchWakeupEvent(S_USBD_DEVICE *psDevice);
void USBD_DispatchMiscEvent(S_USBD_DEVICE *psDevice);
void USBD_DispatchEPEvent(S_USBD_DEVICE *psDevice);
void USBD_memcpy(uint8_t *pi8Dest, uint8_t *pi8Src, uint32_t u32Size);
uint32_t USBD_GetFreeSRAM(void);
    








  



  






#line 6308 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PDMA.h"
 









 



#line 16 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PDMA.h"




 



 


 
 
 

 
 
 
#line 47 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PDMA.h"

 
 
 



 
 
 
#line 66 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PDMA.h"


 
                                                                             
 
#line 85 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PDMA.h"


 
                                                                             
 




 
                                                                             
 



 
 
 

#line 112 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PDMA.h"













 
                                                                             
 


 





 





 





 





 





 





 





 





 





 

                                               



 





 





 





 





 





 





 





 





 





 





 





 





  



  


#line 6309 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"
 










 




#line 18 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"
 






 





#line 25 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdbool.h"



#line 19 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"
 
 
 




 
 



 













  


 








#line 46 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


  
  typedef unsigned int size_t;










    



    typedef unsigned short wchar_t;  
#line 75 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { __int64 quot, rem; } lldiv_t;
    


#line 96 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"
   



 

   




 
#line 115 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) __int64 atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) __int64 strtoll(const char * __restrict  ,
                               char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned __int64 strtoull(const char * __restrict  ,
                                         char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 415 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 503 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 532 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __pure int abs(int  );
   



 

extern __declspec(__nothrow) __pure div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __pure long int labs(long int  );
   



 




extern __declspec(__nothrow) __pure ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __pure __int64 llabs(__int64  );
   



 




extern __declspec(__nothrow) __pure lldiv_t lldiv(__int64  , __int64  );
   











 
#line 613 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"



 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __pure __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 



 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 867 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


 

#line 20 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"
#line 21 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"




 





 












 








 






#line 48 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"

#line 62 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"

   




 















 
#line 93 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"











 





extern __softfp unsigned __ARM_dcmp4(double  , double  );
extern __softfp unsigned __ARM_fcmp4(float  , float  );
    




 

extern __declspec(__nothrow) __softfp int __ARM_fpclassifyf(float  );
extern __declspec(__nothrow) __softfp int __ARM_fpclassify(double  );
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isfinitef(float __x)
{
    return (((*(unsigned *)&(__x)) >> 23) & 0xff) != 0xff;
}
__inline __declspec(__nothrow) __softfp int __ARM_isfinite(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff) != 0x7ff;
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isinff(float __x)
{
    return ((*(unsigned *)&(__x)) << 1) == 0xff000000;
}
__inline __declspec(__nothrow) __softfp int __ARM_isinf(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) << 1) == 0xffe00000) && ((*(unsigned *)&(__x)) == 0);
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_islessgreaterf(float __x, float __y)
{
    unsigned __f = __ARM_fcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
__inline __declspec(__nothrow) __softfp int __ARM_islessgreater(double __x, double __y)
{
    unsigned __f = __ARM_dcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
    


 

__inline __declspec(__nothrow) __softfp int __ARM_isnanf(float __x)
{
    return (0x7f800000 - ((*(unsigned *)&(__x)) & 0x7fffffff)) >> 31;
}
__inline __declspec(__nothrow) __softfp int __ARM_isnan(double __x)
{
    unsigned __xf = (*(1 + (unsigned *)&(__x))) | (((*(unsigned *)&(__x)) == 0) ? 0 : 1);
    return (0x7ff00000 - (__xf & 0x7fffffff)) >> 31;
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isnormalf(float __x)
{
    unsigned __xe = ((*(unsigned *)&(__x)) >> 23) & 0xff;
    return (__xe != 0xff) && (__xe != 0);
}
__inline __declspec(__nothrow) __softfp int __ARM_isnormal(double __x)
{
    unsigned __xe = ((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff;
    return (__xe != 0x7ff) && (__xe != 0);
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_signbitf(float __x)
{
    return (*(unsigned *)&(__x)) >> 31;
}
__inline __declspec(__nothrow) __softfp int __ARM_signbit(double __x)
{
    return (*(1 + (unsigned *)&(__x))) >> 31;
}
     
     








#line 211 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"



   
  typedef float float_t;
  typedef double double_t;







extern const int math_errhandling;



extern __declspec(__nothrow) double acos(double  );
    
    
    
extern __declspec(__nothrow) double asin(double  );
    
    
    
    

extern __declspec(__nothrow) __pure double atan(double  );
    
    

extern __declspec(__nothrow) double atan2(double  , double  );
    
    
    
    

extern __declspec(__nothrow) double cos(double  );
    
    
    
    
extern __declspec(__nothrow) double sin(double  );
    
    
    
    

extern void __use_accurate_range_reduction(void);
    
    

extern __declspec(__nothrow) double tan(double  );
    
    
    
    

extern __declspec(__nothrow) double cosh(double  );
    
    
    
    
extern __declspec(__nothrow) double sinh(double  );
    
    
    
    
    

extern __declspec(__nothrow) __pure double tanh(double  );
    
    

extern __declspec(__nothrow) double exp(double  );
    
    
    
    
    

extern __declspec(__nothrow) double frexp(double  , int *  ) __attribute__((__nonnull__(2)));
    
    
    
    
    
    

extern __declspec(__nothrow) double ldexp(double  , int  );
    
    
    
    
extern __declspec(__nothrow) double log(double  );
    
    
    
    
    
extern __declspec(__nothrow) double log10(double  );
    
    
    
extern __declspec(__nothrow) double modf(double  , double *  ) __attribute__((__nonnull__(2)));
    
    
    
    

extern __declspec(__nothrow) double pow(double  , double  );
    
    
    
    
    
    
extern __declspec(__nothrow) double sqrt(double  );
    
    
    




    __inline double _sqrt(double __x) { return sqrt(__x); }




    __inline float _sqrtf(float __x) { return (float)sqrt(__x); }

    



 

extern __declspec(__nothrow) __pure double ceil(double  );
    
    
extern __declspec(__nothrow) __pure double fabs(double  );
    
    

extern __declspec(__nothrow) __pure double floor(double  );
    
    

extern __declspec(__nothrow) double fmod(double  , double  );
    
    
    
    
    

    









 



extern __declspec(__nothrow) double acosh(double  );
    

 
extern __declspec(__nothrow) double asinh(double  );
    

 
extern __declspec(__nothrow) double atanh(double  );
    

 
extern __declspec(__nothrow) double cbrt(double  );
    

 
__inline __declspec(__nothrow) __pure double copysign(double __x, double __y)
    

 
{
    (*(1 + (unsigned *)&(__x))) = ((*(1 + (unsigned *)&(__x))) & 0x7fffffff) | ((*(1 + (unsigned *)&(__y))) & 0x80000000);
    return __x;
}
__inline __declspec(__nothrow) __pure float copysignf(float __x, float __y)
    

 
{
    (*(unsigned *)&(__x)) = ((*(unsigned *)&(__x)) & 0x7fffffff) | ((*(unsigned *)&(__y)) & 0x80000000);
    return __x;
}
extern __declspec(__nothrow) double erf(double  );
    

 
extern __declspec(__nothrow) double erfc(double  );
    

 
extern __declspec(__nothrow) double expm1(double  );
    

 



    

 






#line 445 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"


extern __declspec(__nothrow) double hypot(double  , double  );
    




 
extern __declspec(__nothrow) int ilogb(double  );
    

 
extern __declspec(__nothrow) int ilogbf(float  );
    

 
extern __declspec(__nothrow) int ilogbl(long double  );
    

 







    

 





    



 





    



 





    

 





    



 





    



 





    



 





    

 





    

 





    


 

extern __declspec(__nothrow) double lgamma (double  );
    


 
extern __declspec(__nothrow) double log1p(double  );
    

 
extern __declspec(__nothrow) double logb(double  );
    

 
extern __declspec(__nothrow) float logbf(float  );
    

 
extern __declspec(__nothrow) long double logbl(long double  );
    

 
extern __declspec(__nothrow) double nextafter(double  , double  );
    


 
extern __declspec(__nothrow) float nextafterf(float  , float  );
    


 
extern __declspec(__nothrow) long double nextafterl(long double  , long double  );
    


 
extern __declspec(__nothrow) double nexttoward(double  , long double  );
    


 
extern __declspec(__nothrow) float nexttowardf(float  , long double  );
    


 
extern __declspec(__nothrow) long double nexttowardl(long double  , long double  );
    


 
extern __declspec(__nothrow) double remainder(double  , double  );
    

 
extern __declspec(__nothrow) __pure double rint(double  );
    

 
extern __declspec(__nothrow) double scalbln(double  , long int  );
    

 
extern __declspec(__nothrow) float scalblnf(float  , long int  );
    

 
extern __declspec(__nothrow) long double scalblnl(long double  , long int  );
    

 
extern __declspec(__nothrow) double scalbn(double  , int  );
    

 
extern __declspec(__nothrow) float scalbnf(float  , int  );
    

 
extern __declspec(__nothrow) long double scalbnl(long double  , int  );
    

 




    

 



 
extern __declspec(__nothrow) __pure float _fabsf(float);  
__inline __declspec(__nothrow) __pure float fabsf(float __f) { return _fabsf(__f); }
extern __declspec(__nothrow) float sinf(float  );
extern __declspec(__nothrow) float cosf(float  );
extern __declspec(__nothrow) float tanf(float  );
extern __declspec(__nothrow) float acosf(float  );
extern __declspec(__nothrow) float asinf(float  );
extern __declspec(__nothrow) float atanf(float  );
extern __declspec(__nothrow) float atan2f(float  , float  );
extern __declspec(__nothrow) float sinhf(float  );
extern __declspec(__nothrow) float coshf(float  );
extern __declspec(__nothrow) float tanhf(float  );
extern __declspec(__nothrow) float expf(float  );
extern __declspec(__nothrow) float logf(float  );
extern __declspec(__nothrow) float log10f(float  );
extern __declspec(__nothrow) float powf(float  , float  );
extern __declspec(__nothrow) float sqrtf(float  );
extern __declspec(__nothrow) float ldexpf(float  , int  );
extern __declspec(__nothrow) float frexpf(float  , int *  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) __pure float ceilf(float  );
extern __declspec(__nothrow) __pure float floorf(float  );
extern __declspec(__nothrow) float fmodf(float  , float  );
extern __declspec(__nothrow) float modff(float  , float *  ) __attribute__((__nonnull__(2)));

 
 













 
__declspec(__nothrow) long double acosl(long double );
__declspec(__nothrow) long double asinl(long double );
__declspec(__nothrow) long double atanl(long double );
__declspec(__nothrow) long double atan2l(long double , long double );
__declspec(__nothrow) long double ceill(long double );
__declspec(__nothrow) long double cosl(long double );
__declspec(__nothrow) long double coshl(long double );
__declspec(__nothrow) long double expl(long double );
__declspec(__nothrow) long double fabsl(long double );
__declspec(__nothrow) long double floorl(long double );
__declspec(__nothrow) long double fmodl(long double , long double );
__declspec(__nothrow) long double frexpl(long double , int* ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double ldexpl(long double , int );
__declspec(__nothrow) long double logl(long double );
__declspec(__nothrow) long double log10l(long double );
__declspec(__nothrow) long double modfl(long double  , long double *  ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double powl(long double , long double );
__declspec(__nothrow) long double sinl(long double );
__declspec(__nothrow) long double sinhl(long double );
__declspec(__nothrow) long double sqrtl(long double );
__declspec(__nothrow) long double tanl(long double );
__declspec(__nothrow) long double tanhl(long double );





 
extern __declspec(__nothrow) float acoshf(float  );
__declspec(__nothrow) long double acoshl(long double );
extern __declspec(__nothrow) float asinhf(float  );
__declspec(__nothrow) long double asinhl(long double );
extern __declspec(__nothrow) float atanhf(float  );
__declspec(__nothrow) long double atanhl(long double );
__declspec(__nothrow) long double copysignl(long double , long double );
extern __declspec(__nothrow) float cbrtf(float  );
__declspec(__nothrow) long double cbrtl(long double );
extern __declspec(__nothrow) float erff(float  );
__declspec(__nothrow) long double erfl(long double );
extern __declspec(__nothrow) float erfcf(float  );
__declspec(__nothrow) long double erfcl(long double );
extern __declspec(__nothrow) float expm1f(float  );
__declspec(__nothrow) long double expm1l(long double );
extern __declspec(__nothrow) float log1pf(float  );
__declspec(__nothrow) long double log1pl(long double );
extern __declspec(__nothrow) float hypotf(float  , float  );
__declspec(__nothrow) long double hypotl(long double , long double );
extern __declspec(__nothrow) float lgammaf(float  );
__declspec(__nothrow) long double lgammal(long double );
extern __declspec(__nothrow) float remainderf(float  , float  );
__declspec(__nothrow) long double remainderl(long double , long double );
extern __declspec(__nothrow) float rintf(float  );
__declspec(__nothrow) long double rintl(long double );



#line 825 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"





#line 980 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"











#line 1182 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\math.h"



 

#line 22 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"
#line 23 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"




 



 


 
 
 



 



 
 
 




 
 
 





 
 
 

 
 
 


 
 
 
#line 91 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"

 
 
 
#line 107 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"

 
 
 


 
 
 
#line 127 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"

 
 
 
#line 142 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"

 
 
 
#line 161 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"

 
 
 
#line 178 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"

 
 
 
#line 204 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"



















#line 230 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"




 












#line 256 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"


 
#line 269 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"



















































 















#line 350 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"



#line 360 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"



 













 
 
 



 
 
 








#line 401 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\SC.h"





























 
 
 
typedef union {
    
    struct {

        unsigned long   l0;

    } l;

    struct {

        uint8_t   b0;
        uint8_t   b1;
        uint8_t   b2;
        uint8_t   b3;
    } b;

} S_SC_LENGTH;


typedef struct {

    
    int32_t   Lc;

    
    int32_t   Le;

} S_SC_T0_DATA;


typedef struct {

    
    uint8_t   IFSC;

    
    uint8_t   IFSD;

	
	uint8_t   IBLOCK_REC;

    
    uint8_t   RSN;

    
    uint8_t   SSN;

    
    
    
    
    uint8_t   Wtx;

} S_SC_T1_DATA;

 
 
 
typedef struct {  
    uint8_t   Nad;
    uint8_t   Pcb;
    uint8_t   Len;
    uint8_t *  Inf;
} S_SC_T1_BLOCK_FRAME;


 
 
 
typedef struct {

    const unsigned long F;
    const unsigned long fs; 

} S_SC_CLOCK_RATE_CONVERSION;







typedef struct {
    const unsigned long DNumerator;
    const unsigned long DDivisor;
} S_SC_BIT_RATE_ADJUSTMENT;





static S_SC_CLOCK_RATE_CONVERSION ClockRateConversion[] = {

        { 372,  4000000     }, 
        { 372,  5000000     }, 
        { 558,  6000000     }, 
        { 744,  8000000     }, 
        { 1116, 12000000    }, 
        { 1488, 16000000    },
        { 1860, 20000000    },
        { 0,    0            },
        { 0,    0            },
        { 512,  5000000     },
        { 768,  7500000     },
        { 1024, 10000000    },
        { 1536, 15000000    },
        { 2048, 20000000    },
        { 0,    0            },
        { 0,    0            }
};      





static S_SC_BIT_RATE_ADJUSTMENT BitRateAdjustment[] = {

    { 0,    0   },
    { 1,    1   },
    { 2,    1   },
    { 4,    1   },
    { 8,    1   },
    { 16,   1   },
    { 32,   1   },
    { 64,   1   },
    { 12,   1   },
    { 20,   1   },
    { 0,    0   },
    { 0,    0   },
    { 0,    0   },
    { 0,    0   },
    { 0,    0   },
    { 0,    0   }
};








typedef struct{

    
    _Bool InversConvention;

    
    unsigned long   etu;        
      
    
    
    
    
    struct {

        uint8_t Buffer[64];
        uint8_t Length;

    } ATR;

    struct {

        uint8_t Buffer[16];
        uint8_t Length;

    } HistoricalChars;

    
    

    
    uint8_t Fl;

    
    uint8_t Dl;

    
    uint8_t II;

    
    uint8_t P;

    
    uint8_t N;

    
    unsigned long GT;

    struct {

		
		unsigned long Supported;
		
		unsigned long Selected;

    } Protocol;

    
    struct {

        
        uint8_t WI;

        
        unsigned long WT;

    } T0;

    
    struct {

        
        uint8_t IFSC;

        
        uint8_t CWI;
        uint8_t BWI;

        
        uint8_t EDC;

        
        unsigned long CWT;
        unsigned long BWT;

        
        unsigned long BGT;

    } T1;

} S_SC_SCARD_CARD_CAPABILITIES;

 
 
 
  
typedef struct 
{
	SC_T *base  ;
	volatile uint32_t op_state;		 
	volatile int32_t errno;
	volatile uint32_t openflag;
	volatile uint32_t clock;			 
	uint32_t clock_stop_level;
	volatile uint32_t etu; 			 
	volatile uint32_t voltage;
	volatile int8_t ActivePowerPin;		 

    
    S_SC_SCARD_CARD_CAPABILITIES CardCapabilities;

    
    
    
    
    
    unsigned long   CurrentState;

	uint8_t *snd_buf, *rcv_buf;  
	volatile int32_t snd_pos, snd_len;
    volatile int32_t rcv_len, rcv_pos;
	volatile int32_t rcv_cnt;  
	volatile uint32_t bCardRemoved  ;
	int8_t pps_complete; 

    
    S_SC_T0_DATA T0;
    
    
    S_SC_T1_DATA T1;

}S_SC_DEV_T;


typedef void (SC_PFN_CALLBACK)(void);
  


void SC_TimerINTEnable(S_SC_DEV_T *dev, uint32_t no);
void SC_TimerINTDisable(S_SC_DEV_T *dev, uint32_t no);
void SC_TimerCountSet(S_SC_DEV_T *dev, uint32_t no, uint32_t op_mode, uint32_t cnt);
void SC_WaitFirstReceivedData(S_SC_DEV_T *dev, uint32_t no, uint32_t op_mode, uint32_t cnt);
void SC_TimerStop(S_SC_DEV_T *dev, uint32_t no);
void SC_TimerAllStop(S_SC_DEV_T *dev);
void SC_TimerStart(S_SC_DEV_T *dev, uint32_t no);
void SC_TimerSelect(S_SC_DEV_T *dev, uint32_t type);
int32_t SC_WarmReset(S_SC_DEV_T *dev);
int32_t SC_DoPPS(S_SC_DEV_T *dev, int32_t f, int32_t d, int32_t t);
void SC_DeactivationCmd(S_SC_DEV_T *dev);
void SC_ActivationCmd(S_SC_DEV_T *dev);
void SC_WarmResetCmd(S_SC_DEV_T *dev);
void SC_SetGuardTime(S_SC_DEV_T *dev);
void SC_SetBlockGuardTime(S_SC_DEV_T *dev, uint32_t bgt);
void SC_StartBlockGuardTime( S_SC_DEV_T *dev );
void SC_StopBlockGuardTime( S_SC_DEV_T *dev );
void SC_ClearFIFO(S_SC_DEV_T *dev);
uint8_t * SC_ErrMsg(long errno);
int32_t SC_CheckCardPresent(SC_T *portno);
int32_t SC_ColdReset(S_SC_DEV_T *dev);
void SC_SetClockState(S_SC_DEV_T *dev, int8_t onoff);
void SC_ClockStopLevel(S_SC_DEV_T *dev);
void SC_VoltageConfig(S_SC_DEV_T *dev);
void SC_SetReaderParameter(S_SC_DEV_T *dev);
int32_t SC_PowerActiveLevel(SC_T *portno, int8_t active);
int32_t SC_IgnoreCardAbsent(SC_T *portno);
int32_t SC_CardDetectEdge(SC_T *portno, int8_t edge);

int32_t SC_UpdateCardCapabilities(S_SC_DEV_T *dev);



int32_t SC_Init(SC_T *portno);
int32_t SC_Open(SC_T *portno);
int32_t SC_Close(SC_T *portno);
int32_t SC_GetATRBuffer(SC_T *portno, uint8_t *buf, int16_t length);
int32_t SC_InstallCallBack(SC_T *portno, SC_PFN_CALLBACK pfncallback);











 
__inline uint32_t SC_GetSmartCardClockSourceFreq(SC_T* SC)
{
    uint32_t u32ClkTbl[4] = {(12000000UL), 0, 0, (22118400UL)};
    uint32_t u32SCxEngineClk = 0;
    
    u32ClkTbl[1] = PllClock;
    u32ClkTbl[2] = SystemCoreClock;  
    if((SC)==((SC_T *) ((( uint32_t)0x40100000) + 0x90000)))
    {
        u32SCxEngineClk = ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL3&(3ul << 0);  
    }   
    else if((SC)==((SC_T *) ((( uint32_t)0x40100000) + 0x94000)))
    {
        u32SCxEngineClk = (((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL3&(3ul << 2))>>2;         
    }   
    else if((SC)==((SC_T *) ((( uint32_t)0x40100000) + 0x98000)))
    {
        u32SCxEngineClk = (((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL3&(3ul << 4))>>4;         
    }     
                                           
    return u32ClkTbl[u32SCxEngineClk];    
}





  



  





 



#line 6310 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"
#line 1 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PS2.h"
 









 



 
 
 
#line 19 "..\\..\\..\\..\\libNUC200Series\\StdDriver\\inc\\PS2.h"

 
 
 


 
 
 



 




 




 




 




 

 


  




 




 




 




 




 




 




 




 




 




 					   




 




 




  




 		




 								




 				




 				




  




 				




 				




 				




 				




  




 				




 				




 




 




 




 


 
 
 


 
__inline void PS2_ResetIP()
{
	((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 |=  (1ul << 23);
	((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->IPRSTC2 &= ~(1ul << 23);
}


 
static __inline void PS2_CLEAR_TX_FIFO()
{
    (((PS2_T *) ((( uint32_t)0x40100000) + 0x00000))->PS2CON |= (1ul << 8));
    (((PS2_T *) ((( uint32_t)0x40100000) + 0x00000))->PS2CON &= (~(1ul << 8)));
}


#line 6311 "..\\..\\..\\..\\libNUC200Series\\CMSIS\\CM0\\DeviceSupport\\Nuvoton\\NUC200Series\\NUC200Series.h"

                                                                                                 
#line 14 "..\\main.c"







 
 
 
uint8_t g_u8SendData[12] ={0};
uint8_t g_u8RecData[1024]  ={0};

volatile uint32_t g_u32comRbytes = 0;        
volatile uint32_t g_u32comRhead  = 0;
volatile uint32_t g_u32comRtail  = 0;
volatile int32_t g_bWait         = 1;
volatile int32_t g_i32pointer = 0;

 
 
 
int32_t main(void);
void UART_TEST_HANDLE(void);
void UART_FunctionTest(void);
void AutoFlow_FunctionTest(void);
void TestItem (void);

extern void RS485_HANDLE(void);
extern void IrDA_FunctionTest(void);
extern void RS485_FunctionTest(void);
extern void LIN_FunctionTest(void);
extern void LIN_FunctionTestUsingLinCtlReg(void);

 
 
 
void TestItem (void)
{
    printf("+-----------------------------------------------------------+\n");
    printf("|               UART Sample Program                         |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| UART function test                                  - [1] |\n");
    printf("| IrDA funtion test                                   - [2] |\n");
    printf("| RS485 funtion test                                  - [3] |\n");
    printf("| LIN Master funtion test                             - [4] |\n");
    printf("| Auto-Flow funtion test                              - [5] |\n");
    printf("| LIN Master funtion test using UA_LIN_CTL register   - [6] |\n");    
    printf("+-----------------------------------------------------------+\n");
    printf("| Quit                                              - [ESC] |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("Please Select key (1~6): ");
}


void SYS_Init(void)
{
 
 
 
     
    SYS_UnlockReg();

     
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->PWRCON |= (1ul << 0);

     
    SYS_WaitingForClockReady( (1ul << 0));

     
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL0 = 0x00UL;

     
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->PLLCON|= (1ul << 16);

             
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->PLLCON = (0x00000000UL | (((3)-2)<<9) | ((25)-2) | 0x4000UL);

     
    SYS_WaitingForClockReady((1ul << 2));

     
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL0 = 0x02UL;

             
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->APBCLK = (1ul << 16) | (1ul << 17);
    
     
    ((SYSCLK_T *) ((( uint32_t)0x50000000) + 0x00200))->CLKSEL1 = 0x00000000UL;                    

     
     
    
    PllClock        = 50000000;            
    SystemCoreClock = 50000000 / 1;        
    CyclesPerUs     = 50000000 / 1000000;  

 
 
 
	 
	((GCR_T *) ((( uint32_t)0x50000000) + 0x00000))->GPB_MFP = (1UL<<0) | (1UL<<1) |
     
				   (1UL<<4) | (1UL<<5) | 
	 
				   (1UL<<6) | (1UL<<7);
     
    SYS_LockReg();
}

void UART0_Init()
{
 
 
 
    ((UART_T *) ((( uint32_t)0x40000000) + 0x50000))->BAUD = ((1ul << 29) | (1ul << 28)) | ((((12000000UL) + (115200/2)) / 115200)-2);
   
    ((((UART_T *) ((( uint32_t)0x40000000) + 0x50000)))->LCR = ((3) | (0x0 << 3) | (0x0 << 2)));
}

void UART1_Init()
{
 
 
 

    ((UART_T *) ((( uint32_t)0x40100000) + 0x50000))->BAUD = ((1ul << 29) | (1ul << 28)) | ((((12000000UL) + (115200/2)) / 115200)-2);

    ((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->LCR = ((3) | (0x0 << 3) | (0x0 << 2)));
}

 
 
 
 
 

 
 
 

int main(void)
{
    uint32_t u32Item;
     
    SYS_Init();
     
    UART0_Init();
     
    UART1_Init();

 
 
 
    
    printf("\n\nCPU @ %dHz\n", SystemCoreClock);

    do{
        TestItem();
        u32Item = getc((& __stdin));
        printf("%c\n",u32Item);
        switch(u32Item)
        {
            case '1':   UART_FunctionTest();     break;
            case '2':   IrDA_FunctionTest();     break;
            case '3':   RS485_FunctionTest();    break;
            case '4':   LIN_FunctionTest();      break;
            case '5':   AutoFlow_FunctionTest(); break;
            case '6':   LIN_FunctionTestUsingLinCtlReg();      break;            
            default:    break;
        }
    }while(u32Item != 27); 

}

 
 
 
void UART02_IRQHandler(void)
{
    UART_TEST_HANDLE();
}

 
 
 
void UART1_IRQHandler(void)
{
    RS485_HANDLE();
}

 
 
 
void UART_TEST_HANDLE()
{
    uint8_t u8InChar=0xFF;
    uint32_t u32IntSts= ((UART_T *) ((( uint32_t)0x40000000) + 0x50000))->ISR;

    if(u32IntSts & (1ul << 8))
    {
        printf("\nInput:");
        
         
        while((((((UART_T *) ((( uint32_t)0x40000000) + 0x50000)))->ISR & (1ul << 0))>>0)) 
        {
             
            ((u8InChar) = (((UART_T *) ((( uint32_t)0x40000000) + 0x50000)))->RBR);                

            printf("%c ", u8InChar);
            
            if(u8InChar == '0')   
            {   
                g_bWait = 0;
            }
        
             
            if(g_u32comRbytes < 1024)
            {
                 
                g_u8RecData[g_u32comRtail] = u8InChar;
                g_u32comRtail = (g_u32comRtail == (1024-1)) ? 0 : (g_u32comRtail+1);
                g_u32comRbytes++;
            }           
        }
        printf("\nTransmission Test:");
    }

    if(u32IntSts & (1ul << 9))
    {   
        uint16_t tmp;
        tmp = g_u32comRtail;
        if(g_u32comRhead != tmp)
        {
            u8InChar = g_u8RecData[g_u32comRhead];
            ((((UART_T *) ((( uint32_t)0x40000000) + 0x50000)))->THR = (u8InChar));
            g_u32comRhead = (g_u32comRhead == (1024-1)) ? 0 : (g_u32comRhead+1);
            g_u32comRbytes--;
        }
    }
}


 
 
 
void UART_FunctionTest()
{
    printf("+-----------------------------------------------------------+\n");
    printf("|  UART Function Test                                       |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  Description :                                            |\n");
    printf("|    The sample code will print input char on terminal      |\n");
    printf("|    Please enter any to start     (Press '0' to exit)      |\n");
    printf("+-----------------------------------------------------------+\n");
   
    




 
   
     
    ((((UART_T *) ((( uint32_t)0x40000000) + 0x50000)))->IER |= (((1ul << 0) | (1ul << 1) | (1ul << 4))));
    NVIC_EnableIRQ(UART02_IRQn);
    while(g_bWait); 
        
     
    ((((UART_T *) ((( uint32_t)0x40000000) + 0x50000)))->IER &= ~ (((1ul << 0) | (1ul << 1) | (1ul << 4))));
    NVIC_DisableIRQ(UART02_IRQn);
    g_bWait =1;
    printf("\nUART Sample Demo End.\n");
        
}

 
 
 
void AutoFlow_FunctionTest()
{
    uint8_t u8Item;
    uint32_t u32i;
    printf("+-----------------------------------------------------------+\n");
    printf("|     Pin Configure                                         |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  _______                                      _______     |\n");
    printf("| |       |                                    |       |    |\n");  
    printf("| |Master |---TXD1(pin46) <====> RXD1(pin45)---| Slave |    |\n");  
    printf("| |       |---RTS1(pin39) <====> CTS1(pin40)---|       |    |\n");  
    printf("| |_______|---CTS1(pin40) <====> RTS1(pin39)---|_______|    |\n");  
    printf("|                                                           |\n");
    printf("+-----------------------------------------------------------+\n\n");  

     
    UART_SetRTS_TrgLev(((UART_T *) ((( uint32_t)0x40100000) + 0x50000)),(0x1 << 9),(0x3 << 16));
    
     
    ((UART_T *) ((( uint32_t)0x40100000) + 0x50000))->IER |= (1ul << 12) | (1ul << 13);
    
    printf("+-----------------------------------------------------------+\n");
    printf("|       AutoFlow Function Test                              |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  Description :                                            |\n");
    printf("|    The sample code needs two boards. One is Master and    |\n");
    printf("|    the other is slave. Master will send 1k bytes data     |\n");
    printf("|    to slave.Slave will check if received data is correct  |\n");
    printf("|    after getting 1k bytes data.                           |\n");
    printf("|  Please select Master or Slave test                       |\n");
    printf("|  [0] Master    [1] Slave                                  |\n");
    printf("+-----------------------------------------------------------+\n\n");
    u8Item = getc((& __stdin));
    
    
    if(u8Item=='0')
    {
        for(u32i=0;u32i<(1024-1);u32i++)
        {
            ((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->THR = (((u32i+1)&0xFF)));

             
            while((((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->MCR & (1ul << 13))>> 13));
        }
        printf("\n Transmit Done\n");
    }
    else
    {
        g_i32pointer = 0;
    
         
        ((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->IER |= (((1ul << 0) | (1ul << 1) | (1ul << 4))));

         
        ((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->FCR = ((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->FCR & ~(0xFul << 4))| ((0x2 << 4)));

         
        UART_SetTimeOutCounter(((UART_T *) ((( uint32_t)0x40100000) + 0x50000)),0x3E);
        
        NVIC_EnableIRQ(UART1_IRQn);

        printf("Starting to recevice %d bytes data...\n", 1024);
        
        while(g_i32pointer<(1024-1))
        {
            printf("%d\r",g_i32pointer);
        }

         
        for(u32i=0;u32i!=(1024-1);u32i++)
        {
            if(g_u8RecData[u32i] != ((u32i+1)&0xFF) )
            {
                printf("Compare Data Failed\n");
                while(1);
            }
        }
        printf("\n Receive OK & Check OK\n");
    }

    NVIC_DisableIRQ(UART1_IRQn);

    ((((UART_T *) ((( uint32_t)0x40100000) + 0x50000)))->IER &= ~ (((1ul << 0) | (1ul << 1) | (1ul << 4))));
}
