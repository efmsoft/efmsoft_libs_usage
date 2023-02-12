if(WIN32)
  set(OPENSSL_SOURCES ${OPENSSL_INCLUDE_DIR}/openssl/applink.c)
endif()

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")
add_executable(example ${SOURCES} ${OPENSSL_SOURCES}) 

target_include_directories(example PUBLIC
  ${ALLSTAT_INCLUDE_DIR}
  ${LOGME_INCLUDE_DIR}
  ${SYNCME_INCLUDE_DIR}
  ${UTF8_INCLUDE_DIR}

  ${OPENSSL_INCLUDE_DIR}
)

target_link_libraries(example LINK_PUBLIC 
  ${ALLSTAT_LIBRARIES}
  ${LOGME_LIBRARIES}
  ${SYNCME_LIBRARIES}
  ${UTF8_LIBRARIES}

  ${OPENSSL_LIBRARIES}
)

if(WIN32)
  target_link_libraries(example LINK_PUBLIC icu.lib)
endif()
