###############################################################################
#
# xman - manual page browser
#
# Copyright (c) 2008, 2016, Oracle and/or its affiliates. All rights reserved.
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
MODULE_NAME=xman

# Version number (used in path names)
MODULE_VERSION=1.1.4

# Checksums for upstream tarball
TARBALL_MD5   = f9ac24d44ccdd6978d3a2c57e8746a8a
TARBALL_SHA1  = b64516dab2b1c407b28ce3822a98b93178e29f02
TARBALL_SHA256= b3fa9d2e3f3745c529eb0b6ee4f0e00d936457d11e5221b2efad06ff7c84df29

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES = 6708109.patch,-p1
SOURCE_PATCHES += groff.patch,-p1

# Man pages to apply Sun footer to & attributes to list
SUNTOUCHED_MANPAGES=man/xman.man
MODULE_STABILITY=Committed

MODULE_ADD_INSTALL_TARGETS = install_po

# Compatibility links from /usr/X11/bin to /usr/bin
MODULE_X11_BINCOMPAT_LINKS = xman

include ../Makefile.inc

install_po:
	mkdir -p $(PROTODIR)$(MODULE_LC_MESSAGES_DIR)
	ginstall -m 0444 xman.po $(PROTODIR)$(MODULE_LC_MESSAGES_DIR)
