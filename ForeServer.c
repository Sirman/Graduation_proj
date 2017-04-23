#include "dataGather.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
static char message_cksum(char *data);
static int message_unpack(unsigned char *buf);
static char generate_pfc(char pfc);
static void message_pack(Message *msg,unsigned char *addr,unsigned char ctl,unsigned char *da,unsigned char *dt,unsigned char *data,unsigned char pfc,unsigned char delay);

/* pack the message */

static void message_pack(Message *msg,unsigned char *addr,unsigned char ctl,unsigned char *da,unsigned char *dt,unsigned char *data,unsigned char pfc, unsigned char delay){
    time_t timep;
    struct tm *p = gmtime(&timep);
    msg->head.start_begin = START; 
    *msg->head.len_pos1 = *msg->head.len_pos2 = (unsigned char)sizeof(msg)-8;
    msg->head.start_end = START; 
    msg->ctl = ctl; 
    msg->addr = addr;
    msg->afn = REPT; 
    msg->seq = pfc&0x0F;    // how to generate seq
    msg->DA = da;
    msg->DT = dt;
    msg->data = data; 
    msg->pfc = generate_pfc(pfc);     //how to generate pfc
    msg->tpv.second = p->tm_sec;
    msg->tpv.minute = p->tm_min;
    msg->tpv.hour = p->tm_hour;
    msg->tpv.day = p->tm_mday;;
    msg->delay = delay; 
    msg->crc = 0x81; 
    msg->end = END; 
} 

/* unpack the message */

static int message_unpack(unsigned char *buf){
    Message * msg =  NULL;
    msg->ctl = buf[7];
    if(msg->ctl & 0x80)
        printf(" xia xing bao wen");
    return 0;
}
static char generate_pfc(char pfc){
    pfc = (pfc + 1)%255;
    return pfc;
}
int main(){
    Message rept_down;
    unsigned char addr[5] = {0x08,0x01,0x90,0x53,0x29};
    unsigned char ctl = 0x42;
    unsigned char da[] = {0x00,0x00};
    unsigned char dt[] = {0x00,0x01};
    unsigned char *data = NULL;
    unsigned char delay = 0x00;
    unsigned char pfc = 0;
    message_pack(&rept_down,addr,ctl,da,dt,data,pfc,delay);
    return 0;

}
