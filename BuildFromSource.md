# Building from source

There is a build script provided written in lua. It is located in the scripts directory. The script does not download the dependencies for you. But there iis an additional script that does that for you. It is located in the scripts directory as well. The script is called `install.lua`. It is recommended to run the install script first and then the build script if you are using linux. If you are using windows you can run the build script directly, if you have setup cmake, ninja and you have setup msvc. MinGW is not supported at the moment.

## Build Requirements

### General

* Ninja
* CMake
* And a C++ compiler, obviously - that supports the C++20-standard.

### Windows

If you are not using msvc you need to install at least the freetype library.

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

* gFortran / Octave (If you run into problems regarding an undefined indentifier 'choke')
