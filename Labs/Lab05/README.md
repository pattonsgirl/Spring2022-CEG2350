# Lab 05 - NOT FINALIZED

- [Lab Procedure](#Lab-Procedure)
- [Part 1 - Self Discovery](#Part-1---Self-Discovery)
- [Part 2 - AWS Instance Exploration](#Part-2---AWS-Instance-Exploration)
- [Part 3 - Bulk Renamer](#Part-3---Bulk-Renamer)
- [Submission](#Submission)
- [Rubric](#Rubric)

## Lab Procedure

[Return to here and select "Start Lab"](https://awsacademy.instructure.com/courses/13249/modules/items/1136419)

Use `ssh` to connect to your AWS Ubuntu instance.

Go to the folder that contains your repository (likely named `ceg2350-yourgithubusername`).

Create a new directory, `Lab05`

This lab may have you creating input files, scripts, and output files. All of your work should be found here.

Some questions will need you to write anwers in `Lab05.md` the [LabTemplate.md is here](LabTemplate.md).

- [Raw version of LabTemplate.md](https://raw.githubusercontent.com/pattonsgirl/Spring2022-CEG2350/main/Labs/Lab05/LabTemplate.md)

For each part below, you will be asked to do an action or answer a question. The actions are going to be commands - you will write the command you used as "answers" to the action requested. You are allowed to use multiple commands to solve an action. Just write down all that were needed to complete. Check with the TAs if you need clarification.

If you did something "wrong" make a note of it in your lab. These are learning experiences - writing them down will help you ask good questions later.

## Part 1 - Self Discovery

Find out the following information about your personal system. Write the answers to the information requested. Part of this is learning about your system, so some info will not be findable. Provide confirmation of your findings where possible.

For example, my laptop does not have a dedicated gpu card. I can run commands whose output will confirm there is no GPU

- You can use the manufactuers website / manuals
- Windows users, I recommend `msinfo`
- You should _not_ need to install additional programs to find this information. If someone tells you to install something, run away.

1. CPU brand, number of cores, and number of logical cores
2. Physical memory size (translate to GB)
3. Virtual memory size (translate to GB)
   - Does your system have a pagefile, and if so where is it?
4. Disk type / model
5. Disk size (translate to GB)
6. Remaining disk space (translate to GB)
7. File system used on primary partition
   - C partition for Windows users
   - / partition for Linux / Mac(?) users
8. BIOS mode / version
9. Note whether or not your BIOS / UEFI is accessible, and what steps should let you access it.

## Part 2 - AWS Instance Exploration

Use your AWS / Ubuntu system to discover the following information. Part of this is learning about a system, so some info will not be findable. Provide confirmation of your findings where possible.

For example, this system does not have a dedicated gpu card. I can run commands whose output will confirm there is no GPU

- **Useful commands for this part: `lscpu`, `free`, `vmstat`, `lsblk`, `df`, `fdisk --list`**

1. CPU brand, number of cores, and number of logical cores
2. Physical memory size (translate to GB)
3. Virtual memory size (translate to GB)
   - Does your system have a pagefile, and if so where is it?
   - https://phoenixnap.com/kb/linux-commands-check-memory-usage
4. Disk type / model
   - https://www.cyberciti.biz/faq/find-hard-disk-hardware-specs-on-linux/
   - https://askubuntu.com/questions/166083/what-is-the-dev-xvda1-device
5. Disk size (translate to GB)
6. Remaining disk space (translate to GB)
7. File system used on primary partition
   - Focus on the ID column - https://www.win.tue.nl/~aeb/partitions/partition_types-1.html

## Part 3 - Bulk Renamer

1. Download and run [this script](createfiles.sh). It will generate some dummy files for this part.
2. Create a script in your `Lab05` folder named `bulkrename` that meets the following specifications. The script will run as: `./bulkrename -f findstring -r replacestring files`
   - Note: files could be all files in a folder, for example: `~/folder/*`
3. Use `getopts` to utilize both arguments and functions.
   - `-r` = what to replace in the filename string. Should have an argument after, save to a variable
   - `-f` = what to find in the filename string. Should have an argument after, save to a variable
   - `?` = printHelp, a function that has a help guide
4. Create a function called `printHelp`. `printHelp` should output the following:

```
Usage: bulkrename -f find -r replace FILES_TO_RENAME*
 -f The text to find in the filename
 -r The replacement text for the new filename
```

5. If `-r` or `-f` have empty (no) arguments after them, output "User must provide string for find and string for replace" following by the usage guide in the `printHelp` function

6. For each file given, create a new filename using `sed` to replace the match in the filename string with the supplied replacement. Use `mv` to change the filename to the new filename. Include a useful output statement to see what changed.

```
# Hint:
for file in $@:
do
   echo $file
done
```

- **Resources**
- [`getopts` examples](https://linuxhint.com/bash_getopts_example/)
- [`sed` with string, not input file](https://stackoverflow.com/questions/13055889/sed-with-literal-string-not-input-file)

## Submission

1. Verify that your GitHub repo has a `Lab05` folder with at minimum:

   - `Lab05.md`
   - `bulkrename`

2. In the Pilot Dropbox, paste the URL to the `Lab05` folder in your GitHub repo
   - URL should look like: https://github.com/WSU-kduncan/ceg2350-YOURGITHUBUSERNAME/tree/main/Lab05

## Rubric

- Part 1 - 1 pt per question - 9 pts total
- Part 2 - 1 pt per question - 7 pts total
- Part 3 - 6 pts total
