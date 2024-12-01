#include "headers/commons.h"
#include "headers/convert.h"

Endian Endianness;

int32_t main() {
	Endianness = getEndianness();
	struct ifaddrs* ifaddr, * ifa;

	if (getifaddrs(&ifaddr) == -1) {
		perror("getifaddrs");
		return 1;
	}

	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
		uint8_t IP_ARR[4];

		if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) { // Filtre IPv4
			char ip[INET_ADDRSTRLEN];
			char netmask[INET_ADDRSTRLEN];

			memset(ip, 0, INET_ADDRSTRLEN);
			memset(netmask, 0, INET_ADDRSTRLEN);

			// Récupération de l'adresse IP
			struct sockaddr_in* addr = (struct sockaddr_in*)ifa->ifa_addr;
			inet_ntop(AF_INET, &addr->sin_addr, ip, sizeof(ip));

			// Récupération du masque de sous-réseau
			if (ifa->ifa_netmask) {
				struct sockaddr_in* mask = (struct sockaddr_in*)ifa->ifa_netmask;
				inet_ntop(AF_INET, &mask->sin_addr, netmask, sizeof(netmask));
			} else {
				snprintf(netmask, sizeof(netmask), "N/A");
			}

			printf("%s\n", ip);
			//uint32_t v = strtoint(ip);

			printf("Interface: %s, IP: %s, Netmask: %s\n", ifa->ifa_name, ip, netmask);
		}
	}

	freeifaddrs(ifaddr);

	IPv4_t test_ip = strtoIntIP("192.168.50.25");
	printf("0x%X\n", test_ip);
	test_ip = SwitchEndianness(test_ip);
	printf("0x%X\n", test_ip);

	return 0;
}
