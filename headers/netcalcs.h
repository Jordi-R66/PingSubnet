#include "commons.h"

IPv4_t IP2INT(uint8_t IP[4]);
uint8_t* INT2IP(IPv4_t IP);

IPv4_t getHostID(IPv4_t addr, IPv4_t mask);
IPv4_t getNetID(IPv4_t addr, IPv4_t mask);
IPv4_t getBroadcast(IPv4_t net_id, IPv4_t mask);

IPv4_t getPossibleAddresses(IPv4_t mask);
char getNetClass(IPv4_t net_id);