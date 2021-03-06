
# gtl #

This repository aims is a collection of useful cross-platform, well-commented, self-contained, simple, and interesting C++ classes in the style of the standard template library.

[![Build Status](https://travis-ci.org/gpdaniels/gtl.svg?branch=master)](https://travis-ci.org/gpdaniels/gtl) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/gpdaniels/gtl.svg)](https://lgtm.com/projects/g/gpdaniels/gtl/context:cpp) [![License: MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://opensource.org/licenses/MIT) 

## Content ##

The current classes are as described below:

### Algorithm ###

|               Class | Description                                                                             |
|--------------------:|:----------------------------------------------------------------------------------------|
| **simulation_loop** | Fixed time step helper class for creating game loops.                                   |

### Container ###

|               Class | Description                                                                             |
|--------------------:|:----------------------------------------------------------------------------------------|
|             **any** | Class that can hold any variable type.                                                  |
|        **array_nd** | N-dimensional statically or dynamically sized array.                                    |
|     **ring_buffer** | Statically sized thread-safe multi-producer multi-consumer ring-buffer.                 |
| **static_array_nd** | N-dimensional statically sized array.                                                   |
|   **static_lambda** | Lambda function class that uses the stack for storage.                                  |

### Debug ###

|               Class | Description                                                                             |
|--------------------:|:----------------------------------------------------------------------------------------|
|      **breakpoint** | Macro for creating a breakpoint.                                                        |
|          **access** | Classes and macros for accessing class private members.                                 |
|          **assert** | Macros that define an assert macro that optionally takes a format string and parameters.|
|          **signal** | Class to wrap signal handlers allowing the use of lambdas with scope.                   |

### Execution ###

|               Class | Description                                                                             |
|--------------------:|:----------------------------------------------------------------------------------------|
|         **barrier** | Thread syncronisation barrier.                                                          |
|       **coroutine** | Setjump/Longjump implementation of stackful coroutines.                                 |
|       **semaphore** | Semaphore made using a mutex and condition variable.                                    |
|       **spin_lock** | Spin lock implemented using an atomic flag.                                             |
|   **triple_buffer** | Lockless triple buffer interface to three buffers.                                      |
|     **thread_pool** | Multi-queue thread-pool that performs jobs in priority order.                           |

### Hash ###

|               Class | Description                                                                             |
|--------------------:|:----------------------------------------------------------------------------------------|
|             **crc** | An implementation of the crc hashing function for 8, 16, 32, and 64 bits.               |
|             **md5** | An implementation of the md5 hashing function.                                          |
|            **sha0** | An implementation of the sha0 hashing function.                                         |
|            **sha1** | An implementation of the sha1 hashing function.                                         |
|            **sha2** | An implementation of the sha2 hashing function for 224, 256, 384, and 512 bits.         |


### IO ###

|               Class | Description                                                                             |
|--------------------:|:----------------------------------------------------------------------------------------|
|           **paths** | Collection of cross platform functions to provide useful paths.                         |

### Random ###

|               Class | Description                                                                             |
|--------------------:|:----------------------------------------------------------------------------------------|
|       **random_mt** | Mersenne twister pseudo-random number generator.                                        |
|      **random_pcg** | PCG pseudo-random number generator.                                                     |
| **random_splitmix** | Splitmix pseudo-random number generator.                                                |
| **random_xorshift** | Xorshift pseudo-random number generator.                                                |

### Type Information ###

|               Class | Description                                                                             |
|--------------------:|:----------------------------------------------------------------------------------------|
|       **enum_name** | Compile-time enum value name as a string with -fno-rtti.                                |
|         **type_id** | Simple run-time-type-information (rtti) with -fno-rtti.                                 |
|       **type_name** | Compile-time type name as a string with -fno-rtti.                                      |

### Utility ###

|               Class | Description                                                                             |
|--------------------:|:----------------------------------------------------------------------------------------|
|             **cpu** | Class to extract cpuid information to determine supported instructions at runtime.      |
|           **error** | Composable error class that can be returned down a call stack.                          |
|           **event** | Thread safe multi-in/multi-out event/messaging system.                                  |
|           **pimpl** | Statically sized pointer to implementation wrapper.                                     |

## Build matrix ##

| Operating System    | Version                                                           | Compiler   | Status |
|:--------------------|:------------------------------------------------------------------|:-----------|:------:|
| Linux               | Ubuntu 14.04 Trusty                                               | Clang 6.0  | [![Build Status](https://travis-matrix-badges.herokuapp.com/repos/gpdaniels/gtl/branches/master/1)](https://travis-ci.org/gpdaniels/gtl) |
| Linux               | Ubuntu 14.04 Trusty                                               | GCC 7      | [![Build Status](https://travis-matrix-badges.herokuapp.com/repos/gpdaniels/gtl/branches/master/2)](https://travis-ci.org/gpdaniels/gtl) |
| Linux               | Ubuntu 16.04 Xenial                                               | GCC 7      | [![Build Status](https://travis-matrix-badges.herokuapp.com/repos/gpdaniels/gtl/branches/master/3)](https://travis-ci.org/gpdaniels/gtl) |
| Macintosh           | macOS 10.13                                                       | XCode 9.3  | [![Build Status](https://travis-matrix-badges.herokuapp.com/repos/gpdaniels/gtl/branches/master/4)](https://travis-ci.org/gpdaniels/gtl) |
| Macintosh           | macOS 10.13                                                       | XCode 9.4  | [![Build Status](https://travis-matrix-badges.herokuapp.com/repos/gpdaniels/gtl/branches/master/5)](https://travis-ci.org/gpdaniels/gtl) |
| Windows             | Windows Server, version 1803                                      | VS 2017    | [![Build Status](https://travis-matrix-badges.herokuapp.com/repos/gpdaniels/gtl/branches/master/6)](https://travis-ci.org/gpdaniels/gtl) |

## License ##

The MIT License

Copyright (c) 2019 Geoffrey Daniels. http://gpdaniels.com/

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
