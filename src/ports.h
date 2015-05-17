typedef unsigned char * port8ptr;

#define ML4IN 0x600
#define ML4OUT 0x400

#define ML4READ *((port8ptr)ML4IN)
#define ML4WRITE *((port8ptr)ML4OUT)


#define KBDIN 0x9c0
#define KBDREAD *((port8ptr)KBDIN)
#define KBDREADptr ((port8ptr)KBDIN)

#define DISP_MODE_REG 0x9c2
#define DISP_DATA_REG 0x9c3

#define DISP_MODE_REG_WRITE *((port8ptr)DISP_MODE_REG)
#define DISP_DATA_REG_WRITE *((port8ptr)DISP_DATA_REG)
