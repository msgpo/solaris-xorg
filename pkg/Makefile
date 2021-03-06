###############################################################################
#
# Makefile for X Consolidation packages
#
# Copyright (c) 2010, 2017, Oracle and/or its affiliates. All rights reserved.
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
###############################################################################
# Heavily inspired by / borrowed from the ON usr/src/pkg/Makefile
# Please read the comments in it and the accompanying README in ON for many
# details omitted here.
# Major differences in the X implementation:
# - X only supports building one repo, not redist + extra
# - X only supports building packages on the same platform as the binaries,
#	no cross-platform packaging
# - X has no bfu legacy to deal with
# - ON has all manifests in one directory, X splits into current & legacy
# - Integrates with X consolidation makefile/build system instead of ON's

PWD:sh=pwd
TOP=$(PWD)/..

### Include common definitions
include $(TOP)/open-src/common/Makefile.init

.SUFFIXES: .p5m .mog .dep .res .pub

# We don't yet support building packages cross-architecture, but would
# need this if we ever did.   (See "Cross platform packaging notes" in
# the ON usr/src/pkg/Makefile for what we'd have to do.)
PKGMACH = $(MACH)

# Map X makefile names to the ones used in the rules copied from ON
# More to be updated if we ever decide to support building cross-platform
PKGROOT = $(PROTODIR)
PKGDEST = $(PROTOTOP)/pkg_$(PKGMACH)

# Map the V=1 style of enabling more verbose build messages used in the
# X.Org/automake builds to the macro used in the rules copied from ON
#
# You can enable verbose output with either V=1 or PKGDEBUG=""
PKGDEBUG_V_0 = @
PKGDEBUG_V_1 = 
PKGDEBUG_V_ = $(PKGDEBUG_V_0)
PKGDEBUG = $(PKGDEBUG_V_$(V))

# Commands used in rules copied from ON
CP=             /usr/bin/cp -f
LN=             /usr/bin/ln
MV=             /usr/bin/mv -f
RM=             /usr/bin/rm -f
SED=	        /usr/bin/sed
TOUCH=          /usr/bin/touch

# Script to generate manifests from history file
NAWK=			/usr/bin/nawk
GENERATE_HISTORY=	$(PWD)/generate-history.awk
HISTORY=		$(PWD)/legacy/history

#
# To suppress package dependency generation on any system, regardless
# of how it was installed, set SUPPRESSPKGDEP=true in the build
# environment.
#
SUPPRESSPKGDEP= false


#
# The packages directory will contain the processed manifests as
# direct build targets and subdirectories for package metadata extracted
# incidentally during manifest processing.
#
# Nothing underneath $(PDIR) should ever be managed by SCM.
#
PDIR= build-$(PKGMACH)

$(PDIR):
	mkdir -p $@

#
# By default, PKGS will list all manifests.  To build and/or publish a
# subset of packages, override this on the command line or in the
# build environment and then reference (implicitly or explicitly) the all
# or install targets.
#
CURRENT_MANIFESTS :sh= (cd manifests; print *.p5m)
STATIC_LEGACY_MANIFESTS :sh= (cd legacy; print *.p5m)
GENERATED_LEGACY_MANIFESTS_cmd = \
    $(NAWK) -v FUNCTION=name -f $(GENERATE_HISTORY) < $(HISTORY)
GENERATED_LEGACY_MANIFESTS = $(GENERATED_LEGACY_MANIFESTS_cmd:sh)
LEGACY_MANIFESTS = $(STATIC_LEGACY_MANIFESTS) $(GENERATED_LEGACY_MANIFESTS)
MANIFESTS = $(CURRENT_MANIFESTS) $(LEGACY_MANIFESTS)
PKGS= $(MANIFESTS:%.p5m=%)

#
# Track the synthetic manifests separately so we can properly express
# build rules and dependencies.  The synthetic and real packages use
# different sets of transforms and macros for pkgmogrify.
#
SYNTH_PKGS= X-incorporation
SYNTH_MANIFESTS = $(SYNTH_PKGS:%=%.p5m)

# Special manifest for exceptions to pass to pkglint & validate_pkg
EXCEPTION_MANIFESTS = exceptions-validate_pkg.p5m

# Manifests are in either manifests or legacy directory - merge in $(PDIR)
$(PDIR)/%.p5m: manifests/%.p5m
	$(PKGDEBUG)$(LN) -s ../$< $@

