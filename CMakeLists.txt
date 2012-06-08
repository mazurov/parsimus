CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (Parsimus CXX)

INCLUDE (ExternalProject)

SET (PARSIM_GIT "file:///home/amazurov/Dev/parsim/.git")
ExternalProject_Add(
  parsim
  GIT_REPOSITORY ${PARSIM_GIT}
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
  INSTALL_DIR ${PROJECT_SOURCE_DIR}/_deps/parsim
  UPDATE_COMMAND "${GIT_EXECUTABLE}" pull
  PREFIX ${PROJECT_SOURCE_DIR}/_deps
)

INCLUDE_DIRECTORIES (include ${PROJECT_SOURCE_DIR}/_deps/parsim/include)
SET (SRC src/primitive.cc)
ADD_LIBRARY(parsimus ${SRC})

SET (SRC_TEST tests/test_parsimus.cc)
ADD_EXECUTABLE (tests_parsimus ${SRC_TEST})
TARGET_LINK_LIBRARIES (tests_parsimus parsimus)

ENABLE_TESTING()
ADD_TEST(tests_parsimus tests_parsimus)
