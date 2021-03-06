CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )

# projects name
PROJECT( YAPOG )

SET( LIB_NAME YAPOG )
SET( CLIENT_NAME YAPOG.Client )
SET( SERVER_NAME YAPOG.Server )

SET( BIN_PATH bin )

# additional flags
if( WIN32 )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc" )
endif()

if( UNIX )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wall -Wextra -Wno-unused-parameter" )
    if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb" )
	endif()
endif()

# external libs
if( WIN32 )
    SET( EXT_LIB_DIR
        ${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/sfml2/Debug #SFML debug lib directory.
        ${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/sfml2/Release #SFML release lib directory.
        ${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/postgresql #PostgreSQL lib directory.
        ${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/boost_1_51_0/Debug #Boost debug lib directory.
        ${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/boost_1_51_0/Release  #Boost release lib directory.
	)

	SET( EXT_INCLUDE_DIR
        ${CMAKE_SOURCE_DIR}/extlibs/headers/sfml2 #SFML include directory.
        ${CMAKE_SOURCE_DIR}/extlibs/headers/postgresql #PostgreSQL include directory.
        ${CMAKE_SOURCE_DIR}/extlibs/headers/boost_1_51_0 #Boost include directory.
	)
endif()

if( UNIX )
    SET( EXT_LIB_DIR
         ${CMAKE_SOURCE_DIR}/extlibs/libs-unix/sfml2
         ${CMAKE_SOURCE_DIR}/extlibs/libs-unix/postgresql
		 ${CMAKE_SOURCE_DIR}/extlibs/libs-unix/boost_1_47_0
    )
    SET( EXT_INCLUDE_DIR 
		 ${CMAKE_SOURCE_DIR}/extlibs/headers/sfml2
         ${CMAKE_SOURCE_DIR}/extlibs/headers/postgresql			 
		 ${CMAKE_SOURCE_DIR}/extlibs/headers/boost_1_51_0 #Boost include directory.
    )
endif()

if( WIN32 )
	SET( boost_signals_lib_debug_name libboost_signals-vc110-mt-gd-1_51 )
	SET( boost_signals_lib_release_name libboost_signals-vc110-mt-1_51 )

	SET( boost_date_time_lib_debug_name libboost_date_time-vc110-mt-gd-1_51 )
	SET( boost_date_time_lib_release_name libboost_date_time-vc110-mt-1_51 )

	SET( boost_filesystem_lib_debug_name libboost_filesystem-vc110-mt-gd-1_51 )
	SET( boost_filesystem_lib_release_name libboost_filesystem-vc110-mt-1_51 )

	SET( boost_regex_lib_debug_name libboost_regex-vc110-mt-gd-1_51 )
	SET( boost_regex_lib_release_name libboost_regex-vc110-mt-1_51 )

	SET( boost_system_lib_debug_name libboost_system-vc110-mt-gd-1_51 )
	SET( boost_system_lib_release_name libboost_system-vc110-mt-1_51 )

    SET( pgsql_lib debug libpq optimized libpq )
endif()

if( UNIX )
	SET( boost_signals_lib_debug_name "boost_signals" CACHE STRING "Boost signals lib debug." )
	SET( boost_signals_lib_release_name "boost_signals" CACHE STRING "Boost signals lib release." )

	SET( boost_date_time_lib_debug_name "boost_date_time" CACHE STRING "Boost date_time lib debug." )
	SET( boost_date_time_lib_release_name "boost_date_time" CACHE STRING "Boost date_time lib release." )

	SET( boost_filesystem_lib_debug_name "boost_filesystem" CACHE STRING "Boost filesystem lib debug." )
	SET( boost_filesystem_lib_release_name "boost_filesystem" CACHE STRING "Boost filesystem lib release." )

	SET( boost_regex_lib_debug_name "boost_regex" CACHE STRING "Boost regex lib debug." )
	SET( boost_regex_lib_release_name "boost_regex" CACHE STRING "Boost regex lib release." )

	SET( boost_system_lib_debug_name "boost_system" CACHE STRING "Boost system lib debug" )
	SET( boost_system_lib_release_name "boost_system" CACHE STRING "Boost system lib release")

	SET( pgsql_lib debug pq optimized pq )
endif()

SET( sfml_system_lib_debug_name sfml-system-d )
SET( sfml_window_lib_debug_name sfml-window-d )
SET( sfml_graphics_lib_debug_name sfml-graphics-d )
SET( sfml_network_lib_debug_name sfml-network-d )
SET( sfml_audio_lib_debug_name sfml-audio-d )

SET( sfml_system_lib_release_name sfml-system )
SET( sfml_window_lib_release_name sfml-window )
SET( sfml_graphics_lib_release_name sfml-graphics )
SET( sfml_network_lib_release_name sfml-network )
SET( sfml_audio_lib_release_name sfml-audio )

SET( sfml_system_lib debug ${sfml_system_lib_debug_name} optimized ${sfml_system_lib_release_name} )
SET( sfml_window_lib debug ${sfml_window_lib_debug_name} optimized ${sfml_window_lib_release_name} )
SET( sfml_graphics_lib debug ${sfml_graphics_lib_debug_name} optimized ${sfml_graphics_lib_release_name} )
SET( sfml_network_lib debug ${sfml_network_lib_debug_name} optimized ${sfml_network_lib_release_name} )
SET( sfml_audio_lib debug ${sfml_audio_lib_debug_name} optimized ${sfml_audio_lib_release_name} )

SET( boost_signals_lib debug ${boost_signals_lib_debug_name} optimized ${boost_signals_lib_release_name} )
SET( boost_date_time_lib debug ${boost_date_time_lib_debug_name} optimized ${boost_date_time_lib_release_name} )
SET( boost_filesystem_lib debug ${boost_filesystem_lib_debug_name} optimized ${boost_filesystem_lib_release_name} )
SET( boost_regex_lib debug ${boost_regex_lib_debug_name} optimized ${boost_regex_lib_release_name} )
SET( boost_system_lib debug ${boost_system_lib_debug_name} optimized ${boost_system_lib_release_name} )

if( UNIX )
        SET( pthread_lib pthread )
endif()

SET(
	link_lib
	${sfml_system_lib}
	${sfml_window_lib}
	${sfml_graphics_lib}
	${sfml_network_lib}
	${sfml_audio_lib}
	${boost_signals_lib}
	${boost_date_time_lib}
    ${boost_filesystem_lib}
	${boost_regex_lib}
	${boost_system_lib}
	${pgsql_lib}
    ${pthread_lib}
)

ADD_SUBDIRECTORY( YAPOG )
ADD_SUBDIRECTORY( YAPOG.Client )
ADD_SUBDIRECTORY( YAPOG.Server )