#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libmysqlloader],[0.0.0],[vincentdm@gmail.com])
AC_CONFIG_HEADERS([src/config.h])

AM_INIT_AUTOMAKE([foreign subdir-objects])
# Checks for programs.
AC_PROG_CC


LT_INIT
LT_CONFIG_LTDL_DIR([libltdl])
LTDL_INIT
# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([ltdl.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_SEARCH_LIBS([lt_dlopen], [ltdl])

AC_CONFIG_FILES([Makefile
                 libltdl/Makefile
                 src/Makefile
                 tests/Makefile
                 src/include/Makefile])
AC_OUTPUT
echo \
"-------------------------------------------------

 ${PACKAGE_NAME} Version ${PACKAGE_VERSION}

 Prefix: '${prefix}'.
 Compiler: '${CC} ${CFLAGS} ${CPPFLAGS}'
 Libraries: '${LIBS}'"
