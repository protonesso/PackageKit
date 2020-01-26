AM_CFLAGS = \
	$(PK_PLUGIN_CFLAGS) \
	$(NEKO_CFLAGS) \
	$(WARNINGFLAGS_C) \
	-DG_LOG_DOMAIN=\"PackageKit-Neko\" \
	-DSYSCONFDIR=\""$(sysconfdir)"\" \
	-DLOCALSTATEDIR=\""$(localstatedir)"\" \
	-DLIBDIR=\""$(libdir)"\"

AM_CPPFLAGS = \
	$(PK_PLUGIN_CFLAGS) \
	$(NEKO_CFLAGS) \
	$(WARNINGFLAGS_CPP) \
	-DG_LOG_DOMAIN=\"PackageKit-Neko\" \
	-DSYSCONFDIR=\""$(sysconfdir)"\" \
	-DLOCALSTATEDIR=\""$(localstatedir)"\" \
	-DLIBDIR=\""$(libdir)"\"

plugindir = $(PK_PLUGIN_DIR)
plugin_LTLIBRARIES = libpk_backend_neko.la
libpk_backend_neko_la_SOURCES = \
	pk-backend-neko.cc \
	utils.cc \
	pkgtools.cc \
	nekopkg.cc \
	dl.cc \
	job.cc
libpk_backend_neko_la_LIBADD = \
	-lbz2 \
	$(PK_PLUGIN_LIBS) \
	${NEKO_LIBS}
libpk_backend_neko_la_LDFLAGS = -module -avoid-version
libpk_backend_neko_la_CFLAGS = $(AM_CFLAGS)
libpk_backend_neko_la_CPPFLAGS = $(AM_CPPFLAGS)

noinst_LIBRARIES = libpk-backend-neko.a
libpk_backend_neko_a_SOURCES = \
	pk-backend-neko.cc \
	utils.cc \
	pkgtools.cc \
	nekopkg.cc \
	dl.cc \
	job.cc
libpk_backend_neko_a_CPPFLAGS = $(AM_CPPFLAGS)

confdir = $(sysconfdir)/PackageKit
conf_in_files = neko.conf.in
conf_DATA = $(conf_in_files:.conf.in=.conf)

$(conf_DATA): $(conf_in_files) Makefile
	@sed -e "s|\@pkgmain\@|$(NEKO_PKGMAIN)|" $< > $@

databasedir = $(localstatedir)/cache/PackageKit/metadata
database_DATA =	metadata.db

EXTRA_DIST = \
	$(conf_in_files) \
	$(database_DATA)

CLEANFILES = *.a

clean-local:
	rm -f *~
	rm -f $(CLEANFILES)

-include $(top_srcdir)/git.mk
