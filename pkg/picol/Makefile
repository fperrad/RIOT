PKG_NAME = picol
PKG_URL = https://github.com/antirez/picol.git
PKG_VERSION = 6ac139137c57f580ddad74a1aa8cd24292bc86e4
PKG_LICENSE = MIT

include $(RIOTBASE)/pkg/pkg.mk

CFLAGS += -DPICOL_LIB
CFLAGS += -Wno-unused-parameter

all:
	$(MAKE) -C $(PKG_SOURCE_DIR) -f $(RIOTBASE)/Makefile.base
