#include <stdio.h>

int read512(int fd, char * buf, int blk_number){
	printf ("reading block: %d\n", blk_number);
	return 1;
}

// keep current position
int curr_pos;

int read(int fd, char * buf, int size){
	printf("start with curr_pos: %d\n", curr_pos);
	while (size > 0){
		int curr_blk = curr_pos / 512;
		int off_in_blk = curr_pos % 512;
		
		int len = 512 - off_in_blk;

		if (len > size)
			len = size;

		char tmp[512];

		int ret = read512(fd, tmp, curr_blk);

		// memcpy(buf, tmp + off_in_blk, len);
		printf("memcopy: buf, tmp + %d, len: %d\n", off_in_blk, len);
		buf += len;
		curr_pos += len;
		size -= len;
	}
	printf("end with curr_pos: %d\n", curr_pos);
}


void main(){

	char buf[500];

	read(0, buff, 5);
	read(0, buf, 500); // block 0, 500 bytes
	read(0, buf, 30);  // block: 0 and 1, 12 and then 18 bytes
	read(0, buf, 8);   // block 1, starting at 17 to 8 bytes, ending at 538
}
