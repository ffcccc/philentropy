from setuptools import setup, find_packages
from setuptools.extension import Extension
from Cython.Build import cythonize

import eigency

extensions = [
    Extension("src.distances", ["src/distances.pyx"],
        include_dirs = [".", "src"] + eigency.get_includes(),  # include_dirs = [".", "module-dir-name", 'path-to-own-eigen'] + eigency.get_includes(include_eigen=False)
        extra_compile_args=['/O2', '/favor:blend', "/DEBUG:NONE", "-DNDEBUG"]
    ),
]

dist = setup(
    name = "philentropy",
    version = "0.1.0",
    ext_modules = cythonize(extensions),
    packages = find_packages()
)