###############################################################################
#
# Droid Fonts Makefile
#
# Copyright (c) 2009, 2013, Oracle and/or its affiliates. All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice (including the next
# paragraph) shall be included in all copies or substantial portions of the
# Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
#

# Package name used in tarballs
MODULE_NAME=google-droid-fonts

# Package metadata
UPSTREAM	= Google Android
UPSTREAM_URL	= http://www.droidfonts.com/
UPSTREAM_SET	= yes

MODULE_LICENSE          = Apache License, Version 2.0
MODULE_LICENSE_SET      = yes
MODULE_DESC		= the Droid font families
ORACLE_TPNO		= 12030

# Version number (used in path names)
MODULE_VERSION=2013.06.07

# Checksums for upstream tarball
TARBALL_MD5   = 05d2a6da4cacf5b294d65ea981861cf8
TARBALL_SHA1  = 50f649133d0f75b889058261f625ae14e89fa09f
TARBALL_SHA256= 61bb7b67050efcdbf5d434085c9cbe7570ed31d97a5ffa920401132bde0f07b1

# Source tarball
SOURCE_TARBALL_NAME=$(SOURCE_DIRNAME).tar.xz
SOURCE_TARBALL_NAME_SET=yes

# Download site for source
# Upstream doesn't have a stable download tarball, so we use our mirror
# to get consistent checksums - updates will come from snapshot of
# https://android.googlesource.com/platform/frameworks/base.git
# via "make upstream" target below
SOURCE_URL=http://dlc.sun.com/osol/x/downloads/mirrors/$(SOURCE_TARBALL_NAME)
SOURCE_URL_SET=yes

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES=		# None

# License file
LICENSE_FILE=NOTICE
LICENSE_FILE_SET=yes

TTF_FONT_FILES = \
    $(LICENSE_FILE)		\
    *.ttf

TTF_SUBDIR=google-droid
TTF_SUBDIR_SET=yes

### Include common rulesets
include ../Makefile.ttf

# Download latest sources from upstream & make new tarball
upstream:
	/bin/bash ./getdroid.sh
