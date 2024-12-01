#include "netcalcs.h"

uint32_t IP2INT(uint8_t IP[4]) {
	uint32_t addr_int = 0;

	for (uint8_t i=0; i<4; i++) {
		addr_int += IP[i];

		if (i < 3) {
			addr_int <<= 8;
		}
	}

	return addr_int;
}

uint8_t* INT2IP(uint32_t IP) {
	uint8_t* addr_arr = (uint8_t*)malloc(sizeof(uint8_t) * 4);
	memset(addr_arr, 0, sizeof(uint8_t) * 4);

	for (uint8_t i=0; i<4; i++) {
		uint8_t j = 3 - i;
		addr_arr[j] = IP % 256;
		IP >>= 8;
	}

	return addr_arr;
}



uint32_t getHostID(uint32_t addr, uint32_t mask) {
	uint32_t host_id;

	host_id = addr & (~mask);

	return host_id;
}

uint32_t getNetID(uint32_t addr, uint32_t mask) {
	uint32_t net_id;

	net_id = addr & mask;

	return net_id;
}

uint32_t getBroadcast(uint32_t net_id, uint32_t mask) {
	uint32_t broadcast;

	broadcast = net_id + (~mask);

	return broadcast;
}



uint32_t getPossibleAddresses(uint32_t mask) {
	uint8_t n_bits = 0;

	uint32_t reversed_mask = ~mask;

	while (reversed_mask) {
		n_bits += reversed_mask & 1;
		reversed_mask >>= 1;
	}

	uint32_t n_addr = (uint32_t)powf(2, n_bits) - 2;

	return n_addr;
}

char getNetClass(uint32_t net_id) {
	uint8_t a_end[] = {126, 255, 255, 255};

	uint8_t b_start[] = {128, 0, 0, 0};
	uint8_t b_end[] = {191, 255, 255, 255};

	uint8_t c_start[] = {192, 0, 0, 0};
	uint8_t c_end[] = {223, 255, 255, 255};

	uint8_t d_start[] = {224, 0, 0, 0};
	uint8_t d_end[] = {239, 255, 255, 255};

	uint8_t e_start[] = {240, 0, 0, 0};
	uint8_t e_end[] = {255, 255, 255, 255};

	uint32_t A_START = 0b0;
	uint32_t A_END = IP2INT(a_end);

	uint32_t B_START = IP2INT(b_start);
	uint32_t B_END = IP2INT(b_end);

	uint32_t C_START = IP2INT(c_start);
	uint32_t C_END = IP2INT(c_end);

	uint32_t D_START = IP2INT(d_start);
	uint32_t D_END = IP2INT(d_end);

	uint32_t E_START = IP2INT(e_start);
	uint32_t E_END = IP2INT(e_end);

	if ((A_START <= net_id) & (net_id <= A_END)) {
		return 'A';
	} else if ((B_START <= net_id) & (net_id <= B_END)) {
		return 'B';
	} else if ((C_START <= net_id) & (net_id <= C_END)) {
		return 'C';
	} else if ((D_START <= net_id) & (net_id <= D_END)) {
		return 'D';
	} else if ((E_START <= net_id) & (net_id <= E_END)) {
		return 'E';
	} else {
		return 'L';
	}
}