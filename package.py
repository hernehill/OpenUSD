name = "usd"

version = "26.08.hh.1.0.0"

authors = [
    "Pixar",
]

description = """Universal Scene Description"""

with scope("config") as c:
    import os
    c.release_packages_path = os.environ["HH_REZ_REPO_RELEASE_EXT"]

requires = [
    "PyOpenGL",
    "tbb-2022.0",
    "alembic-1.8.9",
    "openexr-3.4.4",  # will bring imath
    "OpenSubdiv-3.7",
    "materialx-1.39.4",  # maya-usd 0.37.0 cannot handle 1.39.5+
    "openvdb-13.0",
    "ocio-2.5.2",
    "oiio-3.0.9.1",
    "osl-1.15",
    "vulkanSDK-1.4.321.0",
    "PySide6",
]

private_build_requires = [
    "Jinja2",
]

variants = [
    ["python-3.13"],
]

def commands():
    env.REZ_USD_ROOT = "{root}"
    env.USD_ROOT = "{root}"
    env.USD_LOCATION = "{root}"
    env.USD_INCLUDE_DIR = "{root}/include"
    env.USD_LIBRARY_DIR = "{root}/lib"
    env.PATH.append("{root}/bin")
    env.PATH.append("{root}/lib")
    env.LD_LIBRARY_PATH.append("{root}/bin")
    env.LD_LIBRARY_PATH.append("{root}/lib")

    if "python" in resolve:
        python_ver = resolve["python"].version
        if python_ver.major == 3:
            if python_ver.minor == 13:
                env.USD_PYTHON_DIR = "{root}/lib/python3.13/site-packages"
                env.PYTHONPATH.append("{root}/lib/python3.13/site-packages")


uuid = "repository.OpenUSD"