$(PDIR)/%.p5m: legacy/%.p5m
	$(PKGDEBUG)$(LN) -s ../$< $@

$(PDIR)/%.p5m: %.p5m
	$(PKGDEBUG)$(LN) -s ../$< $@

$(GENERATED_LEGACY_MANIFESTS:%=$(PDIR)/%): $(HISTORY)
	$(PKGDEBUG)$(NAWK) -v TARGET=$(@F) -v FUNCTION=manifest \
	    -f $(GENERATE_HISTORY) < $(HISTORY) | $(PKGFMT) > $@

ALL_MANIFEST_SRCS = $(MANIFESTS) $(SYNTH_MANIFESTS) $(EXCEPTION_MANIFESTS)
ALL_MANIFESTS = $(ALL_MANIFEST_SRCS:%=$(PDIR)/%)
manifests: $(ALL_MANIFESTS)
$(ALL_MANIFESTS): $(PDIR)

### Additional metadata generation

$(PROTOMETA)/%/:
	$(PKGDEBUG)mkdir -p $@

# Generate default copyright notice for packages without contents
$(PROTOMETA)/%/cr_Oracle: $(PDIR)/%.p5m $(PROTOMETA)/%/
	$(PKGDEBUG)gsed -n -e '/# Copyright .* Oracle/ {' \
	 -e 's/^# //' -e 'p' -e 'q' -e'}' $< > $@

SYNTH_LICENSES = $(SYNTH_PKGS:%=$(PROTOMETA)/%/cr_Oracle)

# This should eventually move into pkg publication

FONT_MANIFESTS :sh= (cd manifests; print system-font-*.p5m)
FONT_METADATA = $(FONT_MANIFESTS:%.p5m=$(PDIR)/%.font)
FONT_ATTRS = $(FONT_MANIFESTS:%.p5m=$(PDIR)/%.attr)

$(FONT_ATTRS): $(FONT_METADATA)

FONT_LIBS_PATH=$(PROTODIR)$(X11_SERVERLIBS_DIR)$(LIBSUBDIR_64):$(PROTODIR)/usr/lib$(LIBSUBDIR_64)

$(PDIR)/%.font: $(PDIR)/%.p5m
	@print "## Generating font metadata in $(@F)"
	$(PKGDEBUG)$(RM) $(@)
	$(PKGDEBUG)LD_LIBRARY_PATH=$(FONT_LIBS_PATH) \
		$(PERL) generate_font_metadata.pl \
		-p $(PROTODIR) -m $< > $@ || ( rm $@ ; exit 1 )

### Manifest mogrification

PKGMOGRIFY = pkgmogrify

# The PKGVERS_BRANCH is determined by the values in the Makefile.buildnum
# PSARC 2017/082 for package version scheme
include Makefile.buildnum
PKGVERS_BRANCH_MAIN = 11.$(UPDATENUM).$(SRUNUM).$(ORDERNUM).$(PLATNUM)
PKGVERS_BRANCH = $(PKGVERS_BRANCH_MAIN).$(BUILDID).$(NIGHTLYID)

# Generate pkgmogrify transform file with correct build version info in
# Build number is derived from last nv_XXX tag in hg log
$(PDIR)/versions: transforms/versions.tmpl $(PDIR)
	@print "## Substituting build info in versions transformation template"
	$(PKGDEBUG) HG_ID="$$(hg id)" ; \
	$(PERL) -p -e "s{_PKGVERS_BRANCH_}{$(PKGVERS_BRANCH)};" \
		-e "s{_HG_ID_}{$${HG_ID}}" transforms/versions.tmpl > $@

# Set variables used by pkgmogrify 
# These are the macros that may be used in package manifests
PKGMOG_DEFINES = 

# Most upstream packages provide specific version numbers instead of using
# the default of $(OSPKGVERS)
# Some use $(X11PKGVERS) to refer to the X11 katamari version since they
# bundle together components from multiple upstream packages with individual
# version numbers
PKGMOG_DEFINES += X11PKGVERS=7.7
PKGMOG_DEFINES += OSPKGVERS=11.$(UPDATENUM)

# Base URL for ARC cases used in opensolaris.arc_url metadata
PKGMOG_DEFINES += ARC_URL='http://arc.opensolaris.org/caselog/'

# Platform specific choices
PKGMOG_DEFINES += i386_ONLY=$(POUND_SIGN) sparc_ONLY=$(POUND_SIGN)
PKGMOG_DEFINES += $(PKGMACH)_ONLY= 

