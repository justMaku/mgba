#include <mgba/internal/gb/twitter.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define CMD_READ 1
#define CMD_WRITE 2

int s;

void fake_ram_init() {
	struct sockaddr_in address;

	s = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_port = htons(2137);

	inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);

	connect(s, &address, sizeof(address));
}

uint8_t read_fake_ram(uint16_t address) {
	send(s, CMD_READ, 1, 0);
	send(s, &address, sizeof(address), 0);

	uint8_t value;

	read(s, &value, 1);

	return value;
}

void write_fake_ram(uint16_t address, uint8_t value) {
	send(s, CMD_WRITE, 1, 0);
	send(s, &address, sizeof(address), 0);
	send(s, &value, sizeof(value), 0);
}