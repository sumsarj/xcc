typedef unsigned char * port8ptr;

#define set(x, mask) (x) |= (mask)
#define clear(x, mask) (x) &= ~(mask)

//ML4-----------------
#define ML4IN 0x600
#define ML4OUT 0x400

#define ML4READ *((port8ptr)ML4IN)
#define ML4WRITE *((port8ptr)ML4OUT)
//--------------------------
//KeyboardML15--------------------------
#define KBDIN 0x9c0
#define KBDREAD *((port8ptr)KBDIN)
#define KBDREADptr ((port8ptr)KBDIN)
//-----------------------------------

//DisplayML15-------------------------
#define DISP_MODE_REG 0x9c2
#define DISP_DATA_REG 0x9c3

#define DISP_MODE_REG_WRITE *((port8ptr)DISP_MODE_REG)
#define DISP_DATA_REG_WRITE *((port8ptr)DISP_DATA_REG)
//----------------------------------------------------

//CRG-----------------------------------------------
#define RTICTL *((unsigned char*)(0x34 + 0x7))
#define CRGINT *((unsigned char*)(0x34 + 0x4))
#define CRGFLG *((unsigned char*)(0x34 + 0x3))
typedef void (*vec) (void); // avbrottsvektor 
typedef vec *vecptr; // pekare till avbrottsvektor 
#define IRQ_VEC_ADR 0x3FF0
#define IRQ_VEC *((vecptr) IRQ_VEC_ADR)

typedef volatile unsigned long int time_type;
//---------------------------------------------------
//DRILL-------------------------------------------
#define BORR_STATUS_ADR 0x400
#define BORR_STATUS *((port8ptr)BORR_STATUS_ADR)

#define BORR_CTRL_ADR 0x401
#define BORR_CTRL *((port8ptr)BORR_CTRL_ADR)
//_----------------------------------------

