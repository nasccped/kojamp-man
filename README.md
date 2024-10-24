<!--

  Kojamp Man - README

    This is Kojamp Man at `kojamp-man` github repository, developed
    by @nasccped. You can access by here:

      https://github.com/nasccped/kojamp-man

    This project is 100% open source and free to use.

    Did you want to contribute?
    >>> Check `CONTRIBUTING.md` (if it exists)

    Did you want to support me or the project?
    >>> Consider give a star at the github repo

    Something doesn't works well or it have an unexpected behavior?
    >>> Consider open a issue

    Thank you in advance for your attention S2

  (Copyright (c) 2024 nasccped. All Rights Reserved.)

-->

<h1 align=center>

Kojamp Man

[![version        : beta 0.1.0][kojamp-man-version]](#)
[![license        : Apache    ][kojamp-man-license]](#)
[![builded on     : Java      ][kojamp-builded]](#)
[![also builded on: C         ][kojamp-builded-also]](#)

</h1>

This is Kojamp Man, a Java/Kotlin project manager tool!



Dependencies
------------

To use this entire project, you'll need a few things on
your machine, such as:


- Some kind of version control system [(Git)](https://git-scm.com/downloads)

  To proceed with the following operations, you'll need to use some
  git commands. Git is required!

- **GNU Compile Collection**, aka **GCC** [(see website)](https://gcc.gnu.org/)

  This will be necessary to **compile some C files** along the way.

- **GNU Make** [(see website)](https://www.gnu.org/software/make/)

  In this project, you will **see/generate a bunch of `Makefiles`**,
  so... it will be necessary to have the GNU Make!

- **Java**, **Javac** and **JVM** by [Oracle website](https://www.oracle.com/java/technologies/downloads/)

  Well... the project is based on Java Language, so... obviously
  you'll need the java dependencies such as the _compiler_, _runner_
  and the _virtual machine_.

- **Kotlin** and **Kotlinc** [(see website)](https://kotlinlang.org/)

  Kotlin Lang isn't used in the project's source code, but you'll
  manage Kotlin files, so... Kotlin compiler and runner can be
  usefull!

> [!NOTE]
>
> I could have cited a link on how to download each project
> dependency, but the way to install may vary from one OS to another,
> so I decided to leave this part up to you! 😉



Get, compile and run
--------------------

To get, compile and run the program at your machine you'll need to do
the following steps:


1. Go to an accessible path at your computer:

  Under the current conditions of the program, I recommend going to a
  path that is easy to remember and access (like `Desktop`), so you
  can modify/delete the program folder whenever you want.

> [!TIP]
>
> If a directory called `kojamp-man` or `kojamp` already exists at
> your path, I recommend that you delete or rename it to avoid
> unexpected behavior 💿

2. Clone this repository:

  Now that you are on a suitable path, you can clone this repository
  by opening the terminal at this mentioned path and cloning repo by
  typing this at your terminal:

  ```shell
  git clone https://github.com/nasccped/kojamp-man
  ```

3. Go to the cloned repo:

  Now, if you're still inside the terminal, you can go to the cloned
  repo by typing:

  ```shell
  cd kojamp-man
  ```

4. Compile:

  Within the cloned repo, we have some setupe file(s) at  **setup/**
  dir. You can compile them by the root _Makefile_.

  To compile the program, you can run the Makefile by typing:

  ```shell
  # it will generate the C files output
  # you will need the MAKE GNU and gcc to compile it
  make binary
  ```

  And finally, to run the final product, just type:

  ```shell
  bin/kojamp
  ```



<h4 align=center>

[![license: Apache][kojamp-man-license]](#)

</h4>


[kojamp-man-version]: https://img.shields.io/badge/Version-beta_0.1.0-red?style=for-the-badge&logo=git&logoColor=white
[kojamp-man-license]: https://img.shields.io/badge/License-Apache_2.0-blue?style=for-the-badge&logo=amazoniam&logoColor=white
[kojamp-builded]: https://img.shields.io/badge/Builded_on-Java-orange?style=for-the-badge
[kojamp-builded-also]: https://img.shields.io/badge/Also_builded_on-C-blue?style=for-the-badge
