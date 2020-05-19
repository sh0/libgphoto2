/*
 * Copyright 1999 by Henning Zabel <henning@uni-paderborn.de>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * gphoto driver for the Mustek MDC800 Digital Camera. The driver
 * supports rs232 and USB. It automatically detects which Kernelnode
 * is used.
 */

#include <string.h>
#include "image.h"
#include "print.h"

static const unsigned char Huffman_Tab[424] =
{
    0xFF,0xC4,0x01,0xA2,
    /* DC_Luminance_Bits */
    0, 0, 1, 5, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    /* DC_Luminance_Value */
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0x0A, 0x0B,
    /* DC_Chrominance_Bits */
    1, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    /* DC_Chrominance_Value */
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0x0A, 0x0B,
    /* AC_Luminance_Bits */
    0x10, 0, 2, 1, 3, 3, 2, 4, 3, 5, 5, 4, 4, 0, 0, 1, 0x7D,
    /* AC_Luminance_Value */
    0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05, 0x12,
    0x21, 0x31, 0x41, 0x06, 0x13, 0x51, 0x61, 0x07,
    0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xA1, 0x08,
    0x23, 0x42, 0xB1, 0xC1, 0x15, 0x52, 0xD1, 0xF0,
    0x24, 0x33, 0x62, 0x72, 0x82, 0x09, 0x0A, 0x16,
    0x17, 0x18, 0x19, 0x1A, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2A, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
    0x3A, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
    0x4A, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5A, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
    0x6A, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79,
    0x7A, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
    0x8A, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98,
    0x99, 0x9A, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7,
    0xA8, 0xA9, 0xAA, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6,
    0xB7, 0xB8, 0xB9, 0xBA, 0xC2, 0xC3, 0xC4, 0xC5,
    0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xD2, 0xD3, 0xD4,
    0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xE1, 0xE2,
    0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA,
    0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA,
    /* AC_Chrominance_Bits */
    0x11, 0, 2, 1, 2, 4, 4, 3, 4, 7, 5, 4, 4, 0, 1, 2, 0x77,
    /* AC_Chrominance_Value */
    0x00, 0x01, 0x02, 0x03, 0x11, 0x04, 0x05, 0x21,
    0x31, 0x06, 0x12, 0x41, 0x51, 0x07, 0x61, 0x71,
    0x13, 0x22, 0x32, 0x81, 0x08, 0x14, 0x42, 0x91,
    0xA1, 0xB1, 0xC1, 0x09, 0x23, 0x33, 0x52, 0xF0,
    0x15, 0x62, 0x72, 0xD1, 0x0A, 0x16, 0x24, 0x34,
    0xE1, 0x25, 0xF1, 0x17, 0x18, 0x19, 0x1A, 0x26,
    0x27, 0x28, 0x29, 0x2A, 0x35, 0x36, 0x37, 0x38,
    0x39, 0x3A, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
    0x49, 0x4A, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
    0x59, 0x5A, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
    0x79, 0x7A, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
    0x88, 0x89, 0x8A, 0x92, 0x93, 0x94, 0x95, 0x96,
    0x97, 0x98, 0x99, 0x9A, 0xA2, 0xA3, 0xA4, 0xA5,
    0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xB2, 0xB3, 0xB4,
    0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xC2, 0xC3,
    0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xD2,
    0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA,
    0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9,
    0xEA, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA,
    /* Blank data */
    0xFF, 0xFE, 0x01, 0x8F
};


static const unsigned char File_Header[41]=
{
    /* JPG file start marker */
    0xFF, 0xD8,
    /* Application marker */
    0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x48, 0x00, 0x48, 0x00, 0x00,
    /* Application marker */
    0xFF, 0xE1, 0x00, 0x0E, 0x43, 0x41, 0x4D, 0x2D, 0x4D, 0x44,
    0x43, 0x38, 0x30, 0x30, 0x00, 0x00,
    /* Quantization table marker */
    0xFF, 0xDB, 0x00, 0x84, 0x00
};


