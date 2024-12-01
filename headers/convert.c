#include "convert.h"

uint8_t custom_pow(uint8_t a, uint8_t b) {
	uint8_t res = 1;

	for (uint8_t i=0; i<b; i++) {
		res *= a;
	}

	return res;
}

IPv4_t strtoIntIP(char* ip_str) {
	IPv4_t ip = 0;

	ssize_t ip_len = strlen(ip_str);
	char c;

	int8_t octet[3];
	int8_t octet_len = 0;
	uint8_t octet_val = 0;
	uint8_t buff_i = 0;

	memset(octet, -1, 3);

	for (uint8_t i = 0; i <= ip_len; i++) {
		c = ip_str[i];

		if ( ('0' <= c) && (c <= '9') ) {
			octet[buff_i] = c - '0';

			octet_len++;
			buff_i++;
		} else {
			for (int8_t j = 0; j < octet_len; j++) {
				uint8_t exp = octet_len - j - 1;

				octet_val += octet[j] * custom_pow(10, exp);
			}

			ip <<= 8;
			ip += ((uint32_t)octet_val);

			memset(octet, -1, 3);
			octet_len = 0;
			octet_val = 0;
			buff_i = 0;
		}
	}

	return ip;
}

IPv4_t SwitchEndianness(IPv4_t ip) {
	uint8_t* res = (uint8_t*)&ip;

	for (int8_t i=0; i<2; i++) {
		res[i] += res[3-i];
		res[3-i] = res[i] - res[3-i];
		res[i] -= res[3-i];
	}

	return *(IPv4_t*)res;
}
