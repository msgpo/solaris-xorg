/*
 * Copyright (c) 2008, Oracle and/or its affiliates. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
 * fbc_edid_data - EDID test data
 */



/*
 * This module can be employed by inserting lines such as the following
 * into the code to be tested (e.g. fbc_prconf.c, fbc_predid.c).  It is
 * assumed that edid_data and edid_length are the appropriate variable
 * names.
 *
 *    #define FBC_EDID_TEST_DATA <n>
 *
 *    #if defined(FBC_EDID_TEST_DATA)
 *    #include "fbc_edid_test_data.h"
 *    #endif
 *
 *    $ make -f Makefile.fbc clobber all DEFINE=-DFBC_EDID_TEST_DATA=<n>
 */


{

/*
 * EXAMPLE 1: Sample BASE EDID (Block 0) for an LCD Desktop IT Display
 *
 *    "VESA Enhanced Extended Display Identification Data Standard,"
 *    Release A, Revision 2, September 25, 2006.  (EDID 1.4)
 */
const uint8_t fbc_edid_test_data_ex1[1 * 0x80] = {

	/* EDID Base Block (Block 0) */

	    /* Header */
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
	    /* Vendor & Product Identification */
		0x04, 0x43, 0x06, 0xF2, 0x01, 0x00, 0x00, 0x00,
		0x01, 0x11,
	    /* EDID Structure Version & Revision */
		0x01, 0x04,
	    /* Basic Display Parameters & Features */
		0x0F, 0x2B, 0x20, 0x78, 0x2B,
	    /* Color Characteristics */
		0x9C, 0x68, 0xA0, 0x57, 0x4A, 0x9B, 0x26, 0x12,
		0x48, 0x4C,
	    /* Established Timings */
		0xFF, 0xFF, 0x80,
	    /* Standard Timings */
		0xA9, 0x59, 0xA9, 0x4F, 0xA9, 0x4A, 0xA9, 0x45,
		0x81, 0x99, 0x81, 0x80, 0x61, 0x59, 0x45, 0x59,
	    /* 18-Byte Data Block #1 */
		/* Preferred Timing Mode */
		0x48, 0x3F, 0x40, 0x30, 0x62, 0xB0, 0x32, 0x40,
		0x40, 0xC0, 0x13, 0x00, 0xAB, 0x40, 0x11, 0x00,
		0x00, 0x1E,
	    /* 18-Byte Data Block #2 */
		/* Display Range Limits Descriptor With CVT Support Info */
		0x00, 0x00, 0x00, 0xFD, 0x00, 0x32, 0x5A, 0x1E,
		0x6E, 0x17, 0x04, 0x11, 0x00, 0xC8, 0x90, 0x00,
		0x50, 0x3C,
	    /* 18-Byte Data Block #3 */
		/* Established Timings III Display Descriptor */
		0x00, 0x00, 0x00, 0xF7, 0x00, 0x0A, 0xF7, 0x0F,
		0x03, 0x87, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00,
	    /* 18-Byte Data Block #4 */
		/* Display Product Name (ASCII) String */
		0x00, 0x00, 0x00, 0xFC, 0x00, 0x41, 0x42, 0x43,
		0x20, 0x4C, 0x43, 0x44, 0x32, 0x31, 0x0A, 0x20,
		0x20, 0x20,
	    /* Extension Block Count N */
		0x00,
	    /* Checksum C */
		0x0B

};


/*
 * EXAMPLE 2: Sample BASE EDID & CEA861 Extension for a DTV Display
 *
 *    "VESA Enhanced Extended Display Identification Data Standard,"
 *    Release A, Revision 2, September 25, 2006.  (EDID 1.4)
 */
const uint8_t fbc_edid_test_data_ex2[2 * 0x80] = {

	/* EDID Base Block (Block 0) */

	    /* Header */
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
	    /* Vendor & Product Identification */
		0x04, 0x43, 0x07, 0xF2, 0x01, 0x00, 0x00, 0x00,
		0xFF, 0x11,
	    /* EDID Structure Version & Revision */
		0x01, 0x04,
	    /* Basic Display Parameters & Features */
		0xA2, 0x4F, 0x00, 0x78, 0x1E,
	    /* Color Characteristics */
		0xEE, 0x91, 0xA3, 0x54, 0x4C, 0x99, 0x26, 0x0F,
		0x50, 0x54,
	    /* Established Timings */
		0x20, 0x00, 0x00,
	    /* Standard Timings */
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	    /* 18-Byte Data Block #1 */
		/* Preferred Timing Mode */
		0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40,
		0x58, 0x2C, 0x04, 0x05, 0x0F, 0x48, 0x42, 0x00,
		0x00, 0x1E,
	    /* 18-Byte Data Block #2 */
		/* Detailed Timing Descriptor */
		0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20,
		0x58, 0x2C, 0x25, 0x00, 0x0F, 0x48, 0x42, 0x00,
		0x00, 0x9E,
	    /* 18-Byte Data Block #3 */
		/* Detailed Timing Descriptor */
		0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20,
		0x6E, 0x28, 0x55, 0x00, 0x0F, 0x48, 0x42, 0x00,
		0x00, 0x1E,
	    /* 18-Byte Data Block #4 */
		/* Monitor Name ASCII Descriptor */
		0x00, 0x00, 0x00, 0xFC, 0x00, 0x41, 0x42, 0x43,
		0x20, 0x4C, 0x43, 0x44, 0x34, 0x37, 0x77, 0x0A,
		0x20, 0x20,
	    /* Extension Block Count N */
		0x01,
	    /* Checksum C */
		0xCB,

	/* CEA 861 EXTENSION Block Version 3 (Block 1) */

	    /* Extension Block Tag Number */
		0x02,
	    /* Extension Block Revision Number */
		0x03,
	    /*  */
		0x18, 0x72, 0x47, 0x90, 0x85, 0x04, 0x03, 0x02,
		0x07, 0x06, 0x23, 0x09, 0x07, 0x07, 0x83, 0x01,
		0x00, 0x00, 0x65, 0x03, 0x0C, 0x00, 0x10, 0x00,
	    /* 18-Byte Data Block #5 */
		/* Detailed Timing */
		0x8E, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10,
		0x10, 0x3E, 0x96, 0x00, 0x1F, 0x09, 0x00, 0x00,
		0x00, 0x18,
	    /* 18-Byte Data Block #6 */
		/* Detailed Timing */
		0x8E, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10,
		0x10, 0x3E, 0x96, 0x00, 0x04, 0x03, 0x00, 0x00,
		0x00, 0x18,
	    /* 18-Byte Data Block #7 */
		/* Detailed Timing */
		0x8E, 0x0A, 0xA0, 0x14, 0x51, 0xF0, 0x16, 0x00,
		0x26, 0x7C, 0x43, 0x00, 0x1F, 0x09, 0x00, 0x00,
		0x00, 0x98,
	    /* 18-Byte Data Block #8 */
		/* Detailed Timing */
		0x8E, 0x0A, 0xA0, 0x14, 0x51, 0xF0, 0x16, 0x00,
		0x26, 0x7C, 0x43, 0x00, 0x04, 0x03, 0x00, 0x00,
		0x00, 0x98,
	    /* Unused Addresses */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Checksum */
		0xC9

};


/*
 * EXAMPLE 3: Sample BASE EDID & CEA861 Extension for a IT/DTV Display
 *
 *    "VESA Enhanced Extended Display Identification Data Standard,"
 *    Release A, Revision 2, September 25, 2006.  (EDID 1.4)
 */
const uint8_t fbc_edid_test_data_ex3[2 * 0x80] = {

	/* EDID Base Block (Block 0) */

	    /* Header */
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
	    /* Vendor & Product Identification */
		0x04, 0x43, 0x08, 0xF2, 0x01, 0x00, 0x00, 0x00,
		0x10, 0x11,
	    /* EDID Structure Version & Revision */
		0x01, 0x04,
	    /* Basic Display Parameters & Features */
		0xA2, 0x79, 0x44, 0x78, 0x1E,
	    /* Color Characteristics */
		0xEE, 0x91, 0xA3, 0x54, 0x4C, 0x99, 0x26, 0x0F,
		0x50, 0x54,
	    /* Established Timings */
		0xFF, 0xEF, 0x80,
	    /* Standard Timings */
		0x81, 0x99, 0x81, 0x80, 0x81, 0x59, 0x81, 0x40,
		0x61, 0x59, 0x4B, 0xC0, 0x45, 0x59, 0x31, 0x59,
	    /* 18-Byte Data Block #1 */
		/* Preferred Timing Mode */
		0x66, 0x21, 0x50, 0xB0, 0x51, 0x00, 0x1B, 0x30,
		0x40, 0x70, 0x36, 0x00, 0xBE, 0xAB, 0x42, 0x00,
		0x00, 0x1E,
	    /* 18-Byte Data Block #2 */
		0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20,
		0x6E, 0x28, 0x55, 0x00, 0xBE, 0xAB, 0x42, 0x00,
		0x00, 0x1E,
	    /* 18-Byte Data Block #3 */
		0x00, 0x00, 0x00, 0xF7, 0x00, 0x0A, 0xF7, 0x0F,
		0x03, 0x87, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00,
	    /* 18-Byte Data Block #4 */
		0x00, 0x00, 0x00, 0xFC, 0x00, 0x41, 0x42, 0x43,
		0x20, 0x50, 0x4C, 0x41, 0x35, 0x35, 0x0A, 0x20,
		0x20, 0x20,
	    /* Extension Block Count N */
		0x01,
	    /* Checksum C */
		0x0A,

	/* CEA 861 EXTENSION Block Version 3 (Block 1) */

	    /* Extension Block Tag Number */
		0x02,
	    /* Extension Block Revision Number */
		0x03,
	    /*  */
		0x17, 0xF0, 0x46, 0x05, 0x04, 0x03, 0x02, 0x07,
		0x06, 0x23, 0x09, 0x07, 0x07, 0x83, 0x01, 0x00,
		0x00, 0x65, 0x03, 0x0C, 0x00, 0x10, 0x00,
	    /* 18-Byte Data Block #5 */
		/* Detailed Timing */
		0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20,
		0x58, 0x2C, 0x25, 0x00, 0x0F, 0x48, 0x42, 0x00,
		0x00, 0x9E,
	    /* 18-Byte Data Block #6 */
		/* Detailed Timing */
		0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20,
		0x6E, 0x28, 0x55, 0x00, 0x0F, 0x48, 0x42, 0x00,
		0x00, 0x1E,
	    /* 18-Byte Data Block #7 */
		/* Detailed Timing */
		0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10,
		0x10, 0x3E, 0x96, 0x00, 0xB9, 0x88, 0x21, 0x00,
		0x00, 0x18,
	    /* 18-Byte Data Block #8 */
		/* Detailed Timing */
		0x8E, 0x0A, 0xA0, 0x14, 0x51, 0xF0, 0x16, 0x00,
		0x26, 0x7C, 0x43, 0x00, 0xB9, 0x88, 0x21, 0x00,
		0x00, 0x98,
	    /* Unused Addresses */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Checksum */
		0x5A

};


/*
 * EDID Base Block  (Based on an actual monitor)
 *
 *    Monitor manufacturer: SUN
 *    Product Code:         4
 *    Serial Number:        12212555
 *    Manufacture date:     2000, week 9
 *    EDID Version:         1.1
 *
 * Extension Map Block  (Hand-crafted according to standard)
 *
 *    "VESA Enhanced Extended Display Identification Data Standard,"
 *    Release A, Revision 2, September 25, 2006.  (EDID 1.4)
 *
 * DI-EXT Blocks  (Examples 1-4 from standard)
 *
 *    "VESA Display Information Extension Block Standard,"
 *    Release A, August 21, 2001.
 *
 * VTB-EXT Block  (Sample from standard)
 *
 *    "VESA Video Timing Block Extension Data Standard,"
 *    Release A, November 24, 2003.
 */
const uint8_t fbc_edid_test_data_misc[] = {

	/* EDID Base Block (Block 0) */

	    /* Header */
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
	    /* Vendor & Product Identification */
		0x4E, 0xAE, 0x04, 0x00, 0x4B, 0x59, 0xBA, 0x00,
		0x09, 0x0A,
	    /* EDID Structure Version & Revision */
		/* 0x01, 0x01, */
		0x01, 0x04,
	    /* Basic Display Parameters & Features */
		0x0E, 0x24, 0x1D, 0xA2, 0xE8,
	    /* Color Characteristics */
		0x8F, 0x17, 0x9B, 0x58, 0x4D, 0x90, 0x25,
		0x1E, 0x4F, 0x55,
	    /* Established Timings */
		0xBF, 0xEF, 0x00,
	    /* Standard Timings */
		0x81, 0x80, 0x81, 0x90, 0x71, 0x86, 0x81, 0x8F,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	    /* 18-Byte Data Block #1 */
		/* Preferred Timing Mode */
		0x30, 0x2A, 0x00, 0x98, 0x51, 0x00, 0x2A, 0x40,
		0x30, 0x70, 0x13, 0x00, 0x67, 0x1F, 0x11, 0x00,
		0x00, 0x14,
	    /* 18-Byte Data Block #2 */
		/* Detailed Timing */
		0xBC, 0x34, 0x00, 0x80, 0x51, 0x00, 0x2A, 0x40,
		0x20, 0x40, 0x28, 0x00, 0x67, 0x1F, 0x11, 0x00,
		0x00, 0x14,
	    /* 18-Byte Data Block #3 */
		/* Detailed Timing */
		0xEA, 0x24, 0x80, 0x78, 0x41, 0x84, 0x25, 0x30,
		0x20, 0x80, 0x24, 0x00, 0x43, 0xFC, 0x10, 0x00,
		0x00, 0x14,
	    /* 18-Byte Data Block #4 */
		/* Detailed Timing */
		0xBC, 0x34, 0x00, 0x98, 0x51, 0x00, 0x2A, 0x40,
		0x10, 0x90, 0x13, 0x00, 0x67, 0x1F, 0x11, 0x00,
		0x00, 0x1E,
	    /* Extension Block Count N */
		/* 0x00 */
		0x06,
	    /* Checksum C */
		/* 0x33 */
		0x2A,

	/* Extension Block Map #1 (Block 1) */

	    /* Extension Block Tag Number */
		0xF0,
	    /* Extension Block Tag Numbers for subsequent blocks */
		      0x40, 0x40, 0x40, 0x40, 0x10,
	    /* Unused Bytes */
		                                    0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Checksum */
		0x00,

	/* EXAMPLE 1: DI-EXT Extension Block */

	    /* General Information section */
		/* Block Header */
		0x40,
		/* DI-EXT Version Number */
		0x01,
	    /* Digital Interface section */
		/* Standard/Specification Supported */
		0x03,
		/* Version/Revision Number */
		0x41, 0x00, 0x00, 0x00,
		/* Data Format Description */
		0xD8, 0x48,
		/* Min, Max & Cross-Over Pixel Clock Frequency */
		0x19, 0xA5, 0x00, 0xA5, 0x00,
	    /* Display Device section */
		/* Sub-Pixel Layout & Shape */
		0x00, 0x02, 0x00,
		/* Dot/Pixel Pitch */
		0x1A, 0x00,
		/* Major Display Characteristics */
		0x28,
	    /* Display Capabilities & Feature Support Set */
		/* Miscellaneous Display Capabilities */
		0x80,
		/* Frame Rate Conversion */
		0x00, 0x00, 0x00, 0x00, 0x00,
		/* Display/Scan Orientation */
		0x42,
		/* Color/Luminance Coding Description */
		0x01, 0x00, 0x80, 0x00,
		/* Monitor Color Depth */
		0x00, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00,
		/* Aspect Ratio Conversion Modes */
		0x00,
		/* Packetized Digital Video Support Information */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Unused Bytes (Reserved) section */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00,
	    /* Audio Support (Reserved) section */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00,
	    /* Display Transfer Characteristic - Gamma */
		0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Miscellaneous Items */
		/* Checksum */
		0x59,

	/* EXAMPLE 2 (modified): DI-EXT Extension Block */

	    /* General Information section */
		/* Block Header */
		0x40,
		/* DI-EXT Version Number */
		0x01,
	    /* Digital Interface section */
		/* Standard/Specification Supported */
		0x02,
		/* Version/Revision Number */
		/* 0x41, 0x00, 0x00, 0x00, */
		0xC0, 0x0B, 0x08, 0x15,
		/* Data Format Description */
		0xD0, 0x24,
		/* Min, Max & Cross-Over Pixel Clock Frequency */
		0x19, 0x70, 0x00, 0x00, 0x00,
	    /* Display Device section */
		/* Sub-Pixel Layout & Shape */
		0x00, 0x00, 0x00,
		/* Dot/Pixel Pitch */
		0x00, 0x00,
		/* Major Display Characteristics */
		0xE4,
	    /* Display Capabilities & Feature Support Set */
		/* Miscellaneous Display Capabilities */
		0x09,
		/* Frame Rate Conversion */
		0x60, 0x70, 0x17, 0x00, 0x19,
		/* Display/Scan Orientation */
		0x43,
		/* Color/Luminance Coding Description */
		0x01, 0x00, 0x80, 0x00,
		/* Monitor Color Depth */
		0x00, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00,
		/* Aspect Ratio Conversion Modes */
		0xE0,
		/* Packetized Digital Video Support Information */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Unused Bytes (Reserved) section */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00,
	    /* Audio Support (Reserved) section */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00,
	    /* Display Transfer Characteristic - Gamma */
		0x6D,
		0x00, 0x01, 0x01, 0x02, 0x04, 0x05, 0x07, 0x08,
		0x09, 0x0B, 0x0E, 0x11, 0x16, 0x19, 0x1E, 0x23,
		0x29, 0x30, 0x38, 0x42, 0x4F, 0x5B, 0x7F, 0xA3,
		0xAF, 0xBC, 0xC5, 0xCE, 0xD4, 0xD8, 0xE0, 0xE5,
		0xE9, 0xED, 0xEF, 0xF3, 0xF5, 0xF6, 0xF8, 0xF9,
		0xFA, 0xFB, 0xFC, 0xFD, 0xFE,
	    /* Miscellaneous Items */
		/* Checksum */
		0xF5,

	/* EXAMPLE 3: DI-EXT Extension Block */

	    /* General Information section */
		/* Block Header */
		0x40,
		/* DI-EXT Version Number */
		0x01,
	    /* Digital Interface section */
		/* Standard/Specification Supported */
		0x00,
		/* Version/Revision Number */
		0x00, 0x00, 0x00, 0x00,
		/* Data Format Description */
		0x00, 0x00,
		/* Min, Max & Cross-Over Pixel Clock Frequency */
		0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Display Device section */
		/* Sub-Pixel Layout & Shape */
		0x01, 0x00, 0x03,
		/* Dot/Pixel Pitch */
		0x1E, 0x1E,
		/* Major Display Characteristics */
		0xA8,
	    /* Display Capabilities & Feature Support Set */
		/* Miscellaneous Display Capabilities */
		0x0C,
		/* Frame Rate Conversion */
		0x60, 0x70, 0x17, 0xE8, 0x12,
		/* Display/Scan Orientation */
		0x82,
		/* Color/Luminance Coding Description */
		0x01, 0x00, 0x80, 0x00,
		/* Monitor Color Depth */
		0x00, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00,
		/* Aspect Ratio Conversion Modes */
		0xE0,
		/* Packetized Digital Video Support Information */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Unused Bytes (Reserved) section */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00,
	    /* Audio Support (Reserved) section */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00,
	    /* Display Transfer Characteristic - Gamma */
		0x8A,
		0x00, 0x05, 0x0E, 0x23, 0x4F, 0xBC, 0xE0, 0xF3,
		0xFA, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x01, 0x06, 0x0F, 0x24, 0x50, 0xBB, 0xDF, 0xF2,
		0xF9, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x04, 0x0D, 0x22, 0x4E, 0xBD, 0xE1, 0xF4,
		0xFB, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Miscellaneous Items */
		/* Checksum */
		0x40,

	/* EXAMPLE 4: DI-EXT Extension Block */

	    /* General Information section */
		/* Block Header */
		0x40,
		/* DI-EXT Version Number */
		0x01,
	    /* Digital Interface section */
		/* Standard/Specification Supported */
		0x05,
		/* Version/Revision Number */
		0x80, 0x41, 0x00, 0x00,
		/* Data Format Description */
		0xDC, 0x24,
		/* Min, Max & Cross-Over Pixel Clock Frequency */
		0x19, 0x70, 0x00, 0x00, 0x00,
	    /* Display Device section */
		/* Sub-Pixel Layout & Shape */
		0x00, 0x02, 0x00,
		/* Dot/Pixel Pitch */
		0x1F, 0x00,
		/* Major Display Characteristics */
		0x26,
	    /* Display Capabilities & Feature Support Set */
		/* Miscellaneous Display Capabilities */
		0x01,
		/* Frame Rate Conversion */
		0x00, 0x00, 0x00, 0x00, 0x00,
		/* Display/Scan Orientation */
		0x42,
		/* Color/Luminance Coding Description */
		0x01, 0x03, 0x8F, 0xE0,
		/* Monitor Color Depth */
		0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		/* Aspect Ratio Conversion Modes */
		0xF0,
		/* Packetized Digital Video Support Information */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Unused Bytes (Reserved) section */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00,
	    /* Audio Support (Reserved) section */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00,
	    /* Display Transfer Characteristic - Gamma */
		0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00,
	    /* Miscellaneous Items */
		/* Checksum */
		0x53,

	/* Sample VTB-EXT Block */

	    /* Tag Label & Version Number */
		/* Block Header */
		0x10,
		/* Version Number */
		0x01,
	    /* Data Structure Layout */
		0x03, 0x06, 0x03,
	    /* Detailed Timing Blocks (DTB) */
		/* Detailed Timing Block #1 */
		0x64, 0x32, 0x00, 0x00, 0xF1, 0x60, 0x16, 0x90,
		0x20, 0x80, 0x4A, 0x00, 0xDD, 0x29, 0x11, 0x00,
		0x00, 0x1C,
		/* Detailed Timing Block #2 */
		0x54, 0x3D, 0x00, 0x78, 0xC0, 0x80, 0x28, 0x70,
		0x10, 0x40, 0xAC, 0x00, 0xDD, 0x29, 0x11, 0x00,
		0x00, 0x1C,
		/* Detailed Timing Block #3 */
		0xB8, 0x3D, 0x98, 0x78, 0x90, 0x00, 0x24, 0x60,
		0x10, 0x40, 0xA8, 0x00, 0xDD, 0x29, 0x11, 0x00,
		0x00, 0x1C,
	    /* Coordinated Video Timing (CVT) Descriptors */
		0xCF, 0x28, 0x21, 0x57, 0x28, 0x21, 0x1B, 0x28,
		0x21, 0x67, 0x18, 0x2C, 0x2B, 0x18, 0x2C, 0xEF,
		0x08, 0x2C,
	    /* Standard Timing (ST) Descriptors */
		0xB3, 0x3C, 0xA1, 0x3C, 0x7A, 0x3C,
	    /* Unused Bytes (Reserved) */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
	    /* Checksum */
		0x0A

};


/*
 * Select an EDID test case
 */
#if (FBC_EDID_TEST_DATA == 0)
	/*
	 * Examples: EDID Base block, Map Block, DI-EXT Blocks, VTB-EXT Block
	 */
	edid_data   = &fbc_edid_test_data_misc[0];
	edid_length = sizeof (fbc_edid_test_data_misc);
#elif (FBC_EDID_TEST_DATA == 1)
	/*
	 * EXAMPLE 1: Sample BASE EDID (Block 0) for an LCD Desktop IT Display
	 */
	edid_data   = &fbc_edid_test_data_ex1[0];
	edid_length = sizeof (fbc_edid_test_data_ex1);
#elif (FBC_EDID_TEST_DATA == 2)
	/*
	 * EXAMPLE 2: Sample BASE EDID & CEA861 Extension for a DTV Display
	 */
	edid_data   = &fbc_edid_test_data_ex2[0];
	edid_length = sizeof (fbc_edid_test_data_ex2);
#elif (FBC_EDID_TEST_DATA == 3)
	/*
	 * EXAMPLE 3: Sample BASE EDID & CEA861 Extension for an IT/DTV Display
	 */
	edid_data   = &fbc_edid_test_data_ex3[0];
	edid_length = sizeof (fbc_edid_test_data_ex3);
#endif

}


/* End of fbc_edid_data.h */
