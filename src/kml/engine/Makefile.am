AM_CPPFLAGS= -I$(top_srcdir)/src \
	     -I$(top_srcdir)/third_party/boost_1_34_1 \
	     -I$(top_srcdir)/third_party/zlib-1.2.3/contrib

if GCC
AM_CXXFLAGS = -Wall -Werror -ansi -pedantic -fno-rtti
endif

lib_LTLIBRARIES = libkmlengine.la
libkmlengine_la_SOURCES = \
	clone.cc \
	feature_visitor.cc \
	find.cc \
	get_links.cc \
	href.cc \
	kml_file.cc \
	kmz_file.cc \
	location_util.cc \
	merge.cc \
	style_merger.cc \
	style_resolver.cc

libkmlengine_la_LIBADD = \
	$(top_builddir)/third_party/libminizip.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

libkmlengineincludedir = $(includedir)/kml/engine
libkmlengineinclude_HEADERS = \
	bbox.h \
	clone.h \
	feature_visitor.h \
	find.h \
	get_links.h \
	href.h \
	kml_file.h \
	kmz_file.h \
	location_util.h \
	merge.h \
	object_id_parser_observer.h \
	shared_style_parser_observer.h \
	style_merger.h \
	style_resolver.h

if HAVE_CPPUNIT
DATA_DIR = $(top_srcdir)/testdata
TESTS = kml_file_test \
	bbox_test \
	clone_test \
	feature_visitor_test \
	find_test \
	get_links_test \
	href_test \
	kmz_file_test \
	location_util_test \
	merge_test \
	object_id_parser_observer_test \
	shared_style_parser_observer_test \
	style_merger_test \
	style_resolver_test

check_PROGRAMS = $(TESTS)

# Unit tests for KML Engine

bbox_test_SOURCES = bbox_test.cc
bbox_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
bbox_test_LDFLAGS = $(CPPUNIT_LIBS)

clone_test_SOURCES = clone_test.cc
clone_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
clone_test_LDFLAGS = $(CPPUNIT_LIBS)
clone_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

feature_visitor_test_SOURCES = feature_visitor_test.cc
feature_visitor_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
feature_visitor_test_LDFLAGS = $(CPPUNIT_LIBS)
feature_visitor_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

find_test_SOURCES = find_test.cc
find_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
find_test_LDFLAGS = $(CPPUNIT_LIBS)
find_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

get_links_test_SOURCES = get_links_test.cc
get_links_test_CXXFLAGS = -DDATADIR=\"$(DATA_DIR)\" $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
get_links_test_LDFLAGS = $(CPPUNIT_LIBS)
get_links_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

href_test_SOURCES = href_test.cc
href_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
href_test_LDFLAGS = $(CPPUNIT_LIBS)
href_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

kml_file_test_SOURCES = kml_file_test.cc
kml_file_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
kml_file_test_LDFLAGS = $(CPPUNIT_LIBS)
kml_file_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

kmz_file_test_SOURCES = kmz_file_test.cc
kmz_file_test_CXXFLAGS = -DDATADIR=\"$(DATA_DIR)\" $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
kmz_file_test_LDFLAGS = $(CPPUNIT_LIBS)
kmz_file_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

location_util_test_SOURCES = location_util_test.cc
location_util_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
location_util_test_LDFLAGS = $(CPPUNIT_LIBS)
location_util_test_LDADD = libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

merge_test_SOURCES = merge_test.cc
merge_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
merge_test_LDFLAGS = $(CPPUNIT_LIBS)
merge_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

object_id_parser_observer_test_SOURCES = object_id_parser_observer_test.cc
object_id_parser_observer_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
object_id_parser_observer_test_LDFLAGS = $(CPPUNIT_LIBS)
object_id_parser_observer_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

shared_style_parser_observer_test_SOURCES = shared_style_parser_observer_test.cc
shared_style_parser_observer_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
shared_style_parser_observer_test_LDFLAGS = $(CPPUNIT_LIBS)
shared_style_parser_observer_test_LDADD= \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

style_merger_test_SOURCES = style_merger_test.cc
style_merger_test_CXXFLAGS = $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
style_merger_test_LDFLAGS = $(CPPUNIT_LIBS)
style_merger_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

style_resolver_test_SOURCES = style_resolver_test.cc
style_resolver_test_CXXFLAGS = -DDATADIR=\"$(DATA_DIR)\" $(CPPUNIT_CFLAGS) $(AM_CXXFLAGS)
style_resolver_test_LDFLAGS = $(CPPUNIT_LIBS)
style_resolver_test_LDADD= libkmlengine.la \
	$(top_builddir)/src/kml/dom/libkmldom.la \
	$(top_builddir)/src/kml/base/libkmlbase.la

CLEANFILES = check_PROGRAMS
endif