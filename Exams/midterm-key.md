# Midterm Answer Key

## Spring 2022

1. In order to create passwordless authentication with GitHub, we set up SSH authentication on the system using ssh-keygen to create a key pair. Which key did GitHub need a copy of?

   - Correct answer: public key (contents of id_ed25519.pub). Public keys go on systems that we are connecting to. In this case, we are connecting to GitHub, and github needs a copy of our public key
   - Incorrect: private key (contents of id_ed25519). Private keys stay protected. In our case, the private key of the pair created stays private to us. AWS also had us download a private key; the public key was placed on the system we connect to (the AWS instance). As long as we have the private key, the can authenticate to systems with the correlating public key.

2. I am working in a git repository and want to synchronize my local work with GitHub. The output of `git status` is:

```
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   code.py
```

What steps are next to synchronize my local work with GitHub?

- changes made to file `code.py` are not staged for commit, so a commit of the current version of code.py needs to happen. Next, push to upload the commit(s) to GitHub
- `git add code.py && git commit` OR `git commit -a`
- `git push`

3. I have a repository on GitHub, but do not have a copy of the repository locally. Assuming SSH authentication has been set up, what is my next step?

   - Note the question states that there is NOT a copy of the respository locally.
   - Correct: `git clone repo_URL`
     - If a copy does not exist locally, I first need to **clone** the repository.
   - Explanation of incorrect choices:
   - `git pull` - pull can be performed if the repo exists locally and if there is content (commits) on GitHub that do not exist locally. Local must be in sync with (have commits from) remote before a push can occur
   - `git push` - push can be performed if commits exist locally that need to be syncronized with GitHub. If GitHub has had commits, a pull will need to occur first before the push can occur
   - `git add repo_URL` - improper usage. git add can be given one or more file names. Add is used to tell git and files to be tracked. Files will not be tracked unless they have been added for tracking
   - `git commit repo_URL` - improper usage. git commit creates "snapshots" of changes. These changes need a correlating commit message - best practice has a message describing what has changed between versions of a file.

4. For the AWS Ubuntu instance, what shell is used by default?

   - `bash` is the default shell. This can be accurately by `echo $SHELL`. Other cues include seeing a .bashrc file in the user's home directory.
   - `sh` exists on Linux / Unix systems by default. 0.9 pts
   - `zsh` is a shell used on Mac systems by default. It can be installed on Linux / Unix systems
   - cmd and Powershell exist for Windows systems. These days, Powershell can be installed on Linux systems, but it is not a default.

5. What does the following command do? `ls ..`

   - Correct answer: lists the contents of the parent directory based on the directory you are in
     - this can be found by heading to a terminal and typing `ls ..`
   - `..` is not a directory name, it is a reference to the parent directory. `.` is a reference to the current directory.
   - in order to see hidden files within a directory, options need to be given to `ls`. `-a` is the option to show all files, including hidden. `ls -a ..` would show all files, including hidden, of the parent directory.

6. Find the matching translation for the following chmod command:

```
chmod 456 newfile.txt
```

- Recall numeric permissions:
  - read = 4
  - write = 2
  - execute = 1
  - This is a set of three numbers
    - the first number sets permissions for the owner associated with the file / folder
    - the second number sets the permissions for the group associated with the file / folder
    - the third number sets the permissions for others on the system (outside of group and user)
- 4 = read, user can read
- 5 = read (4) + execute (1), group can read and execute
- 6 = read (4) + write (2), others can read and write
- Correct choice: user = read; group = read execute; other = read write
- https://chmod-calculator.com/

7. Given the following information about a file:

```
-rwxrw-r-x 1 kduncan friends 0 Feb 24 13:29 test.txt
```

And the following information about the friends group:

```
$ getent group friends
friends:x:1003:kduncan,sue,sam,frank
```

The user bob can edit test.txt

- kduncan = owner
  - the owner can read, write (edit) and execute the file
- friends = group.
  - friends group contains users kduncan, sue, sam, frank.
  - member of friends can read and write (edit) the file
- others on the system can read and execute the file
- bob is not a member of friends or an owner of the file. bob falls into the "other" on the system.
- bob cannot edit the file.

8. What is the PATH environment variable and how does the system utilize it?

- The PATH environment variable holds a list of directories that contain executables - the system then uses this list to serach through folders to find executables and run them when referenced on the command line or in other programs. For example, `ls` is a command - it's executable exists in `/bin/ls` (can vary). When we type `ls` and hit enter, the system searches the directories listed in `PATH` to find a matching executable of the name `ls`.
- Sample student answer:
- The PATH environment variable is a colon-delimited list of paths (directories) that linux/your shell searches for executables when the user tries to run a command. They exist so that the user does not have to specify an absolute path when running a command. PATH is essentially a shortcut to executables that the system can use to find a particular program quickly.

