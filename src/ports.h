typedef char * ML4port;

#define ML4IN 0x600
#define ML4OUT 0x400

#define ML4READ *((ML4port)ML4IN)
#define ML4WRITE *((ML4port)ML4OUT)