# Architecture specific directory names
PKGMOG_DEFINES += ARCH=$(PKGMACH)
PKGMOG_DEFINES += ARCH32=$(SUBDIR32_$(PKGMACH))
PKGMOG_DEFINES += ARCH64=$(SUBDIR64_$(PKGMACH))

# Perl version string used in package names, such as pkg:/runtime/perl-512
PERL_PKG_VERSION_CMD = print $(PERL_VERSION) | tr -d '.'
PKGMOG_DEFINES += PERL_PKG_VERSION=$(PERL_PKG_VERSION_CMD:sh)

# Python version string used in path names, such as /usr/lib/python2.6
PKGMOG_DEFINES += PYTHON_PATH_VERSION=$(PYTHON_VERSION)
# Python version string used in package names, such as pkg:/runtime/python-26
PYTHON_PKG_VERSION_CMD = print $(PYTHON_VERSION) | tr -d '.'
PKGMOG_DEFINES += PYTHON_PKG_VERSION=$(PYTHON_PKG_VERSION_CMD:sh)

# automake version needed for build dependencies
AUTOMAKE_PKG_VERSION_CMD = print $(AUTOMAKE_VERSION) | tr -d '.'
PKGMOG_DEFINES += AUTOMAKE_PKG_VERSION=$(AUTOMAKE_PKG_VERSION_CMD:sh)

# gcc version needed for build dependencies
GCC_PKG_VERSION_CMD = print $(GCC_VERSION) | tr -d '.'
PKGMOG_DEFINES += GCC_PKG_VERSION=$(GCC_PKG_VERSION_CMD:sh)

PROC_PKGS = $(PKGS:%=$(PDIR)/%.mog)
PROC_CURRENT_PKGS = $(CURRENT_MANIFESTS:%.p5m=$(PDIR)/%.mog)
PROC_LEGACY_PKGS = $(LEGACY_MANIFESTS:%.p5m=$(PDIR)/%.mog)
PROC_SYNTH_PKGS = $(SYNTH_MANIFESTS:%.p5m=$(PDIR)/%.mog)
PROC_EXCEPTIONS = $(EXCEPTION_MANIFESTS:%.p5m=$(PDIR)/%.mog)

# Default transformations to apply
PM_TRANSFORMS = $(PKG_BRANDING_TRANSFORMS) \
		common_actions publish restart_fmri facets \
		$(PDIR)/versions
PM_INC = transforms

# Additional transforms for specific types of packages
$(PROC_CURRENT_PKGS) $(PROC_SYNTH_PKGS) $(PROC_EXCEPTIONS) := \
	EXTRA_TRANSFORMS = defaults

mogrify: $(PROC_PKGS) $(PROC_EXCEPTIONS)
$(PROC_PKGS) $(PROC_SYNTH_PKGS): $(PDIR)/versions

# Combine & uniq metadata & license attributes generated during build
$(PDIR)/%.attr:
	@print "## Gathering metadata from build for $(@F)"
	$(PKGDEBUG)case '$(@F)' in \
		system-font-*) ADDITIONAL_ATTRS="$(@:%.attr=%.font)" ;; \
	esac ; \
	$(PERL) merge-metadata.pl $${ADDITIONAL_ATTRS} \
		~(N)$(PROTOMETA)/$(@F:.attr=)/attributes_*.p5m \
		~(N)$(PROTOMETA)/$(@F:.attr=)/license_*.p5m /dev/null > $@

$(PDIR)/%.mog: $(PDIR)/%.p5m $(PDIR)/%.attr
	@print "## Processing manifest $(@F:.mog=.p5m)"
	$(PKGDEBUG)$(RM) $(@) $(@:%.mog=%) \
		$(@:%.mog=%.metadata.*) $(@:%.mog=%.synth)
	$(PKGDEBUG)$(PKGMOGRIFY) $(PKGMOG_VERBOSE) $(PM_INC:%= -I %) \
		$(PKGMOG_DEFINES:%=-D %) -O $(@) \
		$(@:%.mog=%.p5m) $(@:%.mog=%.attr) \
		$(PM_TRANSFORMS) $(EXTRA_TRANSFORMS)
	$(PKGDEBUG)$(TOUCH) $(@)

# List of all packages we build, used in open source code release zip files
$(TOP)/pkglist.txt:
	@print "## Generating pkglist.txt"
	$(PKGDEBUG)$(PKGMOGRIFY) $(PKGMOG_VERBOSE) $(PM_INC:%= -I %) \
		$(PKGMOG_DEFINES:%=-D %) -O /dev/null \
		-I manifests -I legacy $(ALL_MANIFEST_SRCS) extract_names \
		| LC_ALL=C sort -u > $(@)

