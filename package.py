name = "usd"

version = "23.11.hh.1.0.0"

authors = [
    "Pixar",
]

description = """Universal Scene Description"""

with scope("config") as c:
    import os

    c.release_packages_path = os.environ["HH_REZ_REPO_RELEASE_EXT"]

requires = [
    "PyOpenGL",
    "tbb-2020.3",
    "alembic-1.8",
    "openexr-3.1",  # will bring imath
    "OpenSubdiv-3.6",
    "materialx-1.38",
    "openvdb-11.0",
    "ocio-2.1",  # being explicit here in case we have oiio 2.5.9 against ocio-2.3.2
    "oiio-2.5.9",
    "osl-1.13",
]

private_build_requires = [
    "Jinja2",
    "PySide6",
]

variants = [
    ["python-3.7"],
    ["python-3.9"],
    ["python-3.10"],
    ["python-3.11"],
    ["python-3.12"],
]


def commands():
    env.REZ_USD_ROOT = "{root}"
    env.USD_ROOT = "{root}"
    env.USD_LOCATION = "{root}"
    env.USD_INCLUDE_DIR = "{root}/include"
    env.USD_LIBRARY_DIR = "{root}/lib"
    env.USD_PYTHON_DIR = "{root}/lib/python"

    env.PATH.append("{root}/bin")
    env.PATH.append("{root}/lib")
    env.LD_LIBRARY_PATH.append("{root}/bin")
    env.LD_LIBRARY_PATH.append("{root}/lib")
    env.PYTHONPATH.append("{root}/lib/python")


uuid = "repository.OpenUSD"