static const unsigned char File_Header1[24]=
{
    /* JPG file start marker */
    0xFF, 0xD8,
    /* Application marker */
    0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00,    0x01,
    0x00, 0x01, 0x00, 0x48,         0x00, 0x48, 0x00, 0x00,
    /* Application marker */
    0xFF, 0xE1,     0x0F, 0xEC
};

static const unsigned char File_Header2[34]=
{
    /* JPG file start marker */
    0xFF, 0xD8,
    /* Application marker */
    0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x48,     0x00, 0x48, 0x00, 0x00,
    /* Application marker */
    0xFF, 0xE1, 0x00, 0x0E, 0x43, 0x41, 0x4D, 0x2D, 0x4D, 0x44,
    0x43, 0x38, 0x30, 0x30
};


/* For Thumbnail: 112x96 */
static const unsigned char SOF_SOS1[33]=
{
    /* Start of frame marker */
    0xFF, 0xC0, 0x00, 0x11, 0x08, 0x00, 0x60, 0x00, 0x70, 0x03,
    0x01, 0x21, 0x00, 0x02, 0x11, 0x01, 0x03, 0x11, 0x01,
    /* Start of scan marker */
    0xFF, 0xDA, 0x00, 0x0C, 0x03, 0x01, 0x00, 0x02, 0x11, 0x03,
    0x11, 0x00, 0x3F, 0x00
};


/* For Economic quality image: 506x384 */
static const unsigned char SOF_SOS2[33]=
{
    /* Start of frame marker */
    0xFF, 0xC0, 0x00, 0x11, 0x08, 0x01, 0x80, 0x01, 0xFA, 0x03,
    0x01, 0x21, 0x00, 0x02, 0x11, 0x01, 0x03, 0x11, 0x01,
    /* Start of scan marker */
    0xFF, 0xDA, 0x00, 0x0C, 0x03, 0x01, 0x00, 0x02, 0x11, 0x03,
    0x11, 0x00, 0x3F, 0x00
};


/* For Standard and High quality image: 1012x768 */
static const unsigned char SOF_SOS3[33]=
{
    /* Start of frame marker */
    0xFF, 0xC0, 0x00, 0x11, 0x08, 0x03, 0x00, 0x03, 0xF4, 0x03,
    0x01, 0x21, 0x00, 0x02, 0x11, 0x01, 0x03, 0x11, 0x01,
    /* Start of scan marker */
    0xFF, 0xDA, 0x00, 0x0C, 0x03, 0x01, 0x00, 0x02, 0x11, 0x03,
    0x11, 0x00, 0x3F, 0x00
};


/*
 * corrects downloaded data
 *
 * thumbnail :  1 data is a thumbnail
 * quality :    0 economy , 1 standard, 2 High
 * location :   1 internal, 0 CF-Card
 */
int mdc800_correctImageData (unsigned char* buffer, int thumbnail,int quality,int location)
{
    printCError ("(mdc800_correctImageData) thumbnail:%i quality:%i location:%i \n", thumbnail, quality, location);
    if (thumbnail)
    {
        if (location == 1)
        {
            memcpy (buffer, File_Header,41);
            *(buffer+105)=1;
            buffer+=170;
            memcpy (buffer, Huffman_Tab, 424);
            buffer+=821;
            memcpy (buffer,SOF_SOS1,33);
        }
        else
        {
            *(buffer+22)=0x00;
            *(buffer+23)=0x0e;
        }
        return 1;
    }
    else
    {
        if (location == 1)
        {
            memcpy (buffer, File_Header1, 24);
            buffer+=4096;
            memcpy (buffer, File_Header, 41);
            *buffer=*(buffer+1)=0;
            *(buffer+105)=1;
            buffer+=170;
            memcpy (buffer, Huffman_Tab,424);
            buffer+=821;
            switch (quality)
            {
            case 0:
                memcpy (buffer,SOF_SOS2,33);
                break;
            case 1:
            case 2:
                memcpy (buffer, SOF_SOS3,33);
                break;
            }
        }


        /* CF Image is correct. */
        return 1;
    }
    return 0;
}
