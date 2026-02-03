# My_Sudo

## Overview

**My_Sudo** is a custom implementation of the `sudo` command, allowing users to execute commands with elevated privileges. It mimics the behavior of the standard `sudo` utility while providing additional flexibility and customization options.

This project was developed as part of the EPITECH curriculum and demonstrates proficiency in system programming, user authentication, and process management.

---

## Features

- **User and Group Management**: Supports specifying users (`-u`) and groups (`-g`) for command execution.
- **Environment Preservation**: Option to preserve the environment variables using the `-E` flag.
- **Command Execution**: Executes commands using `execve` or `execvp` based on the flags provided.
- **Password Authentication**: Validates user credentials using hashed passwords from `/etc/shadow`.
- **Error Handling**: Provides detailed error messages for invalid inputs or failed operations.
- **Help Menu**: Displays usage instructions with the `-h` flag.

---

## Usage

### Command Syntax

```bash
./my_sudo [-ugEs] [command [args ...]]
```

### Flags

- `-u <user>`: Specify the user to execute the command as.
- `-g <group>`: Specify the group to execute the command as.
- `-E`: Preserve the current environment variables.
- `-s`: Execute the command in a shell.
- `-h`: Display the help menu.

### Examples

1. Execute a command as a specific user:
   ```bash
   ./my_sudo -u username ls -l
   ```

2. Execute a command as a specific group:
   ```bash
   ./my_sudo -g groupname ls -l
   ```

3. Preserve environment variables:
   ```bash
   ./my_sudo -E env
   ```

4. Display the help menu:
   ```bash
   ./my_sudo -h
   ```

---

## Project Structure

### Source Code

- **Main Logic**:
  - `main.c`: Entry point of the program.
  - `make_sudo.c`: Handles the execution logic based on flags.

- **Command Execution**:
  - `my_execve.c`: Executes commands using `execve`.
  - `my_execvp.c`: Executes commands using `execvp`.
  - `my_sys.c` and `my_sysve.c`: Alternative execution methods.

- **Flag Parsing**:
  - `flag_parser.c`: Parses command-line flags.
  - `get_command.c`: Extracts the command and its arguments.

- **User and Group Management**:
  - `get_user_and_group.c`: Validates user and group existence.
  - `set_uid.c`, `set_gid.c`, `set_uid_gid.c`: Sets user and group IDs.

- **File Parsing**:
  - `get_username.c`: Retrieves the current username.
  - `get_userpasswd.c`: Retrieves the hashed password for authentication.
  - `bash_parser.c`: Parses the shell path for the user.

### Header File

- `my.h`: Contains function prototypes, macros, and the `flags_t` structure definition.

### Build System

- **Makefile**: Automates the build process and sets appropriate permissions for the executable.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Nielsen-ls/B-PSU-100-MPL-1-1-mysudo.git
   cd B-PSU-100-MPL-1-1-mysudo
   ```

2. Build the project:
   ```bash
   make
   ```

3. Set permissions for the executable:
   ```bash
   sudo make perm
   ```

---

## Security Considerations

- **Password Handling**: Passwords are securely hashed and compared using the `crypt` library.
- **Root Privileges**: The executable requires root ownership and the `setuid` bit to function correctly.

---

## Known Limitations

- Requires access to `/etc/passwd` and `/etc/shadow` for user and password validation.
- Limited error handling for edge cases in system calls.
