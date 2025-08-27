# Welcome everyone!
This repository was made for storing my study results and share to everyone, all resource are not translated to English because i am lazy, also i focus to study DSA as fast as possible, so i will every learning files to Vietnamese as my default language, these text are English because there will be someone who aren't Vietnamese will understand

# How to use
Install this repository by GIT clone (if you have git) or direct install in github.

In case if you have GIT, then enter these:

``` bash
git clone --depth=1 https://github.com/Little-Blueberries/myDSAResult.git
```

Then install Obsidian and open this repository folder
To run the code, you must installed MSVC compiler from the Visual Studio main page (if you use Windows) or GCC compiler from Linux.

## Windows user
Command `winget` to install Visual Build Tools:
``` bash
winget install Microsoft.VisualStudio.2022.BuildTools --force --override "--wait --passive --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64
```
Then, if they ask you to choose what to install, choose Desktop Development with C++, check the left, check if C++ Address Sanitizer is ticked, because it is necessary for debug mode. Then check the WinSDK as well, choose Windows 10 SDK if you use Windows 10, Windows 11 SDK if you use Windows 11. After press install, you will have to wait some of 10 minutes.

Next, open Developer command prompt for VS 2022 and type these command:
``` bash
cd \\path\\to\\file
cd DSA\\Test
.\run.bat test_<number> [/debug][/release]
```

## Linux user
Command to install g++ and valgrind:

### Debian/Ubuntu:
``` bash
sudo apt update && sudo apt upgrade
sudo apt install gcc valgrind
```

### Arch Linux:
``` bash
sudo pacman -Syu --needed gcc valgrind
```

_There's more, but u should search at the internet_

Run files:
``` bash
cd /path/to/file
cd DSA/Test
chmod +x run.sh
./run.sh test_<number> [/debug][/release]
```