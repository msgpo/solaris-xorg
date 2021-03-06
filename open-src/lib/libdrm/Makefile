#
# Copyright (c) 2006, 2016, Oracle and/or its affiliates. All rights reserved.
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
MODULE_NAME=libdrm

# Package metadata
UPSTREAM	= Direct Rendering Infrastructure project
UPSTREAM_URL	= http://dri.freedesktop.org/
UPSTREAM_SET	= yes
# update to 2.4.67 covered by X mass TPNO
ORACLE_TPNO	= 22887

# Version number (used in path names)
MODULE_VERSION=2.4.67

# Checksums for upstream tarball
TARBALL_MD5  = b844c6af34e613ebf52f80b3cd8d7055
TARBALL_SHA1 = 21d43437219ddd1e409fb4b7d77254cd129e8075
TARBALL_SHA256 = ee5b71e1113be37544d0752681c12f040c01f782e2933df7d7bc21fd0d10cebe

# Library name (used for specfiles/mapfiles)
LIBNAME=drm

# Download site for source
SOURCE_URL=http://dri.freedesktop.org/libdrm/$(SOURCE_TARBALL_NAME)
SOURCE_URL_SET=yes
GIT_URL=$(FDO_GIT_URL)/mesa/drm
GIT_URL_SET=yes

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES += solaris-drm-port.patch
SOURCE_PATCHES += includes.patch,-p1
SOURCE_PATCHES += atomic.patch

# Need to use GNU Make to build
MODULE_MAKE=$(GNUMAKE)
MODULE_MAKE_SET=yes

# Need to build with gcc
MODULE_COMPILER=gcc
MODULE_COMPILER_SET=yes

# Command line options to GNU autoconf configure script
MODULE_CONFIG_OPTS = --enable-libkms --disable-nouveau \
		--disable-amdgpu

# Cos of 23185711 - disable parfait temporarily
USE_PARFAIT = no

AUTORECONF=yes

# Man pages to apply Sun footer to & attributes to list
#SUNTOUCHED_MANPAGES=*.man
MODULE_STABILITY = Volatile
LIB_MAN_SUFFIX = 3
MODULE_MTLEVEL=Unknown
MODULE_MTLEVEL_SET=yes
MODULE_PKGCONFIG_MAN=libdrm
MODULE_PKGCONFIG_MAN_SET=yes

# pkg-config files that need to be updated
FIX_PC_FILES=libdrm.pc.in intel/libdrm_intel.pc.in libkms/libkms.pc.in \
	radeon/libdrm_radeon.pc.in

# Where to install files
MODULE_ADD_LIB_SUBDIR = $(X11_SERVERLIBS_SUBDIR)
MODULE_LDFLAGS = -R $(MODULE_FULLARCH_LIB_DIR)
MODULE_PKGCONFIG_DIR = $(PKGCONFIG_DIR)
MODULE_PKGCONFIG_DIR_SET = yes

include ../Makefile.inc

install: $(PROTODIR)/usr/include/drm

$(PROTODIR)/usr/include/drm:
	@rm -f $@
	ln -s libdrm $@

install-gen: install_fixed_manpages

# Need to apply suntouch changes to man pages generated during build
MANDIR = $(PROTODIR)$(MODULE_MAN_DIR)
install_fixed_manpages: default_install
	$(PERL) $(TOP)/open-src/common/suntouch-manpages.pl \
		$(SUNTOUCH_MAN_FLAGS) $(BUILD_DIR)/man/*.{3,7}
	ginstall -m 0444 $(BUILD_DIR)/man/*.3 $(MANDIR)/man3
	ginstall -m 0444 $(BUILD_DIR)/man/*.7 $(MANDIR)/man7
