#ifndef __STV680_SHARPEN_H
#define __STV680_SHARPEN_H
void  stv0680_sharpen(int width, int height,
	unsigned char *src_region, unsigned char *dest_region,
	int sharpen_percent
);
#endif
