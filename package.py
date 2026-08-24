name = "usd"

version = "25.11.hh.1.0.2"

authors = [
    "Pixar",
]

description = """Universal Scene Description"""

with scope("config") as c:
    import os
    c.release_packages_path = os.environ["HH_REZ_REPO_RELEASE_EXT"]

requires = [
    "PyOpenGL",
    "tbb-2021.9",
    "alembic-1.8",
    "openexr-3.1",  # will bring imath
    "OpenSubdiv-3.6",
    "materialx-1.39.4",  # always use exact version that Pixar used
    "openvdb-11.0",
    "ocio-2.2",  # being explicit here to avoid ocio-2.3.2
    "oiio-2.5.16",
    "osl-1.14",
    "vulkanSDK-1.4.321.0",
]

private_build_requires = [
    "Jinja2",
    "visual_studio",
]

variants = [
    ["python-3.9", "PySide2"],
    ["python-3.10", "PySide2"],
    ["python-3.11.9", "PySide6"],  # Maya 2026: undefined symbol _PyModule_add issue
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
    env.PYTHONPATH.append("{root}/lib/python")


uuid = "repository.OpenUSD"