### Dependency detection

# Package manifest containing list of packages to use in dependency
# resolution, and not containing any dependencies to be detected/resolved.
DEP_LIST_PKG = developer-opensolaris-X

DEP_PKGS= $(PKGS:%=$(PDIR)/%.dep)
DEP_CURRENT_PKGS_1 = $(CURRENT_MANIFESTS:%.p5m=$(PDIR)/%.dep)
DEP_CURRENT_PKGS = $(DEP_CURRENT_PKGS_1:$(PDIR)/$(DEP_LIST_PKG).dep=)
DEP_LEGACY_PKGS = $(LEGACY_MANIFESTS:%.p5m=$(PDIR)/%.dep)
DEP_LEGACY_PKGS += $(DEP_LIST_PKG:%=$(PDIR)/%.dep)
DEP_SYNTH_PKGS = $(SYNTH_MANIFESTS:%.p5m=$(PDIR)/%.dep)

PKGDEP_TOKENS_i386= \
	'PLATFORM=i86hvm' \
	'PLATFORM=i86pc' \
	'PLATFORM=i86xpv' \
	'ISALIST=amd64' \
	'ISALIST=i386'
PKGDEP_TOKENS_sparc= \
	'PLATFORM=sun4u' \
	'PLATFORM=sun4v' \
	'ISALIST=sparcv9' \
	'ISALIST=sparc'
PKGDEP_TOKENS= $(PKGDEP_TOKENS_$(PKGMACH))

$(PDIR)/%.dep: $(PDIR)/%.mog
	@print "## Generating dependencies for $(<F)"
	$(PKGDEBUG)$(RM) $(@)
	$(PKGDEBUG)if [[ "$(SUPPRESSPKGDEP)" != "true" ]]; then \
		pkgdepend generate -m $(PKGDEP_TOKENS:%=-D %) $(<) \
			$(PKGROOT) > $(@); \
	else \
		$(CP) $(<) $(@); \
	fi

$(DEP_SYNTH_PKGS) $(DEP_LEGACY_PKGS): $$(@:%.dep=%.mog)
	@print "## Skipping dependency generation for $(@F:%.dep=%)"
	$(PKGDEBUG)$(CP) $(@:%.dep=%.mog) $(@)

### Dependency resolution

DEP_RES_PKGS = $(DEP_PKGS:%=%.res)
DEP_RES_CURRENT_PKGS = $(DEP_CURRENT_PKGS:%=%.res)
DEP_RES_LEGACY_PKGS = $(DEP_LEGACY_PKGS:%=%.res)
DEP_RES_SYNTH_PKGS = $(DEP_SYNTH_PKGS:%=%.res)

PKGDEP_VERBOSE_FLAG_0 =
PKGDEP_VERBOSE_FLAG_1 = -v
PKGDEP_VERBOSE_FLAG = $(PKGDEP_VERBOSE_FLAG_$(V))

# Root of pkg image to use for dependency resolution
# Normally / on the machine used to build the binaries
PKGDEP_RESOLVE_IMAGE = /

# File listing packages to consider in dependency resolution.
# Automatically generated from the developer package to ensure they
# stay in sync.
PKGDEP_RESOLVE_LIST = $(PDIR)/resolve.deps

$(PKGDEP_RESOLVE_LIST): $(PDIR)/$(DEP_LIST_PKG).mog
	@print "## Generating package list for dependency resolution"
	$(PKGDEBUG)$(PKGMOGRIFY) $(PKGMOG_VERBOSE) $(PM_INC:%= -I %) \
	    -O /dev/null -P $(@) $(PDIR)/$(DEP_LIST_PKG).mog extract_depends

# This rule resolves dependencies across all manifests for packages
# currently delivering files.
$(PDIR)/gendeps: $(DEP_CURRENT_PKGS) $(PKGDEP_RESOLVE_LIST)
	$(PKGDEBUG)if [[ "$(SUPPRESSPKGDEP)" = "true" ]]; then \
		print "## Suppressing dependency resolution"; \
		for p in $(DEP_CURRENT_PKGS:%.dep=%); do \
			$(CP) $$p.dep $$p.dep.res; \
		done; \
	else \
		print "## Resolving dependencies"; \
		pkgdepend -R $(PKGDEP_RESOLVE_IMAGE) resolve -E \
		    $(PKGDEP_VERBOSE_FLAG) -e $(PKGDEP_RESOLVE_LIST) \
		    -m $(DEP_CURRENT_PKGS) ; \
	fi
	$(PKGDEBUG)$(TOUCH) $(@)

