# Lab 05

- [Lab Procedure](#Lab-Procedure)
- [Part 1 - Self Discovery](#Part-1---Self-Discovery)
- [Part 2 - AWS Instance Exploration](#Part-2---AWS-Instance-Exploration)
- [Part 3 - Info Finder](#Part-3---Info-Finder)
- [Extra Credit - `date` stamp](#Extra-Credit---`date`-stamp)
- [Submission](#Submission)
- [Rubric](#Rubric)

## Lab Procedure

In your terminal, head to your repository (the folder named `ceg2350-yourgithubusername).

Create a new directory, `Lab05`

This lab will have you creating input files, scripts, and output files.  All of your work should be found here.

Same questions will need you to write anwers in `Lab05.md` the [LabTemplate.md is here](LabTemplate.md).
   - [Raw version of LabTemplate.md](https://raw.githubusercontent.com/pattonsgirl/Fall2021-CEG2350/main/Labs/Lab05/LabTemplate.md)

For each part below, you will be asked to do an action or answer a question.  The actions are going to be commands - you will write the command you used as "answers" to the action requested.  You are allowed to use multiple commands to solve an action.  Just write down all that were needed to complete.  Check with the TAs if you need clarification.

If you did something "wrong" make a note of it in your lab. These are learning experiences - writing them down will help you ask good questions later. 

## Part 1 - Self Discovery

Find out the following information about your personal system. Write the answers to the information requested.  Part of this is learning about your system, so some info will not be findable.  Provide confirmation of your findings where possible.  

For example, my laptop does not have a dedicated gpu card.  I can run commands whose output will confirm there is no GPU

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
9. Note whether or not your BIOS / UEFI is accessible, and what steps shoud let you access it.
10. ~~System bootloader and location~~ removed 9/29

## Part 2 - AWS Instance Exploration

Use your AWS / Ubuntu system to discover the following information.  Part of this is learning about a system, so some info will not be findable.  Provide confirmation of your findings where possible.  

For example, this system does not have a dedicated gpu card.  I can run commands whose output will confirm there is no GPU

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
8. ~~System bootloader and location~~ - removed 9/29

## Part 3 - Info Finder

You could see that manually raoming around tracking down system information could be clunky over enough time over enough systems.  So, we are going to focus on the important bits via a script.  

You have also noticed that some of these commands only run as a certian user (or with certian user priviledges)

1. Check out the list of commands in [command-list.txt](command-list.txt)
2. Create a script in your Lab05 folder named `sys-info`.  Give the script appropriate permissions to be executable.
   - Note: I don't care about PATH knowing where it is
3. `sys-info` should perform the following tasks:
   - If the script is run with `sudo` / as `root`, run a full sytstem report using all commands listed in `command-list.txt`
      - Store the output in a file named `full-system-report.txt`
   - Else, run only the commands that a regular user can run without `sudo`
      - Store the output in a file named `basic-system-report.txt`

- Hints: 
   - [Identify sudo use with whoami](https://www.baeldung.com/linux/identify-user-called-by-sudo)
   - [Have script check user ID](https://www.cyberciti.biz/tips/shell-root-user-check-script.html)


Sample execution:
```
$ ./sys-info
You get a basic report
Report saved to basic-system-report.txt
$ sudo ./sys-info
Running a full report, sir.
Report saved to full-system-report.txt
```

## Extra Credit - `date` stamp

- Use the `date` command to make a better filename.  Instead of `*-system-report.txt`, the filename should now be `*-system-report-0927.txt`, for example.  I'll allow for any use of the `date` command as long as it adds some useful timestamping to the report generation.
   - Hint: https://www.cyberciti.biz/faq/unix-linux-appleosx-bsd-shell-appending-date-to-filename/ 

## Submission

1. Verify that your GitHub repo has a `Lab05` folder with at minimum:
   - `Lab05.md`
   - `sys-info`
   - `basic-system-report.txt` (or the ec version of report name)
   - `full-system-report.txt` (or the ec version of report name)


2. In the Pilot Dropbox, paste the URL to the `Lab05` folder in your GitHub repo
    - URL should look like: https://github.com/WSU-kduncan/ceg2350-YOURGITHUBUSERNAME/tree/main/Lab05

## Rubric

- Part 1 - 1 pt per question - 9 pts total
- Part 2 - 1 pt per question - 7 pts total
- Part 3 - 6 pts total
   - can detect if script is run with sudo / as root - 2 pts
   - outputs basic report if run as regular user - 2 pt
   - outputs full report if run with sudo / root priviledges - 2 pt
- EC - 2.2 pts - 10% 