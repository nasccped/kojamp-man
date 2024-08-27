Kojamp Man
==========

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

4. Compile the source code:

  Within the cloned repo, we have a Makefile with some automations
  processes. To compile to source you can type:

  ```shell
  make build
  ```

5. Run the output:

  And finally, to run the generated one you can just type:

  ```shell
  make run
  ```

  This will run the file!