gendeps: $(PDIR)/gendeps
$(DEP_RES_CURRENT_PKGS): $(PDIR)/gendeps

$(DEP_RES_SYNTH_PKGS) $(DEP_RES_LEGACY_PKGS): $$(@:%.dep.res=%.dep)
	@print "## Skipping dependency generation for $(@F:%.dep.res=%)"
	$(PKGDEBUG)$(CP) $(@:%.dep.res=%.dep) $(@)

# Post-processing of manifests after dependency resolution
RES_PKGS = $(PKGS:%=$(PDIR)/%.res)
RES_CURRENT_PKGS = $(CURRENT_MANIFESTS:%.p5m=$(PDIR)/%.res)
RES_LEGACY_PKGS = $(LEGACY_MANIFESTS:%.p5m=$(PDIR)/%.res)
RES_SYNTH_PKGS = $(SYNTH_MANIFESTS:%.p5m=$(PDIR)/%.res)

POST_TRANSFORMS = post-pkgdepend extract_metadata
$(PDIR)/%.res: $(PDIR)/%.dep.res
	@print "## Post-processing manifest for $(@F:%.res=%)"
	$(PKGDEBUG)if [[ -s $< ]] ; then \
		$(PKGMOGRIFY) $(PKGMOG_VERBOSE) $(PM_INC:%= -I %) \
		 -O $@ -P $(@:%.res=%.synth) $< $(POST_TRANSFORMS) ; \
	else \
		$(CP) $< $@ ; \
	fi

# Generate info for synthetic manifests
$(RES_SYNTH_PKGS): $(RES_PKGS) $$(@:%.res=%.dep.res)
	@print "## Gathering package lists for synthetic package $(@F:%.res=%)"
	$(PKGDEBUG)$(PKGMOGRIFY) $(PKGMOG_VERBOSE) $(PM_INC:%= -I %) \
		-O $(@) -P $(@:%.res=%.synth.sed) \
		$(@:%.res=%.dep.res) synthetic
	$(PKGDEBUG)$(SED) -n -f $(@:%.res=%.synth.sed) $(PDIR)/*.synth >> $(@)


### pkglint checking (pre-publication)

PKGLINT = pkglint
PKGLINTRC = prepub-pkglintrc

#
# This rule runs pkglint across all manifests to be published.
#
# We require that packages be free from lint ERRORs before allowing them
# to be published.  Lint WARNINGs are acceptable (though unpleasant)
# The list of packages is the list of packages that did not resolve to
# 0-byte files, $CHECK_PKGS
#
$(PDIR)/checkmf: $(PDIR)/gendeps $(DEP_SYNTH_PKGS) $(DEP_PKGS)
	@print "## Checking packages"
	@$(RM) $@
	@$(TOUCH) $(PDIR)/pkglint-output.txt
	-$(PKGDEBUG)for p in $(DEP_SYNTH_PKGS:%.dep=%) $(DEP_PKGS:%.dep=%); do \
		if [[ -s $$p.res ]]; then \
			CHECK_PKGS="$$p.res $${CHECK_PKGS}"; \
		fi; \
	done; \
	if [[ -n "$${CHECK_PKGS}" ]]; then \
		$(PKGLINT) -f $(PKGLINTRC) $${CHECK_PKGS} $(PROC_EXCEPTIONS) \
		    2> $(PDIR)/pkglint-output.txt; \
	fi ; \
	if grep '^ERROR' $(PDIR)/pkglint-output.txt; then \
		return 1; \
	fi
	@$(TOUCH) $@

### Repo setup

PKGPUBLISHER = nightly

# Initialize the empty on-disk repositories
$(PKGDEST):
	@print "## Initializing $(@F)"
	$(PKGDEBUG)pkgrepo create --version 4 $(@)
	$(PKGDEBUG)pkgrepo add-publisher -s $(@) $(PKGPUBLISHER)

clean-repo:
	$(RM) -r $(PKGDEST)

### Package publication to repo
PUB_PKGS = $(SYNTH_PKGS:%=$(PDIR)/%.pub) $(PKGS:%=$(PDIR)/%.pub)
PUB_SYNTH_PKGS = $(SYNTH_MANIFESTS:%.p5m=$(PDIR)/%.pub)
publish_pkgs: $(PKGDEST) $(PDIR)/gendeps $(PDIR)/checkmf $(PUB_PKGS)

$(PUB_PKGS): $(PKGDEST) $(PDIR)/gendeps $(PDIR)/checkmf

$(PDIR)/%.pub: $(PKGDEST) $(PDIR)/gendeps $(PDIR)/%.res
	$(PKGDEBUG) if [ -s $(@:%.pub=%.res) ]; then \
		print "## Publishing $(@F:%.pub=%) to proto repository"; \
		pkgsend -s $(PKGDEST) publish -d $(PKGROOT) \
		    -d $(PROTOMETA)/$(@F:%.pub=%) \
		    --fmri-in-manifest --no-index --no-catalog -T '*.py' \
		    $(@:%.pub=%.res) > /dev/null; \
	fi; \
	$(TOUCH) $(@)

$(PUB_SYNTH_PKGS): $(SYNTH_LICENSES)

### Repo finalization

install: repository-metadata
default: install

repository-metadata: $(PUB_PKGS)
	@print "## Creating repository metadata"
	$(PKGDEBUG)pkgrepo refresh -s $(PKGDEST)

### pkglint checking (post-publication)

LINT_PKGLINTRC = postpub-pkglintrc

#
# Perform a pkglint run on the published repositories.  We remove package
# version information from the lint output so that it is comparable across
# lint runs.
#
lint:
	@print "## Running pkglint on the $(PKGPUBLISHER) repository"
	-$(PKGDEBUG)$(PKGLINT) -f $(LINT_PKGLINTRC) \
	    -l file://$(PKGDEST) -c /tmp/pkglint_cache.$$$$ \
	    $(PKGLINT_REFERENCE_REPO:%=-r %) \
	    > $(PDIR)/pkglint.out 2> $(PDIR)/pkglint.lint ; \
	grep '^Error:' $(PDIR)/pkglint.out ; \
	$(RM) -rf /tmp/pkglint_cache.$$$$
	$(PKGDEBUG)$(SED) -e 's/@[0-9TZ.:,-]*//g' $(PDIR)/pkglint.lint

