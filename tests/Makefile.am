noinst_PROGRAMS=mysqltest

AM_CPPFLAGS=\
	-I$(top_srcdir)/src/include

AM_CFLAGS=

mysqltest_SOURCES=\
	mysqltest.c

mysqltest_LDFLAGS=\
	-dlopen self
mysqltest_LDADD=\
	$(top_builddir)/src/libmysqlstub.la \
	$(LIBLTDL)
