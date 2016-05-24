#ifndef _TINYVMH
#define _TINYVMH

#define RAMSIZE 32

void p(int s,void* p){int i,j;for(i=s-1;i>=0;i--)for(j=7;j>=0;j--)printf("%u",(*((unsigned char*)p+i)&(1<<j))>>j);puts("");}

#endif /* _TINYVMH */
