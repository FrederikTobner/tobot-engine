# Contrubuting

You can contribute to this project by adding new features, fixing bugs or improving the documentation. To do so, you can clone this repository, make your changes, and submit a pull request.

When you clone the project you need to add all the submodules and their submodules as well. You can do that by running the following command

```bash
git clone --recursive https://github.com/FrederikTobner/tobot-engine
```

## Requirements

We have a code formatting style configured using clang-format. You can find the configuration file in the root directory of the project. You can use clang-format to format your code. If you are using Visual Studio Code you can install the clang-format extension and it will format your code automatically.
To install clang-format on Windows you can use the following command:

 Install the clang-format plugin, conventional commits and the doxygen comment plugin. Additionally install doxygen or clang-format if needed:
Python: python3 -m pip install clang-format
Node.js: npm install -g clang-format

To format your code automatically on save, if you are using vscode, add the following to your settings.json:

```json
{
  "editor.formatOnSave": true
}
```

Additionally we are using conventional commits to format our commit messages.

You can find more information about conventional commits [here](https://www.conventionalcommits.org/en/v1.0.0/). There is a vscode extension that helps you to write conventional commits. You can find it [here](https://marketplace.visualstudio.com/items?itemName=vivaxy.vscode-conventional-commits).
