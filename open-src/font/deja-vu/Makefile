###############################################################################
#
# Deja Vu Fonts Makefile
#
# Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
# Use subject to license terms.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, and/or sell copies of the Software, and to permit persons
# to whom the Software is furnished to do so, provided that the above
# copyright notice(s) and this permission notice appear in all copies of
# the Software and that both the above copyright notice(s) and this
# permission notice appear in supporting documentation.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT
# OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
# HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL
# INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING
# FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
# NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
# WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
# 
# Except as contained in this notice, the name of a copyright holder
# shall not be used in advertising or otherwise to promote the sale, use
# or other dealings in this Software without prior written authorization
# of the copyright holder.
#
# @(#)Makefile	1.1	07/09/14
#

PWD:sh=pwd
TOP=$(PWD)/../..

# Version number (used in path names)
VERSION=2.19

# Source tarball
SOURCE_TARBALL_NAME=dejavu-ttf-$(VERSION).tar.bz2

# Download site for source
SOURCE_URL=$(SF_DOWNLOADS_URL)/dejavu/$(SOURCE_TARBALL_NAME)
SOURCE_URL_SET=yes

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES=		# None

# Directory created by unpacking source
SOURCE_DIR=$(BUILD_DIR)/dejavu-ttf-$(VERSION)

# What to build
BUILD_TARGETS=$(SOURCE_DIR)/fonts.scale

# Directory to install to
DEST_DIR=$(PROTODIR)$(TRUETYPE_DIR)

### Include common rulesets
include $(TOP)/common/Makefile.inc

### Rules specific to this directory:

DEJAVU_FONT_FILES= \
	DejaVuSans-Bold.ttf \
	DejaVuSans-BoldOblique.ttf \
	DejaVuSans-ExtraLight.ttf \
	DejaVuSans-Oblique.ttf \
	DejaVuSans.ttf \
	DejaVuSansCondensed-Bold.ttf \
	DejaVuSansCondensed-BoldOblique.ttf \
	DejaVuSansCondensed-Oblique.ttf \
	DejaVuSansCondensed.ttf \
	DejaVuSansMono-Bold.ttf \
	DejaVuSansMono-BoldOblique.ttf \
	DejaVuSansMono-Oblique.ttf \
	DejaVuSansMono.ttf \
	DejaVuSerif-Bold.ttf \
	DejaVuSerif-BoldItalic.ttf \
	DejaVuSerif-Italic.ttf \
	DejaVuSerif.ttf \
	DejaVuSerifCondensed-Bold.ttf \
	DejaVuSerifCondensed-BoldItalic.ttf \
	DejaVuSerifCondensed-Italic.ttf \
	DejaVuSerifCondensed.ttf

build_gen: $(BUILD_TARGETS)

$(SOURCE_DIR)/fonts.scale: $(UNPACK_TARGET)
	(cd $(SOURCE_DIR) && \
	 LD_LIBRARY_PATH=$(PROTODIR)$(X11_SERVERLIBS_DIR)$(ARCHLIBSUBDIR) \
	 $(PROTODIR)$(X11_DIR)/bin/mkfontscale . )

install_gen: $(BUILD_TARGETS)
	mkdir -p $(DEST_DIR)
	-( cd $(DEST_DIR) ; rm -f $(DEJAVU_FONT_FILES) DejaVuFontsCopyright.txt )
	( cd $(SOURCE_DIR) ; cp -p $(DEJAVU_FONT_FILES) $(DEST_DIR) )
	cp -p $(SOURCE_DIR)/LICENSE $(DEST_DIR)/DejaVuFontsCopyright.txt 
	touch $(DEST_DIR)/fonts.scale
	chmod +w $(DEST_DIR)/fonts.scale
	../merge-fonts.scale.pl -i $(DEST_DIR)/fonts.scale \
		-i $(SOURCE_DIR)/fonts.scale -o $(DEST_DIR)/fonts.scale