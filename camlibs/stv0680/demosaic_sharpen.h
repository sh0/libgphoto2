/** Decl of demosaic_sharpen */
#ifndef __STV680_DEMOSAIC_SHARPEN_H
#define __STV680_DEMOSAIC_SHARPEN_H

#include "../../libgphoto2/bayer.h"

void stv0680_demosaic_sharpen (const int width, const int height,
		       const unsigned char * const src_region,
		       unsigned char * const dest_region,
		       const int alpha, const BayerTile bt);
#endif
