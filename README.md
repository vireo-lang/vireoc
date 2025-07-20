<div align="center">
    <h1><code>vireoc</code> -- The Vireo compiler</h1>
</div>

<p align="center">
    <a href="#about">❖ About</a>
    <a href="#installation">❖ Installation</a>
    <a href="#credits">❖ Credits</a>
    <a href="#license">❖ License ❖</a>
</p>

> [!WARNING]
> `vireoc` is a work-in-progress.

## About ##

`vireoc` is an **official**, **up-to-date** compiler for the
[Vireo](https://vireo-lang.github.io) programming language.

It uses LLVM as a back-end, generates AOT, profiled executables and is
written on C++.

`vireoc` can also do FFI with many languages, and includes an implementation of
the standard library.

## Installation ##

### Building from source ###

> [!IMPORTANT]
> This is **NOT** recommended way.

#### Dependencies ####

- [CMake](https://cmake.org/).
- A C++ compiler [Clang++ recommended](https://clang.llvm.org/).
- [LLVM](https://llvm.org).
- [Git](httpps:/git-scm.org).

#### Building ####

Run (note the `$` is **not** part of the command):

```bash
$ git clone https://github.com/vireo-lang/vireoc && cd vireoc
$ mkdir build && cd build && cmake ..
$ cmake --build .
$ # Move the vireoc binary to your PATH
$ # On UNIX(r) systems:
$ #    sudo mv vireoc /usr/bin/local
$ # And on Windows (priviledged shell):
$ #    move vireoc C:\Windows\System32
```

Now test it:

```bash
$ vireoc -v
# Should output something like
`vireoc` version X.Y.Z
```

### Pre-buit binaries ###

This is the recommended way.

Go to [this site](https://github.com/vireo-lang/vireoc/releases), and download the
version for your OS and architecture

> [!TIP]
> **Choosing the correct architecture**
>
> Choosing the correct architecture is important, since else it won't work.
>
> Most computers nowadays ship with `amd64` (aka x86_64 or x64), except for
> newer Macs that usually ship with `aarch64`.
>
> Some (but really little nowadays) can ship with `i386` architecture.

Put the binary on your PATH.

On UNIX(r) systems you can use `/usr/local/bin`, and on Windows the easy way is
to place it on `C:\Windows\System32\`.

## Credits ##

- Jarryd Beck -- For the [cxxopts](https://github.com/jarro2783/cxxopts/) library

## License ##

The compiler is licensed under the Mozilla Public License 2.0

And its documentation:

<a href="https://github.com/vireo-lang/vireo-docs">vireoc Documentation</a> © 2025 by <a href="https://github.com/mar1lusk1">Mario Rosell</a> is licensed under <a href="https://creativecommons.org/licenses/by-nc-sa/4.0/">CC BY-NC-SA 4.0</a><img src="https://mirrors.creativecommons.org/presskit/icons/cc.svg" alt="" style="max-width: 1em;max-height:1em;margin-left: .2em;"><img src="https://mirrors.creativecommons.org/presskit/icons/by.svg" alt="" style="max-width: 1em;max-height:1em;margin-left: .2em;"><img src="https://mirrors.creativecommons.org/presskit/icons/nc.svg" alt="" style="max-width: 1em;max-height:1em;margin-left: .2em;"><img src="https://mirrors.creativecommons.org/presskit/icons/sa.svg" alt="" style="max-width: 1em;max-height:1em;margin-left: .2em;">
