# Building from source

There is a build script provided written in lua. It is located in the scripts directory. The script is called `build.lua`.

Usage:

```bash
lua scripts/build.lua <BuildType> <Target> <Generator>
```

The default values are `Release`, `all` and `Ninja` respectively. Under Windows we use MSVC by default. We have not fully tested the build with other compilers, like clang and GCC under windows yet.

The script does not download the dependencies for you. But there is an additional script that does that for you. It is located in the scripts directory as well. The script is called `install_dependencies.lua`.

Usage:

```bash
lua scripts/install_dependencies.lua
```

## Build Requirements

### General

* CMake
* And a C++ compiler, obviously - that supports the C++20-standard.

### Windows

If you are using mysys2 you can install the dependencies with pacman.

```mysis2-ucrt
pacman -S mingw-w64-ucrt-x86_64-opusfile mingw-w64-ucrt-x86_64-flac mingw-w64-ucrt-x86_64-libxmp mingw-w64-ucrt-x86_64-fluidsynth mingw-w64-ucrt-x86_64-wavpac mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake
```

If you are using MSVC there is no need to install any dependencies. They are included in the repository as submodules and will be detected properly.

### Under linux

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

If you run into problems regarding an undefined indentifier 'choke' during compilation you need to install gFortran and Octave. We haven't figured out why yet.
