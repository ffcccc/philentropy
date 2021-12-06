# distutils: language = c++
# distutils: sources = cpp/distance.cpp

from eigency.core cimport *
# cimport eigency.conversions
# from cpp.eigency cimport *


# import eigency
# include "../eigency.pyx"

cdef extern from "distances.h":
     cdef double _euclidean "euclidean"(Map[ArrayXd] &, Map[ArrayXd] &, bool)

# This will be exposed to Python
def euclidean(np.ndarray arrayX, np.ndarray arrayY, bool testNA):
    return _euclidean(Map[ArrayXd](arrayX), Map[ArrayXd](arrayY), testNA)