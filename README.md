# CShark
 A simple and dumb programming language based on a shark

![imagen](https://github.com/user-attachments/assets/2bcfda6c-a730-46b9-b977-277354a69de1)

#Docs
The documentation can be found on the [Wiki](https://github.com/Kuvrot/CShark/wiki)

# Compiling

If using git, clone the repo with 
```
git clone https://github.com/Kuvrot/CShark.git
```
- Configure and build your project. Most popular IDEs support CMake projects with very little effort on your part.
    - [Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170) (recommended)
    - [VS Code](https://code.visualstudio.com) via the [CMake extension](https://code.visualstudio.com/docs/cpp/cmake-linux)
    - [CLion](https://www.jetbrains.com/clion/features/cmake-support.html)
    - [Qt Creator](https://doc.qt.io/qtcreator/creator-project-cmake.html)

    Using CMake from the command line:

    For a single-configuration generator (typically the case on Linux and macOS):
    ```
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    cmake --build build
    ```

    For a multi-configuration generator (typically the case on Windows):
    ```
    cmake -S . -B build
    cmake --build build --config Release
    ```
