# Building from source

When you clone the project you need to add all the submodules and their submodules as well. You can do that by running the following command

```bash
git clone --recursive https://github.com/FrederikTobner/tobot-engine
```

## Build Requirements

To build the project you need to setup the following dependencies:

* CMake
* And a C++ compiler, obviously - that supports the C++20-standard.

### Windows

If you are using MSVC there is no need to install any dependencies. They are included in the repository as submodules and will be detected properly.

If you are using mysys2 you can install the dependencies with pacman.

```mysis2-ucrt
pacman -S mingw-w64-ucrt-x86_64-opusfile mingw-w64-ucrt-x86_64-flac mingw-w64-ucrt-x86_64-libxmp mingw-w64-ucrt-x86_64-fluidsynth mingw-w64-ucrt-x86_64-wavpac mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake
```

### Under Linux

Can be installed with apt. We haven't determined the names of these dependencies using other package managers yet.

* file
* fonts-dejavu-core
* libfreetype-dev
* libharfbuzz-dev
* libflac-dev
* libfluidsynth-dev
* libgme-dev
* libmpg123-dev
* libopusfile-dev
* libvorbis-dev
* libxmp-dev
* libwavpack-dev
* pkg-config

```bash
sudo apt-get install file fonts-dejavu-core libfreetype-dev libharfbuzz-dev libflac-dev libfluidsynth-dev libgme-dev libmpg123-dev libopusfile-dev libvorbis-dev libxmp-dev libwavpack-dev pkg-config
```

If you run into problems regarding an undefined indentifier 'choke' during compilation you need to install gFortran and Octave.
We haven't figured out why this error occurs yet. Additionally you can run a script under linux that installs all the dependencies for you.

The script is called `install_dependencies.lua`. This script is supports Linux at the moment. Additionally it only supports the package managers apt and pacman. If you are using another package manager you need to install the dependencies manually.

| ⚠️ Warning                                                                                                        |
|-------------------------------------------------------------------------------------------------------------------|
| The script hasn't been througly tested yet. Setting up the dependecies manually is the safer option at the moment |

Usage:

```bash
lua scripts/install_dependencies.lua
```

## Build

There is a build script provided written in lua. It is located in the scripts directory. The script is called `build.lua`.

Usage:

```bash
lua scripts/build.lua <BuildType> <Target> <Generator>
```

The default values are `Release`, `all` and `Ninja` respectively, if Ninja is available under your system. Otherwise we let cmake guess which generator shall be used. Under Windows we use MSVC.
