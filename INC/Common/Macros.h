/*
 * Macros.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef _MACROS_H_
#define _MACROS_H_

#define SetBit(Reg,No)     Reg|=(1<<No)  // Reg= Reg|(1<<No)
#define ClearBit(Reg,No)   Reg&=~(1<<No)
#define GetBit(Reg,No)     ((Reg>>No)&1)
#define ToggleBit(Reg,No)   Reg^=(1<<No)

#define NULL    (void *)0
#define NULLChar   '\0'

#define Input     0
#define Output    1

#define Low       0
#define High      1

#ifdef InternalPull
#define NotPressed 0
#define Pressed    1
#endif

#define Disable     0
#define Enable     1
#define SourceConnection    1
#define SinkConnection      2

#endif /* _MACROS_H_ */