9. I have a script that prints hello to standard output. It has the following permission set:

```
-rw-rw---- 1 kduncan kduncan 11 Mar  6 21:14 bar.sh
```

I can run this script by typing:

```
./bar.sh
# OR
/home/kduncan/bar.sh
```

- False. To call on the script by location and name, the file needs execute permissions.
- This script can only be ran with `source bar.sh` OR `bash bar.sh` given its current permission set.
- This can be found by creating a script or taking an existing script, removing execute rights, and testing how it can be run

10. I have written a script named adder with the following contents:

```
#!/bin/bash

while getopts ":hf:s:" opt; do
        case $opt in
        h)
                echo "Help"
                exit
                ;;
        f)      f=$OPTARG

                ;;
        s)      s=$OPTARG
                ;;
        esac
done

echo "$s plus $f equals $(($f+$s))"
```

I would like to use this script to add together the number 4 and 6. Craft a command that will get it to output the added value

- `adder -f 4 -s 6`
- Other forms of proper usage accepted.
- Could place this script in a file in a bash shell and play

11. Which of the following will check if the folder exists before creating a file in it?

- Correct selection:

```
echo "Provide a folder and I'll make you a file!"
read dir

if [[ -d $dir ]]
then
        echo "As promised" > $dir/toldya.txt
else
        echo "Directory does not exist"
fi
```

- Commentary on incorrect selections:

```
echo "Provide a folder and I'll make you a file!"
read dir
# checks for existence, not if is exists AND is a directory
# 0.5 pts given
if [[ -e $dir ]]
then
        echo "As promised" > $dir/toldya.txt
else
        echo "Directory does not exist"
fi
```

```
echo "Provide a folder and I'll make you a file!"
read dir
# to use the value stored in a variable, need to use $variable_name
if [[ -d dir ]]
then
        # misuse of variable value repeated here
        echo "As promised" > dir/toldya.txt
else
        echo "Directory does not exist"
fi
```

```
echo "Provide a folder and I'll make you a file!"
read dir

# -z checks if the dir variable contains a value, not if it exists or is a directory
if (( -z $dir ))
then
        # this uses input redirection, not output redirection
        echo "As promised" < $dir/toldya.txt
else
        echo "Directory does not exist"
fi
```

12. Given the following regex pattern:

```
.+\s[123][ab]{3}
# Typo, wrong slash published: .+/s[123][ab]{3}
```

- `.+` any character repeated one or more times (but at least one)
- `\s` any space character
- `[123]` - the number 1 or 2 or 3
- `[ab]{3}` - the letter a OR b repeated 3 times
- Give a phrase that WILL match: `h45h9 2aba`
- Give phrase that will NOT match: `890cat`

13. Choose all that are valid types of data storage given options:

- SSD, HDD, NVME, DHME, RRD, RAM
- Correct selections:
  - SSD - solid state drive
  - HDD - hard disk drive
  - NVME - NonVolatile Memory Express
- RAM is for process storage; it may temporarily have "data" on a need to use basis, but it does not STORE data
- DHME and RRD were made up

14. The \_\_\_\_ file in the user's home directory holds configurations for their bash shell, including aliases

    - `.bashrc`
    - A handful of other forms of bash rc were given credit
      - `bashrc`, `bash_profile`

15. Correctly number the order of the boot process

    1. UEFI / BIOS loaded into RAM
    2. POST determines if hardware is working correctly
    3. Boot loader read from partition / partition table on disk
    4. Kernel loaded into RAM

16. Given the following snippet from a config file:

```
Host banana
        HostName cool.com
        User apple
        IdentityFile /home/kduncan/orange
```

What user name exists on the remote (host) system?

- `Host` name to use for this SSH profile
- `HostName` IP address or resolvable host name of system to connect to
- `User` username to log on to the system with (ubuntu on our AWS instances)
- `IdentityFile` location and name of the private key used for SSH authentication
- Correct answer: `apple`

17. Assuming I have permissions, which of the following will let me use admin privileges to override "Permission denied" errors?

- Correct answer: `sudo command`
  - If the command had a "Permission denied" error, assuming my user is part of the sudo users group, I can rerun the command with `sudo` (super user do)
- Overview of incorrect options:
  - `su command` - su = switch user
  - `root command` - root is a user, not a command to invoke admin priviledges
  - `cd command` - cd = change directory

18. (Bonus) Given the following data containing first names, last names, a color, and a treat:

```
Bob Barker purple cake
Sue Smith orange cookies
Sam Sanderson yellow oreos
Bill Smith red apples
```

Choose an awk command that will print the favorite color of people with an a or b in their first name.

- Correct answer: `awk '$1 ~ /[ab]/ {print $3}' data`
