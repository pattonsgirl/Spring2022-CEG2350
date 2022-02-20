## Intro topics

1. How did the modern computer come to be?
2. Shells
   - Windows: powershell, cmd
   - Linux / Mac: bash, sh, zsh
3. Terminals:
   - MobaXTerm
   - WSL2
   - Any program that lets you interact with a shell
4. SSH
   - the command ssh
   - private key files (where go and what permissions)
   - public keys (go where)

## Files, directories, and OS structure

1. OS structure in Linux (and Mac) vs Windows
2. Files vs directories
   - Commands: ls, cp, mkdir, rmdir, vim, mv, rm, cd, cat, touch, head/tail, less/more
3. Importance of names and extensions (file)
4. Ownership & sharing
   - rwx permissions in Linux (and Windows counterpart)
   - user vs. group vs. other
   - chmod, chown, chgrp
   - User types and groups: sudo vs. admin vs. “other” (sudo, adduser, deluser)
5. PATH

## Scripting

1. Aliases & customizations (.bashrc, .profile)
2. Commands: grep, ~~diff~~, find, ~~file~~, wc, sort, uniq, whereis, which
3. IO redirection (<, >, |, tee)
4. executing scripts (source, ./, PATH)
5. Scripting languages: bash
   - variables
   - conditionals (`test`)
   - arguments
   - if
   - for
   - while
   - getopts
   - case
6. Regular expressions
7. Requiring root to run

## Computer Hardware, Boot Process, and Data on Disks:

1. Computer Hardware:
   - Von Neumann machine: Control unit; instruction fetch, decode, and execution
   - CPU
   - RAM
   - Motherboard
   - Disks (HDD, SSD, NVME)
   - GPU
2. Booting of OS
   - Power on self-test (POST)
   - BIOS vs UEFI
   - MBR vs GPT
   - Boot loaders: NTLDR, GRUB
   - kernel vs OS
3. Virtual memory
   - What is it and how does it work
4. Disks
   - MBR vs GPT
   - partitions
   - filesystems
   - sectors vs blocks vs inodes
   - fragmentation

## Virtual Machines

1. Set of resources virtually "defined"
2. Resource allocation managed by hypervisor
3. Can install an operating system to a disk using an iso (machine image)
4. What can you do in a virtual machine?

## Git (version control)

1. Git remote (servers) vs. clients (local)
2. Basic commands:
   - clone
   - add
   - commit
   - push
   - pull
