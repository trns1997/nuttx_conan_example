## Getting started
This is an example to compile conan packages using the nuttx generated toolchain. In this example we have create an example that consumes the `Eigen3` package which is installed via conan. The board used for this example is `xmc4800-relax`. Note I tested the code on the board and executes correctly. 

## Steps to build
### Generate nuttx export
```
cp defconfig <NUTTX_FOLDER>/boards/arm/xmc4/xmc4800-relax/configs/nsh/defconfig
cd <NUTTX_FOLDER> 
./tools/configure.sh -E -l xmc4800-relax:nsh
make export
```

### Consume nuttx export
```
mkdir build
cd build
mkdir nuttx
tar -xf <NUTTX_FOLDER>/<NUTTX_ARCHIVE> -C nuttx --strip-component=1
conan install ../conan/conanfile.txt -of=./ -pr ../conan/profile.txt -pr:b ../conan/profile.txt --build=missing -s build_type=Release
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

And there you have it you have successfully built an exec that consumes a conan package with nuttx.
