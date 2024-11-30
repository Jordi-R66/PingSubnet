#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <stdbool.h>

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
