###############################################################################
#
# xlsfonts - utility to list X11 core protocol fonts available from an X server
#
# Copyright (c) 2008, 2015, Oracle and/or its affiliates. All rights reserved.
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
MODULE_NAME=xlsfonts

# Package metadata
MODULE_DESC = the xlsfonts utility to list X11 core protocol fonts available from an X server

# Version number (used in path names)
MODULE_VERSION=1.0.5

# Checksums for upstream tarball
TARBALL_MD5   = 6f5711bef8c765857a0887a91476283b
TARBALL_SHA1  = 4631ad287cecd4c8c3301fc10f6001d00d2e06ef
TARBALL_SHA256= 40295bec35077cee93be2e4c26cc00268ed6ace779ae6e97766a866c1e3927fa

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES = man.patch

# pkg(5) name we deliver the files in (override default)
MODULE_PKGNAME=x11/diagnostic/x11-info-clients
MODULE_PKGNAME_SET=yes

# ARC cases that covered this module
# PSARC/2008/178  xlsfonts update to X11R7
MODULE_ARC_CASES = PSARC/2008/178
# PSARC/2015/221 X11 application updates
MODULE_ARC_CASES += PSARC/2015/221

# Man pages to apply Sun footer to & attributes to list
SUNTOUCHED_MANPAGES = man/xlsfonts.man
MODULE_STABILITY=Committed

# Compatibility links from /usr/X11/bin to /usr/bin
MODULE_X11_BINCOMPAT_LINKS = xlsfonts

include ../Makefile.inc
