/*
 * valIP.h
 *
 *  Created on: Jul 28, 2019
 *      Author: Christos Papazachariou
 */

#ifndef VALIP_H_
#define VALIP_H_

#define VALIP_TRACE

#if defined(VALIP_TRACE)
	#define VALIPTRACE(fmt,...);	printf(fmt,##__VA_ARGS__);
	void runtests(void);
#else
	#define VALIPTRACE(fmt,...);
#endif

#define IP_VALID	1
#define IP_NOT_VALID	0
#define IP_ERROR	-1

int ValidateIp(char * input);

#endif /* VALIP_H_ */