### Overall rules

all: $(PROC_PKGS) $(PROC_SYNTH_PKGS) $(DEP_PKGS) $(DEP_SYNTH_PKGS) \
	$(PDIR)/gendeps

clean:
	-$(RM) -r $(PDIR)

clobber: clean clean-repo

.PARALLEL: $(PKGS) $(PROC_PKGS) $(DEP_PKGS) \
	$(PROC_SYNTH_PKGS) $(DEP_SYNTH_PKGS) $(PUB_PKGS)

#
# rules to validate proto area against manifests, and check for safe
# file permission modes
#

EXCEPTIONS= $(PWD)/../exception_lists/packaging $(PDIR)/generated-exceptions

# Automatically exclude all pkg-config uninstalled.pc files, since those
# should never be packaged
$(PDIR)/generated-exceptions:
	$(PKGDEBUG)(cd $(PKGROOT) ; find . -name '*-uninstalled.pc') > $@

protocmp: $(PROC_PKGS) $(EXCEPTIONS) $(PROC_EXCEPTIONS) fix_perms
	$(PKGDEBUG)validate_pkg -a $(PKGMACH) -v $(EXCEPTIONS:%=-e %) \
		-m $(PDIR) -p $(PKGROOT) || true

pmodes: $(PROC_PKGS) fix_perms
	$(PKGDEBUG)validate_pkg -a $(PKGMACH) -M -m $(PDIR)

check-pkgfmt: $(ALL_MANIFESTS)
	@print "## Checking for manifests not in pkgfmt expected form"
	$(PKGDEBUG)$(PKGFMT) -c $(ALL_MANIFESTS) || true
	@print ""

check: protocmp pmodes lint check-pkgfmt

# Instead of fixing all the upstream packages to follow our permission rules
# just fix the files in these subdirs of the proto area to match our rules.
FIX_PERMS_IN = /usr /lib /etc/X11 /etc/fonts /etc/hal

fix_perms: 
	@print "## Fixing proto area permissions"
	$(PKGDEBUG)find $(FIX_PERMS_IN:%=$(PKGROOT)%) -type f -exec chmod a-w \{\} \+

# Nothing to do for "make source", but avoid error when run at top-level
source:
	@true
