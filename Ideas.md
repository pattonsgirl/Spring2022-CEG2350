1. Run `sudo apt update` - in your lab notes, explain what update does
2. Run `sudo apt upgrade` - in your lab notes, explain what upgrade does
3. Run `sudo apt autoremove` - in your lab notes, explain what autoremove does  
   **Useful commands: `man, apt, sudo`**

`ssh` in to your AWS environment. If you've forgotten your key, you'll need to provision a new stack in AWS Educate and create a new key.  
See [Remaking your AWS Educate environment](../../..) for instructions.

1. Read `/boot/grub/menu.lst`. According to this file, what options would the grub menu present?
2. Using the command `df -h`, determine how much disk space is used and how much space is free?
3. Run the command `sudo parted -l`
   - What is the primary disk in the `/dev` folder?
   - What type of partition table is our AWS environment using?
     - Hint: If it looks unfamilar, use Google to find the common name
   - What file system is used by this device?
4. [Set file system of partition] Run `parted` on the disk (use the answer you found in Part 1-3)
   - How can you view the options for `parted`?
5. [Mount partition]
6. [Add partition to /etc/fstab]

Scripting:
Find out what shell we are using in AWS. Hint, read `/etc/passwd` (1 pt) \* A guide on what is in [/etc/passwd](http://www.linfo.org/etc_passwd.html)

Debugging shell scripts w/ error messages or https://www.shellcheck.net/#

Scripting ideas: https://www.hackerrank.com/domains/shell

Program that outputs file permissions

systems administration:
Create new user on system, create key pair for that user. Use `sftp` to get the private key, log in as the new user just using ssh (no -i flag)
Get the `md5sum` of both your local file and the file now copied to AWS. Make a change to the contents of one or the other, and check the `md5sum` of both again. Are the `md5sum`s of both files still the same? Why or why not?
Use journalctl on Linux or log show on macOS to get the super user accesses and commands in the last day. If there aren’t any you can execute some harmless commands such as sudo ls and check again.

vim tutor
add customization to .vimrc (plugin, coloring, something)
Different outputs in sed, pros and cons (in-place vs copy) - sed s/REGEX/SUBSTITUTION/ input.txt > input.txt why?

Late git:
Complete assigned sections of https://learngitbranching.js.org/
Fork and find a mistake / update / add another resource and create a pull request to course repo.

Networking:
Find an online data set like this one, this one. or maybe one from here. Fetch it using curl and extract out just two columns of numerical data. If you’re fetching HTML data, pup might be helpful. For JSON data, try jq. Find the min and max of one column in a single command, and the sum of the difference between the two columns in another.

tcpdump / Wireshark lab?

Download file with `wget`. Convert to different file type. Use `basename` to keep name but change extension

diehardback.com - investigate sketchyness

3. Somewhere in my command history, I have written the perfect ssh command. Write a search with grep that will narrow down my search of my history.

4. I have a repository with a working version of my project. I decide I would like to add a new feature to my project. Should I create a fork or a branch?

Sign a git commit
Encrypt and decrypt a file

5. Configure /etc/hosts
6. Configure ~/.ssh/config
7. In your client of choice, create a new key pair
   - Note: use the defaults (ie. ~/.ssh/id_rsa)
8. Copy your public key into the `authorized_keys` file on your AWS system.
9. SSH from your local machine to the AWS machine

c:\Windows\System32\Drivers\etc\hosts

Use your AWS portal, or just use Google.

Find something that people are using AWS for that you would be curious about investigating. Try to describe a project idea that comes to mind.

Note: this is for fun. Have some fun! Personally, I want to play with the AWS Deep Racer

### Part 5: Play with hard links, soft links, and inodes (11 pts)

1. By default, what does `ln` followed by a filename do?
2. Use `ln` to create a file named `hard.txt` from `test.txt`
3. Note the inode number of `hard.txt` and `test.txt`. Are they the same?
4. Create a symbolic link called `sym.txt` from `hard.txt`
5. Note the inode number of `sym.txt`. Is it the same as `hard.txt`?
6. Delete `test.txt`. Is `hard.txt` and `sym.txt` still readable?
7. Delete `hard.txt`. Is `sym.txt` still readable? Why or why not?
8. Make a new file called `hard.txt` with some text in it. Can `sym.txt` be read now? Why or why not?
9. Move `hard.txt` to `DirB`. Can you read `sym.txt`?
10. Delete `sym.txt`
11. Create a symbolic link from `hard.txt` in `DirB` to `newsym.txt` in `DirA`  
    **Useful Commands: `ln, test, stat, cp, mv, rm`**

## Lab 02

Part 4
Removed: 3. Find a way for the `ubuntu` user to add a file to `bob`'s home directory named `fromubuntu.txt`

- Write the command(s) you used.
- Are you happy with your solution?

6. Can `bob` edit `fromubuntu.txt`?
7. Fix the permissions so that `bob` owns `fromubuntu.txt`
   - Hint: can `bob` use `sudo`?

## Lab 04

marco / polo - use after talking about parent / child processes?

1. In your `Lab04` folder, create a folder called `scripts`. Inside that folder, create two scripts, one named `marco` and one named `polo`.
2. For now, have `marco` and `polo` print a statment to standard output when they are run - `This is from marco` and `This is from polo` respectively.
3. Add the folder these scripts are located in to your `PATH`. (2 pts)

- First use the `export` command in you terminal to test you have properly added to the `PATH`. Write this command in your lab notes.
  - If you really mess this up, log out (`exit`) your AWS Linux connection and `ssh` back in. You can refer to [here](PATH-backup) to verify it looks how it used to.
- Test that `marco` and `polo` can now be run in any directory.
- Add your working `export` command to your home directory's `.profile`.
  - If you really mess up, there is a backup `.profile` file [here](.profile-backup). You can copy and paste the contents.

4. Modify `marco` so that when it is run, it should save the current working directory in a file so that `polo` can reference it. (1 pt)

- Hint: If `marco` can be ran in any directory and `polo` can be run in any directory, should the path to the file be relative or absolute?

5. Modify `polo` so that when it is run, it echos the command the user needs to go to the directory `marco` was called in.

For the `marco` script, when `marco` is run it should check if a path has already been "saved" and ask if the user would like to update the path. Don't forget to `commit` and `push` your updates for grading.

- [Hint](https://www.cyberciti.biz/faq/linux-unix-script-check-if-file-empty-or-not/)

### Credits:

Exercise based on https://missing.csail.mit.edu/2020/shell-tools/

# Old Lab 05

## Part 1: Write Source Code (2 pts)

1. You may choose _Java_ or _C_ or _C++_ to do the following:

- Write source code that prompts the user to enter text / a string from standard input, then outputs the same string back to standard out. Include your code in your lab write up.
  - I recommend naming the source code file `repeat` with the appropriate language extension (ie. `repeat.java`, `repeat.c`, `repeat.cpp`).
  - Code integrity does not matter - you may work together or use things found on the internet or textbooks.
  - Python only coders - you will be happiest in C. Go about halfway through [this guide](https://www.geeksforgeeks.org/strings-in-c-2/) for starter code. You'll need to add another print statement before the scan statement to prompt the user to enter a string.

## Part 2: Compile Source Code (4 pts)

1. Find the location of the C compiler, `gcc`. Write the command to find out which version of `gcc` is running. (1 pt)  
   **Useful commands: `whereis, which, man`**
2. Find the location of the Java compiler, `javac`. Write the command to find out which version of `javac` is running. (1 pt)  
   **Useful commands: `whereis, which, man`**
3. Compile your code using the corresponding compiler. Write the command you used to compile your source code. (1 pt)
4. Run your program. Write the command you used to run your compiled program. (1 pt)

**Resources**

- [Compile a Java Program](https://beginnersbook.com/2013/05/first-java-program/)
- [Compile a C/C++ Program](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)

## Part 3: Make that Makefile (3 pts)

1. Create a file called `Makefile`.
2. Write contents in `Makefile` so that in the shell the following commands perform the following actions:
   - `make` will compile the program and create an executable version if the source code file exists (1 pt)
   - `make run` will execute the program if the compiled program exists (1 pt)
   - `make clean` will delete the compiled program (1 pt)

**Resources**

- [Sample Java Makefile in this folder](./Makefile-Java)
- [Sample C/C++ Makefile in the folder](./Makefile-C)
- [Makefile in C](https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#C)
- [Makefile in Java](https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#java)

## Part 4: The Git Part (1 pt)

1. In your `README.md` file, add details on how to run your program manually & how to run your program with the `make` command.
2. Use `git` commands to `add`, `commit` and `push` the `Lab05` folder to GitHub.

## Extra Credit (2 pt):

- Create an additional source code file that the original uses as a dependency. Perhaps your main code file calls on a function that is detailed in the other file (function can do a simple action, like print a message).
  - You may use an old / existing multifile project (again, just need to require compilation)
- Modify your `Makefile` to compile the original file & its new dependency. Note that your `Makefile` should have an updated version of the pre requisites to compile the program.
- Don't forget to `commit` and `push` your updates for grading.

## Lab 06 OLD

## Part 1: Self Discovery (5 pts)

Find out the following information about your personal system. Write the answers to the information requested.

- You can use the manufactuers website / manuals
- Windows users, I recommend `msinfo`
- You should _not_ need to install additional programs to find this information. If someone tells you to install something, run away.

1. BIOS version / mode. (1 pt)
2. CPU brand and info. (0.5 pt)
3. Installed memory size. (0.5 pt)
4. Virtual memory size. Does you system have a pagefile or a swapfile? What does this mean? (1 pt)
5. File system on installed disk(s). (0.5 pt)
6. Number of partitions. Which partition is your primary partition? (0.5 pt)
7. Get to your UEFI BIOS. Note what you did to access it. Then run away. (1 pt)
   - If you don't own the machine (and therefore may not be able to access the BIOS), lookup information about the machine and what steps would have worked.
   - Note for Chromebook users: Document what your tried and what you learned about your system.
   - Note for Mac users: [This article](https://www.techwalla.com/articles/macbook-efi-access) may help

## Part 2: Exploration (5 pts)

Use your AWS / Ubuntu system to discover the following information.

1. Read `/boot/grub/menu.lst`. What boot options would the `grub` menu present? (1 pt)
   - Note: since we are using a remote connection, we will never see / interact with the `grub` menu. But it is still there.
2. Using the command `df -h`, determine how much disk space is used and how much space is free. (1 pt)
3. Run the command `sudo parted -l` to answer the following:
   - What is the primary disk in the `/dev` folder? (.33 pt)
   - What type of partition table is the device using? (.33 pt)
     - Hint: If it looks unfamilar, use Google to find a more common name
   - What file system is used by the device? (.33 pt)
4. Use `lshw` to find the following:
   - BIOS version (.33 pt)
   - CPU brand and info (.33 pt)
   - Memory size (.33 pt)
5. Does this system have a swap file (use virtual memory)? Write how you checked. (1 pt)
   - [Hint](https://unix.stackexchange.com/questions/23072/how-can-i-check-if-swap-is-active-from-the-command-line)

## Part 1: Create a filesystem from a file to store files (10 pts)

Perform the following in your AWS instance. For this part, work in your user's home directory (`/home/ubuntu`), not your repository. Your answers will still go in your `README.md` file associated with this lab.

1. Create a file of a defined amount of space: `dd if=/dev/zero of=space bs=1024 count=0 seek=$[1024*100]`
   - Explain `if` and `of` (.33 pt)
   - Explain what `/dev/zero` is (.33 pt)
   - What size file was created? (.33 pt)
2. Create a filesystem on this file. Write the command you used. (1 pt)
   - **Useful commands:** `mkfs`
3. Mount the filesystem to your home directory in the folder `usable`. Write the command you used. (1 pt)
   - **Useful commands:** `mount`, `mkdir`
4. Check to see if the filesystem was mounted according to the output of `df -h` Paste the line that indicates where it was mounted and space usage (1 pt)
   - Notes: you may see and be wondering about `/dev/loop#` loop is what happens when you are using a file that has a filesystem inside, which is exactly what happened - we used `dd` to create a file filled with 0's, then we used `mkfs` to have the file be a filesystem.
   - [More info on `/dev/loop#`](https://en.wikipedia.org/wiki/Loop_device)
5. Go in to the folder `usable` and create some new files with some text inside. Write the steps this took and if you changed permission sets. (1 pt)
6. Unmount the filesystem currently mounted to `usable`. Write the command you used. (1 pt)
   - **Useful commands:** `umount`
7. Can you still access the files? Why or why not? (1 pt)
8. While the filesystem is still unmounted, run `strings` on `space`. What do you see? Can you see the contents of your files? (1 pt)
   - Notes: `cat` would work, but also might act like its hanging. `strings` is kind of like `cat` but it will ONLY print the strings of printable characters in files.
9. Mount the filesystem once more, and delete / remove one of the files. Unmount the filesystem, and run `strings` again. Can you see the contents of your files? (1 pt)
   - Notes: this is the big scary deal about data and disks and making sure data gets overwritten on a disk if the data needs to truly go away. When you delete a file, all you've done is delete the inode association (you can't vim it, and you can't use an inode to get back to it), but the data is still written to the disk until it is overwritten (which could happen given enough time). Removing a file is like throwing away a letter. If the letter is still whole, it can be pulled back out and read.
10. Add this filesystem to be automounted by the OS using `/etc/fstab` Write the line you added to `/etc/fstab` (1 pt)
    - Hint: the line should be in the format of:
      - `/absolute/path/to/filesystem` **tab** `/absolute/path/to/directory/to/mount/to` **tab** `defaults` **tab** `0 0`
      - [More info on `fstab`](https://en.wikipedia.org/wiki/Fstab)
    - Test your changes using the 'mount -a' command. What does this command do?
    - Use `df -h` or head back to your `usable` folder to verify the mount worked (as in the file(s) you didn't delete should be viewable in the folder with `ls`)

**Just in Case Resources:**

- [Mount broken volume to new system](https://www.xtivia.com/blog/recovering-aws-instance-doesnt-start/)
