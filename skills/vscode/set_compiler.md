g++ and c++11:
based on [this json configuration](https://code.visualstudio.com/docs/cpp/config-linux#:~:text=%7B%0A%20%20%22version%22%3A%20%222.0.0%22%2C%0A%20%20%22tasks,build%22%2C%0A%20%20%20%20%20%20%20%20%22isDefault%22%3A%20true%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%5D%0A%7D), and add `"-std=c++11"` on args:
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "g++ build active file",
      "command": "/usr/bin/g++",
      "args": ["-std=c++11", "-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"],
      "options": {
        "cwd": "/usr/bin"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}

clang++ and c++17:
based on [this json config](https://code.visualstudio.com/docs/cpp/config-clang-mac#:~:text=%7B%0A%20%20//%20See%20https%3A//go,build%22%2C%0A%20%20%20%20%20%20%20%20%22isDefault%22%3A%20true%0A%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%5D%0A%7D)
{
  // See https://go.microsoft.com/fwlink/?LinkId=733558
  // for the documentation about the tasks.json format
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "clang++ build active file",
      "command": "/usr/bin/clang++",
      "args": [
        "-std=c++17",
        "-stdlib=libc++",
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "${workspaceFolder}"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
