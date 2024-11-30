#include "convert.h"

uint8_t pow(uint8_t a, uint8_t b) {
	uint8_t res = 1;

	for (uint8_t i=0; i<b; i++) {
		res *= a;
	}

	return res;
}

uint32_t strtoIntIP(char* ip_str) {
	IPv4_t ip = 0;
	uint8_t octet = 0;

	ssize_t ip_len = strlen(ip_str);
	char c;

	for (uint8_t i=0; i<ip_len; i++) {
		c = 
	}

	return ip;
}