# Lab 07

- [Lab Procedure](#Lab-Procedure)
- [Part 1 - inode what is up](#Part-1---inode-what-is-up)
- [Part 2 - unallocated resources](#Part-2---unallocated-resources)
- [Extra Credit - take a fstab at this](#Extra-Credit---take-a-fstab-at-this)
- [Submission](#Submission)
- [Rubric](#Rubric)

## Lab Procedure

In your terminal, head to your repository (the folder named `ceg2350-yourgithubusername).

Create a new directory, `Lab07`

Create a file named `Lab07.md` [based on the template](LabTemplate.md).
   - [Raw version of LabTemplate.md](https://raw.githubusercontent.com/pattonsgirl/Fall2021-CEG2350/main/Labs/Lab07/LabTemplate.md)

For each part below, you will be asked to do an action or answer a question.  The actions are going to be commands - you will write the command you used as "answers" to the action requested.  You are allowed to use multiple commands to solve an action.  Just write down all that were needed to complete.  Check with the TAs if you need clarification.

If you did something "wrong" make a note of it in your lab. These are learning experiences - writing them down will help you ask good questions later. 

## Part 1 - inode what is up
- **Useful Commands: `stat`, `ln`, `cp`, `mv`**

1. Create a file in your Lab07 folder named `original.txt`.  Put some stuff in this file.
2. For `original.txt` identify:
   - Command to find info about `original.txt`: 
   - inode `original.txt`:
   - blocks sym link file:
   - links `original.txt`:
3. Create a new folder in `Lab07` called `playground`
4. In this folder, create a hard link to `original.txt` 
   - Command:
   - inode hard link file: 
   - blocks sym link file:
   - links hard link file: 
   - Does modifying the hard linked file modify `original.txt`?  Explain
5. In this folder, create a symbolic link to `original.txt`
   - Command:
   - inode sym link file: 
   - blocks sym link file: 
   - links sym link file: 
   - If `original.txt` was deleted, and a new `original.txt` was created, would the sym link still work?  Explain
6. In this folder, create a copy of `original.txt`
   - Command:
   - inode copied file: 
   - blocks copied file: 
   - links copied file: 
   - Does modifying the copied file modify `original.txt`? Explain
7. Move `original.txt` to another directory.
   - Command: 
   - Does it have the same inode?  Explain
   - Effect of symbolic link?  Explain
   - Effect on other hard linked file?  Explain
   - Effect on copied version of `original.txt`?  Explain

- Resources:
   - [https://linoxide.com/linux-inode/](https://linoxide.com/linux-inode/)
   - [https://www.howtogeek.com/465350/everything-you-ever-wanted-to-know-about-inodes-on-linux/](https://www.howtogeek.com/465350/everything-you-ever-wanted-to-know-about-inodes-on-linux/)

## Part 2 - unallocated resources

For each step below, write the answer to the question / prompt and how you found / configured the answer (commands used).

- **Useful Commands: `df`, `gdisk`, `mkfs`, `mount`, `strings`**

1. What drive letter and partition number are mounted and where are they mounted to?
2. Is there another drive listed in `/dev/`?
3. For the `gdisk` GPT partition table manipulator, find out what the following main menu options do:
   - `p`
   - `o`
   - `n`
   - `i`
   - `w`
4. Open the unused drive with `gdisk`.  Using the main menu, configure the disk to use the GPT partition table type, have at least 1 partition, and have that partition use the Linux filesystem type.  Save your changes to the disk.
5. Make an ext4 filesystem on the new partition
6. Make a folder in `/mnt/` called `expanse`
7. Mount the partition to `expanse`
8. Create some files (with and without text) and directories in the folder where your partition is mounted
9. Run `strings` on the partition - read through the output and determine what `strings` is outputting
   - Like other commands we have played with, `strings` has more capabilities.  We are going to use it to show you something interesting about data...
10. Delete a file that you created on the partition.  Run `strings` on the partition again - read through the output and see if anything surprises you - what's up?
   - This is a neat trick that starts getting towards digital forensics.  You can assume most people trust that when they hit delete, stuff got deleted.  But the contents may still exist on the disk until they are overwritten...
11. [Read through this article](https://www.howtogeek.com/425232/how-to-securely-delete-files-on-linux/) and determine a way to truly delete a file.  Write a short report of steps and proof that the file is no longer readable on the disk.
12. Umount the partition.  Can you still interact with the files and folders?


## Extra Credit - take a fstab at this

1. Add your partition and the mount point (`/mnt/expanse`) to `/etc/fstab`  
   - Line added to `/etc/fstab`: 
2. Test your changes using the `mount -a` and `df`.  Write what you did to prove you got it right in `/etc/fstab`
3. Reboot, if you're brave enough... test that your partition was automounted to `/mnt/expanse`

- Resources:
   - [https://help.ubuntu.com/community/Fstab](https://help.ubuntu.com/community/Fstab)

## Submission

1. Verify that your GitHub repo has a `Lab07` folder with at minimum:
   - `Lab07.md`

2. In the Pilot Dropbox, paste the URL to the `Lab07` folder in your GitHub repo
    - URL should look like: https://github.com/WSU-kduncan/ceg2350-YOURGITHUBUSERNAME/tree/main/Lab07

## Rubric

- Part 1 - 1 pt per question - 7 pts total
   - Subquestion scoring:
   - Q2 (0.25) pts per bullet
   - Q4 - Q7 (0.2) pts per bullet
- Part 2 - 1 pt per question - 12 pts total
- Extra credit - 10% (2 pts)


