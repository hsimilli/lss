
set(lss_files)
set(lss_ignore)
set(lss_extra_includes)
set(lss_extra_libs coolfluid_common)


list(APPEND lss_extra_libs ${LAPACK_LIBRARIES} ${BLAS_LIBRARIES} )
list(APPEND lss_files
  GaussianElimination.cpp
  GaussianElimination.hpp
  GMRES.cpp
  GMRES.hpp
  LAPACK.cpp
  LAPACK.hpp

  NewtonMethod.cpp
  NewtonMethod.hpp
  NewtonMethodBounded.cpp
  NewtonMethodBounded.hpp
  QuasiNewtonMethod.cpp
  QuasiNewtonMethod.hpp )


if(CF3_HAVE_DLIB)
  list(APPEND lss_extra_includes ${DLIB_INCLUDE_DIRS})
  list(APPEND lss_files
    Dlib.hpp
    Dlib.cpp )
else()
  list(APPEND lss_ignore
    Dlib.hpp
    Dlib.cpp )
endif()


coolfluid3_add_library(
  TARGET   coolfluid_lss
  LIBS     ${lss_extra_libs}
  INCLUDES ${lss_extra_includes}
  SOURCES
    LibLSS.cpp
    LibLSS.hpp
    linearsystem.cpp
    linearsystem.hpp
    matrix.hpp
    nonlinearsystem.cpp
    nonlinearsystem.hpp
    utilities.cpp
    utilities.hpp
    ${lss_files} )


coolfluid_mark_not_orphan(
    reference/a.cpp
    reference/b.cpp
    reference/c.cpp
    reference/index.hpp
    reference/linearsystem.hpp
    reference/lss_index.hpp
    reference/lss_matrix.hpp
    reference/lss_utilities.hpp
    reference/mmatrix.h
    ${lss_ignore} )
