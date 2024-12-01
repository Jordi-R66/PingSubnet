#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#ifdef __linux__
	#include <netdb.h>
	#include <netinet/in.h> 
	#include <sys/socket.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <ifaddrs.h>
	#include <unistd.h>
#elif defined(_WIN32)
	#include <winsock2.h>
	#include <iphlpapi.h>
	#include <ws2tcpip.h>
	#pragma comment(lib, "iphlpapi.lib")
	#pragma comment(lib, "ws2_32.lib")
#endif

typedef uint32_t IPv4_t;

typedef enum Endian {
    BIG = 0,
    LITTLE = 1
} Endian;

typedef struct Interface {
	IPv4_t ip_int;
	IPv4_t mask_int;
	IPv4_t min_ip;
	IPv4_t max_ip;
} Interface;

Endian getEndianness(void);
