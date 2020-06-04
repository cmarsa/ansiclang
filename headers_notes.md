# Calling a function from another file in the same directory in C

## This is a question-answer I found on stackoverflow, explains very well the nature of compilation within different source files.

original post: https://stackoverflow.com/questions/6618921/calling-a-function-from-another-file-in-the-same-directory-in-c

There's a few different things going on here. First I'll go over how basic compilation of multiple files works.

If you have multiple files, the important thing is the difference between the declaration and definition of a function. The definition is probably what you are used to when defining functions: You write up the contents of the function, like

```c
int square(int i) {
    return i*i;
}
```
The declaration, on the other hand, lets you declare to the compiler that you know a function exists, but you don't tell the compiler what it is. For example, you could write

```c
int square(int i);
```
And the compiler would expect that the function "square" is defined elsewhere.

Now, if you have two different files that you want to interoperate (for example, let's say that the function "square" is defined in `add.c`, and you want to call square(10) in main.c), you need to do both a definition and a declaration. First, you define square in `add.c`. Then, you declare it at the beginning of `main.c`. This let's the compiler know when it is compiling `main.c` that there is a function "square" which is defined elsewhere. Now, you need to compile both `main.c` and `add.c` into object files. You can do this by calling

```sh
gcc -c main.c
gcc -c add.c
```

This will produce the files `main.o` and `add.o`. They contain the compiled functions, but are not quite executable. The important thing to understand here is that `main.o` is "incomplete" in a sense. When compiling main.o, you told it that the function "square" exists, but the function "square" is not defined inside `main.o`. Thus `main.o` has a sort of "dangling reference" to the function "square". It won't compile into a full program unless you combine it with another `.o` (or a `.so` or `.a`) file which contains a definition of "square". If you just try to link `main.o` into a program, i.e.

```sh
gcc -o executable main.o
```

You will get an error, because the compiler will try to resolve the dangling reference to the function "square", but wont find any definition for it. However, if you include add.o when linking (linking is the process of resolving all these references to undefined functions while converting .o files to executables or `.so` files), then there won't be any problem. i.e.

```
gcc -o executable main.o add.o
```

So that's how to functionally use functions across C files, but stylistically, what I just showed you is "not the right way". The only reason I did is because I think it will better help you understand what's going on, rather than relying on `"#include magic"`. Now, you might have noticed before that things get a little messy if you have to redeclare every function you want to use at the top of main.c This is why often C programs use helper files called "headers" which have a `.h` extension. The idea of a header is that it contains just the declarations of the functions, without their definitions. This way, in order to compile a program using functions defined in `add.c`, you need not manually declare every function you are using, nor need you #include the entire `add.c` file in your code. Instead, you can `#include add.h`, which simply contains the declarations of all the functions of `add.c`.

Now, a refresher on `#include`: `#include` simply copies the contents of one file directly into another. So, for example, the code

```c
abc
#include "wtf.txt"
def
```

is exactly equivalent to

```
abc
hello world
def
```

assuming that `wtf.txt` contains the text "hello world".

So, if we put all the declarations of `add.c` in add.h (i.e.

```c
int square(int i);
```

and then at the top of `main.c`, we write

```c
#include "add.h"
```
This is functionally the same as if we had just manually declared the function "square" at the top of `main.c`.

So the general idea of using headers is that you can have a special file that automatically declares all the functions you need by just #including it.

However, headers also have one more common use. Let's suppose that `main.c` uses functions from 50 different files. The top of `main.c` would look like:

```c
#include "add.h"
#include "divide.h"
#include "multiply.h"
#include "eat-pie.h"
. . . 
```
Instead, people often move all those #includes to the main.h header file, and just #include main.h from `main.c`. In this case, the header file serves two purposes. It declares the functions in `main.c` for use when included by other files, and it includes all of the dependencies of `main.c` when included from `main.c`. Using it this way also allows chains of dependencies. If you #include `add.h`, not only do you get the functions defined in `add.c`, but you also implicitly get any functions which `add.c` uses, and any functions they use, and so on.

Also, more subtly, #including a header file from it's own `.c`file implicitly checks for errors you make. If for example, you accidentally defined square as

```c
double square(int i);
```

in `add.h`, you normally might not realize until you were linking that main.o is looking for one definition of square, and `add.o` is providing another, incompatible one. This will cause you to get errors when linking, so you won't realize the mistake until later in the build process. However, if you #include `add.h` from `add.c`, to the compiler, your file looks like

```c
#include "add.h"
int square(int i) {
    return i*i;
}
```

which after processing the `#include` statement will look like

```c
double square(int i);
int square(int i) {
    return i*i;
}
```

Which the compiler will notice when compiling `add.c`, and tell you about. Effectively, including your own header in this way prevents you from falsely advertising to other files the type of the functions you are providing.

Why you can use a function without ever declaring it

As you have noticed, in some cases you can actually use a function without every declaring it or #including any file which declares it. This is stupid, and everyone agrees that this is stupid. However, it is a legacy feature of the C programming language (and C compilers) that if you use a function without declaring it first, it just assumes that it is a function returning type "int". So in effect, using a function is implicitly declaring that function as a function which returns "int" if it is not already declared. It's very strange behavior if you think about it, and the compiler should warn you if you it doing that behavior.

## Header Guards

One other common practice is the use of "Header Guards". To explain header guards, let's look at a possible problem. Let's say that we have two files: `herp.c`, and `derp.c`, and they both want to use functions contained in each other. Following the above guidelines, you might have a `herp.h` with the line

```c
#include "derp.h"
```

and a `derp.h` with the line

```c
#include "herp.h"
```

Now, if you think about it, #include `"derp.h"` will be converted to the contents of derp.h, which in turn contains the line `#include "herp.h"`, which will be converted to the contents of `herp.h`, and that contains... and so on, so the compiler will go on forever just expanding the includes. Similarly, if `main.h` #includes both `herp.h` and `derp.h`, and both `herp.h` and `derp.h` include `add.h`, we see that in `main.h`, we end up with two copies of `add.h`, one as a result of #including herp.h, and one as a result of including `derp.h`. So, the solution? A "Header guard", i.e. a piece of code which prevents any header from being #included twice. For `add.h`, for example, the normal way to do this is:

```c
#ifndef ADD_H
#define ADD_H

int sqrt(int i);
...
#endif
```

This piece of code is essentially telling the preprocessor (the part of the compiler which handles all of the "#XXX" statements) to check if `"ADD_H"` is already defined. If it isn't (ifndef) then it first defines `"ADD_H"` (in this context, `ADD_H` doesn't have to be defined as anything, it is just a boolean which is either defined or not), and then defines the rest of the contents of the header. However, if `ADD_H` is already defined, then #including this file will do nothing, because there is nothing outside of the #ifndef block. So the idea is that only the first time it is included in any given file will it actually add any text to that file. After that, #including it will not add any additional text to your file. `ADD_H` is just an arbitrary symbol you choose to keep track of whether add.h has been included yet. For every header, you use a different symbol to keep track of whether it has been included yet or not. For example, herp.h would probably use HERP_H instead of `ADD_H`. Using a "header guard" will fix any of the problems I listed above, where you have duplicate copies of a file included, or an infinite loop of #includes.
