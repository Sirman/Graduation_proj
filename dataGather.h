#define START 0x68
#define END   0x16
#include "stdlib.h"
enum AFN{
    CONFIRM=0X00,
    RESET=0X01,
    LINKTEST=0X02,
    REPT=0X03,
    SET=0X04,
    CONTROL=0X05,
    CERTIFICATE=0X06,
    REQ_CASCADE_RPT=0X08,
    REQ_TEMINAL_CFG=0X09,
    QUERY=0X0A,
    REQ_TASK_DATA=0X0B,
    REQ_ONECLASS_DATA=0X0C,
    REQ_SECCLASS_DATA=0X0D,
    REQ_THIRDCLASS_DATA=0X0E,
    FILE_TRANSFER=0X0F,
    DATA_FORWARD=0X10,
};
typedef struct{
    char start_begin;
    unsigned char *addr = (unsigned char *)malloc(5);
    char start_end;
}Head;
typedef struct{
    char second;
    char minute;
    char hour;
    char day;
}Tpv;
typedef struct {
    Head head;
    unsigned char ctl;
    unsigned char afn;
    unsigned char seq;
    unsigned char *DA;
    unsigned char *DT;
    unsigned char *data;
    unsigned char pfc;
    Tpv tpv;
    unsigned char delay;
    unsigned char crc;
    unsigned char end;
}Message;

